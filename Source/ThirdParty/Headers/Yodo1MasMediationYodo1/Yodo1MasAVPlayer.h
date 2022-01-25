//
//  Yodo1MasAVPlayer.h
//  Yodo1MasMediationYodo1
//
//  Created by 周玉震 on 2021/10/29.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, Yodo1MasAVPlayerState) {
    Yodo1MasAVPlayerStateNone,
    Yodo1MasAVPlayerStateReady,
    Yodo1MasAVPlayerStatePlay,
    Yodo1MasAVPlayerStatePause,
    Yodo1MasAVPlayerStateError
};

@protocol Yodo1MasAVPlayerDelegate <NSObject>

@optional

- (void)onMasAVPlayerReady;

- (void)onMasAVPlayerPlay;

- (void)onMasAVPlayerPause;

- (void)onMasAVPlayerStop;

- (void)onMasAVPlayerError:(NSError *)error;

- (void)onMasAVPlayerProgressChanged:(long)progress duration:(long)duration;

@end

@interface Yodo1MasAVPlayer : AVPlayer

@property (nonatomic, copy, readonly) NSString *url;
@property (nonatomic, assign, readonly) long duration;
@property (nonatomic, assign, readonly) long progress;
@property (nonatomic, assign, readonly) Yodo1MasAVPlayerState state;

@property (nonatomic, weak) id<Yodo1MasAVPlayerDelegate> delegate;

- (void)prepare:(NSString *)url;
- (void)play;
- (void)pause;
- (void)stop;
- (void)seekTo:(long)progress;

@end

NS_ASSUME_NONNULL_END
