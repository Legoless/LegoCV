Pod::Spec.new do |s|
  s.name             = 'LegoCV'
  s.version          = '0.1.2'
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

  s.ios.deployment_target = '10.0'

  s.public_header_files = 'LegoCV/LegoCV/LegoCV.h'
  s.source_files = 'LegoCV/LegoCV/LegoCV.h'

  s.subspec 'Core' do |subspec|
    subspec.public_header_files = 'LegoCV/LegoCV/Wrapper/Core/**/*.h', 'LegoCV/LegoCV/Wrapper/Utilities/**/*.h', 
    subspec.private_header_files = 'LegoCV/LegoCV/Wrapper/Core/Private/*.h'
    subspec.source_files = 'LegoCV/LegoCV/Wrapper/Core/**/*.{h,m,mm}', 'LegoCV/LegoCV/Wrapper/Utilities/**/*.{h,m,mm}'
    subspec.dependency 'OpenCV-Dynamic'
  end

  s.subspec 'ImageProcessing' do |subspec|
    subspec.public_header_files = 'LegoCV/LegoCV/Wrapper/ImageProcessing/**/*.h' 
    #subspec.private_header_files = 'LegoCV/LegoCV/Wrapper/Core/Private/*.h'
    subspec.source_files = 'LegoCV/LegoCV/Wrapper/ImageProcessing/**/*.{h,m,mm}'
    subspec.dependency 'LegoCV/Core'
  end
  
  s.frameworks = 'UIKit'
end
