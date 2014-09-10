//
//  ViewController.m
//  Cobol
//
//  Created by 川島 大地 on 2014/09/08.
//  Copyright (c) 2014年 川島 大地. All rights reserved.
//

#import "ViewController.h"
#import "BLESerialManager.h"

@interface ViewController ()

@property NSString *color;
@property NSString *pattern;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.color = @"W";
    self.pattern = @"S";
    [[BLESerialManager sharedManager] initBLE];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onTouchConnectBtn:(id)sender {
    [[BLESerialManager sharedManager] connect];
    [[BLESerialManager sharedManager] sendStr:[NSString stringWithFormat:@"~"]];
}
- (IBAction)onTouchDisconnectBtn:(id)sender {
    [[BLESerialManager sharedManager] disconnect];
}

- (IBAction)onTouchWhite:(id)sender {
    self.color = @"W";
    [self sendCommand];
}
- (IBAction)onTouchRed:(id)sender {
    self.color = @"R";
    [self sendCommand];
}
- (IBAction)onTouchGreen:(id)sender {
    self.color = @"G";
    [self sendCommand];
}
- (IBAction)onTouchBlue:(id)sender {
    self.color = @"B";
    [self sendCommand];
}
- (IBAction)onTouchYellow:(id)sender {
    self.color = @"Y";
    [self sendCommand];
}
- (IBAction)onTouchPink:(id)sender {
    self.color = @"P";
    [self sendCommand];
}
- (IBAction)onTouchSkyblue:(id)sender {
    self.color = @"S";
    [self sendCommand];
}
- (IBAction)onTouchSolid:(id)sender {
    self.pattern = @"S";
    [self sendCommand];
}
- (IBAction)onTouchFlash:(id)sender {
    self.pattern = @"F";
    [self sendCommand];
}
- (IBAction)onTouchFade:(id)sender {
    self.pattern = @"f";
    [self sendCommand];
}
- (IBAction)onTouchRotate:(id)sender {
    self.pattern = @"L";
    [self sendCommand];
}
- (IBAction)onTouchStop:(id)sender {
    self.color = @"X";
    self.pattern = @"X";
    [self sendCommand];
}

- (void) sendCommand{
    [[BLESerialManager sharedManager] sendStr:[NSString stringWithFormat:@"%@,%@^",self.color,self.pattern]];
}

@end
