//: A UIKit based Playground for presenting user interface

import LegoCV
import UIKit
import PlaygroundSupport

let mat = OCVMat()
let copy = mat.clone()


let image = UIImage(named: "test1")

// Present the view controller in the Live View window
PlaygroundPage.current.liveView = UIImageView(image: image)
