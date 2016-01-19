//
//  TNKActivityIndicatorView.h
//  Pods
//
//  Created by David Beck on 1/13/15.
//
//

#import <UIKit/UIKit.h>


IB_DESIGNABLE
@interface TNKActivityIndicatorView : UIView

/** The current progress indicated when not animating
 
 When the indicator view is not animating, it shows the progress as a percentage of the circle. Setting this to 0 (the default) will have the affect of hiding the view when it isn't animating.
 */
@property (nonatomic) IBInspectable CGFloat progress;

/** Set the current progress with an optional animation
 
 Changes the current progress to the new value, optionally animating to the new value.
 
 @param progress The new progress
 @param animated Controls whether the change is animated or not.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;


/** Starts the animation of the progress indicator.
 
 Calls `-stopAnimatingWithFadeAwayAnimation:completion:` with YES if progress is 0, and with NO otherwise.
 */
- (void)startAnimating;

/** Starts the animation of the progress indicator.
 
 When the progress indicator is animated, it spins to indicate indeterminate progress. The indicator is animated until `-stopAnimatingWithFadeAwayAnimation:completion:` is called.
 
 Use this method to control the fade in animation. When animated is YES, the view grows and fades in animated. When NO, it will immediately jump to fullsize.
 
 If the indicator is already animating, the completion block is never called.
 
 @param animated Whether to fade in with an animation.
 @param completion A completion block that is called when the fade in animation finishes.
 */
- (void)startAnimatingWithFadeInAnimation:(BOOL)animated completion:(void (^)())completion;

/** Stops the animation of the progress indicator.
 
 Calls `-stopAnimatingWithFadeAwayAnimation:completion:` with YES.
 */
- (void)stopAnimating;

/** Stops the animation of the progress indicator.
 
 Stops the animation of the progress indicator started with a call to startAnimating. When animating is stopped, the indicator shows the current progress.
 
 Use this method to control the fade away animation. When animated is YES, the view shrinks and fades away animated. When NO, it will immediately jump to displaying the current progress.
 
 If the indicator is not animating, the completion block is never called.
 
 @param animated Whether to fade away with an animation.
 @param completion A completion block that is called when the fade away animation finishes.
 */
- (void)stopAnimatingWithFadeAwayAnimation:(BOOL)animated completion:(void (^)())completion;

/** Returns whether the receiver is animating.
 
 YES if the receiver is animating, otherwise NO.
 
 This property is YES until the fade away animation has finished, or immediately after calling `-stopAnimatingWithFadeAwayAnimation:completion:` with NO.
 */
@property (nonatomic, readonly, getter=isAnimating) IBInspectable BOOL animating;

@end
