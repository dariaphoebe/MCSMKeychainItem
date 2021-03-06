//
//  MCSMKeychainItem.h
//  MCSMFoundation
//
//  Created by Spencer MacDonald on 12/10/2011.
//  Copyright 2012 Square Bracket Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_MAC && !TARGET_IPHONE_SIMULATOR
#import <Carbon/Carbon.h>
#endif
#import <Security/Security.h>


@interface MCSMKeychainItem : NSObject

#if TARGET_OS_MAC && !TARGET_IPHONE_SIMULATOR

+ (void)lockKeychain;
+ (void)unlockKeychain;

#endif

@property (readonly, copy) NSString *username;
@property (readonly, copy) NSString *password;

- (BOOL)removeFromKeychain;

@end 


@interface MCSMGenericKeychainItem : MCSMKeychainItem

@property (readonly, copy) NSString *service;

+ (MCSMGenericKeychainItem *)genericKeychainItemForService:(NSString *)service
                                                  username:(NSString *)username;

+ (MCSMGenericKeychainItem *)genericKeychainItemWithService:(NSString *)service
                                                   username:(NSString *)username
                                                   password:(NSString *)password;
@end