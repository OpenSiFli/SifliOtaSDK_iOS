//
//  VersionConstant.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/11/6.
//
#import <Foundation/Foundation.h>
#ifndef VersionConstant_h
#define VersionConstant_h
///3.1.7 优化蓝牙工作队列为专有队列
///3.1.9 SifliOCore 封装SSZipArchive
///3.2.0 SifliOCore SSZipArchive 被剥离为外部插件
static NSString * const kSDKVersion = @"3.2.0";
static NSInteger const kOtaVersion = 4;

#endif /* VersionConstant_h */
