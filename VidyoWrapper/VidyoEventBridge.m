//
//  Vidyo Integration
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#import <assert.h>
#import <ctype.h>
#import <stdarg.h>
#import <stdio.h>
#import <string.h>
#import <unistd.h>
#import <wchar.h>
#import "VidyoEventBridge.h"
#import "VidyoWrapper.h"

VidyoWrapper *wrapper;

// Callback for out-events from VidyoClient
void vidyoClientWrapperOnVidyoClientEvent(VidyoClientOutEvent event,
                                          VidyoVoidPtr        param,
                                          VidyoUint           paramSize,
                                          VidyoVoidPtr        data) {
	NSString *notificationMsg = nil;
	VidyoClientOutEventLicense *eventLicense;
	VidyoClientOutEventSignIn *eventSignIn;
	wrapper = (__bridge VidyoWrapper *)data;

	notificationMsg = [NSString stringWithFormat:@"Received Event: %u \n", event];
	NSLog(@"%@", notificationMsg);

	if (event >= VIDYO_CLIENT_OUT_EVENT_MIN
	    && event <= VIDYO_CLIENT_OUT_EVENT_MAX) {
		switch (event) {
			case VIDYO_CLIENT_OUT_EVENT_LICENSE:
			{
				/* If there are any issues with Licenses, this event will be sent by the VidyoClient library */
				eventLicense = (VidyoClientOutEventLicense *)param;
				VidyoUint error = eventLicense->error;
				VidyoUint vmConnectionPath = eventLicense->vmConnectionPath;
				VidyoBool OutOfLicenses = eventLicense->OutOfLicenses;
				notificationMsg = [NSString stringWithFormat:@"License Error: errorid=%d vmConnectionPath=%d OutOfLicense=%d", error, vmConnectionPath, OutOfLicenses];
				logMsg(notificationMsg);
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_SIGN_IN:
			{
				eventSignIn = (VidyoClientOutEventSignIn *)param;
				VidyoUint activeEid = eventSignIn->activeEid;
				VidyoBool signinSecured = eventSignIn->signinSecured;
				NSLog(@"activeEid=%d signinSecured=%@", activeEid, signinSecured ? @"Yes" : @"No");
				/*
				 * If the EID is not setup, it will resturn activeEid = 0
				 * in this case, we invoke the license request using below event
				 */
				if (!activeEid)
					(void)VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_LICENSE, NULL, 0);
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_SIGNED_IN:
			{
				/* Dismissing sign in alert */
				if ([wrapper isSigningIn]) {
                    [wrapper dismissToastAlert];
					[wrapper setIsSigningIn:FALSE];
				}
				notificationMsg = @"***** Successfully signed in *****";
				logMsg(notificationMsg);
                
                // TODO - REMOVE
                [wrapper executeMethodInMainThread:@"initiateConference"];
                
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_SIGNED_OUT:
			{
				/* Dismissing sign in alert */
				if ([wrapper isSigningIn]) {
                    [wrapper dismissToastAlert];
					[wrapper setIsSigningIn:FALSE];
				}
				notificationMsg = @"***** You are signed out *****";
				logMsg(notificationMsg);
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_RESIZE:
			{
				notificationMsg = @"***** Vidyo Window Resized *****";
				logMsg(notificationMsg);
				break;
			}
                
			case VIDYO_CLIENT_OUT_EVENT_INCOMING_CALL:
			{
				/* Auto-accept all incoming calls */
				VidyoClientOutEventIncomingCall *incomingCall = (VidyoClientOutEventIncomingCall *)param;
				notificationMsg = [NSString stringWithFormat:@"Incoming call from %@ %s . Accepting.", incomingCall->onCallFlag ? @"user":@"room", incomingCall->invitingUser];
				logMsg(notificationMsg);

				VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_ANSWER, NULL, 0);
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_CONFERENCE_ACTIVE :
            {
                /* TODO - Add logic for joining to a conference logic */
                /* Dismissing joining conference alert */
                if ([wrapper isJoiningConference]) {
                    [wrapper dismissToastAlert];
                    [wrapper setIsJoiningConference:FALSE];
                }
                notificationMsg = @"*** Vidyo Conference is Active ***";
                logMsg(notificationMsg);
                break;
            }

			case VIDYO_CLIENT_OUT_EVENT_ADD_SHARE:
			{
				VidyoClientOutEventAddShare *share = (VidyoClientOutEventAddShare *)param;
				VidyoClientRequestWindowShares shares = { 0 };
				VidyoUint error;

				shares.requestType = LIST_SHARING_WINDOWS;
				error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES, (void *)&shares, sizeof(VidyoClientRequestWindowShares));
				if (error != VIDYO_CLIENT_ERROR_OK) {
					notificationMsg = [NSString stringWithFormat:@"Failed to send a request for window shares. Error response %u", error];
					logMsg(notificationMsg);
					break;
				}
				/* See if we have a share in a list. If we do set current share to a new one. */
				for (int i = 1 /* index starts from 1 */; i <= shares.shareList.numApp; i++) {
					if (strcmp(shares.shareList.remoteAppUri[i], share->URI) == 0) {
						shares.requestType = ADD_SHARING_WINDOW;
						shares.shareList.currApp = shares.shareList.newApp = i;
						error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_WINDOW_SHARES, (void *)&shares, sizeof(VidyoClientRequestWindowShares));
						if (error != VIDYO_CLIENT_ERROR_OK) {
							notificationMsg = [NSString stringWithFormat:@"Failed to send a request to change window share. Error response %u", error];
							logMsg(notificationMsg);
							break;
						}
						break;
					}
				}
				notificationMsg = @"Share URL is not found in the share list";
				logMsg(notificationMsg);
				break;
			}

			case VIDYO_CLIENT_OUT_EVENT_PARTICIPANTS_CHANGED:
			{
				break;
			}

			default:
				break;
		}
	}
	else {
		NSLog(@"%@", [NSString stringWithFormat:@"Unknown event %d", event]);
	}
}

void logMsg(NSString *msg) {
	wrapper.dynamicNotification = msg;
	NSLog(@"%@", msg);
}
