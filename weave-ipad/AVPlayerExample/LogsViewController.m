//
//  LogsViewController.m
//  Weave-iPad
//
//  Created by Yang Ang on 18/10/18.
//  Copyright © 2018 Twilio Inc. All rights reserved.
//

#import "LogsViewController.h"

@interface LogsViewController ()

@end

@implementation LogsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.logsScrollView setScrollEnabled:YES];
    [self.logsScrollView setContentSize:CGSizeMake(20,800)];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)closeView:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}
@end
