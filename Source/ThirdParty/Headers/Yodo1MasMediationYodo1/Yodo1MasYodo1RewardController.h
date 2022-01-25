//
//  Yodo1MasYodo1RewardController.h
//  Yodo1MasMediationYodo1
//
//  Created by 周玉震 on 2021/11/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol Yodo1MasYodo1RewardDelegate <NSObject>

@optional
- (void)onMasYodo1RewardLoaded;
- (void)onMasYodo1RewardLoadFailed:(NSError *)error;
- (void)onMasYodo1RewardOpened;
- (void)onMasYodo1RewardClosed;
- (void)onMasYodo1RewardClicked;
- (void)onMasYodo1Rewarded;

@end

@interface Yodo1MasYodo1RewardController : UIViewController

@property (nonatomic, assign, readonly) BOOL isAdvertLoaded;
@property (nonatomic, weak) id<Yodo1MasYodo1RewardDelegate> delegate;

- (void)load;
- (void)showInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
