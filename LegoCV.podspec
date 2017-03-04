Pod::Spec.new do |s|
  s.name             = 'LegoCV'
  s.version          = '0.1.0'
  s.summary          = 'Simple, lightweight native OpenCV wrapper for Objective-C and Swift.'

  s.description      = <<-DESC
LegoCV is native OpenCV framework built for Swift and Objective-C projects. It eliminates the need to use Objective-C++ and allows for full compatibility with native Swift projects. The only dependency is native OpenCV framework for iOS.
                       DESC

  s.homepage         = 'https://github.com/legoless/legocv'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => '3-clause BSD', :file => 'LICENSE' }
  s.author           = { 'Dal Rupnik' => 'legoless@gmail.com' }
  s.source           = { :git => 'https://github.com/legoless/legocv.git', :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/thelegoless'

  s.ios.deployment_target = '8.0'

  s.source_files = 'LegoCV/LegoCV/**/*.{h,m,mm}'
  
  #s.public_header_files = 'LegoCV/LegoCV/Public/**/*.h'
  #s.private_header_files = 'LegoCV/LegoCV/Private/*.h'

  s.dependency 'OpenCV-Dynamic'
  s.frameworks = 'UIKit'
end