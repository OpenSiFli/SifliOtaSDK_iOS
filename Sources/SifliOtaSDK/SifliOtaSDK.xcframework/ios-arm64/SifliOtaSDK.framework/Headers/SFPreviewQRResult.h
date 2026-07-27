//
//  SFPreviewQRResult.h
//  SifliOtaSDK
//
//  Created by congqiang on 2026/5/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 自定义业务参数字段常量
static NSString * const kSFPreviewQRKeyMac = @"Mac";           // 设备MAC地址
static NSString * const kSFPreviewQRKeyQuality = @"Quality";   // 图片投屏质量
static NSString * const kSFPreviewQRKeyQualityShort = @"Ql";   // 图片投屏质量

static NSString * const kSFPreviewQRKeySize = @"Size";         // 二维码/投屏显示尺寸
static NSString * const kSFPreviewQRKeySizeShort = @"Sz";         // 二维码/投屏显示尺寸

static NSString * const kSFPreviewQRKeyType = @"Type";         // 投屏类型
static NSString * const kSFPreviewQRKeyTypeShort = @"Tp";         // 投屏类型

static NSString * const kSFPreviewQRKeyIp = @"Ip";             // 设备局域网IP地址
static NSString * const kSFPreviewQRKeyPort = @"Port";         // 设备服务端口
static NSString * const kSFPreviewQRKeyPortShort = @"Pt";         // 设备服务端口

static NSString * const kSFPreviewQRKeyTransType = @"TransType"; // 通信类型
static NSString * const kSFPreviewQRKeyTransTypeShort = @"Tt"; // 通信类型

// 通信类型常量（位掩码）
typedef NS_OPTIONS(uint32_t, SFPreviewQRTransType) {
    SFPreviewQRTransTypeNone = 0,
    SFPreviewQRTransTypeBLE  = 1 << 0,  // 1: 蓝牙低功耗
    SFPreviewQRTransTypeSPP  = 1 << 1,  // 2: 蓝牙串口协议
    SFPreviewQRTransTypePAN  = 1 << 2,  // 4: 个人局域网
    SFPreviewQRTransTypeWIFI = 1 << 3,  // 8: WiFi直连
};

// 投屏类型常量
typedef NS_ENUM(NSInteger, SFPreviewQRContentType) {
    SFPreviewQRContentTypeNone = 0,
    SFPreviewQRContentTypeMap = 1,      // 投屏地图
    SFPreviewQRContentTypeInfo = 2,     // 投屏信息
};

@interface SFPreviewQRWifiResult : NSObject

/// WIFI:T:WPA 为YES;WIFI:T:nopass 为NO
@property (nonatomic, assign) BOOL isSecret;
@property (nonatomic, copy) NSString *SSID;
@property (nonatomic, copy, nullable) NSString *password;
@end

@interface SFPreviewQRResult : NSObject

/// 如果没有WIFI网段则为nil
@property (nonatomic, strong, nullable) SFPreviewQRWifiResult *wifiInfo;

- (void)addKey:(NSString *)key value:(NSString *)value;

/// 获取所有自定义参数
- (NSDictionary<NSString *, NSString *> *)allCustomInfo;

///下面的方法用于适配关键词简称
///TransType    Tt
///Quality    Ql
///Size    Sz
///Type    Tp
///Port    Pt
- (BOOL)containTransTypeKey;
- (BOOL)containPortKey;
- (BOOL)containTypeKey;
- (BOOL)containSizeKey;
- (BOOL)containQualityKey;

- (NSString *)transTypeText;
- (NSString *)portText;
- (NSString *)typeText;
- (NSString *)sizeText;
- (NSString *)qualityText;

@end

NS_ASSUME_NONNULL_END
