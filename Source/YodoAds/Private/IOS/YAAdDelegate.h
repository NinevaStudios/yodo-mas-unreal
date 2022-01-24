// Copyright (c) 2022 Nineva Studios

#pragma once

#import <Foundation/Foundation.h>
#import <Yodo1Mas.h>
#import <Yodo1MasBannerAdView.h>

@interface YAInterstitialAdDelegate : NSObject <Yodo1MasInterstitialAdDelegate>

@property (nonatomic, copy) void (^onAdOpened)();

@property (nonatomic, copy) void (^onAdClosed)();

@property (nonatomic, copy) void (^onAdError)(Yodo1MasError* error);

@end

@interface YARewardedAdDelegate : NSObject <Yodo1MasRewardAdDelegate>

@property (nonatomic, copy) void (^onAdOpened)();

@property (nonatomic, copy) void (^onAdClosed)();

@property (nonatomic, copy) void (^onAdError)(Yodo1MasError* error);

@property (nonatomic, copy) void (^onReward)();

@end

@interface YABannerAdDelegate : NSObject <Yodo1MasBannerAdViewDelegate>

@property (nonatomic, copy) void (^onAdOpened)();

@property (nonatomic, copy) void (^onOpenAdError)(Yodo1MasError* error);

@property (nonatomic, copy) void (^onAdLoaded)();

@property (nonatomic, copy) void (^onLoadAdError)(Yodo1MasError* error);

@property (nonatomic, copy) void (^onAdClosed)();

@end
