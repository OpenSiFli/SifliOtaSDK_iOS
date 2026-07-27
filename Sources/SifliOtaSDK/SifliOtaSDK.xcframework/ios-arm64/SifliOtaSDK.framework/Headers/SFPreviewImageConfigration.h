//
//  SFWatchfacePreviewVideoConfigration.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/11/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SFPreviewImageType) {
    SFPreviewImageTypeImage = 0,//地图导航投屏,逐帧图像制作投屏.每帧制作传输层驱动，UI层实现previewImageManager: makeNextFrame: 制作下一帧
    SFPreviewImageTypeVideo = 1//视频预览。每帧通过视频流推入
};

@interface SFPreviewImageConfigration : NSObject

/// 预览类型 @see SFPreviewImageType
@property (nonatomic,assign) SFPreviewImageType previewType;
/// 视频预览时转为jpg的压缩质量 0~ 1
@property (nonatomic,assign) float JpegQuality;
/// 手表视频预览的分辨率
@property (nonatomic,assign) CGSize watchScreenSize;

/// 图像旋转方向0,90,180,270
@property (nonatomic,assign) NSInteger rotation;
///最大帧率，0-60,0表示没有限制，发送完即开始发送下一帧
@property (nonatomic,assign) NSInteger maxFps;
///// 切片大小级别1-10. 切片大小为sliceLevel * 1024
//@property (nonatomic,assign) NSInteger sliceLevel;

///previewType =SFPreviewImageTypeImage 时是否允许调整图像尺寸
///YES,watchScreenSize,rotation 这两个参数将会有效
@property (nonatomic,assign) BOOL isAspectSizeForImage;
@end

NS_ASSUME_NONNULL_END
