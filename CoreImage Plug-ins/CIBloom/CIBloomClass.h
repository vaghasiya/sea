/*!
	@header		CIBloomClass
	@abstract	Applies a bloom effect to the selection using
				Core Image.
	@discussion	N/A
				<br><br>
				<b>License:</b> Public Domain 2007<br>
				<b>Copyright:</b> N/A
*/

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreGraphics/CoreGraphics.h>
#import "SeaPlugins.h"
#import "PluginData.h"
#import "SeaWhiteboard.h"
#import <SeashoreKit/SSKCIPlugin.h>

@interface CIBloomClass : SSKCIPlugin
// The new radius
@property NSInteger radius;

// The new intensity
@property CGFloat intensity;

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
	@discussion	Returns the type of plug-in so Seashore can correctly interact with the plug-in.
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
*/
- (void)run;

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
	@method		noiseReduction:withBitmap:
	@discussion	Called by execute once preparation is complete.
	@param		pluginData
				The PluginData object.
	@param		data
				The bitmap data to work with (must be 8-bit ARGB).
	@result		Returns the resulting bitmap.
*/
- (unsigned char *)noiseReduction:(PluginData *)pluginData withBitmap:(unsigned char *)data;

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
