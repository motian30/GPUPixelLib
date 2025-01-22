// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "GPUPixelLib",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "GPUPixelLib",
            targets: ["gpupixel","vnn_core_ios","vnn_face_ios","vnn_kit_ios"]),
    ],
    targets: [
        .binaryTarget(name: "vnn_face_ios", path: "vnn_face_ios.xcframework"),
        .binaryTarget(name: "vnn_kit_ios", path: "vnn_kit_ios.xcframework"),
        .binaryTarget(name: "vnn_core_ios", path: "vnn_core_ios.xcframework"),
        .binaryTarget(name: "gpupixel", path: "gpupixel.xcframework"),
    ],
    swiftLanguageVersions: [.v5]
)

