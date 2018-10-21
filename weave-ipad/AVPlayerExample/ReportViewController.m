//
//  ReportViewController.m
//  AVPlayerExample
//
//  Created by Yang Ang on 17/10/18.
//  Copyright © 2018 Twilio Inc. All rights reserved.
//

#import "ReportViewController.h"

@interface ReportViewController ()

@end

@implementation ReportViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.myScrollView setScrollEnabled:YES];
    [self.myScrollView setContentSize:CGSizeMake(20,800)];
    // Do any additional setup after loading the view.
    
    NSError *error;
    NSString *url_string = [NSString stringWithFormat: @"http://weave-sg.herokuapp.com/form"];
    NSData *data = [NSData dataWithContentsOfURL: [NSURL URLWithString:url_string]];
    NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    _lbl_datetime.text = [json valueForKey:@"timeOfOccurrence"];
    _lbl_name.text = [json valueForKey:@"name"];
    _lbl_pDescription.text = [json valueForKey:@"p_descriptoin"];
    _lbl_location.text = [json valueForKey:@"location"];
    _lbl_tAdmin.text = [json valueForKey:@"t_description"];
    _lbl_sceneSituation.text = [json valueForKey:@"s_description"];
    _lbl_pVitals.text = [json valueForKey:@"p_vitals"];
    _lbl_kObserve.text = [json valueForKey:@"other"];
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
