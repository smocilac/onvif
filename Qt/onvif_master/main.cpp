#include <iostream>

#include "onvifclientdevice.h"
#include "onvifclientmedia.h"
#include "onvifclientptz.h"
#include "ptzcontrol.h"


int main()
{
    std::string url = "http://192.168.1.64/onvif/device_service";
    std::string user = "admin";
    std::string pass =  "admin";
    PTZControl cntr(url, user,pass);

    std::cout << cntr.GetSnapshotURI() << std::endl;
    cntr.AbsoluteMove(0.85,0);

    return 0;
}
