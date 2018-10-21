//
//  ReportViewController.h
//  AVPlayerExample
//
//  Created by Yang Ang on 17/10/18.
//  Copyright © 2018 Twilio Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ReportViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIScrollView *myScrollView;
- (IBAction)closeView:(id)sender;
@property (weak, nonatomic) IBOutlet UILabel *lbl_datetime;
@property (weak, nonatomic) IBOutlet UILabel *lbl_name;
@property (weak, nonatomic) IBOutlet UILabel *lbl_pDescription;
@property (weak, nonatomic) IBOutlet UILabel *lbl_location;
@property (weak, nonatomic) IBOutlet UILabel *lbl_tAdmin;
@property (weak, nonatomic) IBOutlet UILabel *lbl_sceneSituation;
@property (weak, nonatomic) IBOutlet UILabel *lbl_pVitals;
@property (weak, nonatomic) IBOutlet UILabel *lbl_kObserve;

@end
