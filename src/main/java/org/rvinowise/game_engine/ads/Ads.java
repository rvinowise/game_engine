package org.rvinowise.game_engine.ads;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.InterstitialAd;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.reward.RewardItem;
import com.google.android.gms.ads.reward.RewardedVideoAd;
import com.google.android.gms.ads.reward.RewardedVideoAdListener;
import com.google.firebase.analytics.FirebaseAnalytics;



public class Ads extends AdListener  {

    private final Context context;
    //private final FirebaseAnalytics firebaseAnalytics;
    private final InterstitialAd interstitialAd;

    public Ads(Context in_context, String app_admob_id, String interstitial_ad_id) {
        context = in_context;

        //firebaseAnalytics = FirebaseAnalytics.getInstance(context);

        MobileAds.initialize(
                context.getApplicationContext(), app_admob_id);

        interstitialAd = new InterstitialAd(context);
        //interstitialAd.setAdUnitId(context.getString(R.string.interstitial_ad_test));
        interstitialAd.setAdUnitId(interstitial_ad_id);
        interstitialAd.setAdListener(this);



    }

    public void init() {

    }

    public void request_interstitial() {
        AdRequest adRequest = new AdRequest.Builder().build();
        interstitialAd.loadAd(adRequest);
    }


    public void can_show_interstitial() {
        if (interstitialAd.isLoaded()) {
            interstitialAd.show();
        }
    }


    public void onResume() {

    }
    public void onPause() {

    }


    @Override
    public void onAdClosed() {
        if (!interstitialAd.isLoading()) {
            request_interstitial();
        }
    }
    @Override
    public void onAdLeftApplication() {
        Log.d("ADS","onAdLeftApplication");
    }




}
