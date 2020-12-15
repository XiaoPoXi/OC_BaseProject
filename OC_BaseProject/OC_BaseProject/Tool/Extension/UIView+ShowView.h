//
//  UIView+ShowView.h
//  HaoWu
//
//  Created by JUMIWGQ on 2019/1/7.
//  Copyright © 2019 JUMI. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ShowView)

- (void)showWithNoDiss;

//View展示界面
- (void)show;

- (void)showWithSize:(CGSize)size;

- (void)showWithFrame:(CGRect)frame;
//- (void)showWithDissMissAndFrame:(CGRect)frame;

//View消失界面
- (void)dismiss;


- (void)diyView;

@end

NS_ASSUME_NONNULL_END
