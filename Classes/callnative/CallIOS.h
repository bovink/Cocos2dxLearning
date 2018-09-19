//
// Created by 吴宗刚 on 2018/9/19.
//

#ifndef PROJ_ANDROID_CALLIOS_H
#define PROJ_ANDROID_CALLIOS_H


#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS && !defined(CC_TARGET_OS_TVOS)

@interface IOSObject : NSObject

-(void) printInfo;

@end


#endif
#endif //PROJ_ANDROID_CALLIOS_H
