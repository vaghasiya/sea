#import <Cocoa/Cocoa.h>
#import "Globals.h"
#import "SeaWarning.h"

@class BannerView;
@class SeaWindowContent;
@class SeaDocument;

/*!
	@class		WarnigsUtility
	@abstract	Handles the warnings bar at the top of the window.
	@discussion	The view for this controller is essentially the BannerView
	<br><br>
	<b>License:</b> GNU General Public License<br>
	<b>Copyright:</b> Copyright (c) 2002 Mark Pazolli	
*/
@interface WarningsUtility : NSObject {
	// The host for the utility
	IBOutlet SeaDocument *document;
	
	// We need the content to show or hide the banner
	IBOutlet SeaWindowContent *windowContent;
	
	// The view itself
	IBOutlet BannerView* view;
	
	// What type of message are we currently displaying?
	SeaWarningImportance mostRecentImportance;
}

/*!
	@method		setWarning:ofImportance
	@discussion	This will reveal the warning bar
	@param		message
				The string to display
	@param		importance
				This affects the color
*/
- (void)setWarning:(NSString *)message ofImportance:(SeaWarningImportance)importance;

/*!
	@method		showFloatBanner
	@discussion	Shows the float banner with the new and anchor buttons.
*/
- (void)showFloatBanner;

/*!
	@method		hideFloatBanner
	@discussion	Hides the float banner with the new and anchor buttons.
*/
- (void)hideFloatBanner;

/*!
	@method		defaultAction
	@discussion	Triggers the action taken by the default button in the banner.
	@param		sender
				Ignored.
*/
- (IBAction)defaultAction:(id)sender;

/*!
	@method		alternateAction
	@discussion	Triggers the action taken by the alternate button in the banner.
	@param		sender
				Ignored.
*/
- (IBAction)alternateAction:(id)sender;

/*!
	@method		keyTriggered
	@discussion	The default button should be triggered by return or enter. Thus
				we need an action to handle this event.
*/
- (void)keyTriggered;

/*!
	@property	activeWarningImportance
	@discussion	This is used to figure out how important the current warning is.
	@result		The importance of the current warning (an int).
*/
@property (readonly) SeaWarningImportance activeWarningImportance;
@end
