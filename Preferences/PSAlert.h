/**
 * This header is generated by class-dump-z 0.1-11s.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/Preferences.framework/Preferences
 */

#import <Foundation/NSObject.h>

@class NSString;

@interface PSAlert : NSObject {
	id _delegate;
	id _userInfo;
	NSString* _body;
	NSString* _title;
	NSString* _defaultButton;
	NSString* _alternateButton;
	int _buttonClicked;
	BOOL _displayed;
}
@property(retain) id bodyText;
@property(retain) NSString* title;
@property(retain) NSString* defaultButton;
@property(retain) NSString* alternateButton;
@property(retain) id userInfo;
+(id)alertWithBodyText:(id)bodyText defaultButton:(id)button alternateButton:(id)button3;
+(void)displayAlertWithBodyText:(id)bodyText defaultButton:(id)button alternateButton:(id)button3 delegate:(id)delegate userInfo:(id)info;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(void)setDelegate:(id)delegate;
-(id)alertSheet;
-(void)display;
-(void)dismiss;
-(void)alertSheet:(id)sheet buttonClicked:(int)clicked;
@end

