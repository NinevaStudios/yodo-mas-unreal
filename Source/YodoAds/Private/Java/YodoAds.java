package com.ninevastudios.yodoads;

import android.app.Activity;
import android.util.DisplayMetrics;
import android.view.ViewGroup;

import androidx.annotation.Keep;
import androidx.annotation.NonNull;

import com.yodo1.mas.Yodo1Mas;
import com.yodo1.mas.banner.Yodo1MasBannerAdListener;
import com.yodo1.mas.banner.Yodo1MasBannerAdSize;
import com.yodo1.mas.banner.Yodo1MasBannerAdView;
import com.yodo1.mas.error.Yodo1MasError;
import com.yodo1.mas.helper.model.Yodo1MasAdBuildConfig;
import com.yodo1.mas.utils.Yodo1MasBannerUtil;

@Keep
public class YodoAds {

	public static native void OnInitSuccess();

	public static native void OnInitError(String error);

	public static native void OnBannerAdLoaded(long pointer);

	public static native void OnBannerAdFailedToLoad(long pointer, String error);

	public static native void OnBannerAdOpened(long pointer);

	public static native void OnBannerAdFailedToOpen(long pointer, String error);

	public static native void OnBannerAdClosed(long pointer);

	public static void setConfig(boolean enableUserPrivacyDialog, boolean enableAdaptiveBanner,
	                             String privacyPolicyUrl, String userAgreementUrl) {
		Yodo1MasAdBuildConfig.Builder builder = new Yodo1MasAdBuildConfig.Builder()
				.enableUserPrivacyDialog(enableUserPrivacyDialog)
				.enableAdaptiveBanner(enableAdaptiveBanner);

		if (!privacyPolicyUrl.isEmpty())
			builder.privacyPolicyUrl(privacyPolicyUrl);
		if (!userAgreementUrl.isEmpty())
			builder.userAgreementUrl(userAgreementUrl);

		Yodo1Mas.getInstance().setAdBuildConfig(builder.build());
	}

	public static void initialize(final Activity activity, final String appKey) {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				Yodo1Mas.getInstance().init(activity, appKey, new Yodo1Mas.InitListener() {
					@Override
					public void onMasInitSuccessful() {
						OnInitSuccess();
					}

					@Override
					public void onMasInitFailed(@NonNull Yodo1MasError error) {
						OnInitError(getErrorString(error));
					}
				});
			}
		});
	}

	public static Yodo1MasBannerAdView createBannerView(Activity activity) {
		return new Yodo1MasBannerAdView(activity);
	}

	public static void setBannerSize(Yodo1MasBannerAdView view, int size) {
		view.setAdSize(parseSize(size));
	}

	public static void setBannerCallbacksAndLoad(Yodo1MasBannerAdView view, final long pointer) {
		view.setAdListener(new Yodo1MasBannerAdListener() {
			@Override
			public void onBannerAdLoaded(Yodo1MasBannerAdView bannerAdView) {
				OnBannerAdLoaded(pointer);
			}

			@Override
			public void onBannerAdFailedToLoad(Yodo1MasBannerAdView bannerAdView, @NonNull Yodo1MasError error) {
				OnBannerAdFailedToLoad(pointer, getErrorString(error));
			}

			@Override
			public void onBannerAdOpened(Yodo1MasBannerAdView bannerAdView) {
				OnBannerAdOpened(pointer);
			}

			@Override
			public void onBannerAdFailedToOpen(Yodo1MasBannerAdView bannerAdView, @NonNull Yodo1MasError error) {
				OnBannerAdFailedToOpen(pointer, getErrorString(error));
			}

			@Override
			public void onBannerAdClosed(Yodo1MasBannerAdView bannerAdView) {
				OnBannerAdClosed(pointer);
			}
		});

		view.loadAd();
	}

	public static void showBannerAd(final Activity activity, final Yodo1MasBannerAdView view, final int bannerType, final int alignmentHorizontal,
	                                final int alignmentVertical, final int offsetX, final int offsetY) {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				ViewGroup.LayoutParams params = Yodo1MasBannerUtil.getLayoutParamsByBannerSize(activity, parseSize(bannerType), null);
				view.setLayoutParams(params);

				setBannerPosition(activity, view, params, alignmentHorizontal, alignmentVertical, offsetX, offsetY);

				final ViewGroup viewGroup = activity.findViewById(android.R.id.content);
				viewGroup.addView(view);
			}
		});
	}

	private static void setBannerPosition(Activity activity, Yodo1MasBannerAdView view, ViewGroup.LayoutParams params, int alignmentHorizontal,
	                                      int alignmentVertical, int offsetX, int offsetY) {
		DisplayMetrics displayMetrics = activity.getResources().getDisplayMetrics();
		int screenWidth = displayMetrics.widthPixels;
		int screenHeight = displayMetrics.heightPixels;

		int bannerWidth = params.width;
		int bannerHeight = params.height;

		int positionX = calculatePositionX(alignmentHorizontal, screenWidth, bannerWidth, offsetX);
		int positionY = calculatePositionY(alignmentVertical, screenHeight, bannerHeight, offsetY);

		view.setX(positionX);
		view.setY(positionY);
	}

	private static int calculatePositionX(int alignmentHorizontal, int screenWidth, int bannerWidth, int offsetX) {
		int position;
		if (alignmentHorizontal == 0 || bannerWidth == ViewGroup.LayoutParams.MATCH_PARENT) {
			position = 0;
		} else if (alignmentHorizontal == 2) {
			position = screenWidth - bannerWidth;
		} else {
			position = (screenWidth - bannerWidth) / 2;
		}

		return position + offsetX;
	}

	private static int calculatePositionY(int alignmentVertical, int screenHeight, int bannerHeight, int offsetY) {
		int position;
		if (alignmentVertical == 0) {
			position = 0;
		} else if (alignmentVertical == 2) {
			position = screenHeight - bannerHeight;
		} else {
			position = (screenHeight - bannerHeight) / 2;
		}

		return position + offsetY;
	}

	public static void destroyBannerAd(Activity activity, final Yodo1MasBannerAdView view) {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				view.destroy();
			}
		});
	}

	private static String getErrorString(Yodo1MasError error) {
		return error.getCode() + " - " + error.getMessage();
	}

	private static Yodo1MasBannerAdSize parseSize(int size) {
		switch (size) {
			case 1:
				return Yodo1MasBannerAdSize.LargeBanner;
			case 2:
				return Yodo1MasBannerAdSize.IABMediumRectangle;
			case 3:
				return Yodo1MasBannerAdSize.SmartBanner;
			case 4:
				return Yodo1MasBannerAdSize.AdaptiveBanner;
			default:
				return Yodo1MasBannerAdSize.Banner;
		}
	}
}