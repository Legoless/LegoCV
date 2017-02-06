# LegoCV

Fully functional OpenCV wrapper for Objective-C and Swift to eliminate the need to use Objective-C++ and allow full compatibility with Swift projects.

# Mission

Swift is one of the fastest evolving languages, but there is no way to use C++ frameworks directly, as it could be with Objective-C/C++.

This project's purpose is to create a simple, easy to use native Swift framework for OpenCV. The project adds Swift and Objective-C convenience methods, but translates to OpenCV API entirely.

The idea is to simply wrap OpenCV native C++ classes into Objective-C classes, which are then natively bridged to Swift, providing a thin layer on top of native OpenCV. [Realm]() and [EmguCV]() in C# use similar framework structure.

# Example

The following examples display the difference in using LegoCV in Swift and Objective-C versus vanilla OpenCV in C++.
The example is extracted from Face detection sample code, shipped with LegoCV. On iOS it uses `OCVVideoCamera` class to get image stream from camera (wraps original `CvVideoCamera`, to keep backward compatibiliy).

Swift (LegoCV):
```swift
let faceDetector = OCVCascadeClassifier();
faceDetector.load(path: "haarcascade_frontalface_alt2.xml")

func process(image: OCVMat) {
    var minSize = OCVSize()
    minSize.width = 30
    minSize.height = 30
        
    let gray = OCVMat()
    let smallImage = OCVMat(rows: Int(round(Double(image.rows) / scale)), cols: Int(round(Double(image.cols) / scale)), type: .cv8U, channels: 1)
        
    OCVOperation.convertColor(fromSource: image, toDestination: gray, with: .typeBGR2GRAY)
    OCVOperation.resize(fromSource: gray, toDestination: smallImage, size: smallImage.size, fx: 0, fy: 0, interpolation: .linear)
    OCVOperation.equalizeHistogram(fromSource: smallImage, toDestination: smallImage)
    
    // Faces are returned as OCVRect instances
    faceDetector.detectMultiscale(with: smallImage, scaleFactor: 1.1, minNeighbours: 2, flags: 0, minSize: minSize).map { $0.rect }
}
```

Objective-C (LegoCV with Objective-C):
```objectivec
- (void)processImage:(OCVMat *)image {
}
```

C++ (OpenCV):
```cpp
void processImage(cv::Mat image) {
}
```

# Documentation

As this is a project in progress, documentation will be added to [Wiki]().

# Installation

LegoCV can be installed with CocoaPods or Carthage.

# License

BSD license, respect [OpenCV](https://github.com/opencv/opencv) license as well.
