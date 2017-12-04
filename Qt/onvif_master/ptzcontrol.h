#ifndef PTZCONTROL_H
#define PTZCONTROL_H

#include <memory>
#include <string>
#include "onvifclientdevice.h"
#include "onvifclientptz.h"
#include "onvifclientmedia.h"


class PTZControl
{
public:
    PTZControl(const std::string &IP, const std::string &username, const std::string &password);
    ~PTZControl();

    void AbsoluteMove(const float &x, const float &y);
    void Zoom(const float &x);
    std::string GetSnapshotURI();

private:
    void initialize();
    bool refreshLimits();

    OnvifClientDevice *m_onvifDevicePtr;
    OnvifClientPTZ *m_onvifPTZPtr;
    OnvifClientMedia *m_onvifMediaPtr;

    std::string m_IP;
    std::string m_username;
    std::string m_password;
    std::string m_profileToken;

    // speed min and max
    float m_speed_x0;
    float m_speed_x1;
    float m_zoom_speed_x0;
    float m_zoom_speed_x1;

    // pantilt position min and max
    float m_pantilt_x0;
    float m_pantilt_x1;
    float m_pantilt_y0;
    float m_pantilt_y1;

    float m_zoom_x0;
    float m_zoom_x1;

    bool m_init;
};

#endif // PTZCONTROL_H
