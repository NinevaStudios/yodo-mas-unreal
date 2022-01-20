// Copyright (c) 2022 Nineva Studios

using System;
using System.IO;
using Tools.DotNETCommon;
using UnrealBuildTool;

public class YodoAds : ModuleRules
{
	public YodoAds(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);

		// Additional routine for Android
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/Android"));
			PrivateDependencyModuleNames.Add("Launch");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "YodoAds_Android_UPL.xml"));
		}
		
		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicFrameworks.AddRange (
				new string[]
				{
					"Accelerate",
					"AdSupport",
					"AppTrackingTransparency",
					"AudioToolbox",
					"AVKit",
					"MapKit",
					"WebKit",
					"Security",
					"CoreMedia",
					"AVFoundation",
					"CoreTelephony",
					"CoreLocation",
					"SystemConfiguration",
					"MobileCoreServices",
					"JavaScriptCore",
					"MessageUI",
					"CoreImage",
					"ImageIO",
					"CoreText",
					"CoreMotion",
					"CoreServices",
					"SafariServices",
					"StoreKit",
					"CFNetwork",
					"Social",
					"WatchConnectivity",
					"QuartzCore",
					"EventKit",
					"CoreVideo",
					"MediaPlayer",
					"LocalAuthentication",
					"VideoToolbox",
					"c++",
					"c++abi",
					"sqlite3",
					"sqlite3.0",
					"xml2",
					"xml2.2",
					"bz2",
					"resolv",
					"iconv",
					"z"
				}
			);
			
			PublicAdditionalFrameworks.Add (new Framework ("AFNetworking", "../ThirdParty/AFNetworking.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("AdColony", "../ThirdParty/AdColony.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("AppLovinQualityService", "../ThirdParty/AppLovinQualityService.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("AppLovinSDK", "../ThirdParty/AppLovinSDK.embeddedframework.zip", "AppLovinSDKResources.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("BUAdSDK", "../ThirdParty/BUAdSDK.embeddedframework.zip", "BUAdSDK.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("BUCNAuxiliary", "../ThirdParty/BUCNAuxiliary.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("BUFoundation", "../ThirdParty/BUFoundation.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("BUVAAuxiliary", "../ThirdParty/BUVAAuxiliary.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("FBAudienceNetwork", "../ThirdParty/FBAudienceNetwork.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("FBLPromises", "../ThirdParty/FBLPromises.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("FBSDKCoreKit_Basics", "../ThirdParty/FBSDKCoreKit_Basics.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleAppMeasurement", "../ThirdParty/GoogleAppMeasurement.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleAppMeasurementIdentitySupport", "../ThirdParty/GoogleAppMeasurementIdentitySupport.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleMobileAds", "../ThirdParty/GoogleMobileAds.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleUtilities", "../ThirdParty/GoogleUtilities.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("IASDKCore", "../ThirdParty/IASDKCore.embeddedframework.zip", "IASDKResources.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("IASDKMRAID", "../ThirdParty/IASDKMRAID.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("IASDKVideo", "../ThirdParty/IASDKVideo.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("InMobiSDK", "../ThirdParty/InMobiSDK.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("IronSource", "../ThirdParty/IronSource.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("MyTargetSDK", "../ThirdParty/MyTargetSDK.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Tapjoy", "../ThirdParty/Tapjoy.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("UnityAds", "../ThirdParty/UnityAds.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("UserMessagingPlatform", "../ThirdParty/UserMessagingPlatform.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("VungleSDK", "../ThirdParty/VungleSDK.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("YYModel", "../ThirdParty/YYModel.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("YandexMobileAds", "../ThirdParty/YandexMobileAds.embeddedframework.zip", "YandexMobileAdsBundle.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("YandexMobileMetrica", "../ThirdParty/YandexMobileMetrica.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("YandexMobileMetricaCrashes", "../ThirdParty/YandexMobileMetricaCrashes.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasCore", "../ThirdParty/Yodo1MasCore.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationAdColony", "../ThirdParty/Yodo1MasMediationAdColony.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationAdMob", "../ThirdParty/Yodo1MasMediationAdMob.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationApplovin", "../ThirdParty/Yodo1MasMediationApplovin.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationFacebook", "../ThirdParty/Yodo1MasMediationFacebook.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationFyber", "../ThirdParty/Yodo1MasMediationFyber.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationInMobi", "../ThirdParty/Yodo1MasMediationInMobi.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationIronSource", "../ThirdParty/Yodo1MasMediationIronSource.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationMyTarget", "../ThirdParty/Yodo1MasMediationMyTarget.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationPangle", "../ThirdParty/Yodo1MasMediationPangle.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationTapjoy", "../ThirdParty/Yodo1MasMediationTapjoy.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationTencent", "../ThirdParty/Yodo1MasMediationTencent.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationUnityAds", "../ThirdParty/Yodo1MasMediationUnityAds.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationVungle", "../ThirdParty/Yodo1MasMediationVungle.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationYandex", "../ThirdParty/Yodo1MasMediationYandex.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1MasMediationYodo1", "../ThirdParty/Yodo1MasMediationYodo1.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1SaAnalyticsSDK", "../ThirdParty/Yodo1SaAnalyticsSDK.embeddedframework.zip", "Yodo1SensorsAnalyticsSDK.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("nanopb", "../ThirdParty/nanopb.embeddedframework.zip"));
			
			string ThirdPartyPath = Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString());
			string LibrariesPath = Path.Combine(ThirdPartyPath, "Libraries");

			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libGDTMobSDK.a"));

			PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/IOS"));
			
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString(), "Headers"));

			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(PluginPath, "YodoAds_IOS_UPL.xml"));
		}
	}
}
