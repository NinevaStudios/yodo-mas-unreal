// Copyright (c) 2022 Nineva Studios

#include "YAAdDelegate.h"

@implementation YAInterstitialAdDelegate

- (void)onAdOpened:(Yodo1MasAdEvent *)event {
	if (_onAdOpened)
		_onAdOpened();
}

- (void)onAdClosed:(Yodo1MasAdEvent *)event {
	if (_onAdClosed)
		_onAdClosed();
}

- (void)onAdError:(Yodo1MasAdEvent *)event error:(Yodo1MasError *)error {
	if (_onAdError)
		_onAdError(error);
}

@end

@implementation YARewardedAdDelegate

- (void)onAdOpened:(Yodo1MasAdEvent *)event {
	if (_onAdOpened)
		_onAdOpened();
}

- (void)onAdClosed:(Yodo1MasAdEvent *)event {
	if (_onAdClosed)
		_onAdClosed();
}

- (void)onAdError:(Yodo1MasAdEvent *)event error:(Yodo1MasError *)error {
	if (_onAdError)
		_onAdError(error);
}

- (void)onAdRewardEarned:(Yodo1MasAdEvent *)event {
	if (_onReward)
		_onReward();
}

@end

@implementation YABannerAdDelegate

- (void)onBannerAdLoaded:(Yodo1MasBannerAdView *)banner {
	if (_onAdLoaded)
		_onAdLoaded();
}

- (void)onBannerAdFailedToLoad:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error {
	if (_onLoadAdError)
		_onLoadAdError(error);
}

- (void)onBannerAdOpened:(Yodo1MasBannerAdView *)banner {
	if (_onAdOpened)
		_onAdOpened();
}

- (void)onBannerAdClosed:(Yodo1MasBannerAdView *)banner {
	if (_onAdClosed)
		_onAdClosed();
}

- (void)onBannerAdFailedToOpen:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error {
	if (_onOpenAdError)
		_onOpenAdError(error);
}

@end
