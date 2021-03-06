#import "AbstractOptions.h"
#import "SeaController.h"
#import "UtilitiesManager.h"
#import "ToolboxUtility.h"
#import "SeaPrefs.h"
#import "SeaDocument.h"
#import "AspectRatio.h"
#import "SeaView.h"

static int lastTool = -1;
static BOOL forceAlt = NO;

@implementation AbstractOptions

- (void)activate:(id)sender
{
	int curTool;
	
	document = sender;
	curTool = [[[SeaController utilitiesManager] toolboxUtilityFor:document] tool];
	if (lastTool != curTool) {
		[self updateModifiers:0];
		lastTool = curTool;
	}
}

- (void)update
{
}

- (void)forceAlt
{
	NSInteger index = [modifierPopup indexOfItemWithTag:kAltModifier];
	if (index > 0) [modifierPopup selectItemAtIndex:index];
	forceAlt = YES;
}

- (void)unforceAlt
{
	if (forceAlt) {
		[self updateModifiers:0];
		forceAlt = NO;
	}
}

- (void)updateModifiers:(NSEventModifierFlags)modifiers
{
	NSInteger index;
	
	if (modifierPopup) {
	
		if ((modifiers & NSAlternateKeyMask) >> 19 && (modifiers & NSControlKeyMask) >> 18) {
			index = [modifierPopup indexOfItemWithTag:kAltControlModifier];
			if (index > 0)
				[modifierPopup selectItemAtIndex:index];
		} else if ((modifiers & NSShiftKeyMask) >> 17 && (modifiers & NSControlKeyMask) >> 18) {
			index = [modifierPopup indexOfItemWithTag:kShiftControlModifier];
			if (index > 0)
				[modifierPopup selectItemAtIndex:index];
		} else if ((modifiers & NSControlKeyMask) >> 18) {
			index = [modifierPopup indexOfItemWithTag:kControlModifier];
			if (index > 0)
				[modifierPopup selectItemAtIndex:index];
		} else if ((modifiers & NSShiftKeyMask) >> 17) {
			index = [modifierPopup indexOfItemWithTag:kShiftModifier];
			if (index > 0)
				[modifierPopup selectItemAtIndex:index];
		} else if ((modifiers & NSAlternateKeyMask) >> 19) {
			index = [modifierPopup indexOfItemWithTag:kAltModifier];
			if (index > 0)
				[modifierPopup selectItemAtIndex:index];
		} else {
			[modifierPopup selectItemAtIndex:kNoModifier];
		}
	}
	// We now need to update all of the documents because the modifiers, and thus possibly
	// the cursors and guides may have changed.
	for (SeaDocument *doc in [[NSDocumentController sharedDocumentController] documents]) {
		[[doc docView] setNeedsDisplay:YES];
	}
	
}

- (AbstractModifiers)modifier
{
	return [[modifierPopup selectedItem] tag];
}

- (IBAction)modifierPopupChanged:(id)sender
{
}

- (BOOL)useTextures
{
	return NO;
}

- (void)shutdown
{
}

- (id)view
{
	return view;
}

@end
