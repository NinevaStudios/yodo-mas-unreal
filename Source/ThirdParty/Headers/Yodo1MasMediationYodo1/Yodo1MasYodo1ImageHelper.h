//
//  Yodo1MasYodo1ImageHelper.h
//  Yodo1MasMediationYodo1
//
//  Created by 周玉震 on 2021/11/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasYodo1ImageHelper : NSObject

+ (void)loadImageWithURL:(NSString *)url
                   block:(void (^)(UIImage *))block;

@end

NS_ASSUME_NONNULL_END
