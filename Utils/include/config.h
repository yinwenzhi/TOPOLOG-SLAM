#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
namespace SLAM
{
    class Config
    {
    private:
        /* data */
    public:
        std::string configPath;
        cv::Mat M1l,M2l,M1r,M2r;
    public:
        Config(string configPath);
        // ~Config();
        void load();
    };
}
