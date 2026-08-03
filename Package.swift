// swift-tools-version:5.7
import PackageDescription

let package = Package(
    name: "WiaTagKit",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "WiaTagKit",
            targets: ["WiaTagKit", "CocoaAsyncSocket"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "WiaTagKit",
            path: "WiaTagKit/WiaTagKit.xcframework"
        ),
        .binaryTarget(
            name: "CocoaAsyncSocket",
            path: "WiaTagKit/CocoaAsyncSocket.xcframework"
        )
    ]
)
