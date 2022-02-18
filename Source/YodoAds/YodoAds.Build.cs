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
					"VideoToolbox"
				}
			);
			
			PublicSystemLibraries.Add("c++");
			PublicSystemLibraries.Add("c++abi");
			PublicSystemLibraries.Add("sqlite3");
			PublicSystemLibraries.Add("sqlite3.0");
			PublicSystemLibraries.Add("xml2");
			PublicSystemLibraries.Add("xml2.2");
			PublicSystemLibraries.Add("bz2");
			PublicSystemLibraries.Add("resolv");
			PublicSystemLibraries.Add("iconv");
			PublicSystemLibraries.Add("z");
			
			PublicAdditionalFrameworks.Add (new Framework ("AdColony", "../ThirdParty/AdColony.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("AppLovinSDK", "../ThirdParty/AppLovinSDK.embeddedframework.zip", "AppLovinSDKResources.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("BUAdSDK", "../ThirdParty/BUAdSDK.embeddedframework.zip", "BUAdSDK.bundle"));
			PublicAdditionalFrameworks.Add (new Framework ("BUCNAuxiliary", "../ThirdParty/BUCNAuxiliary.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("BUFoundation", "../ThirdParty/BUFoundation.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("BUVAAuxiliary", "../ThirdParty/BUVAAuxiliary.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("FBAudienceNetwork", "../ThirdParty/FBAudienceNetwork.embeddedframework.zip"));
			// PublicAdditionalFrameworks.Add (new Framework ("PromisesObjC", "../ThirdParty/PromisesObjC.embeddedframework.zip"));
			// PublicAdditionalFrameworks.Add (new Framework ("FBSDKCoreKit_Basics", "../ThirdParty/FBSDKCoreKit_Basics.embeddedframework.zip"));
			// PublicAdditionalFrameworks.Add (new Framework ("GoogleAppMeasurement", "../ThirdParty/GoogleAppMeasurement.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleAppMeasurementIdentitySupport", "../ThirdParty/GoogleAppMeasurementIdentitySupport.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add (new Framework ("GoogleMobileAds", "../ThirdParty/GoogleMobileAds.embeddedframework.zip"));
			// PublicAdditionalFrameworks.Add (new Framework ("GoogleUtilities", "../ThirdParty/GoogleUtilities.embeddedframework.zip"));
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
			PublicAdditionalFrameworks.Add (new Framework ("Yodo1SaAnalyticsSDK", "../ThirdParty/Yodo1SaAnalyticsSDK.embeddedframework.zip", "Yodo1SensorsAnalyticsSDK.bundle"));
			// PublicAdditionalFrameworks.Add (new Framework ("nanopb", "../ThirdParty/nanopb.embeddedframework.zip"));
			
			// Mediation Adapters
			PublicAdditionalFrameworks.Add(new Framework("AdColonyAdapter", "../ThirdParty/AdColonyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinAdapter", "../ThirdParty/AppLovinAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationAdColonyAdapter", "../ThirdParty/AppLovinMediationAdColonyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationByteDanceAdapter", "../ThirdParty/AppLovinMediationByteDanceAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationFacebookAdapter", "../ThirdParty/AppLovinMediationFacebookAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationFyberAdapter", "../ThirdParty/AppLovinMediationFyberAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationGoogleAdapter", "../ThirdParty/AppLovinMediationGoogleAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationInMobiAdapter", "../ThirdParty/AppLovinMediationInMobiAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationIronSourceAdapter", "../ThirdParty/AppLovinMediationIronSourceAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationMyTargetAdapter", "../ThirdParty/AppLovinMediationMyTargetAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationTapjoyAdapter", "../ThirdParty/AppLovinMediationTapjoyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationTencentGDTAdapter", "../ThirdParty/AppLovinMediationTencentGDTAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationUnityAdsAdapter", "../ThirdParty/AppLovinMediationUnityAdsAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationVungleAdapter", "../ThirdParty/AppLovinMediationVungleAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("AppLovinMediationYandexAdapter", "../ThirdParty/AppLovinMediationYandexAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("FacebookAdapter", "../ThirdParty/FacebookAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("FyberAdapter", "../ThirdParty/FyberAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISAdColonyAdapter", "../ThirdParty/ISAdColonyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISAdMobAdapter", "../ThirdParty/ISAdMobAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISAppLovinAdapter", "../ThirdParty/ISAppLovinAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISFacebookAdapter", "../ThirdParty/ISFacebookAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISFyberAdapter", "../ThirdParty/ISFyberAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISInMobiAdapter", "../ThirdParty/ISInMobiAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISPangleAdapter", "../ThirdParty/ISPangleAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISTapjoyAdapter", "../ThirdParty/ISTapjoyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISUnityAdsAdapter", "../ThirdParty/ISUnityAdsAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("ISVungleAdapter", "../ThirdParty/ISVungleAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("InMobiAdapter", "../ThirdParty/InMobiAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("IronSourceAdapter", "../ThirdParty/IronSourceAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("MyTargetAdapter", "../ThirdParty/MyTargetAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("TapjoyAdapter", "../ThirdParty/TapjoyAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("UnityAdapter", "../ThirdParty/UnityAdapter.embeddedframework.zip"));
			PublicAdditionalFrameworks.Add(new Framework("VungleAdapter", "../ThirdParty/VungleAdapter.embeddedframework.zip"));
			
			string ThirdPartyPath = Path.Combine(ModuleDirectory, "../ThirdParty");
			string LibrariesPath = Path.Combine(ThirdPartyPath, "Libraries");

			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libGDTMobSDK.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libAFNetworking.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasCore.a"));
			
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationIronSource.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationMyTarget.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationPangle.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationAdColony.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationTapjoy.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationAdMob.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationTencent.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationApplovin.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationUnityAds.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationFacebook.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationVungle.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationFyber.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationYandex.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationInMobi.a"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libYodo1MasMediationYodo1.a"));

			PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/IOS"));
			
			string HeadersPath = Path.Combine(ModuleDirectory, "../ThirdParty", "Headers");
			
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "AFNetworking"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationFacebook"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationTapjoy"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "GDTMobSDK"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationFyber"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationTencent"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasCore"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationInMobi"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationUnityAds"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationAdColony"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationIronSource"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationVungle"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationAdMob"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationMyTarget"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationYandex"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationApplovin"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationPangle"));
			PublicIncludePaths.Add(Path.Combine(HeadersPath, "Yodo1MasMediationYodo1"));
			
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../ThirdParty", "Headers"));

			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(PluginPath, "YodoAds_IOS_UPL.xml"));
		}
	}
}
