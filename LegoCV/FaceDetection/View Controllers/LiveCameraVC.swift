//
//  LiveCameraVC.swift
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

import UIKit

class LiveCameraVC: UIViewController {
    
    @IBOutlet weak var cameraView : UIImageView!
    
    var faceDetector : FaceDetector!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        faceDetector = FaceDetector(imageView: cameraView, scale: 2.0)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        faceDetector.startCapture()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        faceDetector.stopCapture()
    }
}

