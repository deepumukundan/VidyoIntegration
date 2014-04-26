//
//  Vidyo Integration 
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#ifndef VidyoIntegration_VidyoConstants_h
#define VidyoIntegration_VidyoConstants_h

// Exposed properties for information pass and flow control 
#define kVidyoDynamicNotification   @"dynamicNotification"
#define kVidyoIsSigningIn           @"isSigningIn"
#define kVidyoIsJoiningConference   @"isJoiningConference"

// Server response types
#define kResponseTypeLoginAsGuest           @"LogInAsGuestResponse"
#define kResponseTypeLinkEndpointToGuest    @"LinkEndpointToGuestResponse"
#define kResponseTypeMyAccount              @"MyAccountResponse"
#define kResponseTypeErrorMessage           @"ErrorMessage"

// Shared response elements
#define kResponseElementisLocked        @"isLocked"

// LogInAsGuestResponse elements
#define kResponseElementGuestID         @"guestID"
#define kResponseElementhasPin          @"hasPin"
#define kResponseElementvmaddress       @"vmaddress"
#define kResponseElementproxyaddress    @"proxyaddress"
#define kResponseElementloctag          @"loctag"
#define kResponseElementun              @"un"
#define kResponseElementpak             @"pak"
#define kResponseElementportal          @"portal"
#define kResponseElementportalVersion   @"portalVersion"

// MyAccountResponse elements
#define kResponseElementEntityType      @"EntityType"
#define kResponseElementLanguage        @"Language"
#define kResponseElementMemberMode      @"MemberMode"
#define kResponseElementMemberStatus    @"MemberStatus"
#define kResponseElementRoomStatus      @"RoomStatus"
#define kResponseElementappshare        @"appshare"
#define kResponseElementaudio           @"audio"
#define kResponseElementcanCallDirect   @"canCallDirect"
#define kResponseElementcanControl      @"canControl"
#define kResponseElementcanJoinMeeting  @"canJoinMeeting"
#define kResponseElementdisplayName     @"displayName"
#define kResponseElementemailAddress    @"emailAddress"
#define kResponseElemententityID        @"entityID"
#define kResponseElementextension       @"extension"
#define kResponseElementhasModeratorPIN @"hasModeratorPIN"
#define kResponseElementhasPIN          @"hasPIN"
#define kResponseElementisInMyContacts  @"InMyContacts"
#define kResponseElementownerID         @"ownerID"
#define kResponseElementroomURL         @"roomURL"
#define kResponseElementtenant          @"tenant"
#define kResponseElementvideo           @"video"

#endif
