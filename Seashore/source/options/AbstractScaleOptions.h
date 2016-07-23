#import "Globals.h"
#import "AbstractOptions.h"
#import "AspectRatio.h"

/*		
	@class		AbstractScaleOptions
	@abstract	Acts as a base class for the options panes of the scaling tools.
	@discussion	This class is responsible for keeping track of the mode of the aspect ratio
	<br><br>
	<b>License:</b> GNU General Public License<br>
	<b>Copyright:</b> Copyright (c) 2002 Mark Pazolli
*/

@interface AbstractScaleOptions : AbstractOptions {
	// If shift is held down we need to 
	SeaAspectType aspectType;
	
	// Whether or not we ignore the move action
	BOOL ignoresMove;
}

/*!
	@property	ratio
	@discussion	Returns the ratio/size for the rect.
				If tool does not have a rect, this method is not needed.
	@result		Returns a NSSize for the crop in the aspect type's
				units. If it is a ratio the width = X / Y and the 
				height = Y / X.
*/
@property (readonly) NSSize ratio;

/*!
	@property	aspectType
	@discussion	Returns the type of aspect ratio.
	@result		Returns a constant representing the type of aspect ratio
				(see AspectRatio).
*/
@property (readonly) SeaAspectType aspectType;


/*!
	@method		setIgnoresMove
	@discussion	Used beacuse for some selection modes you don't do a move
	@param		ignoring
				Whether or not to ignore the move.
*/
- (void)setIgnoresMove:(BOOL)ignoring;

/*!
	@property	ignoresMove
	@discussion	When there are special selctions modes we don't move
	@result		YES if we should not register move drags
*/
@property (nonatomic) BOOL ignoresMove;

@end
