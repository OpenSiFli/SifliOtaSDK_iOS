
// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SifliOtaSDK",
    platforms: [
        .iOS(.v12),
        .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "SifliOtaSDK",
            targets: ["SifliOtaSDK"]),
    ],

    targets: [
        .binaryTarget(
            name: "SifliOtaSDK",
            path: "Sources/SifliOtaSDK/SifliOtaSDK.xcframework"
        ),
        .testTarget(
            name: "SifliOtaSDKTests",
            dependencies: ["SifliOtaSDK"]
        ),
    ]
)


