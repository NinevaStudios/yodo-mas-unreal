//
//  Yodo1MasPrivacyDialog.h
//  AFNetworking
//
//  Created by 周玉震 on 2021/8/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define kYodo1MasPrivacyDialog      @"Yodo1MasPrivacyDialog"
#define kYodo1MasPrivacyAge         @"Yodo1MasPrivacyAge"

@interface Yodo1MasPrivacyDialog : UIViewController

@property (nonatomic, copy) void (^Yodo1MasPrivacyDialogBlock)(void);

- (void)setContentSize;
- (void)showInVC:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
