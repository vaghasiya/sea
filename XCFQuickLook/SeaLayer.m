#import "SeaLayer.h"
#import "SeaContent.h"
#import "Bitmap.h"
#import <ApplicationServices/ApplicationServices.h>
#import <sys/stat.h>
#import <sys/mount.h>

@implementation SeaLayer

- (instancetype)init
{
	if (self = [super init]) {
		// Set the data members to reasonable values
		height = width = mode = 0;
		opacity = 255; xoff = yoff = 0;
		spp = 4;
		srand(time(NULL));
		
		uniqueLayerID = rand();
		if (uniqueLayerID == 0)
			name = [[NSString alloc] initWithString:LOCALSTR(@"background layer", @"Background")];
		else
			name = [[NSString alloc] initWithFormat:LOCALSTR(@"layer title", @"Layer %d"), uniqueLayerID];
		oldNames = [[NSArray alloc] init];
	}
	
	return self;
}


- (void)dealloc
{	
	if (data)
		free(data);
	if (thumbData)
		free(thumbData);
}

- (int)width
{
	return width;
}

- (int)height
{
	return height;
}

- (int)xoff
{
	return xoff;
}

- (int)yoff
{
	return yoff;
}

- (BOOL)visible
{
	return visible;
}

- (BOOL)linked
{
	return linked;
}

- (int)opacity
{
	return opacity;
}

- (int)mode
{
	return mode;
}

- (NSString *)name
{
	return name;
}

- (unsigned char *)data
{
	return data;
}

- (BOOL)hasAlpha
{
	return hasAlpha;
}
- (void)introduceAlpha
{
	hasAlpha = YES;
}
- (char *)lostprops
{
	return lostprops;
}

- (int)lostprops_len
{
	return lostprops_len;
}

- (int)uniqueLayerID
{
	return uniqueLayerID;
}

- (BOOL)floating
{
	return floating;
}

@end
