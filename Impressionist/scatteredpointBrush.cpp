//
// scatteredpointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredpointBrush.h"

extern float frand();

ScatteredpointBrush::ScatteredpointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredpointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredpointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//スライダーつけたあと

	if ( pDoc == NULL ) {
		printf( "ScatteredpointBrush::BrushMove  document is NULL\n" );
		return;
	}
	int size=pDoc->getSize();
	int Ax,Ay;
	glPointSize(1.0); //点のサイズを１ピクセルにする
	glBegin( GL_POINTS );
	SetColor( source );
	for(int i=0;i<10;i++){
		Ax=target.x-size/2+rand()%size;
		Ay=target.y-size/2+rand()%size;
	glVertex2i( Ax, Ay );
}

glEnd();

}

void ScatteredpointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

