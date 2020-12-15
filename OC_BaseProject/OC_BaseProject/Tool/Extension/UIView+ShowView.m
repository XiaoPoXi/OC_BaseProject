//
//  UIView+ShowView.m
//  HaoWu
//
//  Created by JUMIWGQ on 2019/1/7.
//  Copyright © 2019 JUMI. All rights reserved.
//  view  弹框
//　   ╭╬╮
//▁╭▅▆▇□□█▇▆▅▄▃▂▁(WGQ)█╮
//╰═▃__▁▁▁▁▁∠════▔▔▔
//　　 ╙O 　 ╙O

#import "UIView+ShowView.h"

static UIButton *_cover;

@implementation UIView (ShowView)

//动画
- (void)animatedIn
{
    self.transform = CGAffineTransformMakeScale(1.3, 1.3);
    self.alpha = 0;
    [UIView animateWithDuration:.35 animations:^{
        self.alpha = 1;
        self.transform = CGAffineTransformMakeScale(1, 1);
    }];
}
//动画
- (void)animatedOut
{
    [UIView animateWithDuration:.35 animations:^{
        [self removeFromSuperview];
        [_cover removeFromSuperview];
        _cover = nil;
     }];
}

- (void)showWithNoDiss
{
    UIWindow * keyWindow = [[[UIApplication sharedApplication] delegate] window];
    keyWindow.windowLevel = UIWindowLevelNormal;
    
    // 遮盖
    UIButton *cover = [[UIButton alloc] init];
    cover.backgroundColor = [UIColor blackColor];
    cover.alpha = 0.4;
//    [cover addTarget:self action:@selector(animatedOut) forControlEvents:UIControlEventTouchUpInside];
    cover.frame = [UIScreen mainScreen].bounds;
    _cover = cover;
    
    [keyWindow addSubview:cover];
    [keyWindow addSubview:self];
    
    self.center = CGPointMake(keyWindow.bounds.size.width/2.0f,
                              keyWindow.bounds.size.height/2.0f);
    [self animatedIn];
}

//界面展示
- (void)show
{
    UIWindow * keyWindow = [[[UIApplication sharedApplication] delegate] window];
    keyWindow.windowLevel = UIWindowLevelNormal;
    
    // 遮盖
    UIButton *cover = [[UIButton alloc] init];
    cover.backgroundColor = [UIColor blackColor];
    cover.alpha = 0.4;
    [cover addTarget:self action:@selector(animatedOut) forControlEvents:UIControlEventTouchUpInside];
    cover.frame = [UIScreen mainScreen].bounds;
    _cover = cover;
    
    [keyWindow addSubview:cover];
    [keyWindow addSubview:self];
    
    self.center = CGPointMake(keyWindow.bounds.size.width/2.0f,
                              keyWindow.bounds.size.height/2.0f);
    [self animatedIn];
}

- (void)showWithSize:(CGSize)size
{
    UIWindow * keyWindow = [[[UIApplication sharedApplication] delegate] window];
    keyWindow.windowLevel = UIWindowLevelNormal;
    
    // 遮盖
    UIButton *cover = [[UIButton alloc] init];
    cover.backgroundColor = [UIColor blackColor];
    cover.alpha = 0.4;
//    [cover addTarget:self action:@selector(animatedOut) forControlEvents:UIControlEventTouchUpInside];
    cover.frame = [UIScreen mainScreen].bounds;
    _cover = cover;
    
    [keyWindow addSubview:cover];
    [keyWindow addSubview:self];
    
    self.frame = CGRectMake(kScreenWidth-size.width, kScreenHeight - size.height, size.width, size.height);
    [self animatedIn];
}

- (void)showWithFrame:(CGRect)frame
{
    UIWindow * keyWindow = [[[UIApplication sharedApplication] delegate] window];
    keyWindow.windowLevel = UIWindowLevelNormal;
    
    // 遮盖
    UIButton *cover = [[UIButton alloc] init];
    cover.backgroundColor = [UIColor blackColor];
    cover.alpha = 0.4;
//    [cover addTarget:self action:@selector(animatedOut) forControlEvents:UIControlEventTouchUpInside];
    cover.frame = CGRectMake(0,frame.origin.y, kScreenWidth, kScreenHeight - frame.origin.y);
    _cover = cover;
    
    [keyWindow addSubview:cover];
    [keyWindow addSubview:self];
    self.frame = CGRectMake(frame.origin.x, frame.origin.y,frame.size.width ,frame.size.height);
    [self animatedIn];
}

//- (void)showWithDissMissAndFrame:(CGRect)frame
//{
//    UIWindow * keyWindow = [[[UIApplication sharedApplication] delegate] window];
//    keyWindow.windowLevel = UIWindowLevelNormal;
//
//    // 遮盖
//    UIButton *cover = [[UIButton alloc] init];
//    cover.backgroundColor = [UIColor blackColor];
//    cover.alpha = 0.4;
//    [cover addTarget:self action:@selector(animatedOut) forControlEvents:UIControlEventTouchUpInside];
//    cover.frame = CGRectMake(0,frame.origin.y, kScreenWidth, kScreenHeight - frame.origin.y);
//    _cover = cover;
//
//    [keyWindow addSubview:cover];
//    [keyWindow addSubview:self];
//    self.frame = CGRectMake(frame.origin.x, frame.origin.y,frame.size.width ,frame.size.height);
//    [self animatedIn];
//}


//界面消失
- (void)dismiss
{
    [self animatedOut];
}

-(void)diyView
{
    self.layer.cornerRadius = 20;
    self.layer.masksToBounds = YES;
    self.layer.borderWidth = 1;
    
    self.backgroundColor = JMCOLOR255;
    self.layer.borderColor = JMCOLOR255.CGColor;
}


@end
