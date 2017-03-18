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
    
    func processImage(_ image: OCVMat) {
        let faces = detectFaces(on: image, with: Double(scale))

        draw(faces: faces.0, on: image, with: faces.1)
    }
    
    private func setupCamera () {
        videoCamera = OCVVideoCamera(parentView: imageView)
        videoCamera.defaultAVCaptureDevicePosition = .front
        videoCamera.defaultAVCaptureSessionPreset = AVCaptureSessionPreset640x480
        videoCamera.defaultAVCaptureVideoOrientation = .portrait
        videoCamera.defaultFPS = 30
        videoCamera.grayscaleMode = false
        videoCamera.delegate = self
    }
    
    private func setupClassifier () {
        if let path = Bundle.main.path(forResource: "haarcascade_frontalface_alt2", ofType: "xml", inDirectory: "data/haarcascades") {
            faceDetector.loadPath(path)
        }
    }
    
    private func detectFaces (on image: OCVMat, with scale: Double) -> ([OCVRect], OCVMat) {
        let scaleFactor = 1.1
        let minRects = 2
        var minSize = OCVSize()
        minSize.width = 30
        minSize.height = 30
        
        let gray = OCVMat()
        let smallImage = OCVMat(rows: Int(round(Double(image.rows) / scale)), cols: Int(round(Double(image.cols) / scale)), type: .cv8U, channels: 1)
        
        OCVImageOperation.convertColor(fromSource: image, toDestination: gray, with: .typeBGR2GRAY)
        OCVImageOperation.resize(fromSource: gray, toDestination: smallImage, size: smallImage.size, fx: 0, fy: 0, interpolation: .linear)
        OCVImageOperation.equalizeHistogram(fromSource: smallImage, toDestination: smallImage)
        
        return (faceDetector.detectMultiScale(onImage: smallImage, scaleFactor: scaleFactor, minNeighbours: minRects, flags: 0, minSize: minSize).map { $0.rect }, smallImage)
    }
    
    private func draw(faces: [OCVRect], on image: OCVMat, with smallImage: OCVMat) {
        
        let colors : [OCVScalar] = [
            OCVScalar(r: 0, g: 0, b: 255),
            OCVScalar(r: 0, g: 128, b: 255),
            OCVScalar(r: 0, g: 255, b: 255),
            OCVScalar(r: 0, g: 255, b: 0),
            OCVScalar(r: 255, g: 128, b: 0),
            OCVScalar(r: 255, g: 255, b: 0),
            OCVScalar(r: 255, g: 0, b: 0),
            OCVScalar(r: 255, g: 0, b: 255)
        ]
        
        var faceImages : [OCVMat] = []
        
        var i = 0
        
        for face in faces {
            let color = colors[i % colors.count]
            
            var point1 = OCVPoint()
            point1.x = Int(CGFloat(face.origin.x) * scale)
            point1.y = Int(CGFloat(face.origin.y) * scale)
            
            var point2 = OCVPoint()
            point2.x = Int(CGFloat(face.origin.x + face.size.width - 1) * scale)
            point2.y = Int(CGFloat(face.origin.y + face.size.height - 1) * scale)
            
            OCVImageOperation.rectangle(onSource: image, from: point1, to: point2, withColor: color, thickness: 1, lineType: 8, shift: 0)

            let smallImageROI = smallImage.submatrix(with: face)
            
            faceImages.append(smallImageROI.clone())
            
            i += 1
        }
        
        self.faceImgs = faceImages
        
    }
}
