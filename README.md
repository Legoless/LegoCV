# LegoCV

Fully functional OpenCV wrapper for Objective-C and Swift to eliminate the need to use Objective-C++ and allow full compatibility with Swift projects.

# Mission

Swift is one of the fastest evolving languages, but there is no way to use C++ frameworks directly, as it could be with Objective-C/C++.

The idea is to simply wrap OpenCV native C++ classes into Objective-C classes, which are then natively bridged to Swift, providing a thin layer on top of native OpenCV. [Realm]() and [EmguCV]() in C# use similar framework structure.

# Example

The following examples display the difference in using LegoCV in Swift and Objective-C versus vanilla OpenCV in C++.
The example is extracted from Face detection sample code, shipped with LegoCV.

Swift (LegoCV):
```swift
```

Objective-C (LegoCV with Objective-C):
```objectivec
```

C++ (OpenCV):
```cpp
```

# Documentation

As this is a project in progress, documentation will be added to [Wiki]().

# Installation

LegoCV can be installed with CocoaPods or Carthage.

# License

BSD license, respect [OpenCV](https://github.com/opencv/opencv) license as well.
