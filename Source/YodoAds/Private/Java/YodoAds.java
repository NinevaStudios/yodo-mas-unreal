package com.ninevastudios.yodoads;

import android.app.Activity;

import androidx.annotation.Keep;
import androidx.annotation.NonNull;

import com.yodo1.mas.Yodo1Mas;
import com.yodo1.mas.error.Yodo1MasError;
import com.yodo1.mas.helper.model.Yodo1MasAdBuildConfig;

@Keep
public class YodoAds {

	public static native void OnInitSuccess();

	public static native void OnInitError(String error);

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

	public static void initialize(Activity activity, String appKey) {
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

	private static String getErrorString(Yodo1MasError error) {
		return error.getCode() + " - " + error.getMessage();
	}
}