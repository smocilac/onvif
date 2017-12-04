/* soapPullPointSubscriptionBindingProxy.h
   Generated by gSOAP 2.8.17r from onvif.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapPullPointSubscriptionBindingProxy_H
#define soapPullPointSubscriptionBindingProxy_H
#include "soapH.h"

class SOAP_CMAC PullPointSubscriptionBindingProxy : public soap
{ public:
	/// Endpoint URL of service 'PullPointSubscriptionBindingProxy' (change as needed)
	const char *soap_endpoint;
	/// Constructor
	PullPointSubscriptionBindingProxy();
	/// Construct from another engine state
	PullPointSubscriptionBindingProxy(const struct soap&);
	/// Constructor with endpoint URL
	PullPointSubscriptionBindingProxy(const char *url);
	/// Constructor with engine input+output mode control
	PullPointSubscriptionBindingProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	PullPointSubscriptionBindingProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	PullPointSubscriptionBindingProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~PullPointSubscriptionBindingProxy();
	/// Initializer used by constructors
	virtual	void PullPointSubscriptionBindingProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to default
	virtual	void reset();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Put SOAP Header in message
	virtual	void soap_header(struct _wsse__Security *wsse__Security, char *wsa__MessageID, struct wsa__Relationship *wsa__RelatesTo, struct wsa__EndpointReferenceType *wsa__From, struct wsa__EndpointReferenceType *wsa__ReplyTo, struct wsa__EndpointReferenceType *wsa__FaultTo, char *wsa__To, char *wsa__Action, struct wsdd__AppSequenceType *wsdd__AppSequence, char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance);
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'PullMessages' (returns error code or SOAP_OK)
	virtual	int PullMessages(_tev__PullMessages *tev__PullMessages, _tev__PullMessagesResponse *tev__PullMessagesResponse) { return this->PullMessages(NULL, NULL, tev__PullMessages, tev__PullMessagesResponse); }
	virtual	int PullMessages(const char *endpoint, const char *soap_action, _tev__PullMessages *tev__PullMessages, _tev__PullMessagesResponse *tev__PullMessagesResponse);

	/// Web service operation 'Seek' (returns error code or SOAP_OK)
	virtual	int Seek(_tev__Seek *tev__Seek, _tev__SeekResponse *tev__SeekResponse) { return this->Seek(NULL, NULL, tev__Seek, tev__SeekResponse); }
	virtual	int Seek(const char *endpoint, const char *soap_action, _tev__Seek *tev__Seek, _tev__SeekResponse *tev__SeekResponse);

	/// Web service operation 'SetSynchronizationPoint' (returns error code or SOAP_OK)
	virtual	int SetSynchronizationPoint(_tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, _tev__SetSynchronizationPointResponse *tev__SetSynchronizationPointResponse) { return this->SetSynchronizationPoint(NULL, NULL, tev__SetSynchronizationPoint, tev__SetSynchronizationPointResponse); }
	virtual	int SetSynchronizationPoint(const char *endpoint, const char *soap_action, _tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, _tev__SetSynchronizationPointResponse *tev__SetSynchronizationPointResponse);

	/// Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
	virtual	int GetServiceCapabilities(_tev__GetServiceCapabilities *tev__GetServiceCapabilities, _tev__GetServiceCapabilitiesResponse *tev__GetServiceCapabilitiesResponse) { return this->GetServiceCapabilities(NULL, NULL, tev__GetServiceCapabilities, tev__GetServiceCapabilitiesResponse); }
	virtual	int GetServiceCapabilities(const char *endpoint, const char *soap_action, _tev__GetServiceCapabilities *tev__GetServiceCapabilities, _tev__GetServiceCapabilitiesResponse *tev__GetServiceCapabilitiesResponse);

	/// Web service operation 'CreatePullPointSubscription' (returns error code or SOAP_OK)
	virtual	int CreatePullPointSubscription(_tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, _tev__CreatePullPointSubscriptionResponse *tev__CreatePullPointSubscriptionResponse) { return this->CreatePullPointSubscription(NULL, NULL, tev__CreatePullPointSubscription, tev__CreatePullPointSubscriptionResponse); }
	virtual	int CreatePullPointSubscription(const char *endpoint, const char *soap_action, _tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, _tev__CreatePullPointSubscriptionResponse *tev__CreatePullPointSubscriptionResponse);

	/// Web service operation 'GetEventProperties' (returns error code or SOAP_OK)
	virtual	int GetEventProperties(_tev__GetEventProperties *tev__GetEventProperties, _tev__GetEventPropertiesResponse *tev__GetEventPropertiesResponse) { return this->GetEventProperties(NULL, NULL, tev__GetEventProperties, tev__GetEventPropertiesResponse); }
	virtual	int GetEventProperties(const char *endpoint, const char *soap_action, _tev__GetEventProperties *tev__GetEventProperties, _tev__GetEventPropertiesResponse *tev__GetEventPropertiesResponse);

	/// Web service operation 'Renew' (returns error code or SOAP_OK)
	virtual	int Renew(_wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse *wsnt__RenewResponse) { return this->Renew(NULL, NULL, wsnt__Renew, wsnt__RenewResponse); }
	virtual	int Renew(const char *endpoint, const char *soap_action, _wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse *wsnt__RenewResponse);

	/// Web service operation 'Unsubscribe' (returns error code or SOAP_OK)
	virtual	int Unsubscribe(_wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse) { return this->Unsubscribe(NULL, NULL, wsnt__Unsubscribe, wsnt__UnsubscribeResponse); }
	virtual	int Unsubscribe(const char *endpoint, const char *soap_action, _wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse);

	/// Web service operation 'Subscribe' (returns error code or SOAP_OK)
	virtual	int Subscribe(_wsnt__Subscribe *wsnt__Subscribe, _wsnt__SubscribeResponse *wsnt__SubscribeResponse) { return this->Subscribe(NULL, NULL, wsnt__Subscribe, wsnt__SubscribeResponse); }
	virtual	int Subscribe(const char *endpoint, const char *soap_action, _wsnt__Subscribe *wsnt__Subscribe, _wsnt__SubscribeResponse *wsnt__SubscribeResponse);

	/// Web service operation 'GetCurrentMessage' (returns error code or SOAP_OK)
	virtual	int GetCurrentMessage(_wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, _wsnt__GetCurrentMessageResponse *wsnt__GetCurrentMessageResponse) { return this->GetCurrentMessage(NULL, NULL, wsnt__GetCurrentMessage, wsnt__GetCurrentMessageResponse); }
	virtual	int GetCurrentMessage(const char *endpoint, const char *soap_action, _wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, _wsnt__GetCurrentMessageResponse *wsnt__GetCurrentMessageResponse);

	/// Web service one-way send operation 'send_Notify' (returns error code or SOAP_OK)
	virtual	int send_Notify(_wsnt__Notify *wsnt__Notify) { return this->send_Notify(NULL, NULL, wsnt__Notify); }
	virtual	int send_Notify(const char *endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify);
	/// Web service one-way receive operation 'recv_Notify' (returns error code or SOAP_OK);
	virtual	int recv_Notify(struct __tev__Notify&);
	/// Web service receive of HTTP Accept acknowledgment for one-way send operation 'send_Notify' (returns error code or SOAP_OK)
	virtual	int recv_Notify_empty_response() { return soap_recv_empty_response(this); }
	/// Web service one-way synchronous send operation 'Notify' with HTTP Accept/OK response receive (returns error code or SOAP_OK)
	virtual	int Notify(_wsnt__Notify *wsnt__Notify) { return this->Notify(NULL, NULL, wsnt__Notify); }
	virtual	int Notify(const char *endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify) { if (this->send_Notify(endpoint, soap_action, wsnt__Notify) || soap_recv_empty_response(this)) return this->error; return SOAP_OK; }

	/// Web service operation 'GetMessages' (returns error code or SOAP_OK)
	virtual	int GetMessages(_wsnt__GetMessages *wsnt__GetMessages, _wsnt__GetMessagesResponse *wsnt__GetMessagesResponse) { return this->GetMessages(NULL, NULL, wsnt__GetMessages, wsnt__GetMessagesResponse); }
	virtual	int GetMessages(const char *endpoint, const char *soap_action, _wsnt__GetMessages *wsnt__GetMessages, _wsnt__GetMessagesResponse *wsnt__GetMessagesResponse);

	/// Web service operation 'DestroyPullPoint' (returns error code or SOAP_OK)
	virtual	int DestroyPullPoint(_wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, _wsnt__DestroyPullPointResponse *wsnt__DestroyPullPointResponse) { return this->DestroyPullPoint(NULL, NULL, wsnt__DestroyPullPoint, wsnt__DestroyPullPointResponse); }
	virtual	int DestroyPullPoint(const char *endpoint, const char *soap_action, _wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, _wsnt__DestroyPullPointResponse *wsnt__DestroyPullPointResponse);

	/// Web service one-way send operation 'send_Notify' (returns error code or SOAP_OK)
	virtual	int send_Notify_(_wsnt__Notify *wsnt__Notify) { return this->send_Notify_(NULL, NULL, wsnt__Notify); }
	virtual	int send_Notify_(const char *endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify);
	/// Web service one-way receive operation 'recv_Notify' (returns error code or SOAP_OK);
	virtual	int recv_Notify_(struct __tev__Notify_&);
	/// Web service receive of HTTP Accept acknowledgment for one-way send operation 'send_Notify' (returns error code or SOAP_OK)
	virtual	int recv_Notify__empty_response() { return soap_recv_empty_response(this); }
	/// Web service one-way synchronous send operation 'Notify' with HTTP Accept/OK response receive (returns error code or SOAP_OK)
	virtual	int Notify_(_wsnt__Notify *wsnt__Notify) { return this->Notify_(NULL, NULL, wsnt__Notify); }
	virtual	int Notify_(const char *endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify) { if (this->send_Notify_(endpoint, soap_action, wsnt__Notify) || soap_recv_empty_response(this)) return this->error; return SOAP_OK; }

	/// Web service operation 'CreatePullPoint' (returns error code or SOAP_OK)
	virtual	int CreatePullPoint(_wsnt__CreatePullPoint *wsnt__CreatePullPoint, _wsnt__CreatePullPointResponse *wsnt__CreatePullPointResponse) { return this->CreatePullPoint(NULL, NULL, wsnt__CreatePullPoint, wsnt__CreatePullPointResponse); }
	virtual	int CreatePullPoint(const char *endpoint, const char *soap_action, _wsnt__CreatePullPoint *wsnt__CreatePullPoint, _wsnt__CreatePullPointResponse *wsnt__CreatePullPointResponse);

	/// Web service operation 'Renew' (returns error code or SOAP_OK)
	virtual	int Renew_(_wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse *wsnt__RenewResponse) { return this->Renew_(NULL, NULL, wsnt__Renew, wsnt__RenewResponse); }
	virtual	int Renew_(const char *endpoint, const char *soap_action, _wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse *wsnt__RenewResponse);

	/// Web service operation 'Unsubscribe' (returns error code or SOAP_OK)
	virtual	int Unsubscribe_(_wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse) { return this->Unsubscribe_(NULL, NULL, wsnt__Unsubscribe, wsnt__UnsubscribeResponse); }
	virtual	int Unsubscribe_(const char *endpoint, const char *soap_action, _wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse);

	/// Web service operation 'PauseSubscription' (returns error code or SOAP_OK)
	virtual	int PauseSubscription(_wsnt__PauseSubscription *wsnt__PauseSubscription, _wsnt__PauseSubscriptionResponse *wsnt__PauseSubscriptionResponse) { return this->PauseSubscription(NULL, NULL, wsnt__PauseSubscription, wsnt__PauseSubscriptionResponse); }
	virtual	int PauseSubscription(const char *endpoint, const char *soap_action, _wsnt__PauseSubscription *wsnt__PauseSubscription, _wsnt__PauseSubscriptionResponse *wsnt__PauseSubscriptionResponse);

	/// Web service operation 'ResumeSubscription' (returns error code or SOAP_OK)
	virtual	int ResumeSubscription(_wsnt__ResumeSubscription *wsnt__ResumeSubscription, _wsnt__ResumeSubscriptionResponse *wsnt__ResumeSubscriptionResponse) { return this->ResumeSubscription(NULL, NULL, wsnt__ResumeSubscription, wsnt__ResumeSubscriptionResponse); }
	virtual	int ResumeSubscription(const char *endpoint, const char *soap_action, _wsnt__ResumeSubscription *wsnt__ResumeSubscription, _wsnt__ResumeSubscriptionResponse *wsnt__ResumeSubscriptionResponse);
};
#endif
