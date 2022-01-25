//
//  Yodo1MasBannerAdView.h
//  AFNetworking
//
//  Created by 周玉震 on 2021/10/27.
//

#import <UIKit/UIKit.h>
#import "Yodo1MasError.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasBannerAdView;
@protocol Yodo1MasBannerAdViewDelegate <NSObject>

@optional;
- (void)onBannerAdLoaded:(Yodo1MasBannerAdView *)banner;
- (void)onBannerAdFailedToLoad:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error;
- (void)onBannerAdOpened:(Yodo1MasBannerAdView *)banner;
- (void)onBannerAdClosed:(Yodo1MasBannerAdView *)banner;
- (void)onBannerAdFailedToOpen:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error;

@end

@interface Yodo1MasBannerAdView : UIView

@property (nonatomic, assign, readonly) Yodo1MasBannerAdSize adSize;
@property (nonatomic, copy, readonly) NSString *adPlacement;
@property (nonatomic, weak) id<Yodo1MasBannerAdViewDelegate> adDelegate;

- (instancetype)initWithPlacement:(NSString *)placement size:(Yodo1MasBannerAdSize)size;
- (void)setAdPlacement:(NSString * _Nonnull)adPlacement;
- (void)setAdSize:(Yodo1MasBannerAdSize)adSize;
- (BOOL)isLoaded;
- (void)loadAd;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
