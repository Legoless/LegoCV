# LegoCV

LegoCV is native OpenCV framework built for Swift and Objective-C projects. It eliminates the need to use Objective-C++ and allows for full compatibility with native Swift projects. The only dependency is native [OpenCV framework](http://opencv.org) for iOS.

## Mission

Swift is one of the fastest evolving languages, but there is no way to use C++ frameworks directly, as it could be with Objective-C/C++.

This project's purpose is to create a simple, easy to use native Swift framework for OpenCV. The project adds Swift and Objective-C convenience methods, but translates to OpenCV API entirely.

The idea is to simply wrap OpenCV native C++ classes into Objective-C classes, which are then natively bridged to Swift, providing a thin layer on top of native OpenCV. [Realm](https://realm.io) and [EmguCV]() in C# use similar framework structure.

## Example

The following examples display the difference in using LegoCV in Swift and Objective-C versus vanilla OpenCV in C++.
The example is extracted from Face detection sample code, shipped with LegoCV. On iOS it uses `OCVVideoCamera` class to get image stream from camera (wraps OpenCV's `CvVideoCamera`, to keep backward compatibiliy).

#### Swift (LegoCV):
```swift
let faceDetector = OCVCascadeClassifier();
faceDetector.load(path: "haarcascade_frontalface_alt2.xml")

func process(image: OCVMat) {
    let scale = 2.0

    let minSize = OCVSize(width: 30, height: 30)
        
    let gray = OCVMat()
    let smallImage = OCVMat(rows: Int(round(Double(image.rows) / scale)), cols: Int(round(Double(image.cols) / scale)), type: .cv8U, channels: 1)
        
    OCVOperation.convertColor(from: image, to: gray, with: .BGR2GRAY)
    OCVOperation.resize(from: gray, to: smallImage, size: smallImage.size, fx: 0, fy: 0, interpolation: .linear)
    OCVOperation.equalizeHistogram(from: smallImage, to: smallImage)
    
    // Faces are returned as OCVRect instances, so they are mapped in Swift, as they are structs.
    let faces : [OCVRect] = faceDetector.detectMultiscale(with: smallImage, scaleFactor: 1.1, minNeighbours: 2, flags: 0, minSize: minSize).map { $0.rect }
}
```

#### Objective-C (LegoCV with Objective-C):
```objectivec
- (void)setupClassifier {
    self.faceDetector = [[OCVCascadeClassifier alloc] init];
    [self.faceDetector loadPath:@"haarcascade_frontalface_alt2.xml"];
}

- (void)processImage:(OCVMat *)image {
    double scale = 2.0;

    OCVSize minSize;
    minSize.width = 30;
    minSize.height = 30;
        
    OCVMat* gray = [[OCVMat alloc] init];
    OCVMat* smallImage = [[OCVMat alloc] initWithRows:round(image.rows / scale) cols:round(image.cols / scale) type: OCVDepthTypeCv8U, channels: 1)
    
    [OCVOperation convertColorFromSource:image toDestination:gray with:OCVColorConversionTypeBGR2GRAY];
    [OCVOperation resizeFromSource:gray toDestination:smallImage size:smallImage.size fx:0 fy:0 interpolation:OCVInterpolationTypeLinear];
    [OCVOperation equalizeHistogramFromSource:smallImage toDestination:smallImage];
    
    // Faces are returned as OCVRectValue instances, which wrap OCVRect structs.
    NSArray<OCVRectValue *>* faces = [self.faceDetector detectMultiscaleWith:smallImage scaleFactor:1.1 minNeighbours:2 flags: 0 minSize:minSize];
}
```

#### C++ (OpenCV):
```cpp
using namespace cv;

void setup () {
    _faceDetector = new CascadeClassifier();
    _faceDetector->load("haarcascade_frontalface_alt2.xml");
}

void processImage(cv::Mat img) {
    double scale = 2.0;
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );
    
    cvtColor( img, gray, COLOR_BGR2GRAY );
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    cv::Size minSize(30,30);

    vector<cv::Rect> faceRects;

    // Faces are returned in provided faceRects vector
    _faceDetector->detectMultiScale(smallImg, faceRects, 1.1, 2, 0, minSize);
}
```

More examples, including Swift playgrounds can be found in the sample project.

## Documentation

As this is a project in progress, documentation will be added to [Wiki]() as development progresses.

## Performance

There is a smaller performance impact compared to pure native C++ code of OpenCV, due to Objective-C messaging system. If you need a high performance code, it is still recommended to write the algorithm in C++ and add bridges to LegoCV or Objective-C.

## Installation

LegoCV can be installed with [CocoaPods]() or [Carthage](). It's only dependency is OpenCV framework, which can be downloaded from their website.

```ruby
pod 'LegoCV'
```

# Building

To build LegoCV project you need `cmake`. Install it with `brew install cmake` and make sure you have Xcode Command Line tools installed. Trigger with `xcode-select --install` to check. Also make sure you use latest Xcode version and not Beta for master branch.

# License

[BSD license](), respect [OpenCV](https://github.com/opencv/opencv) license as well.
