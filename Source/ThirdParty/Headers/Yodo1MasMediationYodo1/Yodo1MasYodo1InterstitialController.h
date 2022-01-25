//
//  Yodo1MasYodo1InterstitialController.h
//  Yodo1MasMediationYodo1
//
//  Created by 周玉震 on 2021/11/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol Yodo1MasYodo1InterstitialDelegate <NSObject>

@optional
- (void)onMasYodo1InterstitialLoaded;
- (void)onMasYodo1InterstitialLoadFailed:(NSError *)error;
- (void)onMasYodo1InterstitialOpened;
- (void)onMasYodo1InterstitialClosed;
- (void)onMasYodo1InterstitialClicked;

@end

@interface Yodo1MasYodo1InterstitialController : UIViewController

@property (nonatomic, assign, readonly) BOOL isAdvertLoaded;
@property (nonatomic, weak) id<Yodo1MasYodo1InterstitialDelegate> delegate;

- (void)load;
- (void)showInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
