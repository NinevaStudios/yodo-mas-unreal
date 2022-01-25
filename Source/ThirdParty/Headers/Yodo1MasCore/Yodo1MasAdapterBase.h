//
//  Yodo1MasAdapterBase.h
//  FBSDKCoreKit
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import "Yodo1Mas.h"
#import "Yodo1MasBanner.h"

NS_ASSUME_NONNULL_BEGIN

#define DelayTime 30
#define kArgumentPlacement        @"arg_placement"
#define kArgumentBannerAlign      @"arg_banner_align"
#define kArgumentBannerOffset     @"arg_banner_offset"

typedef void(^Yodo1MasAdapterInitSuccessful)(NSString *);
typedef void(^Yodo1MasAdapterInitFail)(NSString *, NSError *);


typedef NS_ENUM(NSInteger, Yodo1MasAdStatus) {
    Yodo1MasAdStatusNone,
    Yodo1MasAdStatusLoading,
    Yodo1MasAdStatusLoaded,
    Yodo1MasAdStatusOpened,
    Yodo1MasAdStatusError
};

@interface Yodo1MasAdapterConfig : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appKey;

@end

@interface Yodo1MasAdId : NSObject

@property (nonatomic, copy) NSString *adId;
@property (nonatomic, strong) id object;

- (instancetype)initWitId:(NSString *)adId object:(id __nullable)object;

@end

@class Yodo1MasBannerAdapterBase;
@interface Yodo1MasAdapterBase : NSObject

+ (NSString *)advertCode;
+ (NSString *)sdkVersion;
+ (NSString *)mediationVersion;

@property (nonatomic, copy) NSString *TAG;
@property (nonatomic, copy, readonly) NSString *advertCode;
@property (nonatomic, copy, readonly) NSString *sdkVersion;
@property (nonatomic, copy, readonly) NSString *mediationVersion;
@property (nonatomic, copy, readonly) Yodo1MasAdapterInitSuccessful initSuccessfulCallback;
@property (nonatomic, copy, readonly) Yodo1MasAdapterInitFail initFailCallback;
@property (nonatomic, copy) NSString * placement;

- (void)initWithConfig:(Yodo1MasAdapterConfig *)config successful:(Yodo1MasAdapterInitSuccessful)successful fail:(Yodo1MasAdapterInitFail)fail;
- (BOOL)isInitSDK;
- (void)updatePrivacy;

- (void)nextReward;
- (Yodo1MasAdId *)getRewardAdId;
- (void)nextInterstitial;
- (Yodo1MasAdId *)getInterstitialAdId;
- (void)nextBanner;
- (Yodo1MasAdId *)getBannerAdId;

- (BOOL)isAdLoaded:(Yodo1MasAdType)type;
- (void)loadAd:(Yodo1MasAdType)type;
- (void)loadAdDelayed:(Yodo1MasAdType)type;
- (void)showAd:(Yodo1MasAdType)type callback:(Yodo1MasAdCallback)callback object:(NSDictionary *)object;
- (BOOL)isCanShow:(Yodo1MasAdType)type callback:(Yodo1MasAdCallback)callback;
- (void)callbackWithEvent:(Yodo1MasAdEventCode)code type:(Yodo1MasAdType)type;
- (void)callbackWithError:(Yodo1MasError *)error type:(Yodo1MasAdType)type;
- (void)callbackWithAdLoadSuccess:(Yodo1MasAdType)type;

#pragma mark - 激励广告
@property (nonatomic, strong) NSMutableArray<Yodo1MasAdId *> *rewardAdIds;
@property (nonatomic, copy, readonly) Yodo1MasAdCallback rewardCallback;

- (BOOL)isRewardAdLoaded;
- (void)loadRewardAd;
- (void)loadRewardAdDelayed;
- (void)showRewardAd:(Yodo1MasAdCallback)callback object:(NSDictionary *)object;
- (void)dismissRewardAd;

#pragma mark - 插屏广告
@property (nonatomic, strong) NSMutableArray<Yodo1MasAdId *> *interstitialAdIds;
@property (nonatomic, copy, readonly) Yodo1MasAdCallback interstitialCallback;

- (BOOL)isInterstitialAdLoaded;
- (void)loadInterstitialAd;
- (void)loadInterstitialAdDelayed;
- (void)showInterstitialAd:(Yodo1MasAdCallback)callback object:(NSDictionary *)object;
- (void)dismissInterstitialAd;

#pragma mark - 横幅广告
@property (nonatomic, strong, readonly) NSMutableArray<Yodo1MasAdId *> *bannerAdIds;
- (Class)bannerAdapterClass;
- (BOOL)isBannerSizeSupport:(Yodo1MasBannerAdSize)size;
- (BOOL)isMultipleBannerSupport;
- (Yodo1MasBannerAdapterBase *)getBanner;

#pragma mark - Common
+ (UIWindow * _Nullable )getTopWindow;
+ (UIViewController * _Nullable )getTopViewController;

@end

NS_ASSUME_NONNULL_END
