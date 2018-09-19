//
// Created by 吴宗刚 on 2018/9/19.
//

#include "CallNativeInterface.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS && !defined(CC_TARGET_OS_TVOS)

#include "CallIOS.h"

@implementation IOSObject {

}

-(void) printInfo {
    
    NSLog(@"hello from the ios");
    
}

@end

CallNativeInterface::CallNativeInterface(){

    object = [IOSObject new];
}

void CallNativeInterface::printInfoFromNative() {

    [((IOSObject*) object) printInfo];
}


#endif

