//
//  Yodo1MasBannerAdapterBase.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2021/11/22.
//

#import <Foundation/Foundation.h>
#import "Yodo1Mas.h"
#import "Yodo1MasBanner.h"
#import "Yodo1MasAdapterBase.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasBannerAdapterBase;
@protocol Yodo1MasAdapterBannerDelegate <NSObject>

@optional
- (void)adapter:(Yodo1MasBannerAdapterBase *)adapter didBannerAdLoad:(UIView *)banner;
- (void)adapter:(Yodo1MasBannerAdapterBase *)adapter didBannerAdLoadFail:(Yodo1MasError *)error;
- (void)adapter:(Yodo1MasBannerAdapterBase *)adapter didBannerAdClick:(UIView *)banner;

@end

@class Yodo1MasAdId;
@interface Yodo1MasBannerAdapterBase : NSObject

+ (BOOL)isBannerSizeSupport:(Yodo1MasBannerAdSize)size;
+ (BOOL)isMultipleBannerSupport;

@property (nonatomic, copy, readonly) NSString *TAG;
@property (nonatomic, copy, readonly) NSString *advertCode;
@property (nonatomic, copy, readonly) NSString *sdkVersion;

@property (nonatomic, assign, readonly) Yodo1MasAdPriceType maxPriceType;
@property (nonatomic, assign, readonly) CGFloat maxPrice;
@property (nonatomic, assign, readonly) Yodo1MasAdPriceType priceType;
@property (nonatomic, assign, readonly) CGFloat price;
@property (nonatomic, assign, readonly) UIView *bannerView;
@property (nonatomic, assign, readonly) BOOL isBannerAdLoaded;
@property (nonatomic, assign) Yodo1MasAdStatus bannerStatus;
@property (nonatomic, copy) NSString *bannerPlacement;
@property (nonatomic, weak) id<Yodo1MasAdapterBannerDelegate> bannerDelegate;

- (instancetype)initWithAdUnitId:(NSArray<Yodo1MasAdId *> *)unitIds;
- (CGSize)bannerSize:(Yodo1MasBannerAdSize)size;
- (CGSize)bannerContentSize;

#pragma mark - public
- (void)loadBannerAd:(Yodo1MasBannerAdSize)size controller:(UIViewController *)controller;
- (void)loadNextBannerAd;
- (void)destroyBanner;

#pragma mark - private
- (id)getAdUnitId:(BOOL)next;
- (void)callbackLoad:(id _Nullable)args;
- (void)callbackError:(Yodo1MasError *)error;
- (void)callbackClick;

@end

NS_ASSUME_NONNULL_END
