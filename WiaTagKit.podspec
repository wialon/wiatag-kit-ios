#
# Be sure to run `pod lib lint WiaTagKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'WiaTagKit'
  s.version          = '1.0.0'
  s.summary          = 'WiaTagKit is a lib.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
WiaTagKit is a lib for sending data for Wialon service.
                       DESC

  s.homepage         = 'https://github.com/wialon/wiatag-kit-ios'
  s.license          = { :type => 'CC BY-ND 4.0', :file => 'LICENSE' }
  s.author           = { 'wialon' => 'development@gurtam.com' }
  s.source           = { :http => "https://github.com/wialon/wiatag-kit-ios/releases/download/#{s.version.to_s}/WiatagKit.xcframework.zip" }
  s.ios.deployment_target = '13.0'
  s.swift_version    = '5.0'
  s.vendored_xcframeworks = 'WiaTagSendingLib.xcframework'

  s.library = 'z'

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.frameworks = 'UIKit', 'CoreLocation', 'Foundation'
  s.dependency 'CocoaAsyncSocket', '~> 7.6'
end
