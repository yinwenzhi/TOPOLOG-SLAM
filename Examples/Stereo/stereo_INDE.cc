#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>

#include <opencv2/core/core.hpp>

#define PI 3.141593
using namespace std;
using namespace cv;



// load config file


// read data frome camera
// void getCameraData640
// void getImuData
int readDataOnline()
{
    int imutime = 2;
    int cameratime = 60;
    indem::IDriverInterface *pDriver = (indem::IDriverInterface*) DriverFactory();

    if (pDriver->Open(1000,50)) {
        std::cout << "open success\n"<<std::endl;
    }
    pDriver->SetCameraCallback(getCameraData640);
    //pDriver->SetCameraCallback(getCameraData);

    pDriver->SetIMUCallback(getImuData);
    sleep(10000000);
    return  1;


// start slam


// parameters

// camera yaml file

// camera W H  
// IMU  
// 200
// 25
}
