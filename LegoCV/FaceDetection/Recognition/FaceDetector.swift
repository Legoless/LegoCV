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
    
    private var faceDetector = OCVCascadeClassifier()
    
    var videoCamera : OCVVideoCamera!
    
    init(imageView: UIImageView, scale: CGFloat) {
        self.imageView = imageView
        self.scale = scale
        
        super.init()
        
        setupCamera()
        setupClassifier()
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
        let faces = detectFaces(on: image, with: Double(scale))
        
        draw(faces: faces, on: image)
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
    
    private func setupClassifier () {
        let path = Bundle.main.path(forResource: "haarcascade_frontalface_alt2", ofType: "xml", inDirectory: nil)
        
        faceDetector.loadPath(path)
    }
    
    private func detectFaces (on image: OCVMat, with scale: Double) -> [OCVRect] {
        let scaleFactor = 1.1
        let minRects = 2
        var minSize = OCVSize()
        minSize.width = 30
        minSize.height = 30
        
        let gray = OCVMat()
        let smallImage = OCVMat(rows: Int(round(Double(image.rows) / scale)), cols: Int(round(Double(image.cols) / scale)), type: .cv8S, channels: 1)
        
        OCVOperation.convertColor(fromSource: image, toDestination: gray, with: .typeBGR2GRAY)
        OCVOperation.resize(fromSource: gray, toDestination: smallImage, size: smallImage.size, fx: 0, fy: 0, interpolation: .linear)
        
        return faceDetector.detectMultiscale(with: smallImage, scaleFactor: scaleFactor, minNeighbours: minRects, flags: 0, minSize: minSize).map { $0.rect }
    }
    
    private func draw(faces: [OCVRect], on image: OCVMat) {
        
        let colors : [OCVScalar] = [
            OCVScalarRGB(0, 0, 255),
            OCVScalarRGB(0, 128, 255),
            OCVScalarRGB(0, 255, 255),
            OCVScalarRGB(0, 255, 0),
            OCVScalarRGB(255, 128, 0),
            OCVScalarRGB(255, 255, 0),
            OCVScalarRGB(255, 0, 0),
            OCVScalarRGB(255, 0, 255)
        ]
        
        
        
        for face in faces {
            
        }
        
    }
}
