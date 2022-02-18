// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "YodoAdsLibrary.generated.h"

/**
* Structure to pass the config values for Yoda Ads SDK.
*/
USTRUCT(BlueprintType)
struct FYodoAdsConfig
{
	GENERATED_BODY()

	/**
	* Whether to show the default user privacy dialog on the first run of the application.
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	bool EnableUserPrivacyDialog = false;

	/**
	* Whether to enable adaptive banner ads.
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	bool EnableAdaptiveBanner = false;

	/**
	* Privacy policy URL to redirect to after the respective hyperlink is clicked on the User Privacy Dialog.
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	FString PrivacyPolicyUrl = "";

	/**
	* User agreement URL to redirect to after the respective hyperlink is clicked on the User Privacy Dialog.
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	FString UserAgreementUrl = "";
};

DECLARE_DYNAMIC_DELEGATE(FYAVoidDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FYAErrorDelegate, FString, Error);

class UYodoAdsBanner;

/**
* Main entry point of the Yodo SDK.
*/
UCLASS()
class YODOADS_API UYodoAdsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	* Set the configuration values for SDK before initializing.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetConfig(const FYodoAdsConfig& Config);

	/**
	* Initialize the SDK. Make sure to call all functions except SetConfig after the SDK is initialized (OnSuccess callback is invoked).
	 *
	 * @param OnSuccess - callback to be invoked after the successful initialization of the SDK.
	 * @param OnError - callback to be invoked with the error message if something goes wrong.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnSuccess,OnError"))
	static void Initialize(const FYAVoidDelegate& OnSuccess, const FYAErrorDelegate& OnError);

	/**
	* Set whether user has given consent to data gathering.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetGDPR(bool UserConsent);

	/**
	* Whether user has given consent to data gathering.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsGDPRUserConsent();

	/**
	* Set whether user is a child.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetCOPPA(bool AgeRestricted);

	/**
	* Whether user is a child.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsCOPPAAgeRestricted();

	/**
	* Set whether user has allowed data selling (California only).
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetCCPA(bool DontSell);

	/**
	* Whether user has allowed data selling (California only).
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsCCPADontSell();

	/**
	* Set global rewarded ad callbacks.
	 *
	 * @param OnOpened - callback to be invoked after the ad is opened.
	 * @param OnError - callback to be invoked with the error message if something goes wrong.
	 * @param OnClosed - callback to be invoked after the ad is closed.
	 * @param OnRewardEarned - callback to be invoked after the ad has finished playing, and a reward is earned.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnOpened,OnError,OnClosed,OnRewardEarned"))
	static void SetRewardedAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed, const FYAVoidDelegate& OnRewardEarned);

	/**
	* Whether next rewarded ad is loaded.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsRewardedAdLoaded();

	/**
	* Show rewarded ad with optional placement.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void ShowRewardedAd(const FString& Placement = "");

	/**
	* Set global interstitial ad callbacks.
	 *
	 * @param OnOpened - callback to be invoked after the ad is opened.
	 * @param OnError - callback to be invoked with the error message if something goes wrong.
	 * @param OnClosed - callback to be invoked after the ad is closed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnOpened,OnError,OnClosed"))
	static void SetInterstitialAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed);

	/**
	* Whether next interstitial ad is loaded.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsInterstitialAdLoaded();

	/**
	* Show interstitial ad with optional placement.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void ShowInterstitialAd(const FString& Placement = "");

	/**
	* Create a banner ad.
	*/
	UFUNCTION(BlueprintPure, Category = "Yodo Ads")
	static UYodoAdsBanner* MakeBannerAd();

	static FYAVoidDelegate OnInitializeSuccess;
	static FYAErrorDelegate OnInitializeError;

	static FYAVoidDelegate OnRewardedAdOpened;
	static FYAErrorDelegate OnRewardedAdError;
	static FYAVoidDelegate OnRewardedAdClosed;
	static FYAVoidDelegate OnRewardedAdRewardEarned;

	static FYAVoidDelegate OnInterstitialAdOpened;
	static FYAErrorDelegate OnInterstitialAdError;
	static FYAVoidDelegate OnInterstitialAdClosed;

	static const ANSICHAR* YodoAdsClassName;
};
