#include <opencv2/opencv.hpp>
#include "../include/config.h"

using namespace SLAM;


Config::Config(std::string Path)
{
    this->configPath =  Path;
}

void Config::load()
{
    cv::FileStorage fsSettings(configPath, cv::FileStorage::READ);
    if(!fsSettings.isOpened())
    {
        cerr << "ERROR: Wrong path to settings" << endl;
        return;
    }
    cv::Mat K_l, K_r, P_l, P_r, R_l, R_r, D_l, D_r;

    fsSettings["LEFT.K"] >> K_l;
    fsSettings["RIGHT.K"] >> K_r;

    fsSettings["LEFT.P"] >> P_l;
    fsSettings["RIGHT.P"] >> P_r;

    fsSettings["LEFT.R"] >> R_l;
    fsSettings["RIGHT.R"] >> R_r;

    fsSettings["LEFT.D"] >> D_l;
    fsSettings["RIGHT.D"] >> D_r;

    int rows_l = fsSettings["LEFT.height"];
    int cols_l = fsSettings["LEFT.width"];
    int rows_r = fsSettings["RIGHT.height"];
    int cols_r = fsSettings["RIGHT.width"];

    cv::initUndistortRectifyMap(K_l,D_l,R_l,P_l.rowRange(0,3).colRange(0,3),cv::Size(cols_l,rows_l),CV_32F,M1l,M2l);
    cv::initUndistortRectifyMap(K_r,D_r,R_r,P_r.rowRange(0,3).colRange(0,3),cv::Size(cols_r,rows_r),CV_32F,M1r,M2r);

    float fx = fsSettings["Camera.fx"];
    float fy = fsSettings["Camera.fy"];
    float cx = fsSettings["Camera.cx"];
    float cy = fsSettings["Camera.cy"];
    float bf = fsSettings["Camera.bf"];
    float b = bf/fx;

    // stereoCameraPara.fx = fx;
    // stereoCameraPara.fy = fy;
    // stereoCameraPara.cx = cx;
    // stereoCameraPara.cy = cy;
    // stereoCameraPara.bf = bf;
    // stereoCameraPara.b = b;

    cv::Mat Tbc;

    fsSettings["T_BS"] >> Tbc;
    std::cout << "Tbc "<< Tbc<<std::endl;
    
    // stereoCameraPara.Tbc = B_Pose_camLrect_;
    // stereoCameraPara.Tbc.print("stereoCameraPara.Tbc");

    fsSettings.release();

} // namespace SLAM

int main(){
    using namespace SLAM;
    Config fconfig("EuRoC.yaml");
    fconfig.load();

}