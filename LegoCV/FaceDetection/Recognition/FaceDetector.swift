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
        
    }
    
    func stopCapture () {
        
    }
    
    func detectedFaces () -> [CGRect] {
        return []
    }
    
    func face(with index: Int) -> UIImage? {
        guard index < faceImgs.count else {
            return nil
        }
        
        return faceImgs[index].image()
    }
    
    private func setupCamera () {
        videoCamera = OCVVideoCamera(parentView: imageView)
        videoCamera.defaultAVCaptureDevicePosition = .back
        videoCamera.defaultAVCaptureSessionPreset = AVCaptureSessionPreset640x480
    }
    
    func processImage(_ image: OCVMat!) {
        
    }
}
