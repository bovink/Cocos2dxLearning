//
// Created by 吴宗刚 on 2018/9/19.
//

#include "CallNativeInterface.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS && !defined(CC_TARGET_OS_TVOS)

#include "CallIOS.h"

@implementation IOSObject {

}

-(void) printInfo:(string&) s {

    NSString *errorMessage = [NSString stringWithCString:s.c_str()
                                           encoding:[NSString defaultCStringEncoding]];
    NSLog(@"%@",errorMessage);

}

-(void) showToast {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Do you want to say hello?"
                                                    message:@"More info..."
                                                   delegate:self
                                          cancelButtonTitle:@"Cancel"
                                          otherButtonTitles:@"Say Hello",nil];
    [alert show];
    [alert release];
    
}

@end

CallNativeInterface::CallNativeInterface(){

    object = [IOSObject new];
}

void CallNativeInterface::printInfoFromNative(string &s) {

    [((IOSObject*) object) printInfo:s];
}

void CallNativeInterface::showToast() {

    [((IOSObject*) object) showToast];
}

#endif

