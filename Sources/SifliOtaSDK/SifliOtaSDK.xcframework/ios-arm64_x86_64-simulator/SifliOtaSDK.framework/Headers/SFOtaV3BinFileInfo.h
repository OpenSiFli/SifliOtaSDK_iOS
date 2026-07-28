//
//  SFOtaV3BinFileInfo.h
//  SifliOtaSDK
//
//  Created by Sean on 2024/7/27.
//

#import <SifliOtaSDK/SFOtaV3FileInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFOtaV3BinFileInfo : SFOtaV3FileInfo
@property(nonatomic,assign) uint16_t imageId;
@property(nonatomic,copy,nullable)NSString *hexOffset;
- (instancetype)initWidthFileType:(SFOtaV3DfuFileType)fileType filePath:(NSString *)filePath imageId:(uint16_t)imageId;
@end

NS_ASSUME_NONNULL_END
