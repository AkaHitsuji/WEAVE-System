//
//  LogsViewController.h
//  Weave-iPad
//
//  Created by Yang Ang on 18/10/18.
//  Copyright © 2018 Twilio Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LogsViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIScrollView *logsScrollView;
- (IBAction)closeView:(id)sender;

@end
