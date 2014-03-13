/*!
	@header		BrightnessClass
	@abstract	Adjusts the brightness and contrast of the selection.
	@discussion	N/A
				<br><br>
				<b>License:</b> GNU General Public License<br>
				<b>Copyright:</b> Copyright (c) 2004 Mark Pazolli and
				Copyright (c) 1995 Spencer Kimball and Peter Mattis
*/

#import <Cocoa/Cocoa.h>
#import "SeaPlugins.h"

@interface BrightnessClass : NSObject <SSSeaVisualPlugin>
{
	// The label displaying the brightness
	IBOutlet id brightnessLabel;
	
	// The slider for the brightness
	IBOutlet id brightnessSlider;

	// The label displaying the contrast
	IBOutlet id contrastLabel;
	
	// The slider for the contrast
	IBOutlet id contrastSlider;

	// The brightness
	float brightness;

	// The contrast
	float contrast;

	// YES if the effect must be refreshed
	BOOL refresh;

	// YES if the application succeeded
	BOOL success;

}

/*!
	@method		initWithManager:
	@discussion	Initializes an instance of this class with the given manager.
	@param		manager
				The SeaPlugins instance responsible for managing the plug-ins.
	@result		Returns instance upon success (or NULL otherwise).
*/
- (id)initWithManager:(SeaPlugins *)manager;

/*!
	@method		type
	@discussion	Returns the type of plug-in so Seashore can correctly interact
				with the plug-in.
	@result		Returns an integer indicating the plug-in's type.
*/
- (int)type;

/*!
	@method		name
	@discussion	Returns the plug-in's name.
	@result		Returns an NSString indicating the plug-in's name.
*/
- (NSString *)name;

/*!
	@method		groupName
	@discussion	Returns the plug-in's group name.
	@result		Returns an NSString indicating the plug-in's group name.
*/
- (NSString *)groupName;

/*!
	@method		sanity
	@discussion	Returns a string to indicate this is a Seashore plug-in.
	@result		Returns the NSString "Seashore Approved (Bobo)".
*/
- (NSString *)sanity;

/*!
	@method		run
	@discussion	Runs the plug-in.
	@result		YES if the plug-in was run successfully, NO otherwise.
*/
- (void)run;

/*!
	@method		apply:
	@discussion	Applies the plug-in's changes.
	@param		sender
				Ignored.
*/
- (IBAction)apply:(id)sender;

/*!
	@method		reapply
	@discussion	Applies the plug-in with previous settings.
*/
- (void)reapply;

/*!
	@method		canReapply
	@discussion Returns whether or not the plug-in can be applied again.
	@result		Returns YES if the plug-in can be applied again, NO otherwise.
*/
- (BOOL)canReapply;

/*!
	@method		preview:
	@discussion	Previews the plug-in's changes.
	@param		sender
				Ignored.
*/
- (IBAction)preview:(id)sender;

/*!
	@method		cancel:
	@discussion	Cancels the plug-in's changes.
	@param		sender
				Ignored.
*/
- (IBAction)cancel:(id)sender;

/*!
	@method		update:
	@discussion	Updates the panel's labels.
	@param		sender
				Ignored.
*/
- (IBAction)update:(id)sender;

/*!
	@method		adjust
	@discussion	Executes the adjustments.
*/
- (void)adjust;

/*!
	@method		validateMenuItem:
	@discussion	Determines whether a given menu item should be enabled or
				disabled.
	@param		menuItem
				The menu item to be validated.
	@result		YES if the menu item should be enabled, NO otherwise.
*/
- (BOOL)validateMenuItem:(id)menuItem;

@end
