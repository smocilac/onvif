#ifndef ONVIFCLIENTPTZ_H
#define ONVIFCLIENTPTZ_H


#include <string>
#include <map>
#include <iostream>
#include <list>

#include "onvifclientdevice.h"
#include "soapStub.hpp"
#include "soapPTZBindingProxy.h"
#include "wsseapi.h"

using namespace std;

class OnvifClientPTZ
{
public:
    OnvifClientPTZ(OnvifClientDevice &device);
    ~OnvifClientPTZ();

    bool m_bHasRelativePTMove;
    bool m_bHasRelativeZoomMove;
    bool m_bHasAbsolutePTMove;
    bool m_bHasAbsoluteZoomMove;
    bool m_bHasContinuousPTMove;
    bool m_bHasContinuousZoomMove;

public:
    /* Add function to here */
    //Configuration functions
    int GetConfiguration(_tptz__GetConfigurationResponse &configurationResp, string token);
    int GetConfigurations(_tptz__GetConfigurationsResponse &configurationsResp);
    int GetConfigurationOptions(_tptz__GetConfigurationOptionsResponse &configOptions, string configToken);
    int SetConfiguration(_tptz__SetConfigurationResponse &SetConfiguration, tt__PTZConfiguration &PTZConfiguration,bool ForcePersist);
    //Move Functions (includes Pan, Tilt, and Zoom Moves)
    int RelativeMove(_tptz__RelativeMoveResponse &relMoveResponse, tt__PTZVector &Translation, tt__PTZSpeed &Speed, string profileToken);
    int ContinuousMove(_tptz__ContinuousMoveResponse &ContMoveResponse, tt__PTZSpeed &Speed, LONG64 &Timeout, string profileToken);
    int AbsoluteMove(_tptz__AbsoluteMoveResponse &AbsoluteMoveResponse, tt__PTZSpeed &Speed, tt__PTZVector &position, string profileToken);
    int Stop(_tptz__StopResponse &StopResponse,bool PanTilt,bool Zoom,string profileToken);
    //Zoom Functions
    //TODO:

    //Node, status, and service capabilities
    int GetNodes(_tptz__GetNodesResponse &GetNodesResponse);
    int GetNode(_tptz__GetNodeResponse &GetNodeResponse, string nodeToken);
    int GetStatus(_tptz__GetStatusResponse &StatusResponse,string profileToken);
    int GetServiceCapabilities(_tptz__GetServiceCapabilitiesResponse &ServiceCapResponse);

    int Initialize();

private:
    OnvifClientDevice &m_Device;
    PTZBindingProxy ptzProxy;

};


#endif // ONVIFCLIENTPTZ_H
