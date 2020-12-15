//
//  UIView+Extension.h
//  BWM_iOS
//
//  Created by JoySang on 2019/10/12.
//  Copyright © 2019 JoySang. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Extension)
/**
 *  @brief  设置视图圆角
 *
 *  @param corner 角度值
 */
- (void)setRoundWithCorner:(CGFloat)corner;

/**
 *  @brief  获取当前view所在的控制器对象
 *
 *  @return 返回当前view所在的控制器对象
 */
- (UIViewController *)viewController;
@end

NS_ASSUME_NONNULL_END
