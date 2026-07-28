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
///3.3.1 SifliOtaSdk支持地图投屏，帧率显示优化，帧率控制
///3.3.2 SifliOtasdk  地图投屏编码优化，帧延迟优化
///3.3.3 SifliOtaSdk 地图投屏支持尺寸调整
///3.3.4 fix bug preview video send task task busy 设置时机问题.
///3.3.5 增加二维码简写字段
///3.3.6 最大imageId校验提升到50
///3.3.7 内部去掉SFOtaV3ImageID依赖，便于外部自定义ImageID
static NSString * const kSDKVersion = @"3.3.7";
static NSInteger const kOtaVersion = 4;

#endif /* VersionConstant_h */
