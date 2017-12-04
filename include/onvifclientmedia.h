#ifndef ONVIFCLIENTMEDIA_H
#define ONVIFCLIENTMEDIA_H


#include <string>
#include <map>
#include <iostream>
#include <list>

#include "onvifclientdevice.h"
#include "soapStub.hpp"
#include "soapMediaBindingProxy.h"
#include "wsseapi.h"


using namespace std;

class OnvifClientMedia
{
public:
    OnvifClientMedia(OnvifClientDevice &device);
    ~OnvifClientMedia();
public:
    //Profile Functions
    int GetProfiles(_trt__GetProfilesResponse &profiles);
    int GetProfile(_trt__GetProfileResponse &profileResponse,string profileToken);
    int CreateProfile(_trt__CreateProfileResponse &CreateProfileResponse,string Name,string token);
    //Uri and streaming functions
    int GetSnapshotUri(_trt__GetSnapshotUriResponse &SnapshotUriResponse,string profileToken);
    int GetStreamUri(_trt__GetStreamUriResponse &StreamUriResponse,tt__StreamSetup &StreamSetup, string profileToken);
    int GetServiceCapabilities(_trt__GetServiceCapabilitiesResponse &GetServiceCapResponse);
    int StartMulticastStreaming(_trt__StartMulticastStreamingResponse &StartMulticastResponse,string profileToken);
    int StopMulticastStreaming(_trt__StopMulticastStreamingResponse &StopMulticastResponse,string profileToken);
    //Video Source Functions
    int GetVideoSources(_trt__GetVideoSourcesResponse &GetVideoSourcesResponse);
    int GetVideoSourceConfigurations(_trt__GetVideoSourceConfigurationsResponse &GetVideoSourceConfigResponse);
    int SetVideoSourceConfiguration(_trt__SetVideoSourceConfigurationResponse &SetVideoSourceConfigResponse);
    int GetVideoSourceConfiguration(_trt__GetVideoSourceConfigurationResponse &GetVideoSourceConfigResponse,string ConfigurationToken);
    int GetVideoSourceConfigurationOptions(_trt__GetVideoSourceConfigurationOptionsResponse &GetVideoSourceConfigOptionsResponse, string ConfigurationToken,string profileToken);
    //Meta data functions
    int GetMetadataConfigurations(_trt__GetMetadataConfigurationsResponse &GetMetadataConfigurationsResponse);
    int GetMetadataConfiguration(_trt__GetMetadataConfigurationResponse &GetMetadataConfigurationResponse,string profileToken);
    int GetMetadataConfigurationOptions(_trt__GetMetadataConfigurationOptionsResponse &GetMetadataConfigurationOptionsResponse,string ConfigToken,string profileToken);

private:
    OnvifClientDevice &m_Device;
    MediaBindingProxy  mediaProxy;

};
#endif // ONVIFCLIENTMEDIA_H
