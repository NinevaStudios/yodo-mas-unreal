// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Private/NativeObjectWrapper.h"

#include "YodoAdsLibrary.h"

#include "YodoAdsBanner.generated.h"

UENUM()
enum class EYABannerSize : uint8
{
	Banner = 0,
	LargeBanner = 1,
	IABMediumRectangle = 2,
	SmartBanner = 3,
	AdaptiveBanner = 4
};

UENUM()
enum class EYABannerHorizontalPosition : uint8
{
	Left = 1,
	Center = 2,
	Right = 4
};

UENUM()
enum class EYABannerVerticalPosition : uint8
{
	Top = 8,
	Center = 16,
	Bottom = 32
};

UCLASS(BlueprintType)
class YODOADS_API UYodoAdsBanner : public UNativeObjectWrapper
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void SetSize(EYABannerSize Size);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void Show(EYABannerHorizontalPosition HorizontalPosition, EYABannerVerticalPosition VerticalPosition, const FVector2D& Offset);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdLoadedDelegate(const FYAVoidDelegate& OnBannerAdLoadedCallback)
	{
		OnBannerAdLoaded = OnBannerAdLoadedCallback;
	}

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdFailedToLoadDelegate(const FYAErrorDelegate& OnBannerAdFailedToLoadCallback)
	{
		OnBannerAdFailedToLoad = OnBannerAdFailedToLoadCallback;
	}

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdOpenedDelegate(const FYAVoidDelegate& OnBannerAdOpenedCallback)
	{
		OnBannerAdOpened = OnBannerAdOpenedCallback;
	}

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	void BindOnBannerAdFailedToOpenDelegate(const FYAErrorDelegate& OnBannerAdFailedToOpenCallback)
	{
		OnBannerAdFailedToOpen = OnBannerAdFailedToOpenCallback;
	}

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
};