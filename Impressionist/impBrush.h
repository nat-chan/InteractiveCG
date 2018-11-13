#ifndef IMPBRUSH_H
#define IMPBRUSH_H

//
// ImpBrush.h
//
// The header file of virtual brush. All the other brushes inherit from it.
//

#include <stdlib.h>

// Each brush type has an associated constant.
//�u���V�ǉ�
enum
{
	
	BRUSH_POINTS = 0,
	BRUSH_TRIANGLES = 1,
	BRUSH_CIRCLES = 2,
	BRUSH_LINES = 3,
	BRUSH_SCATTEREDPOINTS = 4,
	NUM_BRUSH_TYPE // Make sure this stays at the end!
};


class ImpressionistDoc; // Pre-declaring class

class Point
{
public:
	Point() {};
	Point(int xx, int yy) { x = xx; y = yy; };

	int x, y;
};

class ImpBrush
{
protected:
	ImpBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

public:
	// The implementation of your brush should realize these virtual functions
	virtual void BrushBegin( const Point source, const Point target ) = 0;
	virtual void BrushMove( const Point source, const Point target ) = 0;
	virtual void BrushEnd( const Point source, const Point target ) = 0;

	// according to the source image and the position, determine the draw color
	void SetColor( const Point source );

	void SetColorAlpha (const Point source, float alpha);

	// get Doc to communicate with it
	ImpressionistDoc* GetDocument( void );

	// Return the name of the brush (not used in this version).
	char* BrushName( void );

	static int			c_nBrushCount;	// How many brushes we have,
	static ImpBrush**	c_pBrushes;		// and what they are.

private:
	ImpressionistDoc*	m_pDoc;

	// Brush's name (not used in this version).
	char*				m_pBrushName;
};

#endif

