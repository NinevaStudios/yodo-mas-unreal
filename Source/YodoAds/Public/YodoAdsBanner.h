// Copyright (c) 2022 Nineva Studios

#pragma once

#include "NativeObjectWrapper.h"

#include "YodoAdsLibrary.h"

#include "YodoAdsBanner.generated.h"

/**
* Possible banner ad sizes.
*/
UENUM()
enum class EYABannerSize : uint8
{
	/*320×50*/
	Banner = 0,
	/*320×100*/
	LargeBanner = 1,
	/*300×250*/
	IABMediumRectangle = 2,
	/*Full screen width x Adaptive height*/
	SmartBanner = 3,
	/*Screen width x 32/50/90*/
	AdaptiveBanner = 4
};

/**
* Horizontal alignment of the banner.
*/
UENUM()
enum class EYABannerHorizontalPosition : uint8
{
	Left = 0,
	Center = 1,
	Right = 2
};

/**
* Vertical alignment of the banner.
*/
UENUM()
enum class EYABannerVerticalPosition : uint8
{
	Top = 0,
	Center = 1,
	Bottom = 2
};

/**
* Wrapper class for the banner ads.
*/
UCLASS(BlueprintType)
class YODOADS_API UYodoAdsBanner : public UNativeObjectWrapper
{
	GENERATED_BODY()

public:

	/**
	* Set the banner size. Call before loading.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void SetSize(EYABannerSize Size);

	/**
	* Set the ad placement ID (optional). Call before loading.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void SetPlacement(const FString& PlacementId);

	/**
	* Load ad. Make sure to set the size and bind callbacks before loading.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void LoadAd();

	/**
	* Show ad. Make sure to call this after the ad is loaded.
	*
	* @param HorizontalPosition - horizontal alignment of the banner.
	* @param VerticalPosition - vertical alignment of the banner.
	* @param Offset - offset from the aligned position. Shifts: Negative X - left, Positive X - right, Negative Y - up, Positive Y - down.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void Show(EYABannerHorizontalPosition HorizontalPosition, EYABannerVerticalPosition VerticalPosition, const FVector2D& Offset);

	/**
	* Destroy ad.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void Destroy();

	/**
	* Bind a function to be called after the ad is loaded.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdLoadedDelegate(const FYAVoidDelegate& OnBannerAdLoadedCallback)
	{
		OnBannerAdLoaded = OnBannerAdLoadedCallback;
	}

	/**
	* Bind a function to be called if the ad loading has failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdFailedToLoadDelegate(const FYAErrorDelegate& OnBannerAdFailedToLoadCallback)
	{
		OnBannerAdFailedToLoad = OnBannerAdFailedToLoadCallback;
	}

	/**
	* Bind a function to be called after the ad is opened (shown).
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdOpenedDelegate(const FYAVoidDelegate& OnBannerAdOpenedCallback)
	{
		OnBannerAdOpened = OnBannerAdOpenedCallback;
	}

	/**
	* Bind a function to be called if the ad has failed to show.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdFailedToOpenDelegate(const FYAErrorDelegate& OnBannerAdFailedToOpenCallback)
	{
		OnBannerAdFailedToOpen = OnBannerAdFailedToOpenCallback;
	}

	/**
	* Bind a function to be called after the ad is closed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdClosedDelegate(const FYAVoidDelegate& OnBannerAdClosedCallback)
	{
		OnBannerAdClosed = OnBannerAdClosedCallback;
	}

	FYAVoidDelegate OnBannerAdLoaded;
	FYAErrorDelegate OnBannerAdFailedToLoad;
	FYAVoidDelegate OnBannerAdOpened;
	FYAErrorDelegate OnBannerAdFailedToOpen;
	FYAVoidDelegate OnBannerAdClosed;

private:
	EYABannerSize BannerSize = EYABannerSize::Banner;

};
