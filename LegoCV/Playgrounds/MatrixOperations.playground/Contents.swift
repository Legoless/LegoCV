//: A UIKit based Playground for presenting user interface

import LegoCV
import LegoSwiftCV

import UIKit
import PlaygroundSupport

//let matrix = Matrix.zeros(withRows: 2, cols: 2, type: .cv8U, channels: 3)

let mat = OCVMat()
let copy = mat.clone()


let image = UIImage(named: "test1")

// Present the view controller in the Live View window
PlaygroundPage.current.liveView = UIImageView(image: image)
