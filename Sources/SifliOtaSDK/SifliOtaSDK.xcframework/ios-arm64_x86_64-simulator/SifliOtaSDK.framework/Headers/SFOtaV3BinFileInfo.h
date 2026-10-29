//
//  SFOtaV3BinFileInfo.h
//  SifliOtaSDK
//
//  Created by Sean on 2024/7/27.
//

#import <SifliOtaSDK/SFOtaV3FileInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFOtaV3BinFileInfo : SFOtaV3FileInfo
///参照SFOtaV3ImageID
@property(nonatomic,assign) uint16_t imageId;

/// 新地址（十六进制字符串，大端书写，即人类习惯的地址值）
///
/// 填写规则：
/// - 按地址值的大端书写习惯填入，例如地址 0x87654321 填 @"87654321"；
/// - 不要带 "0x" 前缀、空格或分隔符，仅 0-9A-Fa-f；
/// - 建议正好 8 位（不足 8 位 SDK 会自动左补 0，超过 8 位报错）；
/// - 留空/nil 表示地址 0。
///
/// 说明：SDK 内部会将此大端书写值转换为小端序写入通信包（wire 字节为
/// 0x21 0x43 0x65 0x87），MCU 侧可直接按 uint32 读取得到 0x87654321。
/// 本字段语义与 Android SDK 一致，请勿"反着填"。
@property(nonatomic,copy,nullable)NSString *hexNewAddr;
- (instancetype)initWidthFileType:(SFOtaV3DfuFileType)fileType filePath:(NSString *)filePath imageId:(uint16_t)imageId;
@end

NS_ASSUME_NONNULL_END
