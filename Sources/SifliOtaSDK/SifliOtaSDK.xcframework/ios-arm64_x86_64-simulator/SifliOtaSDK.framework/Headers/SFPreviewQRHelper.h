//
//  SFPreviewQRHelper.h
//  SifliOtaSDK
//
//  Created by congqiang on 2026/5/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SifliOtaSDK/SFPreviewQRResult.h>

NS_ASSUME_NONNULL_BEGIN


@interface SFPreviewQRHelper : NSObject

/// 解析二维码文本
/// @param qrText 二维码原始文本
/// @return 解析结果对象，解析失败返回nil
- (nullable SFPreviewQRResult *)analyzeQRText:(NSString *)qrText;

#pragma mark - 类型化解析帮助方法

/// 解析尺寸字符串，格式: "宽x高"，如 "466x466"
/// @param sizeText 尺寸文本
/// @return CGSize结构体，解析失败返回CGSizeZero
- (CGSize)makeSizeWithText:(NSString *)sizeText defaultSize:(CGSize)defaultSize;

/// 解析浮点数质量值，取值范围 0.1~1.0
/// @param qualityText 质量文本
/// @return 浮点数值，解析失败返回0.0
- (CGFloat)makeQualityWithText:(NSString *)qualityText defaultQuality:(CGFloat)defaultQuality;

/// 解析整型端口号，取值范围 1~65535
/// @param portText 端口文本
/// @return 端口号，解析失败或超出范围返回0
- (uint16_t)makePortWithText:(NSString *)portText defaultPort:(uint16_t)defaultPort;

/// 解析整型投屏类型，取值范围 1 或 2
/// @param typeText 类型文本
/// @return 投屏类型，解析失败或无效返回0
- (SFPreviewQRContentType)makeTypeWithText:(NSString *)typeText defaultType:(SFPreviewQRContentType)defaultType;

/// 解析通信类型（支持位掩码）
/// @param transTypeText 通信类型文本
/// @return 通信类型整数值，解析失败返回0
- (uint32_t)makeTransTypeWithText:(NSString *)transTypeText;

/// 解析MAC地址，统一转为大写，去除分隔符
/// @param macText MAC地址文本
/// @return 标准格式的MAC地址（12位十六进制字符串），解析失败返回nil
- (nullable NSString *)makeMacAddressWithText:(NSString *)macText;

/// 解析IP地址，验证格式有效性
/// @param ipText IP地址文本
/// @return 有效的IP地址字符串，无效返回nil
- (nullable NSString *)makeIPAddressWithText:(NSString *)ipText;

/// 检查传输类型复合值是否包含某个传输类型
/// @param allTransType 二维码文本中解析得到的传输复合值
/// @param transType 参照SFPreviewQRTransType
- (BOOL)containTransType:(uint32_t)allTransType transType:(uint32_t)transType;


@end

NS_ASSUME_NONNULL_END
