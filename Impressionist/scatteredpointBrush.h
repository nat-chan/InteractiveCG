//
// scatteredpointBrush.h
//
// The header file for Point Brush. 
//

#ifndef SCATTEREDPOINTBRUSH_H
#define SCATTEREDPOINTBRUSH_H

#include "impBrush.h"

class ScatteredpointBrush : public ImpBrush
{
public:
	ScatteredpointBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
