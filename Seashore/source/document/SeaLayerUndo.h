#import <Cocoa/Cocoa.h>
#ifdef SEASYSPLUGIN
#import "Globals.h"
#else
#import <SeashoreKit/Globals.h>
#endif

/*!
	@defined	kNumberOfUndoRecordsPerMalloc
	@discussion	Defines the number of undo records to allocate at a single time.
*/
#define kNumberOfUndoRecordsPerMalloc 150

/*!
	@struct		UndoRecord
	@discussion	A record that contains all the information necessary to restore
				the pixels of a layer to a previous state (i.e. to undo a
				change).
	@field		fileNumber
				A number used to reference a file after the data is written to
				disk. If the data is in memory than this number should be -1, if
				the file is not available this number should be -2.
	@field		data
				The data containing the changed pixels as well as additional
				information specifying where those pixels are.
*/
typedef struct {
	int fileNumber;
	unsigned char *data;
} UndoRecord;

@class SeaDocument;
@class SeaLayer;

/*!
	@class		SeaLayerUndo
	@abstract	Makes changes to the associated layer's pixels undoable.
	@discussion	N/A
				<br><br>
				<b>License:</b> GNU General Public License<br>
				<b>Copyright:</b> Copyright (c) 2002 Mark Pazolli
*/
@interface SeaLayerUndo : NSObject {
	
	// The document associated with this oject
	SeaDocument *document;
	
	// The layer associated with this oject
	SeaLayer *layer;

	// The records of all changes to the layer
	UndoRecord *records;
	size_t records_len;
	size_t records_max_len;
	
	// The minimum size of the memory cache
	unsigned long memoryCacheSize;
	
	// The big block of memory which we use to record new data
	char *memory_cache;
	ssize_t memory_cache_pos;
	size_t memory_cache_len;
	
}

// CREATION METHODS

/*!
	@method		initWithDocument:forLayer:
	@discussion	Initializes an instance of this class for use by the given layer
				of the given document.
	@param		doc
				The document with which to initialize the instance.
	@param		ilayer
				The layer with which to initialize the instance.
	@result		Returns instance upon success (or NULL otherwise).
*/
- (instancetype)initWithDocument:(SeaDocument*)doc forLayer:(SeaLayer*)ilayer;


/*!
	@method		checkDiskSpace
	@discussion	Checks there is sufficient disk space to save the undo data.
	@result		YES if there is enough space to save the undo data, NO
				otherwise.
*/
- (BOOL)checkDiskSpace;

/*!
	@method		takeSanpshot:automatic:
	@discussion	Takes a snapshot of the pixels within a given rectangle.
				Regardless of the value of automatic, this method will not
				update anything.
	@param		rect
				The rectangle containing the pixels to take a snapshot of.
	@param		automatic
				YES if the method should notify the undo manager of the
				document, NO otherwise.
	@result		Returns an integer representing the index of the snapshot.
*/
- (NSInteger)takeSnapshot:(IntRect)rect automatic:(BOOL)automatic;

/*!
	@method 	restoreSnapshot:manual:
	@discussion	Restores a given snapshot.
	@param		index
				The index of the snapshot to restore.
	@param		automatic
				Should always be NO when called from outside SeaLayerUndo. If NO
				method does not handle either undoing the restoration nor
				updating.
*/
- (void)restoreSnapshot:(NSInteger)index automatic:(BOOL)automatic;

@end
