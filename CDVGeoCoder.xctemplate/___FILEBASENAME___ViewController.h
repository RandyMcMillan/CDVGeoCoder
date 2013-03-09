//  Created by Jesse MacFadyen on 10-05-29.
//  Copyright 2010 Nitobi. All rights reserved.
//
//  ___FILEBASENAME___ Template Created Jan 7 2013
//  Copyright 2013 @RandyMcMillan

//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___ORGANIZATIONNAME___ ___YEAR___. All rights reserved.

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "Geocoder.h"

@protocol ___FILEBASENAME___Delegate <NSObject,GeocoderDelegate>

/*
 *  onChildLocationChanging:newLoc
 *
 *  Discussion:
 *    Invoked when a new page has loaded
 */
- (void)onChildLocationChange:(NSString *)newLoc;
- (void)onOpenInSafari;
- (void)onClose;
- (void)locationFound:(NSString *)latitude :(NSString *)longitude;

@end

@protocol CDVOrientationDelegate <NSObject>

- (NSUInteger)supportedInterfaceOrientations;
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (BOOL)shouldAutorotate;

@end

@interface ___FILEBASENAME___ViewController : UIViewController <UIWebViewDelegate,GeocoderDelegate>{
    
    IBOutlet MKMapView *mapView;
	IBOutlet UILabel *latLngLabel;


}


@property (nonatomic, strong) IBOutlet MKMapView *mapView;
@property (nonatomic, strong) IBOutlet UILabel *latLngLabel;

@property (nonatomic, strong) IBOutlet UIWebView				*webView;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*closeBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*refreshBtn;
@property (nonatomic, strong) IBOutlet UILabel					*addressLabel;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*backBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*fwdBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*safariBtn;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView	*spinner;

// unsafe_unretained is equivalent to assign - used to prevent retain cycles in the two properties below
@property (nonatomic, unsafe_unretained) id <___FILEBASENAME___Delegate>	delegate;
@property (nonatomic, unsafe_unretained) id									orientationDelegate;

@property (copy) NSString	*imageURL;
@property (assign) BOOL		isImage;
@property (assign) BOOL		scaleEnabled;

- (___FILEBASENAME___ViewController *)initWithScale:(BOOL)enabled;
- (IBAction)onDoneButtonPress:(id)sender;
- (IBAction)onSafariButtonPress:(id)sender;
- (void)loadURL:(NSString *)url;
- (void)closeBrowser;

@end
