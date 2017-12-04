#include "ptzcontrol.h"

PTZControl::PTZControl(const std::string &IP, const std::string &username, const std::string &password) :
    m_IP(IP), m_username(username), m_password(password)
{
    m_onvifDevicePtr = new OnvifClientDevice(m_IP, m_username, m_password);
    m_onvifPTZPtr = new OnvifClientPTZ(*m_onvifDevicePtr);
    m_onvifMediaPtr = new OnvifClientMedia(*m_onvifDevicePtr);
    m_init = false;
    initialize();
}

std::string PTZControl::GetSnapshotURI()
{
    if (!m_init)
        return "";

    _trt__GetSnapshotUriResponse trt__GetSnapshotUriResponse;

    if ((m_onvifMediaPtr->GetSnapshotUri(trt__GetSnapshotUriResponse, m_profileToken) != SOAP_OK)
            || (trt__GetSnapshotUriResponse.MediaUri == NULL))
        return "";

    return trt__GetSnapshotUriResponse.MediaUri->Uri;
}

PTZControl::~PTZControl()
{
    delete(m_onvifDevicePtr);
    delete(m_onvifMediaPtr);
    delete(m_onvifPTZPtr);
}

void PTZControl::AbsoluteMove(const float &x, const float &y)
{
    if ((x < 0) || (x > 1) || (y < 0) || (y > 1) || (!m_init))
        return;
    _tptz__AbsoluteMoveResponse tptz__AbsoluteMoveResponse;
    tt__PTZSpeed ptSpeed;
    tt__Vector2D vecSpeed;
    tt__PTZVector ptPos;
    tt__Vector2D vecPos;
    // set speed vector
    vecSpeed.x = (m_speed_x0 + m_speed_x1) / 2;
    vecSpeed.y = vecSpeed.x;
    ptSpeed.PanTilt = &vecSpeed;
    // set position vector
    vecPos.x = m_pantilt_x0 + ((m_pantilt_x1 - m_pantilt_x0) * x);
    vecPos.y = m_pantilt_y0 + ((m_pantilt_y1 - m_pantilt_y0) * y);
    ptPos.PanTilt = &vecPos;
    // send request to camera
    m_onvifPTZPtr->AbsoluteMove(tptz__AbsoluteMoveResponse, ptSpeed, ptPos, m_profileToken);

}

void PTZControl::Zoom(const float &x)
{
    if ((x < 0) || (x > 1) || (!m_init))
        return;
    _tptz__AbsoluteMoveResponse tptz__AbsoluteMoveResponse;
    tt__PTZSpeed zoomSpeed;
    tt__Vector1D vecSpeed;
    tt__PTZVector zoomPos;
    tt__Vector1D vecPos;
    // set speed vector
    vecSpeed.x = (m_zoom_speed_x0 + m_zoom_speed_x1) / 2;
    zoomSpeed.Zoom = &vecSpeed;
    // set position vector
    vecPos.x = m_zoom_x0 + ((m_zoom_x1 - m_zoom_x0) * x);
    zoomPos.Zoom = &vecPos;

    // set absolute zoom position
    m_onvifPTZPtr->AbsoluteMove(tptz__AbsoluteMoveResponse, zoomSpeed, zoomPos, m_profileToken);
}


void PTZControl::initialize()
{
    if (!refreshLimits())
        return;

    _trt__GetProfilesResponse profiles;
    m_onvifMediaPtr->GetProfiles(profiles);

    if (!profiles.Profiles.size())
        return;

    m_profileToken = profiles.Profiles[0]->token;


    m_init = true;
}

bool PTZControl::refreshLimits()
{
    _tptz__GetNodesResponse tptz__GetNodesResponse;

    if ((m_onvifPTZPtr->GetNodes(tptz__GetNodesResponse) != SOAP_OK)
            || (tptz__GetNodesResponse.PTZNode.size() == 0)
            || (tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces == NULL)
            || (tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace.size() == 0)
            || (tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->AbsoluteZoomPositionSpace.size() == 0)
            || (tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->PanTiltSpeedSpace.size() == 0)
            || (tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->ZoomSpeedSpace.size() == 0))
        return false;

    tt__FloatRange *xRange = tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[0]->XRange;
    tt__FloatRange *yRange = tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[0]->YRange;
    tt__FloatRange *zoomRange = tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->AbsoluteZoomPositionSpace[0]->XRange;
    tt__FloatRange *speedRange = tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->PanTiltSpeedSpace[0]->XRange;
    tt__FloatRange *zoomSpeedRange = tptz__GetNodesResponse.PTZNode[0]->SupportedPTZSpaces->ZoomSpeedSpace[0]->XRange;

    if ((xRange == NULL) || (yRange == NULL) || (zoomRange == NULL)
            || (speedRange == NULL) || (zoomSpeedRange == NULL))
        return false;

    m_pantilt_x0 = xRange->Min;
    m_pantilt_x1 = xRange->Max;
    m_pantilt_y0 = yRange->Min;
    m_pantilt_y1 = yRange->Max;

    m_zoom_x0 = zoomRange->Min;
    m_zoom_x1 = zoomRange->Max;

    m_speed_x0 = speedRange->Min;
    m_speed_x1 = speedRange->Max;
    m_zoom_speed_x0 = zoomSpeedRange->Min;
    m_zoom_speed_x1 = zoomSpeedRange->Max;

    return true;
}

