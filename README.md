# OTA V3 iOS SDK
## 1. 集成

Swift Package
```bash
https://github.com/OpenSiFli/SifliOtaSDK_iOS.git
https://github.com/OpenSiFli/SifliOCore.git
```

```java
import SifliOtaSDK
import SifliOCore
```
版本号匹配

- SifliOtaSDK 3.1.9
- SifliOCore 1.0.12

-  初始化

```java
let manager = SFOtaV3Manager.shared()

 override func viewDidLoad() {
 //需要实现SFOtaV3ManagerDelegate
  manager.delegate = self
 }
```

## 2. 接口调用
### 2.1 资源传输

调用otaManager如下方法

```java
/// 资源ota
/// - Parameters:
///   - identifier: 蓝牙设备地址
///   - otaV3Type: 0-表盘，1-多语言, 2-背景图，3-自定义, 4-音乐,5-JS,8-4G模块, 9-GUIBuilder 表盘, 
///                12-GUIBuilder App,13-GUIBuilder 扩展资源。其它类型查阅文档
///   - resourceFile: 资源文件描述
///   - tryResume: 是否尝试续传
- (void)startOtaResWithIdentifier:(NSString *)identifier
                          otaV3Type:(SFOtaV3Type)otaV3Type
                          resourceFile:(SFOtaV3ResourceFileInfo *)resourceFile
                          tryResume:(BOOL)tryResume;
```

SFOtaV3Type

```java
typedef NS_ENUM(NSUInteger, SFOtaV3Type) {
    SFOtaV3TypeDynamicModule = 0,//表盘
    SFOtaV3TypeMutilLanguage = 1,//多语言
    SFOtaV3TypeBgPicture = 2,//背景图
    SFOtaV3TypeCustomFile = 3,//自定义
    SFOtaV3TypeMusic = 4,//背景音乐
    SFOtaV3TypeQjs = 5,//JavaScript
    SFOtaV3TypePhotoView = 7,//拍照预览
    SFOtaV3TypeAicModule = 8,//4g模块
    SFOtaV3TypeSilfiWatchface = 9,//SifliGuiBuiler 表盘
    SFOtaV3TypeFirmware = 10,//固件
    SFOtaV3TypeFirmwareManager = 11,//固件 ota manager
    SFOtaV3TypeSifliApp = 12,//SifliGuiBuilder app
    SFOtaV3TypeSifliAppRes = 13,//SifliGuiBuilder app 拓展资源
    SFOtaV3TypeSifliAppWidget = 14//SifliGuiBuilder app 拓展组件
};
```
SFOtaV3ResourceFileInfo

```java
typedef NS_ENUM(NSUInteger, SFOtaV3DfuFileType) {
    SFOtaV3DfuFileTypeZipResource = 0,//zip资源文件
    SFOtaV3DfuFileTypeZipResourceNoFilePath = 1,//zip资源没有路径
    SFOtaV3DfuFileTypeCtrlFile = 2,//固件ota 控制文件
    SFOtaV3DfuFileTypeBinFile = 3,//固件ota image bin文件
    SFOtaV3DfuFileTypeTransBinFile = 4,//直接传输的bin文件
};
@interface SFOtaV3FileInfo : NSObject
@property (nonatomic,copy,readonly)NSString *filePath;
@property (nonatomic,assign,readonly)SFOtaV3DfuFileType fileType;
- (instancetype)initWidthFileType:(SFOtaV3DfuFileType)fileType filePath:(NSString *)filePath;

@end

@interface SFOtaV3ResourceFileInfo : SFOtaV3FileInfo
@property(nonatomic,assign)BOOL withByteAlign;

- (instancetype)initWithFileType:(SFOtaV3DfuFileType)fileType
                filePath:(NSString *)filePath
           withByteAlign:(BOOL)withByteAlign;

- (BOOL)isFilePathNullOrEmpty;
@end
```
### 2.2 固件传输
调用如下方法

```java
/// 固件ota
/// - Parameters:
///   - identifier: 蓝牙设备地址
///   - resourceFile: 差分包资源文件描述
///   - imageFiles: 固件ota的bin文件，包括ctrl packet
///   - tryResume: 是否尝试续传
- (void)startOtaFirmwareWithIdentifier:(NSString *)identifier
                          resourceFile:(nullable SFOtaV3ResourceFileInfo *)resourceFile
                            imageFIles:(nullable NSArray<SFOtaV3BinFileInfo *> *)imageFiles
                             tryResume:(BOOL)tryResume;
```

SFOtaV3BinFileInfo

```java
typedef NS_ENUM(NSUInteger, SFOtaV3ImageID) {
    SFOtaV3ImageIDHcpu = 0,
    SFOtaV3ImageIDLcpu = 1,
    SFOtaV3ImageIDLcpuPatch = 2,
    SFOtaV3ImageIDNORResOrNandPic = 3,
    SFOtaV3ImageIDNORFontOrNandFont = 4,
    SFOtaV3ImageIDNORRootOrNandLang = 5,
    SFOtaV3ImageIDNOROtaManagerOrNandRing = 6,
    SFOtaV3ImageIDNORTinyFontOrNandRoot = 7,
    SFOtaV3ImageIDNandMusic = 8,
    SFOtaV3ImageIDNandDyn = 9,
    SFOtaV3ImageIDNandNym = 10
};

@interface SFOtaV3BinFileInfo : SFOtaV3FileInfo
@property(nonatomic,assign) SFOtaV3ImageID imageId;
@property(nonatomic,copy,nullable)NSString *hexOffset;
- (instancetype)initWidthFileType:(SFOtaV3DfuFileType)fileType filePath:(NSString *)filePath imageId:(SFOtaV3ImageID)imageId;
@end
```

## 3. 错误码
错误码参照[ios-sdk-error-code](http://docs.sifli.cc/solution2_0_doc/mobile-sdk/ota/ota_v3_error_code.html)

## 4. Change Log
- 3.1.8/1.0.11初始化
- 3.1.9/1.0.12 支持arm64模拟器
