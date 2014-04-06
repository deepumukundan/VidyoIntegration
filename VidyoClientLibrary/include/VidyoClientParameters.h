/*! @file VidyoClientParameters.h
    @brief Message parameters for Vidyo Client API Library.
    @copyright (c) 2006-2009 Vidyo, Inc.
	433 Hackensack Avenue, 6th Floor,
	Hackensack, NJ  07601.
	All rights reserved.
	The information contained herein is proprietary to Vidyo, Inc.
	and shall not be reproduced, copied (in whole or in part), adapted,
	modified, disseminated, transmitted, transcribed, stored in a retrieval
	system, or translated into any language in any form by any means
	without the express written consent of Vidyo, Inc.
*/


#ifndef VIDYO_CLIENT_PARAMETERS_H
#define VIDYO_CLIENT_PARAMETERS_H

/*******************************************************************************
 Parameter enumerations for messages between Vidyo Client Library and GUI
*******************************************************************************/

/*! Modes for self-view region in video layout.

	- Used for the following events:
		+ #VIDYO_CLIENT_IN_EVENT_PREVIEW
		+ #VIDYO_CLIENT_OUT_EVENT_PREVIEW

	- Passed in field _previewMode_ of following structs:
		+ #VidyoClientInEventPreview
		+ #VidyoClientOutEventPreview

	@warning Mobile version is limited
*/

typedef enum VidyoClientPreviewMode_
{
	/*! Disable preview */
	VIDYO_CLIENT_PREVIEW_MODE_NONE = 0,
	/*! Picture-in-picture mode */
	VIDYO_CLIENT_PREVIEW_MODE_PIP,
	/*! Docking mode */
	VIDYO_CLIENT_PREVIEW_MODE_DOCK,
	/*! Only supported on Room systems */
	VIDYO_CLIENT_PREVIEW_MODE_OTHER = 4 
} VidyoClientPreviewMode;

/*! Types of messages that could be shown to a user.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_USER_MESSAGE
	- Passed in field messageType of following structs:
		+ #VidyoClientOutEventUserMessage
*/
typedef enum VidyoClientUserMessageType_
{
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CHANGES_TO_AUDIO_VIDEO_DEVICES,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CANNOT_DETERMINE_LOG_PATH,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CANNOT_DETERMINE_INSTALLED_PATH,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CANNOT_WRITE_LOG_FILE,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYO_SDK_BASE,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_FRAMEWORK_LOG,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYO_DESKTOP_LOG,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYOPROXY_LOG,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_SDK_CLIENT,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_CONSTRUCTION_VD_LOGIC,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_START_VD_LOGIC,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VD_HELPER_CONSTRUCT,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VD_HELPER_START,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_CONSTRUCTION_STRING_TRANSLATION_TABLE,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_SSE2_CHECK_FAILED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_TASKBAR_ICON_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CONF_STATUS_HOTKEY,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_AUDIO_DEBUG_HOTKEY,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_LOG_SETTINGS_HOTKEY,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_APP_SERVER_COMM_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_PROTOCOL_VERSION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INVALIDUSER_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INVALIDMAC_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_USERINCONF_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INVALIDCONF_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MAXPORTS_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_LOCKEDCONF_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NOROUTER_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CONFMAXUSERS_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MAXDESKTOPS_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_OFFLINECALLER_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_OFFLINECALLEE_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_START_VIDEO_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_START_AUDIO_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CONTACT_USER_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_USER_NO_ANSWER,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_ROUTER_REJECT_JOIN_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_OTHER_PARTY_HANGUP,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_CAMERA,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_MICROPHONE,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_JOIN_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_SPEAKERS,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_COMPLETE_CALL_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_JOIN_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CALLER_CANCELLED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CALLEE_DECLINED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_LOGGED_IN_ELSEWHERE_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NOT_LOGGED_IN_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_IN_CALL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_IN_CALL_OR_CONFERENCE_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_UNEXPECTED_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CALL_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_SIGNIN_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_ACCEPT_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_IGNORE_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RESTART_VIDEO_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_LOCK_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_F_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_L_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_LS_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RANGE_LS_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_CH_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RANGE_CH_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_CW_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RANGE_CW_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_LP_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RANGE_LP_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_MD_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_RANGE_MD_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_P_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_S_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_MISSING_VALUE_U_OPTION_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_DIRECT_X_DISABLED_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_DIRECT_X_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_MAC_ADDR_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_DISCONNECTED_FROM_CONFERENCE ,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CONNECTION_TO_SERVER_LOST,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_HEARTBEAT_FAILED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_DISCONNECTED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_HTTP_RESPONSE_CODE,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_HTTP_RESPONSE_407,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INVITATION_TIMED_OUT,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_PROXY_CONNECT_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_COULDNT_RESOLVE_PROXY,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_QUEUE_INTERNAL_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_INACTIVE_EID,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_LOGGED_OUT_BY_SERVER,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NETWORK_CONNECTIVITY,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CALL_TIMED_OUT,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_WEB_PROXY_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_REGISTER_LICENSE_COM_ERROR,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_REGISTER_LICENSE_OTHER,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_CHECK_UPDATES_NORMAL_MSG,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_SELECTED_DEVICE_LOST_MSG,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_DEVICE_SELECTION_CHANGED_MSG,
 	VIDYO_CLIENT_USER_MESSAGE_TYPE_AUDIO_ECHO_COUPLING_WARNING,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_DIAGNOSTICS_REPORT_GENERATED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_TOO_FREQUENT_START_VIDEO_IGNORED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_TOO_FREQUENT_STOP_VIDEO_IGNORED,
	VIDYO_CLIENT_USER_MESSAGE_TYPE_NO_MESSAGE, /* Always leave last.
											      Represents an unset message field */
} VidyoClientUserMessageType;

/*! Types of media devices.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_DEVICES_CHANGED
	- Passed in field deviceType of following structs:
		+ #VidyoClientOutEventDevicesChanged
*/
typedef enum VidyoClientDeviceType_
{
	/*! Audio playback */
	VIDYO_CLIENT_DEVICE_TYPE_AUDIO_OUT = 1,
	/*! Audio capturing */
	VIDYO_CLIENT_DEVICE_TYPE_AUDIO_IN,
	/*! Video */
	VIDYO_CLIENT_DEVICE_TYPE_VIDEO,
	/*! Ring tone */
	VIDYO_CLIENT_DEVICE_TYPE_RING_TONE,
} VidyoClientDeviceType;

/*! Status of endpoint registration and user binding.  Indicate state of client connection to
	servers.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_SUBSCRIBING
Used in field  of following structs:
		+ #VidyoClientRequestGetEndpointStatus
*/
typedef enum VidyoClientEndpointStatus_
{
	VIDYO_CLIENT_ENDPOINT_STATUS_INACTIVE,  /*!< Client not registered to
	                                           server */
	VIDYO_CLIENT_ENDPOINT_STATUS_REGISTERED,/*!< Registered to server, but not
	                                           bound to a user */
	VIDYO_CLIENT_ENDPOINT_STATUS_ACTIVE,    /*!< Client is registered and bound
	                                           to a user - ready for use */
} VidyoClientEndpointStatus;

/*! Status of user sign-in.  Indicate state of how user is signed in.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_SIGN_IN
	- Passed in field signinType of following structs:
		+ #VidyoClientOutEventSignIn
*/
typedef enum VidyoClientSignInEnum_
{
	SIGNIN_INTERNAL = 1,	/*!< The source of the sign-in event 
							   is the VidyoClient library */
	SIGNIN_EXTERNAL,		/*!< The source of the sign-in event
							   is external e.g. browser */
	SIGNIN_APPLICATION,		/*!< The source of the sign-in event
							   is the application using VidyoClient */
} VidyoClientSignInEnum;

/*! Commands that control media streams.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_MEDIA_CONTROL
	- Passed in field mediaCommand of following structs:
		+ #VidyoClientOutEventMediaControl
*/
typedef enum VidyoClientMediaControlCommand_
{
    VIDYO_CLIENT_MEDIA_CONTROL_COMMAND_MUTE,		
    VIDYO_CLIENT_MEDIA_CONTROL_COMMAND_UNMUTE,		
    VIDYO_CLIENT_MEDIA_CONTROL_COMMAND_SILENCE,		
} VidyoClientMediaControlCommand;

/*! Types of media streams that can be controlled.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_MEDIA_CONTROL
	- Passed in field mediaType of following structs:
		+ #VidyoClientOutEventMediaControl
*/
typedef enum VidyoClientMediaControlType_
{
    VIDYO_CLIENT_MEDIA_CONTROL_TYPE_VIDEO,		
    VIDYO_CLIENT_MEDIA_CONTROL_TYPE_APPLICATION,		
	VIDYO_CLIENT_MEDIA_CONTROL_TYPE_AUDIO,
	VIDYO_CLIENT_MEDIA_CONTROL_TYPE_UNKNOWN,
} VidyoClientMediaControlType;

/*! Locality of media streams that can be controlled.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_MEDIA_CONTROL
	- Passed in field mediaSource of following structs:
		+ #VidyoClientOutEventMediaControl
*/
typedef enum VidyoClientMediaControlSource_
{
    VIDYO_CLIENT_MEDIA_CONTROL_SOURCE_LOCAL,		
    VIDYO_CLIENT_MEDIA_CONTROL_SOURCE_REMOTE,		
	VIDYO_CLIENT_MEDIA_CONTROL_SOURCE_UNKNOWN,
} VidyoClientMediaControlSource;

/*! Configuration of video layout resolution and frame rate.
	- Used for the following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CONFIGURATION
	VIDYO_CLIENT_REQUEST_SET_CONFIGURATION
	- Passed in field videoPreferences of following structs:
		+ #VidyoClientRequestConfiguration
*/
typedef enum VidyoClientVideoPreferences_
{
    VIDYO_CLIENT_VIDEO_PREFERENCES_BEST_QUALITY,
	/*!< Default. All resolutions above SVGA are filtered out. For VGA
	   resolutions and above (incl. SVGA) -- frame-rate is limited to 15
	   FPS. */
    VIDYO_CLIENT_VIDEO_PREFERENCES_BEST_FRAMERATE,
	/*!< All resolutions above 720p are filtered out. Minimal frame-rate is
	   30 FPS. */
    VIDYO_CLIENT_VIDEO_PREFERENCES_BEST_RESOLUTION,
	/*!< All resolutions above 720p are filtered out. Maximal frame-rate is
	   15 FPS. */
	VIDYO_CLIENT_VIDEO_PREFERENCES_LIMITED_BANDWIDTH,
	/*!< Limit the maximum encoding resolution to CIF. No limit on the
	   frame-rate -- would initially be 30 FPS. Set the initial ABA
	   available receive bandwidth for video to 500Kbp/s. */
	VIDYO_CLIENT_VIDEO_PREFERENCES_ADVANCED_450p30 = 10,
	/*!< Limit resolution to 450p. Ignore CPU score. */
	VIDYO_CLIENT_VIDEO_PREFERENCES_ADVANCED_720p15 = 11,
	/*!< Limit resolution to 720p. Limit frame-rate to 15 FPS. Ignore CPU
	   score. */
	VIDYO_CLIENT_VIDEO_PREFERENCES_ADVANCED_720p30 = 12,
	/*!< Limit resolution to 720p. Ignore CPU score. */

	VIDYO_CLIENT_VIDEO_PREFERENCES_1080p30 = 20,
	/*!< Limit resolution to 1080p using CPU score. */

	/* Configurations that apply to room systems only */
	VIDYO_CLIENT_VIDEO_PREFERENCES_VIDYOROOM_SVGA = 50, /*!< Do not use */
	VIDYO_CLIENT_VIDEO_PREFERENCES_VIDYOROOM_VGA = 51, /*!< Do not use */
	VIDYO_CLIENT_VIDEO_PREFERENCES_VIDYOROOM_SUB_HD = 52, /*!< Do not use */
	VIDYO_CLIENT_VIDEO_PREFERENCES_VIDYOROOM_HD = 53, /*!< Do not use */
	VIDYO_CLIENT_VIDEO_PREFERENCES_VIDYOROOM_HD1080 = 54, /*!< Do not use */
} VidyoClientVideoPreferences;

/*! Methods for resizing of video layout.
	- Used for the following requests:
		+ #VIDYO_CLIENT_REQUEST_SNAP_RESIZE
	- Passed in field sizingmethod of following structs:
		+ #VidyoClientRequestSnapResize
*/
typedef enum VidyoClientResizingMethod_
{
	VIDYO_CLIENT_RESIZING_METHOD_HORIZONTAL,
	VIDYO_CLIENT_RESIZING_METHOD_VERTICAL,
	VIDYO_CLIENT_RESIZING_METHOD_DIAGONAL,
} VidyoClientResizingMethod;

/*!	Call state indicates the client's state and whether it is engaged in a call.
	- Used for the following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CALL_STATE
		+ #VIDYO_CLIENT_OUT_EVENT_CALL_STATE
	- Passed in field sizingmethod of following structs:
		+ #VidyoClientRequestCallState
		+ #VidyoClientOutEventCallState
*/
typedef enum VidyoClientCallState_
{
	VIDYO_CLIENT_CALL_STATE_IDLE,			/*!< The client is not engaged in a call. */
	VIDYO_CLIENT_CALL_STATE_RINGING,		/*!< Incoming call. Client is ringing. */
	VIDYO_CLIENT_CALL_STATE_CALLING,		/*!< Client is dialing out. */
	VIDYO_CLIENT_CALL_STATE_JOINING,		/*!< Client is in the process of joining a
											   conference or a call. */
	VIDYO_CLIENT_CALL_STATE_IN_CONFERENCE,	/*!< Client is engaged in a conference or a
											   call. */
	VIDYO_CLIENT_CALL_STATE_DISCONNECTING,	/*!< Caling is in the process of disconnecting
											   from a conference or a cal.l */
} VidyoClientCallState;
/*! Session display context identifiers.  Indicate how the current session was set up for
	displaying field SessionDisplayText of struct VidyoClientRequestSessionDisplayInfo properly.
	- Used for the following requests:
	 	+ #VIDYO_CLIENT_REQUEST_GET_CURRENT_SESSION_DISPLAY_INFO
	- Passed in field SessionDisplayContext of following structs:
		+ #VidyoClientRequestSessionDisplayInfo
*/
typedef enum VidyoClientSessionDisplayContext_
{
	VIDYO_CLIENT_SESSION_DISPLAY_CONTEXT_CONF,      /*!< Session created as a conference
													   - userID shows \<conference\> */
	VIDYO_CLIENT_SESSION_DISPLAY_CONTEXT_OUT_CALL,  /*!< Session created as outbound
													   - userID shows \<to\> */
	VIDYO_CLIENT_SESSION_DISPLAY_CONTEXT_IN_CALL,   /*!< Session created as inbound
													   - userID shows \<from\> */
	VIDYO_CLIENT_SESSION_DISPLAY_CONTEXT_IDLE		/*!< No current session */
} VidyoClientSessionDisplayContext;

/*! Display language codes.
	- Used for the following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_LANGUAGE
	- Passed in field _Languagecode_ of following structs:
		+ #VidyoClientRequestGetLanguage
*/
typedef enum VidyoClientLanguageCode_
{
    VIDYO_CLIENT_LANGUAGE_CODE_EN = 0,    /*!< U.S. English */
    VIDYO_CLIENT_LANGUAGE_CODE_FR,        /*!< French */
    VIDYO_CLIENT_LANGUAGE_CODE_JA,        /*!< Japanese */
    VIDYO_CLIENT_LANGUAGE_CODE_ZH_CN,     /*!< Chinese (simplified) */
    VIDYO_CLIENT_LANGUAGE_CODE_ES,        /*!< Spanish */
    VIDYO_CLIENT_LANGUAGE_CODE_IT,        /*!< Italian */
    VIDYO_CLIENT_LANGUAGE_CODE_DE,        /*!< German */
    VIDYO_CLIENT_LANGUAGE_CODE_KO,        /*!< Korean */
    VIDYO_CLIENT_LANGUAGE_CODE_PT,        /*!< Portuguese */
	VIDYO_CLIENT_LANGUAGE_CODE_PL,		  /*!< Polish */
	VIDYO_CLIENT_LANGUAGE_CODE_FI,		  /*!< Finish */ 
	VIDYO_CLIENT_LANGUAGE_CODE_ZH_TW,	  /*!< Chinese (traditional) */ 
	VIDYO_CLIENT_LANGUAGE_CODE_TH,		  /*!< Thai */ 
	VIDYO_CLIENT_LANGUAGE_CODE_RU,		  /*!< Russian */ 
	VIDYO_CLIENT_LANGUAGE_CODE_TR,        /*!< Turkish */
	VIDYO_CLIENT_LANGUAGE_CODE_NO,        /*!< Norwegian */
	VIDYO_CLIENT_LANGUAGE_CODE_SV,        /*!< Swedish */
    VIDYO_CLIENT_LANGUAGE_CODE_UNKNOWN,   /*!< KEEP THIS AS ENDING ENUM
										     - other codes are dependent on this value */
} VidyoClientLanguageCode;

/*! Commands that control camera.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_CONTROL_CAMERA
		+ #VIDYO_CLIENT_IN_EVENT_CONTROL_CAMERA
	- Passed in field cameraCommand of following structs:
		+ #VidyoClientOutEventControlCamera
	VidyoClientInEventControlCamera
*/
typedef enum VidyoClientCameraControlCommand_
{
    VIDYO_CLIENT_CAMERA_CONTROL_PANRIGHT,
	VIDYO_CLIENT_CAMERA_CONTROL_PANLEFT,
	VIDYO_CLIENT_CAMERA_CONTROL_TILTUP,
	VIDYO_CLIENT_CAMERA_CONTROL_TILTDOWN,
	VIDYO_CLIENT_CAMERA_CONTROL_ZOOMIN,
	VIDYO_CLIENT_CAMERA_CONTROL_ZOOMOUT,
	VIDYO_CLIENT_CAMERA_CONTROL_POSITION,
	VIDYO_CLIENT_CAMERA_CONTROL_VISCACOMMAND,
	VIDYO_CLIENT_CAMERA_CONTROL_VISCARESPONSE,
} VidyoClientCameraControlCommand;

/*! Video display modes for video source.
	- Used for the following requests:
		+ #VIDYO_CLIENT_IN_EVENT_SET_PARTICIPANT_VIDEO_MODE
	- Passed in field videoMode of following structs:
		+ #VidyoClientInEventSetParticipantVideoMode
*/
typedef enum VidyoClientParticipantVideoMode_
{
	VIDYO_CLIENT_VIDEO_MODE_DOCK = 1,   /*!< Default video mode */
	VIDYO_CLIENT_VIDEO_MODE_PINHIGH, 	/*!< Preferred video mode */
	VIDYO_CLIENT_VIDEO_MODE_PINLOW,   	/*!< Continuous, subordinate to Docked */
} VidyoClientParticipantVideoMode;

/*! Conference information update event identifier.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_CONFERENCE_INFO_UPDATE
*/
typedef enum VidyoClientConferenceInfoUpdateEventID_
{
    VIDYO_CLIENT_CONFERENCE_INFO_UPDATE_WEBCASTING,
	VIDYO_CLIENT_CONFERENCE_INFO_UPDATE_RECORDING,
} VidyoClientConferenceInfoUpdateEventID;

/*! Types of label or text.
	- Used for the following events:
		+ #VIDYO_CLIENT_REQUEST_SET_LABEL
*/
typedef enum VidyoClientLabelType_
{
	VIDYO_CLIENT_LABEL_SELF_VIEW,
	VIDYO_CLIENT_LABEL_MAX,
} VidyoClientLabelType;

/*! Values of requestType on windows share.
	- Used for the following events:
		+ #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES
		+ #VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES
	- Passed in field requestType of following structs:
		+ #VidyoClientRequestWindowShares
*/
typedef enum VidyoClientWindowShareRequestType_
{
	LIST_SHARING_WINDOWS, 			/*!< Get the list of shared application windows available for display. */
	CHANGE_SHARING_WINDOW, 			/*!< Change the shared application window currently being displayed.
									     This request type with value of newApp set to 0 will stop showing
									     a remote shared app on layout window. newApp set to a valid value can
									     be used to start viewing a remote shared app on layout.*/
	TOGGLE_SHARING_WINDOW, 			/*!< Change the shared application window currently being displayed to next item in list. */
	STOP_SHARING_WINDOW, 			/*!< Stop display of shared application window specified by eventUri (if being displayed now).
		  					  			 If currently viewed remote shared APP view is stopped next remote APP in list will be used
		  					  			 as viewable remote sharing window. */
	UPDATE_DISPLAY_SHARING_WINDOW, 	/*!< For future use. */
	ADD_SHARING_WINDOW, 			/*!< For usage in mobile devices, where renderer has GUI to show/choose app share
										 @note Important to use this event when button bar is used*/
} VidyoClientWindowShareRequestType;

/*! Indicate the reason why a sign-out event is generated.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_SIGNED_OUT
	- Passed in field cause of following structs:
		+ #VidyoClientOutEventSignedOut
*/
typedef enum VidyoClientSignedOutCause_
{
	VIDYO_CLIENT_USER_SIGNED_IN, 	/*!< Signout generated in response to user initiated sign-in */
	VIDYO_CLIENT_USER_SIGNED_OUT,	/*!< Signout generated in response to user initiated sign-out */
	VIDYO_CLIENT_SERVER_SIGNED_OUT,	/*!< Signout command from server */
} VidyoClientSignedOutCause;

/*! Indicate the reason why #VIDYO_CLIENT_OUT_EVENT_DEVICE_SELECTION_CHANGED is generated.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_DEVICE_SELECTION_CHANGED
	- Passed in field cause of following structs:
		+ #VidyoClientOutEventDeviceSelectionChanged
*/
typedef enum VidyoClientDeviceChangeType_
{
	VIDYO_CLIENT_USER_MESSAGE_DEVICE_LOST,					/*!< The specified device being used in conference is lost
																and no alternate selection is made. */
	VIDYO_CLIENT_USER_MESSAGE_DEVICE_SELECTION_CHANGED,		/*!< The specified device being used in conference is lost
																and another device of same type is being used now. */
} VidyoClientDeviceChangeType;

/*! Indicates particular orientation to set. 
	- Used for the following events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION
	- Passed in field orientation of following structs:
		+ #VidyoClientInEventSetOrientation
*/
typedef enum VidyoClientOrientation_
{
	/* These values must be kept in sync with corresponding enum LmiOrientation */
	VIDYO_CLIENT_ORIENTATION_UP = 0,	/*!< Up */
	VIDYO_CLIENT_ORIENTATION_DOWN,		/*!< Down */
	VIDYO_CLIENT_ORIENTATION_LEFT,		/*!< Left */
	VIDYO_CLIENT_ORIENTATION_RIGHT,		/*!< Right */
} VidyoClientOrientation;

/*! Indicates which aspects of conference (own video, video layout, both) to set orientation for. 
	- Used for the following events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION
	- Passed in field orientation of following structs:
		+ #VidyoClientInEventSetOrientation
*/
typedef enum VidyoClientOrientationControl_
{
	VIDYO_CLIENT_ORIENTATION_CONTROL_BOTH = 0,	/*!< Capture and render */
	VIDYO_CLIENT_ORIENTATION_CONTROL_CAPTURE,	/*!< Capture */
	VIDYO_CLIENT_ORIENTATION_CONTROL_RENDER,	/*!< Render */
} VidyoClientOrientationControl;

/*! Indicates which kind of touch event has been generated.
	- Used for the following events:
		+ #VIDYO_CLIENT_OUT_EVENT_TOUCH
	- Passed in field state of following structs:
		+ #VidyoClientInEventSetOrientation
*/
typedef enum VidyoClientTouchState_
{
	VIDYO_CLIENT_TOUCH_STATE_START = 0,
	VIDYO_CLIENT_TOUCH_STATE_MOVE,
	VIDYO_CLIENT_TOUCH_STATE_STOP,
	VIDYO_CLIENT_TOUCH_STATE_UNKNOWN,
} VidyoClientTouchState;

/*!	Icons shown by the renderer.
	- Used for following events:
		+ #VIDYO_CLIENT_IN_EVENT_RENDERER_SHOW_ICON
	- Passed in field rendererIcon of following structs:
		+ #VidyoClientInEventRendererShowIcon
*/
typedef enum VidyoClientRendererIcon_
{
	/*! Webcasting indication icon */
	VIDYO_CLIENT_RENDERER_ICON_WEBCASTING,
	/*! Recording indication icon */
	VIDYO_CLIENT_RENDERER_ICON_RECORDING,
} VidyoClientRendererIcon;

/*! Buttons shown by for Mobile Device incall participants.
	- Used for following events:
		+ #VIDYO_CLIENT_OUT_EVENT_PARTICIPANT_BUTTON_CLICK
	- Passed in field rendererIcon of following structs:
		+ #VidyoClientOutEventParticipantButtonClick
*/
typedef enum VidyoClientParticipantButtonType_
{
	VIDYO_CLIENT_PARTICIPANT_BUTTON_FECC = 0,
	VIDYO_CLIENT_PARTICIPANT_BUTTON_PREFERRED,
	VIDYO_CLIENT_PARTICIPANT_BUTTON_HIDE,
} VidyoClientParticipantButtonType;
/*! The state of a button, associated with a button event.
	- Used for following events:
		+ #VIDYO_CLIENT_OUT_EVENT_PARTICIPANT_BUTTON_CLICK
	- Passed in field rendererIcon of following structs:
		+ #VidyoClientOutEventParticipantButtonClick
*/
typedef enum VidyoClientParticipantButtonState_
{
	/*! State is on */ 
	VIDYO_CLIENT_BUTTON_STATE_ON,
	/*! State is off */ 
	VIDYO_CLIENT_BUTTON_STATE_OFF,
} VidyoClientParticipantButtonState;
/*!	Fault code of SOAP operation
	- Used for following events:
		+ events connected to SOAP operation, for example, #VIDYO_CLIENT_OUT_EVENT_LICENSE
*/	
typedef enum VidyoClientSoapFault_
{
 	VIDYO_CLIENT_SOAP_FAULT_NONE,	/*!< None */
	VIDYO_CLIENT_SOAP_FAULT_INVALID_ARGUMENT,	/*!< Invalid argument */
	VIDYO_CLIENT_SOAP_FAULT_NOT_LICENSED,	/*!< Not licensed */
	VIDYO_CLIENT_SOAP_FAULT_GENERAL,	/*!< General fault */
	VIDYO_CLIENT_SOAP_FAULT_CONFERENCE_LOCKED,	/*!< Conference in locked */
	VIDYO_CLIENT_SOAP_FAULT_LICENSE_EXPIRED,	/*!< License expired */
	VIDYO_CLIENT_SOAP_FAULT_WRONG_PIN,	/*!< Wrong conference PIN */
} VidyoClientSoapFault;

/*!	Result code of SOAP operation
	- Used for following events:
		+ events connected to SOAP operation, for example, #VIDYO_CLIENT_OUT_EVENT_LICENSE
*/	
typedef enum VidyoClientSoapResultCode_
{
	VIDYO_CLIENT_SOAP_RESULT_FAILURE,				/*!< Result is some unknown general failure */
	VIDYO_CLIENT_SOAP_RESULT_SUCCESS,				/*!< Result is success */
	VIDYO_CLIENT_SOAP_RESULT_NOT_LICENSED,			/*!< Not licensed */
	VIDYO_CLIENT_SOAP_RESULT_SEAT_LICENSE_EXPIRED,	/*!< Seat license expired */
	VIDYO_CLIENT_SOAP_RESULT_WRONG_PIN,				/*!< Wrong PIN */
	VIDYO_CLIENT_SOAP_RESULT_CONFERENCE_LOCKED,		/*!< Conference locked */
	VIDYO_CLIENT_SOAP_RESULT_ROOM_DISABLED,			/*!< Room disabled */
	VIDYO_CLIENT_SOAP_RESULT_GENERAL_FAULT,			/*!< General Fault */
	VIDYO_CLIENT_SOAP_RESULT_INVALID_ARGUMENT_FAULT,/*!< Invalid argument fault */
	VIDYO_CLIENT_SOAP_RESULT_MEMBER_NOT_ONLINE,		/*!< Status of member is not online */
	VIDYO_CLIENT_SOAP_RESULT_NOT_OWNER_OF_ROOM,		/*!< Not owner of room */
	VIDYO_CLIENT_SOAP_RESULT_USER_NOT_FOUND,		/*!< Specified user is not found */
	VIDYO_CLIENT_SOAP_RESULT_UNEXPECTED_SUBELEMENT_IN_MESSAGE,  /*!< Unexpected sub element in SOAP message */
	VIDYO_CLIENT_SOAP_RESULT_END_POINT_NOT_FOUND,	/*!< Endpoint not found */
	VIDYO_CLIENT_SOAP_RESULT_FAILED_PLACE_DIRECT_CALL, /*!< Failed to place a direct call */
	VIDYO_CLIENT_SOAP_RESULT_IPC_JOIN_FAILURE,		/*!< Failure to join room on other portal */
	VIDYO_CLIENT_SOAP_RESULT_ALL_LINES_IN_USE,		/*!< All lines are in use */
} VidyoClientSoapResultCode;

/*! Indicates which kind of touch event has been generated.
	- Used for following events:
		+ #VIDYO_CLIENT_OUT_EVENT_FECC_STATUS_UPDATE
	- Passed in field state of following structs:
		+ #VidyoClientOutEventFeccStatusUpdate
*/
typedef enum VidyoClientFeccStatusCode_
{
	/*! The remote participant under FECC is disconnected from call */
	VIDYO_CLIENT_FECC_STATUS_CODE_USER_LOST = 0,
	/*! The remote participant under FECC set camara to privacy */
	VIDYO_CLIENT_FECC_STATUS_CODE_USER_IN_PRIVACY,
} VidyoClientFeccStatusCode;

/*! Indicates the type of Proxy available to the client.
	- Used for following events:
		+ #VIDYO_CLIENT_IN_EVENT_SIGN_IN
	- Passed in field state of following structs:
		+ #VidyoClientInEventSignIn
*/
typedef enum VidyoClientProxyType_
{
	/*! No proxy */
	VIDYO_CLIENT_PROXY_NONE = 0,
	/*! Proxy type is Vidyo Proxy */
	VIDYO_CLIENT_VIDYO_PROXY,
	/*! The proxy type is reverse proxy */
	VIDYO_CLIENT_REVERSE_PROXY,
} VidyoClientProxyType;
/*******************************************************************************
 Parameter structures for events from GUI to Vidyo Client Library
*******************************************************************************/

/*! Sign in event.

	- Used for the following events:
    	+ #VIDYO_CLIENT_IN_EVENT_SIGN_IN
*/
typedef struct VidyoClientInEventSignIn_
{
	char serverAddress[SIGNIN_SERVERADDRESS_SIZE]; 			
	/*!< Hostname or IP address of VidyoManager to be used */
	char serverPort[SIGNIN_SERVERPORT_SIZE]; 				
	/*!< Port of VidyoManager to be used. */
	char userName[SIGNIN_USERNAME_SIZE]; 					
	/*!< Username to sign in with, as known to VidyoPortal.  Encoded as UTF-8. */
	char portalAccessKey[SIGNIN_PORTAL_ACCESS_KEY_SIZE]; 	
	/*!< Key allocated by VidyoPortal to be used in place of password.  This value should be acquired through login procedure with VidyoPortal. */
	char portalAddress[SIGNIN_PORTALADDRESS_SIZE];			
	/*!< Base URL for accessing SOAP services on the VidyoPortal
		 (e.g. http://example.vidyo.com/services). */
	char portalVersion[SIGNIN_PORTALVERSION_SIZE];			
	/*!< Portal version */
	char vmIdentity[VIDYO_MANAGER_ID_SIZE];					
	/*!< 
		Identity of Vidyo Manager to which end point is assigned. This value should be
		acquired through login procedure with VidyoPortal. This is required for vidyo
		router cascading feature.
	*/
	char locationTag[ENDPOINT_LOCATION_TAG_SIZE];			
	/*!< 
		Location tag of end point. This is configured on portal to indicate the location of
		an endpoint. It is used to assign end point nearest and lowest loaded vidyo router
		when joining a call. This value should be acquired through login procedure with VidyoPortal.
	*/
	char clientExternalIPAddress[MAX_IPADDRESS_LEN]; 					
	/*!< External IP address of machine on which client is running as seen by web server. */
	VidyoClientProxyType proxyType;
	/*!< 
		The type of Proxy available to the client.
		If value is VIDYO_CLIENT_VIDYO_PROXY vidyoProxyAddress should have valid proxy address
		and vidyoProxyPort should have valid proxy port. Instead if value is VIDYO_CLIENT_REVERSE_PROXY
		reverseProxyAddress should have valid proxy address and reverseProxyPort should have valid proxy port.
		In both cases numberProxies will provide the number of proxies available to client.
	*/
	char vidyoProxyAddress[SIGNIN_VIDYO_PROXY_NUMBER][SIGNIN_VIDYO_PROXY_ADDRESS_SIZE]; 
	/*!< 
		Array of VidyoProxy hostnames or IP addresses.  Only 0 or 1 VidyoProxy addresses
		are currently supported.
	*/
	char vidyoProxyPort[SIGNIN_VIDYO_PROXY_NUMBER][SIGNIN_VIDYO_PROXY_PORT_SIZE]; 
	/*!< 
		Array of VidyoProxy ports.  Only 0 or 1 VidyoProxy addresses are currently supported.
		Each port is used with corresponding value found in the same index of preceding
		parameter vidyoProxyAddress.
	*/
	char reverseProxyAddress[SIGNIN_VIDYO_PROXY_NUMBER][SIGNIN_VIDYO_PROXY_ADDRESS_SIZE]; 
	/*!< 
		Array of ReverseProxy hostnames or IP addresses.  Only 0 or 1 ReverseProxy addresses
		are currently supported.
	*/
	char reverseProxyPort[SIGNIN_VIDYO_PROXY_NUMBER][SIGNIN_VIDYO_PROXY_PORT_SIZE]; 
	/*!< 
		Array of ReverseProxy ports.  Only 0 or 1 ReverseProxy addresses are currently supported.
		Each port is used with corresponding value found in the same index of preceding
		parameter reverseProxyAddress.
	*/
	VidyoUint numberProxies;
	/*!< 
		Number of entries in parameters vidyoProxyAddress and vidyoProxyPort. This value
		should currently be set to only 0 or 1.
	*/
	VidyoUint emcpSecured;
	/*!< 
		VIDYO_TRUE if connection to VidyoManager should be secured using TLS,
		VIDYO_FALSE if connection to VidyoManager should not be secure.
	*/
	VidyoBool guestLogin;
	/*!< 
		VIDYO_TRUE if username given in preceding parameter userName is ephemeral
		value allocated for guest login, VIDYO_FALSE for permanent users.
	*/
	VidyoBool showDialpad;			
	/*!< 
		Reserved for use by standard Vidyo clients.  Should be set to VIDYO_FALSE.
	*/
	VidyoBool showStartmeeting;		
	/*!< 
		Reserved for use by standard Vidyo clients.  Should be set to VIDYO_FALSE.
	*/
} VidyoClientInEventSignIn;


/*! Represents input event structure for preview mode

@see VidyoClientPreviewMode
@see VIDYO_CLIENT_IN_EVENT_PREVIEW
*/
typedef struct VidyoClientInEventPreview_
{
	/*! How video will be shown in video layout */
	VidyoClientPreviewMode previewMode;
	VidyoBool primaryDisplay; // Only applies to Room system mode
} VidyoClientInEventPreview;

/*! Mute structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_IN
		+ #VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_OUT
		+ #VIDYO_CLIENT_IN_EVENT_MUTE_VIDEO
*/
typedef struct VidyoClientInEventMute_
{
	/*! VIDYO_TRUE to mute local media device for specified in event, VIDYO_FALSE to un-mute.
		Use VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_IN to (un-)mute the microphone device,
		VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_OUT to (un-)mute the speaker device,
		and VIDYO_CLIENT_IN_EVENT_MUTE_VIDEO to (un-)mute the camera device.
	*/
	VidyoBool willMute;
} VidyoClientInEventMute;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SHARE
*/
typedef struct VidyoClientInEventShare_
{
	/*! 
		OS-specific window ID of local application window to share with remote participants in
		a conference.  See VidyoTypes.h for definition of VidyoWindowCapturerWindowId for 
		particular platform. 
	*/
	VidyoWindowCapturerWindowId window; 
	
	VidyoRect windowSize;  /*!< Geometry of subregion of window to share.  @note not yet supported. */
} VidyoClientInEventShare;


/*! Event structure

	- Used by the following in events:
		 + #VIDYO_CLIENT__IN_EVENT_SEND_FRAME to send a share frame

	@note Replaces the less generic VidyoClientInEventRawFrame. May be used for out events as well.
*/
typedef struct VidyoClientInEventVideoFrame_
{
	/*!
		Width of shared frame
	*/ 
	VidyoUint width;
	/*!
		Height of shared frame
	*/ 
	VidyoUint height;
	/*!
		The fourcc code of the frame format
	*/ 
	VidyoUint format;
	/*!
		The size of the data buffer holding the frame
	*/ 
	VidyoUint size;
	/*!
		Frame data start. Frame data must be contiguous in memory so that it can be passed to VidyoClientSendEvent
		@note Do not add strcuture members below
		@note When calling VidyoClientSendEvent set event data size to sizeof(VidyoClientInEventVideoFrame)+VidyoClientInEventVideoFrame.size
	*/ 
	VidyoUint8 data[1];
} VidyoClientInEventVideoFrame;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_RESIZE
*/
typedef struct VidyoClientInEventResize_
{
	VidyoUint x;				/*!< Horizontal offset of the topmost left corner of video layout region on 
									 all platforms except MacOS X. It is lowermost left corner on Mac OS X. */
	VidyoUint y;				/*!< Vertical offset of the topmost left corner of video layout region.
									 all platforms except MacOS X. It is lowermost left corner on Mac OS X. */
	VidyoUint width;			/*!< Width of video layout region.  Range of allowed values 0~UINT_MAX. */
	VidyoUint height;			/*!< Height of video layout region.  Range of allowed values 0~UINT_MAX.*/
} VidyoClientInEventResize;		

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_PARTICIPANTS_LIMIT
*/
typedef struct VidyoClientInEventParticipantsLimit_
{
	/*!
		Maximum number of viewable remote participants in video layout.  A value of 0
		causes no remote participants (not even a loopback of own video via server) to
		be shown.  A value of 1 causes only one remote participant (including loopback
		of own video, if applicable) to be shown.  A value of 2~8 causes a maximum of
		the specified number of remote participants (including loopback of own video,
		if applicable) to be shown.  A value of 16 causes the system to automatically
		regulate the maximum number of remote participants that can be shown.  Range of
		allowed values 0~8 and 16.	
	*/
	VidyoUint maxNumParticipants;
} VidyoClientInEventParticipantsLimit;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_LAYOUT
*/
typedef struct VidyoClientInEventLayout_
{
	/*!
		Number of remote participants to be shown in a larger size region within video
		layout.  A value of 0 causes all remote participants to be shown in equal size
		regions.  A value of 1 causes one remote participant (selected by virtue of having
		been last loudest speaker), the so-called "preferred" participant, to be shown in
		a larger size region than any other participants within video layout.  Range of
		allowed values 0~1.
	*/
	VidyoUint numPreferred; 
} VidyoClientInEventLayout;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_PLAY_SOUND
		+ #VIDYO_CLIENT_IN_EVENT_PLAY_RINGTONE
*/
typedef struct VidyoClientInEventPlaySound_
{
	/*!
		Pointer to a buffer of sound data.  Required encoding of sound data 1-channel,
		16 bits per sample and 16000 samples per second.
	*/
	VidyoUint8 *soundData;
} VidyoClientInEventPlaySound;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_ECHO_DETECT
		+ #VIDYO_CLIENT_IN_EVENT_SET_ECHO_CANCEL
		+ #VIDYO_CLIENT_IN_EVENT_SET_AUDIO_AGC
		+ #VIDYO_CLIENT_IN_EVENT_SET_FREEZE_IMAGE
*/
typedef struct VidyoClientInEventSetFlag_
{
	/*!
		VIDYO_TRUE to set flag corresponding to specified event, VIDYO_FALSE to clear flag.
		Use VIDYO_CLIENT_IN_EVENT_SET_ECHO_DETECT to enable/disable acoustic echo detection,
		VIDYO_CLIENT_IN_EVENT_SET_ECHO_CANCEL to enable/disable acoustic echo cancellation,
		VIDYO_CLIENT_IN_EVENT_SET_AUDIO_AGC to enable/disable automatic gain control,
		and VIDYO_CLIENT_IN_EVENT_SET_FREEZE_IMAGE to enable/disable freezing of video image.
	*/
	VidyoBool willEnable;
} VidyoClientInEventSetFlag;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION
*/
typedef struct VidyoClientInEventSetOrientation_
{
	/*!
		Orientation of own video and/or video layout to set.
		Typically, this value tracks where the camera is located on the device relative to
		the normal orientation of the device. Devices that have the camera located at the
		top will 'usually' have an orientation of VIDYO_CLIENT_ORIENTATION_UP.  Not all
		devices adhere to this scheme and will require some experimentation to get the
		correct value for this parameter.	
	*/
	VidyoClientOrientation orientation;
	/*! Which aspects of conference (own video, video layout, both) to set orientation for. */
	VidyoClientOrientationControl control;
} VidyoClientInEventSetOrientation;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_PLAY_DIAL_TONE
*/
typedef struct VidyoClientInEventPlayDialTone_
{
	/*! Dial tone to play.  Range of allowed values 0~9, *, #, A, B, C, D. */
	char tone;
	/*! Duration of dial tone, in milliseconds.  Range of allowed values 0~INT_MAX. */
	VidyoInt duration; 
} VidyoClientInEventPlayDialTone;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_START_PLAYING_CONTINUOUS_DIAL_TONE
*/ 
typedef struct VidyoClientInEventPlayContinuousDialTone_
{
	/*! Dial tone to play.  Range of allowed values 0~9, *, #, A, B, C, D. */
	char tone;
} VidyoClientInEventPlayContinuousDialTone;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_CONTROL_CAMERA
*/
typedef struct VidyoClientInEventControlCamera_
{
	/*! Vidyo URI of remote participant to control camera of. */
	char uri[URI_LEN];
	/*! Type of camera control operation.  See definition of VidyoClientCameraControlCommand. */
	VidyoClientCameraControlCommand cameraCommand;
	/*! ID for VISCA pass-through command */
	char commandId[MAX_VISCA_COMMAND];
	/*! Data for VISCA pass-through command in hex, e.g. "81 09 06 12 ff". */
	char commandData[MAX_VISCA_COMMAND];
	unsigned char preset;
} VidyoClientInEventControlCamera;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_PARTICIPANT_VIDEO_MODE
*/
typedef struct VidyoClientInEventSetParticipantVideoMode_
{
	/*! Vidyo URI of remote participant to set video mode for. */
	char uri[URI_LEN];
	/*! Video mode of remote participant.  See definition of VidyoClientParticipantVideoMode. */
	VidyoClientParticipantVideoMode videoMode;
} VidyoClientInEventSetParticipantVideoMode;

/*!  Structure for internal use
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_MONITORS
*/
typedef struct VidyoClientInEventSetMonitors_
{
	VidyoUint numMonitors;  /*!< Number of displays to use, 1 or 2 */
	VidyoUint seqMon[2];  	/*!< If 2 displays set order: 0 for the primary
						     monitor, 1 for the secondary monitor */
} VidyoClientInEventSetMonitors;

/*!  Structure for internal use
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_SEND_BANDWIDTH
*/
typedef struct VidyoClientInEventSetSendBandwidth_
{
	VidyoInt sendBandwidth;  /*!< Maximum send bandwidth:
	                            7 - 768Kbps,  1 - 1Mbps, 2 - 2Mbps, 3 - 3Mbps,
								4 - 4Mbps, 6 - 6Mbps */
	VidyoUint sLayers;       /* 1 - 3 */
} VidyoClientInEventSetSendBandwidth;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_LOGIN
*/
typedef struct VidyoClientInEventLogIn_
{
	/*! Portal URI, i.e. "https://example.vidyo.com" */
	char portalUri[URI_LEN];
	/*! Name of the registered user on portal */
	char userName[USERID_SIZE];
	/*! Password of the user */
	char userPass[PASSWORD_SIZE];
} VidyoClientInEventLogIn;

/*! Event structure
 
 - Used by following in events:
 + #VIDYO_CLIENT_IN_EVENT_ROOM_LINK
 */
typedef struct VidyoClientInEventRoomLink_
{
	/*! Portal URI, i.e. "https://example.vidyo.com" */
	char portalUri[URI_LEN];
	/*! Room Key -- value of parameter "key=" of Room Link */
	char roomKey[ROOMKEY_SIZE];
	/*! Display Name for Guest only */
	char displaytName[USERID_SIZE];
	/*! Conference PIN if needed */
	char pin[PIN_SIZE];
} VidyoClientInEventRoomLink;


/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_SET_OFFLINE
*/
typedef struct VidyoClientInEventSetOffline_
{
	/*!
		VIDYO_TRUE to disconnect communication with conference manager and go offline,
		ending any active conference.
		VIDYO_FALSE to establish communication with conference manager and go online.
	*/
	VidyoBool offline;
} VidyoClientInEventSetOffline;

/*!	States of Telephone call
	- sent with event
		+ #VIDYO_CLIENT_IN_EVENT_TELEPHONE_CALL
*/
typedef enum VidyoClientTelephoneCallState_
{
	VIDYO_CLIENT_TELEPHONE_CALL_NONE = 0,
	VIDYO_CLIENT_TELEPHONE_CALL_DIALING,
	VIDYO_CLIENT_TELEPHONE_CALL_INCOMING,
	VIDYO_CLIENT_TELEPHONE_CALL_CONNECTED,
	VIDYO_CLIENT_TELEPHONE_CALL_DISCONNECTED,
} VidyoClientTelephoneCallState;

/*!	Event structure
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_TELEPHONE_CALL
*/
typedef struct VidyoClientInEventTelephoneCall_
{
	VidyoClientTelephoneCallState state;
}
VidyoClientInEventTelephoneCall;

/*!	Event structure
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_RAW_FRAME
*/
typedef struct VidyoClientInEventRawFrame_
{
	/*! Width of video frame.  Range of allowed values 0~INT_MAX. */
	VidyoInt width;
	/*! Height of video frame.  Range of allowed values 0~INT_MAX. */
	VidyoInt height;
	/*! Buffer containing a raw RGB frame. */
	VidyoUint8 samples[1];
} VidyoClientInEventRawFrame;

/*! Event structure
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_ENABLE_STATUS_BAR
		+ #VIDYO_CLIENT_IN_EVENT_ENABLE_BUTTON_BAR
*/
typedef struct VidyoClientInEventEnable_
{
	/*!
		VIDYO_TRUE to enable setting for specified in event,
		VIDYO_FALSE to disable.
	*/
	VidyoBool willEnable;
} VidyoClientInEventEnable;

/*! Event structure
	- Used by following in event:
		+ #VIDYO_CLIENT_IN_EVENT_RENDERER_SHOW_ICON
*/
typedef struct VidyoClientInEventRendererShowIcon_
{
	/*!
		VIDYO_CLIENT_RENDERER_ICON_WEBCASTING to specify the Webcasting icon.
		VIDYO_CLIENT_RENDERER_ICON_RECORDING to specify as the Recording icon.
	*/
	VidyoClientRendererIcon rendererIcon;
	/*!
		VIDYO_TRUE to enable showing this icon by the renderer
		VIDYO_FALSE to disable.
	*/
	VidyoBool setVisible;
} VidyoClientInEventRendererShowIcon;

/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_GROUP_CHAT
*/
typedef struct VidyoClientInEventGroupChat_
{
	/*! Message (contents) to be sent to all remote participants */
    char message[MAX_CHAT_MESSAGE_LEN];
} VidyoClientInEventGroupChat;


/*! Event structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_IN_EVENT_PRIVATE_CHAT
*/
typedef struct VidyoClientInEventPrivateChat_
{
	/*! Vidyo URI of remote participant to whom this text message to be sent. */
    char uri[URI_LEN];
	/*! Message (contents) to be sent. */
    char message[MAX_CHAT_MESSAGE_LEN];
} VidyoClientInEventPrivateChat;

typedef struct VidyoClientInEventSetDisplayName_
{
	/*! Vidyo URI of remote participant whose display name has to be changed. */
    char uri[MAX_URI_LEN];
	/*! Display name in UTF8 encoded string which will be set to the participant. */
	char displayName[USERID_SIZE];
}VidyoClientInEventSetDisplayName;

typedef struct VidyoClientInEventResetDisplayName_
{
	/*! Vidyo URI of remote participant whose display name has to be reverted to the default participant name. */
    char uri[MAX_URI_LEN];
}VidyoClientInEventResetDisplayName;

/*******************************************************************************
 Parameter structures for events from Vidyo Client Library to GUI
*******************************************************************************/

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_USER_MESSAGE
*/
typedef struct VidyoClientOutEventUserMessage_
{
	/*! Specific message to convey to user.  See definition of VidyoClientUserMessageType. */
	VidyoClientUserMessageType messageType;
	/*!
		Additional information, currently limited to the first element of this array.

		Passed with (but can be ignored for) following messages:
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYO_SDK_BASE
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_FRAMEWORK_LOG
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYO_DESKTOP_LOG
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VIDYOPROXY_LOG
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_SDK_CLIENT
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_CONSTRUCTION_VD_LOGIC
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_START_VD_LOGIC
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VD_HELPER_CONSTRUCT
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_VD_HELPER_START
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_CONSTRUCTION_STRING_TRANSLATION_TABLE
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INIT_ERROR_SSE2_CHECK_FAILED
	*/
	VidyoUint messageCode[NUM_USER_MESSAGE_CODES];
	/*!
		Additional information, currently limited to the first element of this array.

		Passed with following messages:
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_CALLEE_DECLINED
				Username of recipient of outbound call.
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_CALLER_CANCELLED
				Username of originator of inbound call.
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_INVITATION_TIMED_OUT
				Username of originator of inbound call.
			- VIDYO_CLIENT_USER_MESSAGE_TYPE_CALL_TIMED_OUT
				Username of originator of inbound call.
	*/
	VidyoUint8 messageString[MAX_USER_MESSAGE_STRING_SIZE];
} VidyoClientOutEventUserMessage;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_SIGN_IN
*/
typedef struct VidyoClientOutEventSignIn_
{
	/*!
		Value is non-zero if client is licensed and can function.  If value is zero, action
		must be taken by application to acquire license from VidyoPortal and activate 
		license (which produces an EID).
	*/
	VidyoUint activeEid;
	/*!
		VIDYO_TRUE if sign-in is for guest user, VIDYO_FALSE if sign-in is for
		permanent user.
	*/
	VidyoBool guestLogin;
	/*! Reserved for use by standard Vidyo clients.  Value can be ignored. */
	VidyoBool showDialpad;
	/*! Reserved for use by standard Vidyo clients.  Value can be ignored. */
	VidyoBool showStartmeeting;
	/*! Indicates source of sign-in event.  @see VidyoClientSignInEnum. */
	VidyoClientSignInEnum signinType;
	/*!
		VIDYO_TRUE if sign-in is for secure VidyoPortal and VidyoManager, VIDYO_FALSE if
		sign-in is for insecure VidyoPortal and VidyoManager.
	*/
	VidyoBool signinSecured;
} VidyoClientOutEventSignIn;

/*! Structure for device change event
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_DEVICES_CHANGED
*/
typedef struct  VidyoClientOutEventDevicesChanged_
{
	/*!
		Kind of device, for which a device was added or removed.  @see VidyoClientDeviceType.
	*/
	VidyoClientDeviceType deviceType;
} VidyoClientOutEventDevicesChanged;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_DEVICES_CHANGED
*/
typedef struct VidyoClientOutEventDeviceSelectionChanged_
{
	/*!
		Kind of device, whose selection is changed.  @see VidyoClientDeviceType.
	*/
	VidyoClientDeviceType deviceType;
	/*!
		The type of device change had happened. @see VidyoClientDeviceChangeType.
	*/
	VidyoClientDeviceChangeType changeType;
	/*! Name of the device that is changed. */
	VidyoUint8 prevDeviceName[DEVICE_NAME_SIZE];
	/*!
		Name of the device that is changed to. Valid only when an alternate
		device is selected. i.e. when the value of changeType is 
		VIDYO_CLIENT_USER_MESSAGE_DEVICE_SELECTION_CHANGED
	*/
	VidyoUint8 newDeviceName[DEVICE_NAME_SIZE];	
} VidyoClientOutEventDeviceSelectionChanged;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_RINGING
		+ #VIDYO_CLIENT_OUT_EVENT_CALLING
		+ #VIDYO_CLIENT_OUT_EVENT_JOINING
		+ #VIDYO_CLIENT_OUT_EVENT_RETRYING
*/
typedef struct VidyoClientOutEventStartProgress_
{
	/*! How many maximum steps of progress anticipated.  Range of values 0~UINT_MAX. */
	VidyoUint numProgressSteps;
	/*!
		For #VIDYO_CLIENT_OUT_EVENT_CALLING, the username of the recipient of an outbound
		call.  For #VIDYO_CLIENT_OUT_EVENT_JOINING, the name of the conference to be joined.
		Encoded as UTF-8.
	*/
	char caption[DISPLAY_CONFERENCE_SIZE];
} VidyoClientOutEventStartProgress;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_PARTICIPANTS_CHANGED
*/
typedef struct VidyoClientOutEventParticipantsChanged_
{
	/*! The number of participants in conference now. */
	VidyoUint participantCount;
} VidyoClientOutEventParticipantsChanged;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_INCOMING_CALL
*/
typedef struct VidyoClientOutEventIncomingCall_
{
	/*!
		Username of the originator of an inbound call.  Only valid if this event was generated
		for an inbound call initiated by another endpoint and not VidyoPortal, as determined by
		parameter onCallFlag.  Encoded as UTF-8.
	*/
	char invitingUser[DISPLAY_CONFERENCE_SIZE];
	/*!
		VIDYO_TRUE if this event was generated for an inbound call initiated by another
		endpoint, VIDYO_FALSE if this event was generated for an inbound call initiated by
		VidyoPortal.
	*/
	VidyoBool onCallFlag;
} VidyoClientOutEventIncomingCall;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_CALL_STATE
*/
typedef struct VidyoClientOutEventCallState_
{
	/*! Updated call state of client
	
		@see VidyoClientCallState
	*/
	VidyoClientCallState callState;
} VidyoClientOutEventCallState;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_PREVIEW
*/
typedef struct VidyoClientOutEventPreview_
{
	/*! How video is now shown in video layout.  @see VidyoClientPreviewMode. */
	VidyoClientPreviewMode previewMode;
} VidyoClientOutEventPreview;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_IN
		+ #VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_OUT
		+ #VIDYO_CLIENT_OUT_EVENT_MUTED_VIDEO
		+ #VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_AUDIO_IN
		+ #VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_VIDEO
*/
typedef struct VidyoClientOutEventMuted_
{
	/*!
		VIDYO_TRUE to acknowledge or indicate muting of local media device for specified out
		event, VIDYO_FALSE to acknowledge or indicate un-muting.
		#VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_IN is sent for local muting of the microphone device,
		#VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_OUT is sent for local muting of the speaker device,
		and #VIDYO_CLIENT_OUT_EVENT_MUTED_VIDEO is sent for local muting of the camera device.
		#VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_AUDIO_IN is sent for remote muting of the
		microphone device, and #VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_VIDEO is sent for remote
		muting of the camera device.
	*/
	VidyoBool isMuted;
	/*!
		Possible values, only for acknowledgment events #VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_IN,
		#VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_OUT, and #VIDYO_CLIENT_OUT_EVENT_MUTED_VIDEO,
		from VidyoClientConstants.h:
		- VIDYO_CLIENT_ERROR_OK
			No error.
		- VIDYO_CLIENT_ERROR_NO_ENGINE
			Client is currently not in a conference. 	
		
		@note Only applies to acknowledgments, not indications
	*/
	VidyoUint errorCode;
} VidyoClientOutEventMuted;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_ADD_SHARE
*/
typedef struct VidyoClientOutEventAddShare_
{
	/*!
		Vidyo URI of remote participant who has added an application sharing window to
		the current conference.
	*/
	char URI[URI_LEN];
} VidyoClientOutEventAddShare;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_REMOVE_SHARE
*/
typedef struct VidyoClientOutEventRemoveShare_
{
	/*!
		Vidyo URI of remote participant who has removed an application sharing window from
		the current conference.
	*/
	char URI[URI_LEN];
} VidyoClientOutEventRemoveShare;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_RESIZE
*/
typedef struct VidyoClientOutEventResize_
{
	VidyoUint width; 	/*!< Width of video layout region.  Range of values 0~UINT_MAX. */
	VidyoUint height;	/*!< Height of video layout region.  Range of values 0~UINT_MAX. */
} VidyoClientOutEventResize;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_PARTICIPANTS_LIMIT
*/
typedef struct VidyoClientOutEventParticipantsLimit_
{
	/*!
		Maximum number of viewable remote participants in video layout, due to current network
		bandwidth.  Range of values 0~16.
	*/	
	VidyoUint BandwidthLimit;
	/*!
		Maximum number of viewable remote participants in video layout, due to current CPU
		utilization.  Range of values 0~16.
	*/
	VidyoUint CpuLimit;
} VidyoClientOutEventParticipantsLimit;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_KEYDOWN
		+ #VIDYO_CLIENT_OUT_EVENT_KEYUP
*/
typedef struct VidyoClientOutEventKeyboard_
{
	/*!
		Keycode of key, which has either been pressed (VIDYO_CLIENT_OUT_EVENT_KEYDOWN) or
		released (VIDYO_CLIENT_OUT_EVENT_KEYUP) while window containing video layout had
		focus.  Actual range of values dependent on underlying platform.
	*/
	VidyoUint key;
	/*!	How many times the key was pressed/released in succession.  Range of values 1~UINT_MAX. */
	VidyoUint count;
} VidyoClientOutEventKeyboard;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_MOUSE_DOWN
		+ #VIDYO_CLIENT_OUT_EVENT_MOUSE_UP (not yet supported)
		+ #VIDYO_CLIENT_OUT_EVENT_MOUSE_MOVE
		+ #VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL (not yet supported)
*/
typedef struct VidyoClientOutEventMouse_
{
	/*!
		Index of mouse button, which is involved in triggering event.  A value of 1
		indicates the left button, a value of 2 indicates the right button (for 2-button mice 
		and emulation of the 2-button mice), and a value of 3 indicates the middle button (for
		3-button mice and emulation of 3-button mice.)
	*/
	VidyoUint button;
	/*!
		How many times the mouse button was pressed.  A value of 0 is used for 
		events #VIDYO_CLIENT_OUT_EVENT_MOUSE_UP, #VIDYO_CLIENT_OUT_EVENT_MOUSE_MOVE, and
		#VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL, a value of 1 is used for event
		#VIDYO_CLIENT_OUT_EVENT_MOUSE_DOWN to indicate a single click, and a value of 2 is used
		for event #VIDYO_CLIENT_OUT_EVENT_MOUSE_DOWN to indicate a double click.

	*/
	VidyoUint count;
	/*!
		Horizontal offset of mouse event.  Actual range of values dependent on underlying
		platform.
	*/
	VidyoInt xPos;
	/*!
		Vertical offset of mouse event.  Actual range of values dependent on underlying
		platform.
	*/
	VidyoInt yPos;
	/*!
		VIDYO_TRUE if shift modifier key was depressed when mouse button was clicked,
		VIDYO_FALSE if shift modifier key was not depressed when mouse button was clicked.
	*/
	VidyoBool shift;
	/*!
		VIDYO_TRUE if ctrl modifier key was depressed when mouse button was clicked,
		VIDYO_FALSE if ctrl modifier key was not depressed when mouse button was clicked.
	*/
	VidyoBool ctrl;
	/*!
		VIDYO_TRUE if alt modifier key was depressed when mouse button was clicked,
		VIDYO_FALSE if alt modifier key was not depressed when mouse button was clicked.
	*/
	VidyoBool alt;
	/*!
		VIDYO_TRUE if command modifier key was depressed when mouse button was clicked,
		VIDYO_FALSE if command modifier key was not depressed when mouse button was clicked.
		@note Only supported on OS X platform.
	*/
	VidyoBool command;
	/*!
		Difference in horizontal offset between last mouse event and this mouse event, for
		event #VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL.  Actual range of values dependent on
		underlying platform.
	*/
	VidyoInt scrollDeltaX;
	/*!
		Difference in vertical offset between last mouse event and this mouse event, for
		event #VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL.  Actual range of values dependent on
		underlying platform.
	*/
	VidyoInt scrollDeltaY;
	/*!
		Difference in z-axis offset between last mouse event and this mouse event, for
		event #VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL.  Actual range of values dependent on
		underlying platform.
	*/
	VidyoInt scrollDeltaZ;
} VidyoClientOutEventMouse;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_TOUCH
*/
typedef struct VidyoClientOutEventTouch_
{
	/*!
		How many times the same kind of touch event was generated.  A value of 1 is used 
        to indicate a single tap, a value of 2 is used to indicate a double tap, and so on.
	*/
	VidyoUint count;
	/*!
		Horizontal offset of touch event.  Actual range of values dependent on underlying
		platform.
	*/
	VidyoInt xPos;
	/*!
		Vertical offset of touch event.  Actual range of values dependent on underlying
		platform.
		@note Only supported on OS X platform.
	*/	
	VidyoInt yPos;
	/*! Indicates which kind of touch event has been generated. */
	VidyoClientTouchState state;
} VidyoClientOutEventTouch;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_FECC_LIST_UPDATED
*/
typedef struct VidyoClientOutEventFeccListUpdated_
{
	/*! Number of Vidyo URI values in parameter uri.  Range of values 0~UINT_MAX. */
	VidyoUint numberParticipants;
} VidyoClientOutEventFeccListUpdated;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_FECC_STATUS_UPDATE
*/
typedef struct VidyoClientOutEventFeccStatusUpdate_
{
	/*! FECC status code */
	VidyoClientFeccStatusCode statusCode;
	/*! URI of the remote participant */
	char curFeccUri[URI_LEN];
} VidyoClientOutEventFeccStatusUpdate;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_PARTICIPANT_BUTTON_CLICK
*/
typedef struct VidyoClientOutEventParticipantButtonClick_
{
	/*! Vidyo URI of participant for the button that was clicked. */
	char srcParticipantID[URI_LEN];
	/*! Identifies which button has been clicked.

		For a buttonType of #VIDYO_CLIENT_PARTICIPANT_BUTTON_FECC the buttonState will be either
		a value of #VIDYO_CLIENT_BUTTON_STATE_ON or #VIDYO_CLIENT_BUTTON_STATE_OFF. */
	VidyoClientParticipantButtonType buttonType;
	/*! 		
		- #VIDYO_CLIENT_BUTTON_STATE_ON when the button is in an ON (or highlited) state,
		- #VIDYO_CLIENT_BUTTON_STATE_OFF when button is OFF
	*/
	VidyoClientParticipantButtonState buttonState;
} VidyoClientOutEventParticipantButtonClick;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_CONTROL_CAMERA
*/
typedef struct VidyoClientOutEventControlCamera_
{
	/*! Vidyo URI of remote participant that issued request to control local camera. */
	char srcParticipantID[URI_LEN];
	/*! Type of camera control operation.  See definition of VidyoClientCameraControlCommand. */
	VidyoClientCameraControlCommand cameraCommand;
	/*! ID for VISCA pass-through command. */
	char commandId[MAX_VISCA_COMMAND];
	/*! Data for VISCA pass-through response in hex (e.g. "95 50 00 00 00 00 00 00 00 00 ff") */
	char commandData[MAX_VISCA_COMMAND];
} VidyoClientOutEventControlCamera;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_SET_PARTICIPANT_VIDEO_MODE_DONE
*/
typedef struct VidyoClientOutEventSetParticipantVideoModeDone_
{
	/*! Vidyo URI of remote participant that video mode was set for. */
	char uri[URI_LEN];
	/*! Video mode of remote participant.  See definition of VidyoClientParticipantVideoMode. */
	VidyoClientParticipantVideoMode videoMode;
	/*!
		VIDYO_TRUE if video mode was successfully set, VIDYO_FALSE if video mode was not
		successfully set.
	*/
	VidyoBool isSet;
} VidyoClientOutEventSetParticipantVideoModeDone;

/*! Event structure
	
	- Used for reporting conference information update events:
		+ #VIDYO_CLIENT_OUT_EVENT_CONFERENCE_INFO_UPDATE
*/
typedef struct VidyoClientOutEventConferenceInfoUpdate_
{
	VidyoClientConferenceInfoUpdateEventID eventID; /*!< Event identity */
	VidyoBool eventStatus;							/*!< Event status and get value 0 (false) or 1 (true) */
} VidyoClientOutEventConferenceInfoUpdate;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_MEDIA_CONTROL
*/
typedef struct VidyoClientOutEventMediaControl_
{
	/*! Operation to perform.  @see VidyoClientMediaControlCommand. */
	VidyoClientMediaControlCommand mediaCommand; 
	/*! Kind of media on which to perform operation.  @see VidyoClientMediaControlType. */
	VidyoClientMediaControlType mediaType;
	/*! Source of operation.  @see VidyoClientMediaControlSource. */
	VidyoClientMediaControlSource mediaSource;
} VidyoClientOutEventMediaControl;

/*! Combined error codes from Curl(TCP), VCSOAP/Curl(HTTP), SOAP server returned faults/results, internal VCSOAP module errors
	- Used for reporting guest login & join-room state and error via event:
		+ #VIDYO_CLIENT_OUT_EVENT_ROOM_LINK
	- Passed in field error of following structs:
		+ #VidyoClientOutEventRoomLink
*/
typedef enum VidyoClientSoapError_
{
	VIDYO_CLIENT_ERROR_NONE = 0, 

	//curl/TCP errors 1-88
	VIDYO_CLIENT_ERROR_TCP_UNSUPPORTED_PROTOCOL		=  1,	// CURLE_UNSUPPORTED_PROTOCOL,    /* 1 */
	VIDYO_CLIENT_ERROR_TCP_FAILED_INIT				=  2,	// CURLE_FAILED_INIT,             /* 2 */
	VIDYO_CLIENT_ERROR_TCP_URL_MALFORMAT			=  3,	// CURLE_URL_MALFORMAT,           /* 3 */
	VIDYO_CLIENT_ERROR_TCP_NOT_BUILT_IN				=  4,	// CURLE_NOT_BUILT_IN,            /* 4 - [was obsoleted in August 2007 for 7.17.0, reused in April 2011 for 7.21.5] */
	VIDYO_CLIENT_ERROR_TCP_COULD_NOT_RESOLVE_PROXY	=  5,	// CURLE_COULDNT_RESOLVE_PROXY,   /* 5 */
	VIDYO_CLIENT_ERROR_TCP_COULD_NOT_RESOLVE_HOST	=  6,	// CURLE_COULDNT_RESOLVE_HOST,    /* 6 */
	VIDYO_CLIENT_ERROR_TCP_COULD_NOT_CONNECT		=  7,	// CURLE_COULDNT_CONNECT,         /* 7 */
	VIDYO_CLIENT_ERROR_TCP_FTP_WEIRD_SERVER_REPLY	=  8,	// CURLE_FTP_WEIRD_SERVER_REPLY,  /* 8 */
	VIDYO_CLIENT_ERROR_TCP_REMOTE_ACCESS_DENIED		=  9,	// CURLE_REMOTE_ACCESS_DENIED,    /* 9 a service was denied by the server due to lack of access - when login fails this is not returned. */
	VIDYO_CLIENT_ERROR_TCP_PARTIAL_FILE				= 18,	// CURLE_PARTIAL_FILE,            /* 18 */	
	VIDYO_CLIENT_ERROR_TCP_HTTP_RETURNED_ERROR		= 22,	// CURLE_HTTP_RETURNED_ERROR,     /* 22 */
	VIDYO_CLIENT_ERROR_TCP_OUT_OF_MEMORY			= 27,	// CURLE_OUT_OF_MEMORY,           /* 27 */	
	VIDYO_CLIENT_ERROR_TCP_OPERATION_TIMED_OUT		= 28,	// CURLE_OPERATION_TIMEDOUT,      /* 28 - the timeout time was reached */
	VIDYO_CLIENT_ERROR_TCP_HTTP_POST_ERROR			= 34,	// CURLE_HTTP_POST_ERROR,         /* 34 */
	VIDYO_CLIENT_ERROR_TCP_SSL_CONNECT_ERROR		= 35,	// CURLE_SSL_CONNECT_ERROR,       /* 35 - wrong when connecting with SSL */
	VIDYO_CLIENT_ERROR_TCP_FUNCTION_NOT_FOUND		= 41,	// CURLE_FUNCTION_NOT_FOUND,      /* 41 */	
	VIDYO_CLIENT_ERROR_TCP_ABORTED_BY_CALLBACK		= 42,	// CURLE_ABORTED_BY_CALLBACK,     /* 42 */	
	VIDYO_CLIENT_ERROR_TCP_BAD_FUNCTION_ARGUMENT	= 43,	// CURLE_BAD_FUNCTION_ARGUMENT,   /* 43 */	
	VIDYO_CLIENT_ERROR_TCP_INTERFACE_FAILED			= 45,	// CURLE_INTERFACE_FAILED,        /* 45 - CURLOPT_INTERFACE failed */	
	VIDYO_CLIENT_ERROR_TCP_TOO_MANY_REDIRECTS		= 47,	// CURLE_TOO_MANY_REDIRECTS ,     /* 47 - catch endless re-direct loops */
	VIDYO_CLIENT_ERROR_TCP_UNKNOWN_OPTION			= 48,	// CURLE_UNKNOWN_OPTION,          /* 48 - User specified an unknown option */
	VIDYO_CLIENT_ERROR_TCP_PEER_FAILED_VERIFICATION	= 51,	// CURLE_PEER_FAILED_VERIFICATION, /* 51 - peer's certificate or fingerprint wasn't verified fine */
	VIDYO_CLIENT_ERROR_TCP_GOT_NOTHING				= 52,	// CURLE_GOT_NOTHING,             /* 52 - when this is a specific error */
	VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_NOT_FOUND		= 53,	// CURLE_SSL_ENGINE_NOTFOUND,     /* 53 - SSL crypto engine not found */
	VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_SET_FAILED	= 54,	// CURLE_SSL_ENGINE_SETFAILED,    /* 54 - can not set SSL crypto engine as default */
	VIDYO_CLIENT_ERROR_TCP_SEND_ERROR				= 55,	// CURLE_SEND_ERROR,              /* 55 - failed sending network data */
	VIDYO_CLIENT_ERROR_TCP_RECV_ERROR				= 56,	// CURLE_RECV_ERROR,              /* 56 - failure in receiving network data */
	VIDYO_CLIENT_ERROR_TCP_SSL_CERT_PROBLEM			= 58,	// CURLE_SSL_CERTPROBLEM,         /* 58 - problem with the local certificate */
	VIDYO_CLIENT_ERROR_TCP_SSL_CIPHER				= 59,	// CURLE_SSL_CIPHER,              /* 59 - couldn't use specified cipher */
	VIDYO_CLIENT_ERROR_TCP_SSL_CACERT				= 60,	// CURLE_SSL_CACERT,              /* 60 - problem with the CA cert (path?) */
	VIDYO_CLIENT_ERROR_TCP_BAD_CONTENT_ENCODING		= 61,	// CURLE_BAD_CONTENT_ENCODING,    /* 61 - Unrecognized/bad encoding */
	VIDYO_CLIENT_ERROR_TCP_FILE_SIZE_EXCEEDED		= 63,	// CURLE_FILESIZE_EXCEEDED,       /* 63 - Maximum file size exceeded */
	VIDYO_CLIENT_ERROR_TCP_SEND_FAIL_REWIND			= 65,	// CURLE_SEND_FAIL_REWIND,        /* 65 - Sending the data requires a rewind that failed */	
	VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_INIT_FAILED	= 66,	// CURLE_SSL_ENGINE_INITFAILED,   /* 66 - failed to initialise ENGINE */
	VIDYO_CLIENT_ERROR_TCP_SSL_SHUTDOWN_FAILED		= 80,	// CURLE_SSL_SHUTDOWN_FAILED,     /* 80 - Failed to shut down the SSL connection */	
	VIDYO_CLIENT_ERROR_TCP_AGAIN					= 81,	// CURLE_AGAIN,                   /* 81 - socket is not ready for send/recv, wait till it's ready and try again (Added in 7.18.2) */
	VIDYO_CLIENT_ERROR_TCP_SSL_ISSUER_ERROR			= 83,	// CURLE_SSL_ISSUER_ERROR,        /* 83 - Issuer check failed.  (Added in 7.19.0) */
	VIDYO_CLIENT_ERROR_TCP_CHUNK_FAILED				= 88,	// CURLE_CHUNK_FAILED,            /* 88 - chunk callback reported error */		

	//http errors
	VIDYO_CLIENT_ERROR_HTTP_200_OK 					= 200,
	VIDYO_CLIENT_ERROR_HTTP_301_REDIRECT 			= 301,
	VIDYO_CLIENT_ERROR_HTTP_302_REDIRECT 			= 302,
	VIDYO_CLIENT_ERROR_HTTP_401_UNAUTHORIZED 		= 401,
	VIDYO_CLIENT_ERROR_HTTP_404_NOT_IMPLEMENTED 	= 404,
	VIDYO_CLIENT_ERROR_HTTP_407_PROXY_AUTHENTICATION_REQUIRED = 407,
	VIDYO_CLIENT_ERROR_HTTP_500_SERVER_ERROR		= 500,
	VIDYO_CLIENT_ERROR_HTTP_501_NOT_IMPLEMENTED 	= 501,
	
	//SOAP faults/results
	VIDYO_CLIENT_ERROR_SOAP_SUCCESS 				= 1000,		// Result is success
	VIDYO_CLIENT_ERROR_SOAP_FAILURE,							// Result is some unknown general failure
	VIDYO_CLIENT_ERROR_SOAP_NOT_LICENSED,						// Not licensed
	VIDYO_CLIENT_ERROR_SOAP_SEAT_LICENSE_EXPIRED,				// Seat license expired
	VIDYO_CLIENT_ERROR_SOAP_WRONG_PIN,							// Wrong PIN
	VIDYO_CLIENT_ERROR_SOAP_CONFERENCE_LOCKED,					// Conference locked
	VIDYO_CLIENT_ERROR_SOAP_ROOM_DISABLED,						// Room disabled
	VIDYO_CLIENT_ERROR_SOAP_GENERAL_FAULT,						// General Fault
	VIDYO_CLIENT_ERROR_SOAP_INVALID_ARGUMENT_FAULT,				// Invalid argument fault
	VIDYO_CLIENT_ERROR_SOAP_MEMBER_NOT_ONLINE,					// Status of member is not online
	VIDYO_CLIENT_ERROR_SOAP_NOT_OWNER_OF_ROOM,					// Not owner of room
	VIDYO_CLIENT_ERROR_SOAP_USER_NOT_FOUND,						// Specified user is not found
	VIDYO_CLIENT_ERROR_SOAP_UNEXPECTED_SUBELEMENT_IN_MESSAGE,	// Unexpected subelement in SOAP message
	VIDYO_CLIENT_ERROR_SOAP_END_POINT_NOT_FOUND,				// Endpoint not found
	VIDYO_CLIENT_ERROR_SOAP_FAILED_PLACE_DIRECT_CALL,
	VIDYO_CLIENT_ERROR_SOAP_IPC_JOIN_FAILURE,					// Failure to join room on other portal
	VIDYO_CLIENT_ERROR_SOAP_ALL_LINES_IN_USE,					// All lines are in use
	VIDYO_CLIENT_ERROR_SOAP_RESOURCE_NOT_AVAILABLE,				// Resource Not available
	VIDYO_CLIENT_ERROR_SOAP_RESULT_ACCESS_RESTRICTED,			// Access restricted
	VIDYO_CLIENT_ERROR_SOAP_RESULT_USER_NOT_BOUND,
	VIDYO_CLIENT_ERROR_SOAP_CANNOT_JOIN_GUEST,
	
	//internal errors
	VIDYO_CLIENT_ERROR_INTERNAL_REQUEST 			= 2000,
	VIDYO_CLIENT_ERROR_INTERNAL_RESPONSE,
	VIDYO_CLIENT_ERROR_INTERNAL_COULD_NOT_LINK,
	VIDYO_CLIENT_ERROR_INTERNAL_LOGIN_CANCELED,
	VIDYO_CLIENT_ERROR_INTERNAL_LOGIN_OLD_SERVER,
	VIDYO_CLIENT_ERROR_INTERNAL_CURL_INIT,
	VIDYO_CLIENT_ERROR_INTERNAL_NO_PORTAL_ADDRESS, 
	VIDYO_CLIENT_ERROR_INTERNAL_WRONG_STATE, 
	
	// USER_MESSAGES will be here	
	
	VIDYO_CLIENT_ERROR_UNKNOWN = 0xFFFF,
} VidyoClientError;

/*! Event structure
	
	- Used for reporting conference information update events:
		+ #VIDYO_CLIENT_OUT_EVENT_LOGIN
*/
typedef struct VidyoClientOutEventLogIn_
{
	/*! Error code.  */
	VidyoUint error;
	/*! Portal URI */
	char portalUri[URI_LEN];
	/*! User name */
	char userName[USERID_SIZE];
} VidyoClientOutEventLogIn;

/*!	Status code of Guest Link Room operation
	- Used for event
		+ VIDYO_CLIENT_OUT_EVENT_ROOM_LINK
*/	
typedef enum VidyoClientRoomLinkState_
{
	VIDYO_CLIENT_ROOM_LINK_STATE_INIT = 0,		/*!< Initial state, nothing achived */
	VIDYO_CLIENT_ROOM_LINK_STATE_CONNECTED, 	/*!< Connection to server (maybe HTTP proxy) tried by Getting Portal Version */
	VIDYO_CLIENT_ROOM_LINK_STATE_LOGGED,		/*!< SOAP request Logging to Portal is sent */
	VIDYO_CLIENT_ROOM_LINK_STATE_LINKED,		/*!< Process Linking to VidyoMahager is passed */
	VIDYO_CLIENT_ROOM_LINK_STATE_GOT_ENTITY,	/*!< intermedia state for using Room Link being logged in the same Portal */
	VIDYO_CLIENT_ROOM_LINK_STATE_CANCELLED,		/*!< process cancelled by User */
	VIDYO_CLIENT_ROOM_LINK_STATE_JOINED,		/*!< SOAP request Joining Conference is sent */
} VidyoClientRoomLinkState;

/*! Event structure
	
	- Used for reporting guest login & join-room state and error via event:
		+ #VIDYO_CLIENT_OUT_EVENT_ROOM_LINK
*/
typedef struct VidyoClientOutEventRoomLink_
{
	/*! Error code.  */
	VidyoClientError error;
	/*! Guest login & join-room state  */
	VidyoClientRoomLinkState state;
	/*! Server URI */
	char serverUri[URI_LEN];
}VidyoClientOutEventRoomLink;

/*! Event structure
	
	- Used for reporting conference information update events:
		+ #VIDYO_CLIENT_OUT_EVENT_LICENSE
*/
typedef struct VidyoClientOutEventLicense_
{
	/*! Error code. */
	VidyoUint error;
	/*! Connection path */
	VidyoUint vmConnectionPath;
	/*! VIDYO_TRUE when licenses are exhausted on the portal. VIDYO_FALSE otherwise. */
	VidyoBool OutOfLicenses;
	/*! Result from SOAP response */
	VidyoClientSoapResultCode result;
	/*! SOAP fault code */
	VidyoClientSoapFault fault;
} VidyoClientOutEventLicense;

/*! Event structure
	
	- Used for reporting conference information update events:
		+ #VIDYO_CLIENT_OUT_EVENT_LINKED
*/
typedef struct VidyoClientOutEventLinked_
{
	/*! Error code.  */
	VidyoUint error;
} VidyoClientOutEventLinked;

/*! Event structure
	
	- Used for reporting failure of sign-in request.
	- Used for responding to signed-out request.
	- Used for reporting sign-out command from portal 
		 e.g. user signed-in to another machine.
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_SIGNED_OUT
*/
typedef struct VidyoClientOutEventSignedOut_
{
	/*! Cause to generate this event. */
	VidyoClientSignedOutCause cause;
	/*! Error code. */
	VidyoUint error;
	/*!
	 VIDYO_TRUE if logged (joined to Room Link) as guest, 
	 VIDYO_FALSE for permanent users.
	 */
	VidyoBool guestLogin;	
} VidyoClientOutEventSignedOut;

/*! Event structure
	
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_ENABLED_STATUS_BAR
		+ #VIDYO_CLIENT_OUT_EVENT_ENABLED_BUTTON_BAR
*/
typedef struct VidyoClientOutEventEnabled_
{
	/*!
		VIDYO_TRUE to confirm enabling of setting for specified out event,
		VIDYO_FALSE to confirm disabling.
	*/
	VidyoBool isEnabled;
} VidyoClientOutEventEnabled;

/*! Event structure
	- Used by following in events:
		+ #VIDYO_CLIENT_OUT_EVENT_FLOATING_WINDOW
*/
typedef struct VidyoClientOutEventFloatingWindow_
{
	/*!
		OS-specific window ID of floating window.  0 when the window has been destroyed.
		See VidyoTypes.h for definition of #VidyoWindowId for particular platform.
	*/
	VidyoWindowId window;
} VidyoClientOutEventFloatingWindow;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_GROUP_CHAT
*/
typedef struct VidyoClientOutEventGroupChat_
{
	/*! Vidyo URI of remote participant that sent message. */
    char uri[URI_LEN];
	/*! Display name of conference participant. */
    char displayName[USERID_SIZE];
	/*! Message (contents) to be sent. */
    char message[MAX_CHAT_MESSAGE_LEN];

} VidyoClientOutEventGroupChat;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_OUT_EVENT_PRIVATE_CHAT
*/
typedef struct VidyoClientOutEventPrivateChat_
{
	/*! Vidyo URI of remote participant to whom this text message to be sent. */ 
    char uri[URI_LEN];
	/*! Display name of conference participant to whom this text message to be sent. */
    char displayName[USERID_SIZE];
	/*! Message (contents) to be sent. */
    char message[MAX_CHAT_MESSAGE_LEN];

} VidyoClientOutEventPrivateChat;
/*******************************************************************************
 Parameter structures for requests from GUI to Vidyo Client Library
*******************************************************************************/

/*! @struct VidyoClientRequestConfiguration
	@brief  Request structure
	@details - Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CONFIGURATION
		+ #VIDYO_CLIENT_REQUEST_SET_CONFIGURATION
	
	@var VidyoClientRequestConfiguration::microphones [out] 
		Array of values for the names of attached audio input (capture/microphone) devices.
	@var VidyoClientRequestConfiguration::numberMicrophones  [out]
		Number of attached audio input (capture/microphone) devices.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestConfiguration::currentMicrophone  [in,out]
		Index of currently selected audio input (capture/microphone) device.  Range of values
		0~UINT_MAX, UINT_MAX designating no current selection.
	@var VidyoClientRequestConfiguration::speakers [out]
		Array of values for the names of attached audio output (playback/speaker) devices.
	@var VidyoClientRequestConfiguration::numberSpeakers [out]
		Number of attached audio output (playback/speaker) devices.  
		Range of values 0~UINT_MAX.
	@var VidyoClientRequestConfiguration::currentSpeaker [in,out]
		Index of currently selected audio output (playback/speaker) device.  Range of values
		0~UINT_MAX, UINT_MAX designating no current selection.
	@var VidyoClientRequestConfiguration::cameras [out]
		Array of values for the names of attached video (capture/camera) devices.
	@var VidyoClientRequestConfiguration::numberCameras [out]
		Number of attached video (capture/camera) devices.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestConfiguration::currentCamera [in,out]
		Index of currently selected video (capture/camera) device.  Range of values
		0~UINT_MAX, UINT_MAX designating no current selection.
	@var VidyoClientRequestConfiguration::enableFeccEndpoint [in,out]
		Non-zero value if endpoint camera is controllable, Zero value if endpoint camera is not
		controllable.
	@var VidyoClientRequestConfiguration::enableFeccController [in,out]
		Non-zero value if endpoint can send FECC commands, Zero value if endpoint cannot send
		FECC commands.
	@var VidyoClientRequestConfiguration::vidyoProxies [out]
		Array of values for the IP addresses and ports of configured VidyoProxy entities.
		Format of individual values is <b>\<IP address\>:\<port\></b>.
	@var VidyoClientRequestConfiguration::numberVidyoProxies [out]
		Number of configured VidyoProxy entities.  
		Range of values 0~UINT_MAX, but currently
		limited to 0 or 1.
	@var VidyoClientRequestConfiguration::currentVidyoProxy [out]
		Index of currently configured VidyoProxy entity.  
		Range of values
		0~UINT_MAX, but currently limited to 0.
	@var VidyoClientRequestConfiguration::userID [in,out]
		Username to sign in with, as known to VidyoPortal.  Encoded as UTF-8. 
	@var VidyoClientRequestConfiguration::password [in,out]
		Key allocated by VidyoPortal to be used in place of password.  This value should be
		acquired through login procedure with VidyoPortal. 
	@var VidyoClientRequestConfiguration::serverAddress [in,out]
		Hostname or IP address of VidyoManager to be used.  
	@var VidyoClientRequestConfiguration::serverPort [in,out]
		Port of VidyoManager to be used.  
	@var VidyoClientRequestConfiguration::vidyoProxyAddress [in,out]
		VidyoProxy hostname or IP address.  *Deprecated*.
	@var VidyoClientRequestConfiguration::vidyoProxyPort [in,out]
		VidyoProxy port.   *Deprecated*.
	@var VidyoClientRequestConfiguration::webProxyAddress [in,out]
		Web proxy hostname or IP address, used when parameter proxySettings does set bit for
		PROXY_WEB_LOCAL_MANUAL.  
	@var VidyoClientRequestConfiguration::webProxyPort [in,out]
		Web proxy port, used when parameter proxySettings does set bit for PROXY_WEB_LOCAL_MANUAL.
	@var VidyoClientRequestConfiguration::webProxyUsername [in,out]
		Web proxy username, used when parameter proxySettings does set bit for PROXY_WEB_ENABLE.
	@var VidyoClientRequestConfiguration::webProxyPassword [in,out]
		Web proxy password, used when parameter proxySettings does set bit for PROXY_WEB_ENABLE.
	@var VidyoClientRequestConfiguration::webProxyIeAddress [out]
		Web proxy hostname or IP address, used when parameter proxySettings does set bit
		for PROXY_WEB_IE_MANUAL.  Cannot be changed via request
		#VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, since value comes from underlying platform.
	@var VidyoClientRequestConfiguration::webProxyIePort [out]
		Web proxy port, used when parameter proxySettings does set bit for PROXY_WEB_IE_MANUAL.
		Cannot be changed via request #VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, since value comes
		from underlying platform.
	@var VidyoClientRequestConfiguration::portalAddress [in,out]
		@details Base URL for accessing SOAP services on the VidyoPortal
		(e.g. http://example.vidyo.com/services). 
	@var VidyoClientRequestConfiguration::ringtoneDeviceName [in,out]
		Name of device to play ring tone for inbound calls.  Used in conjunction with
		event #VIDYO_CLIENT_IN_EVENT_PLAY_RINGTONE. 
	@var VidyoClientRequestConfiguration::verifyCertPortalAcct [in,out]
		@details Name of the portal account (address and port) for which Certificate authenticity check is
		disabled by user temporarily for that specific username.
	@var VidyoClientRequestConfiguration::webProxyScriptUrl [in,out]
		URL for Web proxy PAC script, used when parameter proxySettings does set bit for #PROXY_WEB_LOCAL_AUTO_CONFIG_SCRIPT.
	@var VidyoClientRequestConfiguration::webProxyIeScriptUrl [out]
		URL for Web proxy PAC script, used when parameter proxySettings does set bit for #PROXY_WEB_IE_AUTO_CONFIG_SCRIPT.
		Cannot be changed via request #VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, since value comes from underlying platform.
	@var VidyoClientRequestConfiguration::mediaLowPort [in,out]
		Lowest value of IP source port to be used for media connections.  Range of allowed
		values 1~65530.
	@var VidyoClientRequestConfiguration::mediaHighPort [in,out]
		Highest value of IP source port to be used for media connections.  Range of allowed
		values 6~65535.
	@var VidyoClientRequestConfiguration::proxySettings [in,out]
		Configuration of use of VidyoProxy and web proxies.  See definition of
		following constants, in VidyoClientConstants.h:
		- #PROXY_VIDYO_AUTO (1<<1)  *Deprecated*.
		- #PROXY_VIDYO_MANUAL (1<<2) *Deprecated*.
		- #PROXY_VIDYO_FORCE (1)
		- #PROXY_WEB_ENABLE (1<<3)
		- #PROXY_WEB_IE (1<<4)
		- #PROXY_WEB_LOCAL (1<<5)
		- #PROXY_WEB_IE_AUTO_DETECT (1<<6)
		- #PROXY_WEB_IE_AUTO_CONFIG_SCRIPT (1<<7)
		- #PROXY_WEB_IE_MANUAL (1<<8)	
		- #PROXY_WEB_LOCAL_AUTO_DETECT (1<<6)
		- #PROXY_WEB_LOCAL_AUTO_CONFIG_SCRIPT (1<<7)
		- #PROXY_WEB_LOCAL_MANUAL (1<<8)	
	@var VidyoClientRequestConfiguration::videoPreferences [in,out]
		Configuration of own video resolution and frame rate.  See definition of
		VidyoClientVideoPreferences.
	@var VidyoClientRequestConfiguration::enableLogging [in,out]
		Non-zero value for logging enabled, zero value for logging disabled.  Currently not
		supported.
	@var VidyoClientRequestConfiguration::enableAutoAnswer [in,out]
		@details Non-zero value for auto-answer of inbound calls enabled, zero value for auto-answer of
		inbound calls disabled.
	@var VidyoClientRequestConfiguration::enableForceProxy [out]
		@details Non-zero value for forced use of VidyoProxy enabled, zero value for forced use of
		VidyoProxy disabled.
	@var VidyoClientRequestConfiguration::enableLogWindow [in,out]
		Non-zero value for log settings window enabled, zero value for log settings window
		disabled.  Currently not supported.
	@var VidyoClientRequestConfiguration::enableEntryTone [in,out]
		Non-zero value for entry and exit tones enabled, zero value for entry and exit tones
		disabled.  It is still responsibility of GUI to manage logic for when to play entry
		and exit tones, using other events provided by this API.
	@var VidyoClientRequestConfiguration::enableEchoDetection [in,out]
		Non-zero value for echo detection enabled, zero value for echo detection disabled.
	@var VidyoClientRequestConfiguration::enableEchoCancellation [in,out]
		Non-zero value for echo cancellation enabled, zero value for echo cancellation disabled.
	@var VidyoClientRequestConfiguration::enableFullScreenVideo [in,out]
		Non-zero value for full-screen on joining of conference enabled, zero value for
		full-screen on joining of conference disabled.  It is still responsibility of GUI to
		manage logic for actual display of a video layout in full-screen, using other events
		provided by this API.
	@var VidyoClientRequestConfiguration::showToolbarInFullScreenVideo [in,out]
		Non-zero value for showing GUI controls (toolbar) while full-screen enabled, zero value
		for showing GUI controls (toolbar) while full-screen disabled.  It is still
		responsibility of GUI to manage logic for actual display of GUI controls while
		full-screen, using other events provided by this API.
	@var VidyoClientRequestConfiguration::enableAudioAGC [in,out]
		@details Non-zero value for audio AGC (Automatic Gain Control) enabled, zero value for audio AGC
		disabled.
	@var VidyoClientRequestConfiguration::enableAutoStart [in,out]
		@details Non-zero value for auto-start of application on login enabled, zero value for auto-start
		disabled.
	@var VidyoClientRequestConfiguration::enableShowConfParticipantName [in,out]
		@details Non-zero value for labeling of video layout with participant display names enabled, zero
        value for labeling disabled.
	@var VidyoClientRequestConfiguration::enableMuteMicrophoneOnJoin [in,out]
		@details Non-zero value for muting of microphone device when conference or call entered, zero
        value for no muting.
	@var VidyoClientRequestConfiguration::enableHideCameraOnJoin [in,out]
		@details Non-zero value for hiding of camera device when conference or call entered, zero
        value for no hiding.
	@var VidyoClientRequestConfiguration::enableMuteSpeakerOnJoin [in,out]
		@details Non-zero value for muting of speaker device when conference or call entered, zero
        value for no muting.
	@var VidyoClientRequestConfiguration::enableEulaAgreed [in,out]
		@details Non-zero value for terms of EULA (End User License Agreement) agreed to by user, zero
        value for not yet agreed.
	@var VidyoClientRequestConfiguration::enableRendering [in,out]
		Non-zero value to enable rendering, zero value to disable rendering.
	@var VidyoClientRequestConfiguration::enableBackgrounding [in,out]
		Non-zero value for backgrounding enablement, zero value for backgrounding disabled.
	@var VidyoClientRequestConfiguration::enableFullDisplaySharing [in,out]
		Non-zero value for Full Display Sharing enabled, zero value for Full Display Sharing disabled.
	@var VidyoClientRequestConfiguration::selfViewLoopbackPolicy [in,out]
		@details 0 for participant to see self video, 1 for disabling self video and 2 for enabling self video 
		only when there are no other participant in conference.   

*/
typedef struct VidyoClientRequestConfiguration_
{
	VidyoUint8 microphones[MAX_DEVICE_NUMBER][DEVICE_NAME_SIZE];
	VidyoUint numberMicrophones;
	VidyoUint currentMicrophone;

	VidyoUint8 speakers[MAX_DEVICE_NUMBER][DEVICE_NAME_SIZE];
	VidyoUint numberSpeakers;
	VidyoUint currentSpeaker;

	VidyoUint8 cameras[MAX_DEVICE_NUMBER][DEVICE_NAME_SIZE];
	VidyoUint numberCameras;
	VidyoUint currentCamera;

	VidyoUint enableFeccEndpoint;
	VidyoUint enableFeccController;

	VidyoUint8 vidyoProxies[SIGNIN_VIDYO_PROXY_NUMBER]
		[SIGNIN_VIDYO_PROXY_ADDRESS_SIZE+SIGNIN_VIDYO_PROXY_PORT_SIZE+1];
	VidyoUint numberVidyoProxies;
	VidyoUint currentVidyoProxy;

	VidyoUint8 userID[FIELD_SIZE];
	VidyoUint8 password[FIELD_SIZE];
	VidyoUint8 serverAddress[URI_LEN];
	VidyoUint8 serverPort[SERVERPORT_SIZE];
	VidyoUint8 vidyoProxyAddress[URI_LEN];
	VidyoUint8 vidyoProxyPort[SERVERPORT_SIZE];
	VidyoUint8 webProxyAddress[URI_LEN];
	VidyoUint8 webProxyPort[SERVERPORT_SIZE];
	VidyoUint8 webProxyUsername[FIELD_SIZE];
	VidyoUint8 webProxyPassword[FIELD_SIZE];
	VidyoUint8 webProxyIeAddress[URI_LEN];
	VidyoUint8 webProxyIePort[SERVERPORT_SIZE];
	VidyoUint8 portalAddress[FIELD_SIZE];
	VidyoUint8 ringtoneDeviceName[FIELD_SIZE];
	VidyoUint8 verifyCertPortalAcct[MAX_PORTAL_ADDRESS];
	VidyoUint8 webProxyScriptUrl[URI_LEN];
	VidyoUint8 webProxyIeScriptUrl[URI_LEN];
	
	VidyoUint mediaLowPort;
	VidyoUint mediaHighPort;
	VidyoUint proxySettings;
	VidyoClientVideoPreferences videoPreferences;

	VidyoUint enableLogging;
	VidyoUint enableAutoAnswer;
	VidyoUint enableForceProxy;
	VidyoUint enableLogWindow;			
	VidyoUint enableEntryTone;
	VidyoUint enableEchoDetection;
	VidyoUint enableEchoCancellation;
	VidyoUint enableFullScreenVideo;
	VidyoUint showToolbarInFullScreenVideo;
	VidyoUint enableAudioAGC;
	VidyoUint enableAutoStart;
	VidyoUint enableShowConfParticipantName;
	VidyoUint enableMuteMicrophoneOnJoin;
	VidyoUint enableHideCameraOnJoin;
	VidyoUint enableMuteSpeakerOnJoin;
	VidyoUint enableEulaAgreed;
	VidyoUint enableRendering;
	VidyoUint enableBackgrounding;
	VidyoUint enableFullDisplaySharing;
	VidyoUint selfViewLoopbackPolicy;
} VidyoClientRequestConfiguration;

/*! Request structure
	
	- Used by following in events:
		+ #VIDYO_CLIENT_REQUEST_GET_CONNECTIVITY_INFO
*/
typedef struct VidyoClientRequestConnectivityInfo_
{
	/*!
		Hostname or IP address of VidyoManager
	*/
	char serverAddress[SIGNIN_SERVERADDRESS_SIZE];
	/*!
		Port of VidyoManager address
	*/
	char serverPort[SIGNIN_SERVERPORT_SIZE];
	/*!
		VIDYO_TRUE if connection to VidyoManager would be secured using TLS,
		VIDYO_FALSE if connection to VidyoManager would not be secure.
	*/
	VidyoBool serverSecured;
	/*!
		Identity of Vidyo Manager to which end point is assigned. This value was
		acquired through login procedure with VidyoPortal.
	*/
	char vmIdentity[VIDYO_MANAGER_ID_SIZE];
	/*!
		Username to sign in with, as known to VidyoPortal.  Encoded as UTF-8.
	*/
	char userName[SIGNIN_USERNAME_SIZE];
	/*!
		Base URL used for accessing SOAP services on the VidyoPortal
		(e.g. http://example.vidyo.com/services).
	*/
	char portalAddress[SIGNIN_PORTALADDRESS_SIZE];
	/*!
		Array of portal version
	*/
	char portalVersion[SIGNIN_PORTALVERSION_SIZE];
	/*!
		Location tag assigned to the endpoint. This is configured on portal to indicate the
		location of an endpoint and is used to assign a VidyoRouter group to the endpoint
		when joining a call.
	*/
	char locationTag[ENDPOINT_LOCATION_TAG_SIZE];
	/*!
		Array of VidyoProxy hostnames or IP addresses.  Only 0 or 1 VidyoProxy addresses
		are currently supported.
	*/
	char vidyoProxyAddress[SIGNIN_VIDYO_PROXY_ADDRESS_SIZE];
	/*!
		Array of VidyoProxy ports.  Only 0 or 1 VidyoProxy addresses are currently supported.
		Each port is used with corresponding value found in the same index of preceding
		parameter vidyoProxyAddress.
	*/
	char vidyoProxyPort[SIGNIN_VIDYO_PROXY_PORT_SIZE];
	/*!
		VIDYO_TRUE if username given in preceding parameter userName is ephemeral
		value allocated for guest login, VIDYO_FALSE for permanent users.
	*/
	VidyoBool guestLogin;

	/*!< External IP address of machine on which client is running as seen by web server. */
	char clientExternalIPAddress[MAX_IPADDRESS_LEN]; 					
	/*!< 
		The type of Proxy available to the client.
		If value is VIDYO_CLIENT_VIDYO_PROXY vidyoProxyAddress should have valid proxy address
		and vidyoProxyPort should have valid proxy port. Instead if value is VIDYO_CLIENT_REVERSE_PROXY
		reverseProxyAddress should have valid proxy address and reverseProxyPort should have valid proxy port.
		In both cases numberProxies will provide the number of proxies available to client.
	*/
	VidyoClientProxyType proxyType;
	/*!< 
		ReverseProxy hostnames or IP addresses used to connect to VidyoManager.
	*/
	char reverseProxyAddress[SIGNIN_VIDYO_PROXY_ADDRESS_SIZE]; 
	/*!< 
		ReverseProxy port used to connect to VidyoManager.
	*/
	char reverseProxyPort[SIGNIN_VIDYO_PROXY_PORT_SIZE]; 
} VidyoClientRequestConnectivityInfo;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_EID
*/
typedef struct VidyoClientRequestGetEid_
{
	/*!
		EID (Endpoint IDentifier) uniquely identifies VidyoClient installation and is
		used as identifier of VidyoClient towards VidyoManager and VidyoPortal.
	*/
	char EID[MAX_EID_SIZE];
} VidyoClientRequestGetEid;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_LID
*/
typedef struct VidyoClientRequestGetLid_
{
	/*!
		LID (Licensing IDentifier) is used as unique identifier of VidyoClient
		installation for licensing purposes. The LID should be used in sent installation
		license request to identify installation to VidyoPortal.
	*/
	char LID[MAX_EID_SIZE];
} VidyoClientRequestGetLid;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PID
*/
typedef struct VidyoClientRequestGetPid_
{
	/*!
		PID (Participant IDentifier) assigned to VidyoClient by VidyoManager.
		The participant identifier is in-conference unique identifier used by 
		VidyoClient to identify itself when joining conference on VidyoRouter.
	*/
	char PID[MAX_PID_SIZE];
} VidyoClientRequestGetPid;

/*! Request structure

	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_ACTIVATE_EID
*/
typedef struct VidyoClientRequestActivateEid_
{
	/*!
		LAC (License Activation Key) is provided by VidyoPortal when license is requested.
		LAC must be passed to VidyoClient as verification that VidyoPortal has authorized
		activation of installation license.
	*/
	char lacKey[LAC_KEY_SIZE];
} VidyoClientRequestActivateEid;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_VOLUME_AUDIO_IN
		+ #VIDYO_CLIENT_REQUEST_SET_VOLUME_AUDIO_IN
		+ #VIDYO_CLIENT_REQUEST_GET_VOLUME_AUDIO_OUT
		+ #VIDYO_CLIENT_REQUEST_SET_VOLUME_AUDIO_OUT
*/
typedef struct VidyoClientRequestVolume_
{
	/*!
		Volume (requests ending in AUDIO_OUT) or gain level (requests ending in AUDIO_IN) of
		local audio device.  Use requests ending in AUDIO_IN to control gain level of
		microphone device, requests ending in AUDIO_OUT to control volume of speaker device.
		Range of allowed values 0~65535.	
	*/
	VidyoUint volume;
} VidyoClientRequestVolume;

/*! @struct VidyoClientWindowShares
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES
		+ #VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES

	@var VidyoClientWindowShares::remoteAppUri [in,out]
		Array of Vidyo URI values for remote participants providing application window shares.
		Output parameter for both #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES and 
		#VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES.  Input parameter for 
		#VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES, used in conjunction with parameter setApp to 
		determine which application window share to show in the video layout.  Recommended
		for GUI to always use #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES just prior to 
		#VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES, passing pointer to same copy of struct
		#VidyoClientRequestWindowShares, in order for this parameter to be set correctly.
		Valid application URI are filled from index 1 and 0th index is not used.
	@var VidyoClientWindowShares::remoteAppName [out]
		Array of values for application window share names or captions.  The order of this
		array matches that for the parameter remoteAppUri.
		Valid application name are filled from index 1 and 0th index is not used.
	@var VidyoClientWindowShares::numApp [out]
		Number of entries in the parameters remoteAppUri and remoteAppName.  Range of values
		0~UINT_MAX.
	@var VidyoClientWindowShares::currApp [out]
		Index of entry in parameter remoteAppUri, to use for determining which application
		window share is currently shown in the video layout.  Only valid for
		#VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES.  A value of zero means no application window
		share is currently shown in the video layout.  Range of allowed values -INT_MAX~INT_MAX.
	@var VidyoClientWindowShares::eventUri [in]
		URI of the current application being shared.  Used to stop sharing when remote
		stopped to share.
	@var VidyoClientWindowShares::newApp [in]
		Index of entry in parameter remoteAppUri, to use for determining which application
		window share to show in the video layout.  Only valid for
		#VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES.  A value of zero causes no application window
		share to be shown in the video layout.  Range of allowed values -INT_MAX~INT_MAX.

*/
typedef struct VidyoClientWindowShares_
{
	char remoteAppUri[MAX_REMOTE_SHARE_APP][MAX_URI_LEN];
	char remoteAppName[MAX_REMOTE_SHARE_APP][MAX_URI_LEN];
	VidyoInt numApp;
	VidyoInt currApp;
	char eventUri[MAX_URI_LEN];
	VidyoInt newApp;
} VidyoClientWindowShares;

/*! @struct VidyoClientRequestWindowShares
	@brief Request structure
	@details - Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES
		+ #VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES

	@var VidyoClientRequestWindowShares::requestType [in]
			The type of request:
			- list
			- change
			- stop
			- toggle
	
		
	@var VidyoClientRequestWindowShares::shareList [in,out]
		The details of sharable windows.

	@note LIST_SHARING_WINDOWS - Shall be used only for #VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES.
	Other values are valid only with #VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES.

*/
typedef struct VidyoClientRequestWindowShares_
{
	
	VidyoClientWindowShareRequestType requestType;
	VidyoClientWindowShares shareList;
} VidyoClientRequestWindowShares;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_SET_LABEL
*/
typedef struct VidyoClientRequestSetLabel_
{
	/*! Identity of label to be set. */
	VidyoClientLabelType labelID;
	/*! Actual text to be used. */
	char labelText[MAX_LABEL_STRING_SIZE];
} VidyoClientRequestSetLabel;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PORTAL_HISTORY
		+ #VIDYO_CLIENT_REQUEST_SET_PORTAL_HISTORY

	@note	CurrentPortalHistory always FIRST.
*/
typedef struct VidyoClientRequestPortalHistory_
{
	/*! Combined string from URI and User Name. */
	VidyoUint8 portalUriName[MAX_PORTAL_HISTORY_NUMBER][MAX_PORTAL_HISTORY_SIZE];
	/*! Number of entries in the parameter portalUriName. */
	VidyoUint numberPortalHistory;
} VidyoClientRequestPortalHistory;

/*! @struct VidyoClientRequestSnapResize
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_SNAP_RESIZE

    @var VidyoClientRequestSnapResize::width [in,out]
		Prospective width of video layout region.  Value will be changed to closest
		allowed, that preserves aspect ratio.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::height [in,out]
		Prospective height of video layout region.  Value will be changed to closest
		allowed, that preserves aspect ratio.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::curWidth [in]
		Current width of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::curHeight [in]
		Current height of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::minWidth [in]
		Minimum acceptable width of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::minHeight [in]
		Minimum acceptable height of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::maxWidth [in]
		Maximum acceptable width of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::maxHeight [in]
		Maximum acceptable height of video layout region.  Range of allowed values 0~UINT_MAX.
    @var VidyoClientRequestSnapResize::sizingmethod [in]
		Constraints on prospective resize operation.  See definition of
		#VidyoClientResizingMethod.
*/ 
typedef struct VidyoClientRequestSnapResize_
{
    VidyoUint width; 
    VidyoUint height; 
    VidyoUint curWidth;
    VidyoUint curHeight;
    VidyoUint minWidth;
    VidyoUint minHeight;
    VidyoUint maxWidth;
    VidyoUint maxHeight;
    VidyoClientResizingMethod sizingmethod; 
} VidyoClientRequestSnapResize;

/*! Request structure
	
	- Sent by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_IN
		+ #VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_OUT
		+ #VIDYO_CLIENT_REQUEST_GET_MUTED_VIDEO
		+ #VIDYO_CLIENT_REQUEST_GET_MUTED_SERVER_AUDIO_IN
		+ #VIDYO_CLIENT_REQUEST_GET_MUTED_SERVER_VIDEO
*/
typedef struct VidyoClientRequestGetMuted_
{
	/*!
		VIDYO_TRUE if local media device for specified request muted, VIDYO_FALSE if local
		media device for specified request not muted.  Use
		#VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_IN to check local muting of microphone device,
		#VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_OUT to check local muting of speaker device,
		and #VIDYO_CLIENT_REQUEST_GET_MUTED_VIDEO to check local muting of camera device.
		Use #VIDYO_CLIENT_REQUEST_GET_MUTED_SERVER_AUDIO_IN to check remote muting of microphone
		device.
	*/
	VidyoBool isMuted;
} VidyoClientRequestGetMuted;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_LANGUAGE
*/
typedef struct VidyoClientRequestGetLanguage_
{
	/*! Currently selected display language.  See definition of VidyoClientLanguageCode. */
	VidyoClientLanguageCode Languagecode;
} VidyoClientRequestGetLanguage;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_SECURE_CONNECTION
*/
typedef struct VidyoClientRequestSecureConnection_
{
	/*! Secure connection state */
	VidyoUint secureConnectionState;
	/*! Certificate */
	VidyoUint8 verifyCertPortalAcct[MAX_PORTAL_ADDRESS];
} VidyoClientRequestSecureConnection;

/*! @struct VidyoClientRequestEchoRecommendation
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_ECHO_RECOMMENDATION

	@var VidyoClientRequestEchoRecommendation::speakerIndex [in]
		Selected speaker index.
	@var VidyoClientRequestEchoRecommendation::micIndex [in]
		Selected Mic index.
	@var VidyoClientRequestEchoRecommendation::echoDisabled [out]
		Echo disabled recommendation (VIDYO_TRUE or VIDYO_FALSE.).
*/
typedef struct VidyoClientRequestEchoRecommendation_
{
	VidyoUint speakerIndex;
	VidyoUint micIndex;
	VidyoBool echoDisabled;
} VidyoClientRequestEchoRecommendation;

/*! @struct VidyoClientRequestCheckRecommended
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_CHECK_RECOMMENDED

	@var VidyoClientRequestCheckRecommended::deviceType [in] 
		Selected device type - #VIDYO_CLIENT_DEVICE_TYPE_AUDIO_OUT or #VIDYO_CLIENT_DEVICE_TYPE_AUDIO_IN.
	@var VidyoClientRequestCheckRecommended::deviceIndex [in]
		Selected device index.
	@var VidyoClientRequestCheckRecommended::isRecommended [out]
		Device is recommended or NOT (VIDYO_TRUE or VIDYO_FALSE.)
*/
typedef struct VidyoClientRequestCheckRecommended_
{
	VidyoClientDeviceType deviceType;
	VidyoUint deviceIndex;
	VidyoBool isRecommended;
} VidyoClientRequestCheckRecommended;

/*! @struct VidyoClientRequestWebProxySettingValid
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_WEB_PROXY_SETTING_VALID

	@var VidyoClientRequestWebProxySettingValid::isConfigComplete [out]
		VIDYO_TRUE if web proxy configuration is complete, VIDYO_FALSE otherwise.
*/
typedef struct VidyoClientRequestWebProxySettingValid_
{
	VidyoBool isConfigComplete;
} VidyoClientRequestWebProxySettingValid;

/*! @struct VidyoClientRequestWebProxySetUsernamePassword 
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_SET_WEBPROXY_USERNAME_PASSWORD

	@var VidyoClientRequestWebProxySetUsernamePassword::isSaved [in] 
		@details VIDYO_TRUE if the values are to be saved in Configuration, VIDYO_FALSE if volatile
	@var VidyoClientRequestWebProxySetUsernamePassword::webProxyUsername [in,out]
		Web proxy username, used when parameter proxySettings does set bit for PROXY_WEB_ENABLE.
	@var VidyoClientRequestWebProxySetUsernamePassword::webProxyPassword [in,out]
		Web proxy password, used when parameter proxySettings does set bit for PROXY_WEB_ENABLE.
*/
typedef struct VidyoClientRequestWebProxySetUsernamePassword_
{
	VidyoBool isSaved;
	VidyoUint8 webProxyUsername[FIELD_SIZE];
	VidyoUint8 webProxyPassword[FIELD_SIZE];
} VidyoClientRequestWebProxySetUsernamePassword;

/*! @struct VidyoClientRequestCurrentUser
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CURRENT_USER

	@var VidyoClientRequestCurrentUser::currentUserID [out]
		User ID of currently signed in user.
	@var VidyoClientRequestCurrentUser::currentUserDisplay [out]
		Display name of currently signed in user.
*/
typedef struct VidyoClientRequestCurrentUser_
{
	char currentUserID[USERID_SIZE];
	char currentUserDisplay[USERID_SIZE];
} VidyoClientRequestCurrentUser;

/*!	@struct VidyoClientRequestCallState
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CALL_STATE

	@var	VidyoClientRequestCallState::callState [out]
			Current call state of client @see #VidyoClientCallState
*/
typedef struct VidyoClientRequestCallState_
{
	VidyoClientCallState callState;
} VidyoClientRequestCallState;
/*! @struct VidyoClientRequestSessionDisplayInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CURRENT_SESSION_DISPLAY_INFO

	@var VidyoClientRequestSessionDisplayInfo::sessionDisplayContext [out]
		Current conference state of client.  See definition of VidyoClientSessionDisplayContext.
	@var VidyoClientRequestSessionDisplayInfo:: sessionDisplayText [out]
		If client is in a conference, current text which could be displayed in a window
		caption, to identify the conference to the user.  Encoded as UTF-8.
*/
typedef struct VidyoClientRequestSessionDisplayInfo_
{
	VidyoClientSessionDisplayContext sessionDisplayContext;
	char sessionDisplayText[DISPLAY_CONFERENCE_SIZE];
} VidyoClientRequestSessionDisplayInfo;

/*! @struct VidyoClientRequestParticipantsLimit
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS_LIMIT

	@var VidyoClientRequestParticipantsLimit::bandwidthLimit [out]
		Maximum number of viewable remote participants in video layout, due to current network
		bandwidth.  Range of values 0~16.
	@var VidyoClientRequestParticipantsLimit::cpuLimit [out]
		Maximum number of viewable remote participants in video layout, due to current CPU
		utilization.  Range of values 0~16.
	@var VidyoClientRequestParticipantsLimit::userLimit [out]
		Maximum number of viewable remote participants in video layout, due to use of
		event #VIDYO_CLIENT_IN_EVENT_PARTICIPANTS_LIMIT.  Range of values 0~8 and 16.
*/
typedef struct VidyoClientRequestParticipantsLimit_
{
	VidyoUint bandwidthLimit;
	VidyoUint cpuLimit;
	VidyoUint userLimit;
} VidyoClientRequestParticipantsLimit;

/*! @struct VidyoClientRequestParticipants
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS

	@var VidyoClientRequestParticipants::name [out]
		Array of values for display name of remote participants in a conference.  Encoded as
		UTF-8.
	@var VidyoClientRequestParticipants::URI [out]
		Array of values for Vidyo URI of remote participants in a conference.
	@var VidyoClientRequestParticipants::numberParticipants [out]
		Number of remote participants in a conference.  Range of values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestParticipants_
{
	char name[MAX_PARTICIPANTS_NUM][FIELD_SIZE];
	char URI[MAX_PARTICIPANTS_NUM][URI_LEN];
	VidyoUint numberParticipants;
} VidyoClientRequestParticipants;

/*! @struct VidyoClientRequestInvitingUser
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_INVITING_USER

	@var VidyoClientRequestInvitingUser::invitingUser [out]
		Display name of originator of inbound call.  Encoded as UTF-8.
*/
typedef struct VidyoClientRequestInvitingUser_
{
	char invitingUser[FIELD_SIZE];
} VidyoClientRequestInvitingUser;

/*! @struct VidyoClientRequestSessionVidyoRouter
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CURRENT_SESSION_VIDYO_ROUTER

	@var VidyoClientRequestSessionVidyoRouter::routerAddress [out]
		Router address.
*/
typedef struct VidyoClientRequestSessionVidyoRouter_
{
	char routerAddress[SERVER_ADDRESS_SIZE];
} VidyoClientRequestSessionVidyoRouter;

/*! @struct VidyoClientRequestFeccList
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_FECC_LIST

	@var VidyoClientRequestFeccList::uri [out]
		Array of Vidyo URI values, one for each remote participant 
		that can have its camera controlled.
	@var VidyoClientRequestFeccList::name [out]
		Array of usernames, one for each remote participant 
		that can have its camera controlled.
	@var VidyoClientRequestFeccList::privacyMode [out]
		Array of LMI_TRUE or LMI_FALSE value representing privacy ON(=LMI_TRUE) or OFF(=LMI_FALSE) status, 
		one for each remote participant that can have its camera controlled.
	@var VidyoClientRequestFeccList::numberParticipants [out]
		Number of Vidyo URI values in parameter uri. Range from 0 to MAX_PARTICIPANTS_NUM.
	@var VidyoClientRequestFeccList::feccParticipantIndex [out]
		The current participant under FECC. If no participant in being controlled value is MAX_PARTICIPANTS_NUM. Range from 0 to MAX_PARTICIPANTS_NUM.
*/
typedef struct VidyoClientRequestFeccList_
{
	char uri[MAX_PARTICIPANTS_NUM][URI_LEN];
	char name[MAX_PARTICIPANTS_NUM][USERID_SIZE];
	VidyoBool privacyMode[MAX_PARTICIPANTS_NUM];
	VidyoUint numberParticipants;
	VidyoUint feccParticipantIndex;
} VidyoClientRequestFeccList;

/*! @struct VidyoClientRequestConferenceInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_CONFERENCE_INFO

	@var VidyoClientRequestConferenceInfo::recording [out] 
		VIDYO_TRUE or VIDYO_FALSE to indicate whether conference is recording or not.
	@var VidyoClientRequestConferenceInfo::webcast [out]
		VIDYO_TRUE or VIDYO_FALSE to indicate whether conference is webcast or not.
*/
typedef struct VidyoClientRequestConferenceInfo_
{
	VidyoBool recording;
	VidyoBool webcast;
} VidyoClientRequestConferenceInfo;

/*! @struct VidyoClientRequestBandwidthInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_BANDWIDTH_INFO

	@var VidyoClientRequestBandwidthInfo::AvailSendBwVideo [out]
		Available bandwidth for sending video data, in units of kilobits per second.  Range of
		values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailSendBwAudio [out]
		Available bandwidth for sending audio data, in units of kilobits per second.  Range of
		values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailSendBwApplication [out]
		Available bandwidth for sending application window sharing data, in units of kilobits
		per second.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailSendBwMax [out]
		Available bandwidth for sending all media data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualSendBwVideo [out]
		Actual bandwidth for sending video data, in units of kilobits per second.  Range of
		values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualSendBwAudio [out]
		Actual bandwidth for sending audio data, in units of kilobits per second.  Range of
		values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualSendBwApplication [out]
		Actual bandwidth for sending application window sharing data, in units of kilobits
		per second.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualSendBwMax [out]
		Actual bandwidth for sending all media data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailRecvBwVideo [out]
		Available bandwidth for receiving video data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailRecvBwAudio [out]
		Available bandwidth for receiving audio data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailRecvBwApplication [out]
		Available bandwidth for receiving application window sharing data, in units of kilobits
		per second.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::AvailRecvBwMax [out]
		Available bandwidth for receiving all media data, in units of kilobits per second.
		Range of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualRecvBwVideo [out]
		Actual bandwidth for receiving video data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualRecvBwAudio [out]
		Actual bandwidth for receiving audio data, in units of kilobits per second.  Range
		of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualRecvBwApplication [out]
		Actual bandwidth for receiving application window sharing data, in units of kilobits
		per second.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestBandwidthInfo::ActualRecvBwMax [out]
		Actual bandwidth for receiving all media data, in units of kilobits per second.
		Range of values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestBandwidthInfo_
{
	VidyoUint AvailSendBwVideo;
	VidyoUint AvailSendBwAudio;
	VidyoUint AvailSendBwApplication;
	VidyoUint AvailSendBwMax;
	VidyoUint ActualSendBwVideo;
	VidyoUint ActualSendBwAudio;
	VidyoUint ActualSendBwApplication;
	VidyoUint ActualSendBwMax;
	VidyoUint AvailRecvBwVideo;
	VidyoUint AvailRecvBwAudio;
	VidyoUint AvailRecvBwApplication;
	VidyoUint AvailRecvBwMax;
	VidyoUint ActualRecvBwVideo;
	VidyoUint ActualRecvBwAudio;
	VidyoUint ActualRecvBwApplication;
	VidyoUint ActualRecvBwMax;
} VidyoClientRequestBandwidthInfo;

/*! @struct VidyoClientRequestFrameRateInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_VIDEO_FRAME_RATE_INFO

    @var VidyoClientRequestFrameRateInfo::captureFrameRate [out]
		Current frame rate of video as captured from the local device, in frames per second.
		Range of values 0~UINT_MAX.
    @var VidyoClientRequestFrameRateInfo::encodeFrameRate [out]
		Current frame rate of video as encoded, in frames per second.  Range of values
		0~UINT_MAX.
    @var VidyoClientRequestFrameRateInfo::sendFrameRate [out]
		Current frame rate of video as sent over the network, in frames per second.  Range of
		values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestFrameRateInfo_
{
    VidyoUint captureFrameRate;
    VidyoUint encodeFrameRate;
    VidyoUint sendFrameRate;
} VidyoClientRequestFrameRateInfo;

/*! @struct VidyoClientRequestMediaInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_MEDIA_INFO

	@var VidyoClientRequestMediaInfo::numIFrames [out]
		Total number of I-frames sent from the client, since the beginning of the current
		conference.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestMediaInfo::numFirs [out]
		Total number of FIR (Full Intra Request) messages received by the client, since the
		beginning of the current conference.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestMediaInfo::numNacks [out]
		Total number of distinct NACK (No ACKnowledgement) messages received by the client,
		since the beginning of the current conference.  Only NACK messages received for
		sequence numbers that are reasonably close to the most recent packet sent are counted.
		Range of values 0~UINT_MAX.
	@var VidyoClientRequestMediaInfo::mediaRTT [out]
		Current estimate of round-trip time for media packets, based on RTCP interactions,
		in units of milliseconds.  Range of values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestMediaInfo_
{
	VidyoUint numIFrames;
	VidyoUint numFirs;
	VidyoUint numNacks;
	VidyoUint mediaRTT;
} VidyoClientRequestMediaInfo;

/*! @struct VidyoClientRequestRateShaperInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_RATE_SHAPER_INFO

	@var VidyoClientRequestRateShaperInfo::delayVideoPriorytyNormal [out]
   		Maximum actual delay of packets flowing through normal priority rate shaper queue,
		for sent video data, in units of milliseconds.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numPacketsVideoPriorytyNormal [out]
   		Current number of packets in normal priority rate shaper queue, for sent video data.
		Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numFramesVideoPriorytyNormal [out]
   		Reserved for future use.
	@var VidyoClientRequestRateShaperInfo::numDroppedVideoPriorytyNormal [out]
   		Total number of packets dropped from normal priority rate shaper queue for current
		conference, for sent video data.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::delayVideoPriorutyRetransmit [out]
   		Maximum actual delay of packets flowing through high priority rate shaper queue,
		for sent video data, in units of milliseconds.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numPacketsVideoPriorutyRetransmit [out]
   		Current number of packets in high priority rate shaper queue, for sent video data.
		Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numFramesVideoPriorutyRetransmit [out]
   		Reserved for future use.
	@var VidyoClientRequestRateShaperInfo::numDroppedVideoPriorutyRetransmit [out]
   		Total number of packets dropped from high priority rate shaper queue for current
		conference, for sent video data.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::delayAppPriorityNormal [out]
   		Maximum actual delay of packets flowing through normal priority rate shaper queue,
		for sent application window sharing data, in units of milliseconds.  Range of values
		0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numPacketsAppPriorityNormal [out]
   		Current number of packets in normal priority rate shaper queue, for sent application
		window sharing data.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numFramesAppPriorityNormal [out]
   		Reserved for future use.
	@var VidyoClientRequestRateShaperInfo::numDroppedAppPriorityNormal [out]
   		Total number of packets dropped from normal priority rate shaper queue for current
		conference, for sent application window sharing data.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::delayAppPriorityRetransmit [out]
   		Maximum actual delay of packets flowing through high priority rate shaper queue,
		for sent application window sharing data, in units of milliseconds.  Range of
		values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numPacketsAppPriorityRetransmit [out]
   		Current number of packets in high priority rate shaper queue, for sent application
		window sharing data.  Range of values 0~UINT_MAX.
	@var VidyoClientRequestRateShaperInfo::numFramesAppPriorityRetransmit [out]
   		Reserved for future use.
	@var VidyoClientRequestRateShaperInfo::numDroppedAppPriorityRetransmit [out]
   		Total number of packets dropped from high priority rate shaper queue for current
		conference, for sent application window sharing data.  Range of values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestRateShaperInfo_
{
	 VidyoUint delayVideoPriorytyNormal;
	 VidyoUint numPacketsVideoPriorytyNormal;
	 VidyoUint numFramesVideoPriorytyNormal;
	 VidyoUint numDroppedVideoPriorytyNormal;
	 VidyoUint delayVideoPriorutyRetransmit;
	 VidyoUint numPacketsVideoPriorutyRetransmit;
	 VidyoUint numFramesVideoPriorutyRetransmit;
	 VidyoUint numDroppedVideoPriorutyRetransmit;
	 VidyoUint delayAppPriorityNormal;
	 VidyoUint numPacketsAppPriorityNormal;
	 VidyoUint numFramesAppPriorityNormal;
	 VidyoUint numDroppedAppPriorityNormal;
	 VidyoUint delayAppPriorityRetransmit;
	 VidyoUint numPacketsAppPriorityRetransmit;
	 VidyoUint numFramesAppPriorityRetransmit;
	 VidyoUint numDroppedAppPriorityRetransmit;
} VidyoClientRequestRateShaperInfo;

/*! @struct VidyoClientRequestParticipantInfo
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_INFO

	@var VidyoClientRequestParticipantInfo::Name [out]
		Array of values for display name of remote participants in a conference.  Encoded as
		UTF-8.
	@var VidyoClientRequestParticipantInfo::URI [out]
		Array of values for Vidyo URI of remote participants in a conference.
	@var VidyoClientRequestParticipantInfo::bytesRcvd [out]
   		Reserved for future use.
	@var VidyoClientRequestParticipantInfo::numFirsSent [out]
   		Reserved for future use.
	@var VidyoClientRequestParticipantInfo::numNacksSent [out]
   		Reserved for future use.
	@var VidyoClientRequestParticipantInfo::numDistinctNacksSent [out]
   		Reserved for future use.
	@var VidyoClientRequestParticipantInfo::receivedFrameRate [out]
		Array of values for current received frame rate (units of frames per second) of remote
		participants in a conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::decodedFrameRate [out]
		Array of values for current decoded frame rate (units of frames per second) of remote
		participants in a conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::displayedFrameRate [out]
		Array of values for current displayed frame rate (units of frames per second) of remote
		participants in a conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::receivedPacketRate [out]
   		Received rate of packet. *Not currently implemented*.
	@var VidyoClientRequestParticipantInfo::receivedBpsVideo [out]
   		Received payload.
	@var VidyoClientRequestParticipantInfo::receivedBpsAudio [out]
   		Reserved for future use.
	@var VidyoClientRequestParticipantInfo::receivedWidth [out]
		Array of values for current received width of video stream of remote participants in a
		conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::receivedHeight [out]
		Array of values for current received height of video stream of remote participants in a
		conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::receivedBytesVideo [out]
		Array of values for total received bytes of video data of remote participants in a
		conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::receivedBytesAudio [out]
		Array of values for total received bytes of audio data of remote participants in a
		conference.  Range of values 0~SIZE_MAX.
	@var VidyoClientRequestParticipantInfo::numberParticipants  [out]
		Number of remote participants in a conference.  Range of values 0~UINT_MAX.
*/
typedef struct VidyoClientRequestParticipantInfo_
{
	char Name[MAX_PARTICIPANTS_NUM][FIELD_SIZE];
	char URI[MAX_PARTICIPANTS_NUM][URI_LEN];
	VidyoSizeT bytesRcvd[MAX_PARTICIPANTS_NUM];
	VidyoSizeT numFirsSent[MAX_PARTICIPANTS_NUM];
	VidyoSizeT numNacksSent[MAX_PARTICIPANTS_NUM];
	VidyoSizeT numDistinctNacksSent[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedFrameRate[MAX_PARTICIPANTS_NUM];
	VidyoSizeT decodedFrameRate[MAX_PARTICIPANTS_NUM];
	VidyoSizeT displayedFrameRate[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedPacketRate[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedBpsVideo[MAX_PARTICIPANTS_NUM];  /* receivedPayload */
	VidyoSizeT receivedBpsAudio[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedWidth[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedHeight[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedBytesVideo[MAX_PARTICIPANTS_NUM];
	VidyoSizeT receivedBytesAudio[MAX_PARTICIPANTS_NUM];
	VidyoUint numberParticipants;
} VidyoClientRequestParticipantInfo;

/*! @struct VidyoClientRequestGetNumParticipants
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_NUM_PARTICIPANTS

	@var VidyoClientRequestGetNumParticipants::numParticipants [out]
		Total number of participants in a conference call.
*/
typedef struct VidyoClientRequestGetNumParticipants_
{
	VidyoSizeT numParticipants;
} VidyoClientRequestGetNumParticipants;

/*! @struct VidyoClientRequestGetParticipantNameAt
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_NAME_AT

	@var VidyoClientRequestGetParticipantNameAt::index [in]
		Index of conference participant whose name to be retrieved.
	@var VidyoClientRequestGetParticipantNameAt::result [out]
		Success (VIDYO_TRUE) or failure (VIDYO_FALSE).
		Name is valid only when result is VIDYO_TRUE.  If value of
		result is VIDYO_FALSE, it means there is no participant at
		the given location/index.
	@var VidyoClientRequestGetParticipantNameAt::name [out]
		Participant's display name.
*/
typedef struct VidyoClientRequestGetParticipantNameAt_
{
	VidyoUint index;
	VidyoBool result;
	char name[USERID_SIZE];
} VidyoClientRequestGetParticipantNameAt;

/*! @struct VidyoClientParticipantStatistics
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_STATISTICS_AT

	@var VidyoClientParticipantStatistics::uri [out]
		URI of conference participant.
	@var VidyoClientParticipantStatistics::name [out]
		Display name of conference participant.
	@var VidyoClientParticipantStatistics::videoResolution [out]
		Received video resolution, as width by height.
	@var VidyoClientParticipantStatistics::videoKBitsPerSecRecv [out]
		Received video in kBPS.
	@var VidyoClientParticipantStatistics::audioKBitsPerSecRecv [out]
		Received audio in kBPS.
	@var VidyoClientParticipantStatistics::firs [out]
		Number of FIR packets.
	@var VidyoClientParticipantStatistics::nacks [out]
		Number of NACK packets.
	@var VidyoClientParticipantStatistics::videoFrameRate [out]
		Video frame rate.
	@var VidyoClientParticipantStatistics::videoDecodedFrameRate [out]
		Decoded video frame rate.
	@var VidyoClientParticipantStatistics::videoDisplayedFrameRate [out]
		Displayed Video frame rate.
*/
typedef struct VidyoClientParticipantStatistics_
{
	char uri[MAX_URI_LEN];
	char name[USERID_SIZE];
	VidyoRect videoResolution;
	VidyoUint videoKBitsPerSecRecv;
	VidyoUint audioKBitsPerSecRecv;
	VidyoUint firs;
	VidyoUint nacks;
	VidyoUint videoFrameRate;
	VidyoUint videoDecodedFrameRate;
	VidyoUint videoDisplayedFrameRate;
} VidyoClientParticipantStatistics;

/*! @struct VidyoClientRequestParticipantStatisticsAt
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_STATISTICS_AT

	@var VidyoClientRequestParticipantStatisticsAt::index [in]
		Index of conference participant whose statistics
		to be retrieved.
	@var VidyoClientRequestParticipantStatisticsAt::result [out]
		Success (VIDYO_TRUE) or failure (VIDYO_FALSE).
		Contents are valid only when result is VIDYO_TRUE. If
		value of result is VIDYO_FALSE, means there is no
		participant at the given location/index.
	@var VidyoClientRequestParticipantStatisticsAt::statistics [out]
		Statistics parameters.
*/
typedef struct VidyoClientRequestParticipantStatisticsAt_
{
	VidyoUint index;
	VidyoBool result;
	VidyoClientParticipantStatistics statistics;
} VidyoClientRequestParticipantStatisticsAt;

/*!	@struct VidyoClientRequestGetParticipantNameList
	Used for retrieving participant's display name.
	A list of maxmum MAX_GET_PARTICIPANT_NAME will
	be retried starting from the participant identified 
	by an index.
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_NAME_LIST

	@var VidyoClientRequestGetParticipantNameList::startIndex [in]
	Index of conference participant from
	where the list should start. 
	@var VidyoClientRequestGetParticipantNameList::numParticipants [out]
	Number of participants names included
	in this message. If the value is 0, there are no participants 
	starting from the given startIndex.
	@var VidyoClientRequestGetParticipantNameList::name [out]
	Participant's display name list.
*/
typedef struct VidyoClientRequestGetParticipantNameList_
{
	VidyoUint startIndex;
	VidyoUint numParticipants;
	char name[MAX_GET_PARTICIPANT_NAME][USERID_SIZE];
} VidyoClientRequestGetParticipantNameList;

/*! @struct VidyoClientRequestParticipantStatisticsList
	Used for retrieving statistics of a list of conference participants.
	A maximum of MAX_GET_PARTICIPANT_STATISTICS participant's
	statistics can be retrieved using one message.
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_STATISTICS_LIST

	@var VidyoClientRequestParticipantStatisticsList::startIndex [in]
	Starting index of conference participant starting
	from where the statistics to be retrieved.
	@var VidyoClientRequestParticipantStatisticsList::numParticipants [out]
	Number of participant's statistics included
	in this message. If the value is 0, there are no participants 
	starting from the given startIndex.
	@var VidyoClientRequestParticipantStatisticsList::statistics [out]
	Statistics parameters of each participants.	
*/
typedef struct VidyoClientRequestParticipantStatisticsList_
{
	VidyoUint startIndex;
	VidyoUint numParticipants;
	VidyoClientParticipantStatistics statistics[MAX_GET_PARTICIPANT_STATISTICS];
} VidyoClientRequestParticipantStatisticsList;

/*! @struct VidyoClientRequestGetDisplayString
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_DISPLAY_STRING

	@var VidyoClientRequestGetDisplayString::enumStringID [in]
		Numeric ID (usually based on enumeration type) of display string requested, for
		currently set display language.  Range of allowed values 0 to a maximum, that is
		dependent on number of strings originally registered by GUI, at time of call to
		#VidyoClientStart().
	@var VidyoClientRequestGetDisplayString::StringDisplayText [out]
		Pointer to display string requested, for currently set display language.  No
		modification of the storage accessed by this pointer should be attempted.  Encoding
		of string based on strings originally registered by GUI, at time of call to
		#VidyoClientStart().
*/
typedef struct VidyoClientRequestGetDisplayString_
{
	VidyoUint enumStringID;
	VidyoVoidPtr StringDisplayText;
} VidyoClientRequestGetDisplayString;

#ifndef DOXYGEN_SHOULD_IGNORE_THIS

/*! Camera location enumeration for mobile devices

	- Passed in field _previewMode_ of following structs:
		+ #VidyoClientDeviceInfo
*/
typedef enum 
{
	VIDYO_VIDEOCAPTURERLOCATION_Front,
	VIDYO_VIDEOCAPTURERLOCATION_Back
}
VidyoVideoCapturerLocation;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_DEVICES_FROM_MANAGER
*/
typedef struct VidyoClientDeviceInfo_
{
	/*! Name of device. */
	VidyoUint8 name[DEVICE_NAME_SIZE];
	/*! Identity of device */
	VidyoUint8 id[DEVICE_ID_SIZE];
	/*! Properties of device */
	VidyoUint  properties;
	/*! Device Location */
	VidyoVideoCapturerLocation location;
} VidyoClientDeviceInfo;

/*! Request structure
	
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_DEVICES_FROM_MANAGER
*/
typedef struct VidyoClientRequestDevices_
{
	/*! Device information - Reserved for internal use. */
	VidyoClientDeviceInfo deviceInfo[MAX_DEVICE_NUMBER];
	/*! Reserved for internal use. */
	VidyoUint numberDevices;
	/*! Reserved for internal use. */
	VidyoUint currentDevice;
	/*! Reserved for internal use. */
	VidyoClientDeviceType deviceType;
} VidyoClientRequestDevices;
#endif

/*! @struct VidyoClientRequestGetEndpointStatus
	Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_ENDPOINT_STATUS

	@var VidyoClientRequestGetEndpointStatus::endPointStatus [out] 
		Status of endpoint.
*/
typedef struct VidyoClientRequestGetEndpointStatus_
{
	VidyoClientEndpointStatus endPointStatus;
} VidyoClientRequestGetEndpointStatus;

/*!	@struct VidyoClientRequestSetLayoutRect
	Request structure
 	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_SET_LAYOUT_RECT
*/
typedef struct VidyoClientRequestSetLayoutRect_
{
	/*!	Top left X coordinate of layout rectangle */
	VidyoUint xPos;
	/*! Top left Y coordinate of layout rectangle */
	VidyoUint yPos;
	/*! Width of the layout rectangle */
	VidyoUint width;
	/*! Height of the layout rectangle */
	VidyoUint height;
} VidyoClientRequestSetLayoutRect;

/*! @struct VidyoClientRequestSetLogLevelsAndCategories
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_SET_LOG_LEVELS_AND_CATEGORIES
	@var VidyoClientRequestSetLogLevelsAndCategories::levelsAndCategories [in] 
	New setting for log levels and categories.
*/
typedef struct VidyoClientRequestSetLogLevelsAndCategories_
{
	char levelsAndCategories[MAX_LOG_STRING_SIZE];
} VidyoClientRequestSetLogLevelsAndCategories;

/*!	@struct	VidyoClientRequestGetDockCounts
	Request structure
 	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS
*/
typedef struct VidyoClientRequestGetDockCounts_
{
	/*! The number of application shares currently docked */
	VidyoUint numApplicationsDocked;
	VidyoBool isApplicationDockVisible;
	/*! The number of participant videos currently docked */
	VidyoUint numParticipantsDocked;
	VidyoBool isParticipantDockVisible;
} VidyoClientRequestGetDockCounts;

/*!	@struct	VidyoClientRequestGetWindowsAndDesktops
	Request structure
 	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_GET_WINDOWS_AND_DESKTOPS
*/
typedef struct VidyoClientRequestGetWindowsAndDesktops_
{
	/*! The number of application windows currently open */
	VidyoSizeT numApplicationWindows;
	/*! List of open application window names (UTF-8) (Localized) */
	char appWindowName[MAX_NUM_APP_WINDOWS][MAX_URI_LEN];
	/*! List of open application window handles */
	VidyoWindowCapturerWindowId appWindowId[MAX_NUM_APP_WINDOWS];
	/*! The number of system desktops currently available */
	VidyoSizeT numSystemDesktops;
	/*! List of available system desktop names (UTF-8) (Not localized) */
	char sysDesktopName[MAX_SHARE_DISPLAY_DEVICE][MAX_URI_LEN];
	/*! List of open application window handles */
	VidyoWindowCapturerWindowId sysDesktopId[MAX_SHARE_DISPLAY_DEVICE];
} VidyoClientRequestGetWindowsAndDesktops;

/*!	Event structure
	- Used by following in events:
		+ #VIDYO_CLIENT_REQUEST_SET_BACKGROUND
*/
typedef struct VidyoClientRequestSetBackground_
{
	/*!
		VIDYO_TRUE to enable backgrounded state, VIDYO_FALSE otherwise.
		When in backgrounded state during a conference, video and application window
		sharing streams are not requested from the server, and no rendering of
		those media types is performed.  Also, video capture is not performed.
		Audio capture continues, and received audio streams continue to be mixed and
		played back.
	*/
	VidyoBool willBackground;
} VidyoClientRequestSetBackground;


#ifndef DOXYGEN_SHOULD_IGNORE_THIS
/*! Request structure
	- Used by following requests:
		+ #VIDYO_CLIENT_REQUEST_PRIVATE
*/
typedef struct VidyoClientRequestPrivate_
{
	/*! (Reserved for private requests only used by standard Vidyo clients) */
	VidyoUint requestType;
	/*! (Reserved for private requests only used by standard Vidyo clients) */
	VidyoVoidPtr requestData;
	/*! (Reserved for private requests only used by standard Vidyo clients) */
	VidyoSizeT requestDataSize;
	/*! (Reserved for private requests only used by standard Vidyo clients) */
	VidyoSizeT reserved;
} VidyoClientRequestPrivate;
#endif

#endif /* VIDYO_CLIENT_PARAMETERS_H */

