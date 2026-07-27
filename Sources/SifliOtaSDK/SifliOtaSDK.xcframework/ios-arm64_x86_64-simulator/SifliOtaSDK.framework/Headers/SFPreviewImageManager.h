//
//  SFPreviewVideoManager.h
//  SifliOtaSDK
//
//  Created by Sean on 2025/5/29.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <SifliOCore/SifliOCore.h>
#import <SifliOtaSDK/SFPreviewImageConfigration.h>
#import <SifliOtaSDK/SFOtaV3Error.h>
#import <SifliOCore/SifliImageHelper.h>
#import <AVFoundation/AVFoundation.h>
NS_ASSUME_NONNULL_BEGIN

@class SFPreviewImageManager;
@protocol SFPreviewImageManagerDelegate <NSObject>

- (void)previewImageManager:(SFPreviewImageManager *)manager updateBleState:(SFBleCoreManagerState)state;
- (void)previewImageManager:(SFPreviewImageManager *)manager success:(BOOL)success errror:(nullable SFOtaV3Error *)error;
- (void)previewImageManager:(SFPreviewImageManager *)manager updateManagerState:(SFBleShellStatus)state;

@optional
///当前帧的发送进度，当进度达到一定时开始制作新帧
///previewType = SFPreviewImageTypeImage 时需要实现此回调
///注意:该回调在子线程执行，便于UI层在非主线程合成下一帧
- (void)previewImageManager:(SFPreviewImageManager *)manager makeNextFrame:(float) process;
///初始化命令就绪，可以开始发送图片
///previewType = SFPreviewImageTypeImage 时需要实现此回调
- (void)previewImageManageReadyToSendImage;
/// 实时帧率
/// @param manager self
/// @param fps 帧率
- (void)previewImageManager:(SFPreviewImageManager *)manager fps:(float)fps;

/// 即将发送的图片数据
/// @param manager self
/// @param jpgData jpg数据
- (void)previewImageManager:(SFPreviewImageManager *)manager onImageMake:(NSData *)jpgData;
///已经发送图片数量，用于外部监测是否继续工作
- (void)previewImageManager:(SFPreviewImageManager *)manager imageCount:(NSInteger) imageCount sendBytes:(uint64_t)sendBytes;


/// 预览模式改变,用于地图投屏 previewType = SFPreviewImageTypeImage 时需要实现此回调
/// @param manager self
/// @param mode 预览模式 1,投屏地图;2,投品信息
- (void)previewImageManager:(SFPreviewImageManager *)manager onPreviewModeChanged:(NSInteger)mode;


@end

@interface SFPreviewImageManager : NSObject
@property (nonatomic,weak) id<SFPreviewImageManagerDelegate> delegate;
+ (SFPreviewImageManager *)shared;


/// 帧率
@property (nonatomic,assign) float fps;


/// 初始化传输模式
/// - Parameter transMode: 传输模式
- (void)initSdkWithTransmissionMode:(SFTransmissionMode)transMode
                        imageHelper:(id<SifliImageHelper>)imageHelper;

- (BOOL)isBusy;

/// 发起视频预览,用于transMode = SFTransmissionModeBle
/// 发起蓝牙连接，之后初始化传输，在状态未就绪前发送到priviewVideoSample的采样数据会被丢弃
/// - Parameter configration: 配置参数
- (void)startPreviewVideo:(SFPreviewImageConfigration *)configration targetIdentifier:(NSString *)identifier;

/// 发起视频预览 仅用于transMode = SFTransmissionModeSocketServer
/// - Parameter configration: config
- (void)startPreviewVideoAsSocketServer:(SFPreviewImageConfigration *)configration;

/// 发起视频预览，仅用于transMode = SFTransmissionModeSocketClient
/// - Parameters:
///   - configration: config
///   - ip: ip 地址
///   - port: 端口
- (void)startPreviewVideoAsSocketClient:(SFPreviewImageConfigration *)configration ip:(NSString *)ip port:(uint16_t)port;

/// 向手表端发送视频采样
/// sdk根据SFPreviewVideoConfigration 的配置对采样进行处理，之后将jpeg数据通过蓝牙发送到手表端
/// - Parameter sample: 视频数据采样，通过AVCaptureVideoDataOutput 获得;
/// - Parameter timeStamp:Unix时间戳的低4字节
- (void)previewVideoSample:(UIImage *)sample timeStamp:(NSTimeInterval)timeStamp;

/// 发送 CVPixelBuffer 图像数据到投屏模块 (高性能接口)
/// - Parameters:
///   - sample: CVPixelBufferRef 图像数据
///   - timeStamp: timeStamp 时间戳
- (void)previewPixelSample:(CVPixelBufferRef)sample timeStamp:(NSTimeInterval)timeStamp;

/// 向固件发送音频数据
/// - Parameter audioData: 音频数据
/// - Parameter timeStamp: 时间戳
- (void)previewAudio:(NSData *)audioData timeStamp:(NSTimeInterval)timeStamp;
/// 向手表端发送视频采样
/// sdk根据SFPreviewVideoConfigration 的配置对采样进行处理，之后将jpeg数据通过蓝牙发送到手表端
/// - Parameter sample: 视频数据采样，通过AVCaptureVideoDataOutput 获得;
- (void)previewVideoSample:(CMSampleBufferRef)sample;

/// 预览导航信息
/// - Parameters:
///   - navInfo: 导航信息，速度，距离等组成的json/protobuf
///   - timeStamp: 时间戳
- (void)previewNavInfo:(NSData *)navInfo timeStamp:(NSTimeInterval)timeStamp;

/// 结束预览视频,保持连接
- (void)endPreviewVideo;
/// 停止传输, 关闭连接
- (void)stop;
- (BOOL)canSendImage;
/// 开始监听本地端口，当有设备连接进入时，即可开始startPreviewVideo
/// 设备连接时通过updateManagerState 回调表达 SFBleShellStatusModuleWorking
- (void)startTcpListen:(uint16_t)port;

- (void)setSocketMtu:(uint16_t)kMtu;
@end

NS_ASSUME_NONNULL_END
