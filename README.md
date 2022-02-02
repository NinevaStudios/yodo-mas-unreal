# Unofficial Yodo MAS SDK for Unreal Engine 4

Disclaimer: this plugin is in no way associated with Yodo1, this is just a wrapper on top of their official Android and iOS SDKs.

This plugin provides Unreal Engine 4 integration for YODO1 MAS Service.

* Documentation: https://docs.ninevastudios.com/#/ue-plugins/yodo-unreal
* Our web-site: https://ninevastudios.com

---

# Update SDK guide
## Android
Go to YodoAds_Android_UPL.xml file and change dependencies.
## iOS
- create empty xcode project
- in terminal cd to folder with the created project
- run `pod init`
- open the created `Podfile` and make sure it looks like this (change dependency):
```
# Uncomment the next line to define a global platform for your project
platform :ios, '10.0'

target 'borsch' do
  # Comment the next line if you don't want to use dynamic frameworks
  # use_frameworks!

  # Pods for borsch
source 'https://github.com/CocoaPods/Specs.git'  # recommend: source 'https://cdn.cocoapods.org/'
source 'https://github.com/Yodo1Games/MAS-Spec.git'
source 'https://github.com/Yodo1Games/Yodo1Spec.git'
pod 'Yodo1MasFull', '4.5.0'

end
```
- run `pod install --repo-update`, make sure you have VPN enabled for Yandex frameworks to download
- open xcode project
- make sure the following lines in the files are:
	* YodoMas1Core/Yodo1Mas.m
	```
	+ (NSString *)sdkVersion {
		static NSString *version = nil;
		static dispatch_once_t onceToken;
		dispatch_once(&onceToken, ^{
			version = @"4.5.0";
		});
		return version;
	}
	
	- (void)initWithAppKey:(NSString *)appKey successful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail {
	
		...
		
		NSLog(@"The Sensor's user id is %@", userId);
    
		NSString* sdkVersion = [Yodo1Mas sdkVersion];
    
		NSString* sdkType = @"mas_global";
		
		NSString *bundleId = [NSBundle.mainBundle objectForInfoDictionaryKey:@"CFBundleIdentifier"];
		
		...
		
	}
	
	```
	
	* Yodo1MasMediationYodo1/Yodo1MasYodo1InterstitialController.m and Yodo1MasMediationYodo1/Yodo1MasYodo1RewardController.m in `(void)viewDidLoad {` replace UIImage loading from bundle with these lines:
	```
	
	
		NSString* imageString = @",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";
	NSData *data = [[NSData alloc]initWithBase64EncodedString:imageString options:NSDataBase64DecodingIgnoreUnknownCharacters];
	UIImage* image = [UIImage imageWithData:data];
	
	...
	
	[self.closeButton setImage:image forState:UIControlStateNormal];
    
    ...
	```
- press CMD+B to build the project
- navigate to the build directory - it should look like this: `/Users/nineva/Library/Developer/Xcode/DerivedData/borsch-fpjwgnfkqtvltvchxtsorxsticvx/Build/Products/Debug-iphoneos`
- now there are two different types of assets we will use
	1. Frameworks and xcframeworks - usual flow to create embedded framework. If a framework has a bundle - consult Build.cs for the placement of the bundle.
	2. Libraries (.a files) - copy the lib.a file to the '../ThirParty/Libraries' folder and copy it's relevant headers to '../ThirParty/Headers/[LibraryName]' folder.
- go to the folder with the created xcode project and open the `Pods` folder.
- for every folder that has frameworks in it use flow 1, for every other folder copy the headers from the containing Classes folder and subfolders, then copy the built library from the `/Users/nineva/Library/Developer/Xcode/DerivedData/borsch-fpjwgnfkqtvltvchxtsorxsticvx/Build/Products/Debug-iphoneos` subfolders.
- if new dependencies are found - add the respective lines to the Build.cs file
