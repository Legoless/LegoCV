//
//  FaceDetector.swift
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

import LegoCV

class FaceDetector : NSObject, OCVVideoCameraDelegate {
    private var imageView : UIImageView
    private var scale : CGFloat
    
    private var faceRects : [OCVRect] = []
    private var faceImgs : [OCVMat] = []
    
    var videoCamera : OCVVideoCamera!
    
    init(imageView: UIImageView, scale: CGFloat) {
        self.imageView = imageView
        self.scale = scale
        
        super.init()
        
        setupCamera()
    }
    
    func startCapture () {
        videoCamera.start()
    }
    
    func stopCapture () {
        videoCamera.stop()
    }
    
    func detectedFaces () -> [CGRect] {
        var rects : [CGRect] = []
        
        for faceRect in faceRects {
            let rect = CGRect(x: scale * CGFloat(faceRect.origin.x) / 480.0, y: scale * CGFloat(faceRect.origin.y) / 640.0, width: scale * CGFloat(faceRect.size.width) / 480.0, height: scale * CGFloat(faceRect.size.height) / 640.0)
            rects.append(rect)
        }
        
        
        return rects
    }
    
    func face(with index: Int) -> UIImage? {
        guard index < faceImgs.count else {
            return nil
        }
        
        return faceImgs[index].image()
    }
    
    func processImage(_ image: OCVMat!) {
        
    }
    
    private func setupCamera () {
        videoCamera = OCVVideoCamera(parentView: imageView)
        videoCamera.defaultAVCaptureDevicePosition = .back
        videoCamera.defaultAVCaptureSessionPreset = AVCaptureSessionPreset640x480
        videoCamera.defaultAVCaptureVideoOrientation = .portrait
        videoCamera.defaultFPS = 30
        videoCamera.grayscaleMode = false
        videoCamera.delegate = self
    }
    
}
