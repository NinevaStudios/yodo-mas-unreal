//
//  Yodo1MasYodo1BannerView.h
//  AFNetworking
//
//  Created by 周玉震 on 2021/11/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol Yodo1MasYodo1BannerDelegate <NSObject>

@optional
- (void)onMasYodo1BannerLoaded;
- (void)onMasYodo1BannerLoadFailed:(NSError *)error;
- (void)onMasYodo1BannerOpened;
- (void)onMasYodo1BannerClosed;
- (void)onMasYodo1BannerClicked;

@end

@interface Yodo1MasYodo1BannerView : UIView

@property (nonatomic, assign, readonly) BOOL isAdvertLoaded;
@property (nonatomic, weak) id<Yodo1MasYodo1BannerDelegate> delegate;

- (void)load;

@end

NS_ASSUME_NONNULL_END
