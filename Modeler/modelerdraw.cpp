#pragma warning(disable:4996)

#include "modelerdraw.h"
#include <FL/gl.h>
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

// ********************************************************
// Support functions from previous version of modeler
// ********************************************************
void _dump_current_modelview( void )
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	if (mds->m_rayFile == NULL)
	{
		fprintf(stderr, "No .ray file opened for writing, bailing out.¥n");
		exit(-1);
	}

	GLdouble mv[16];
	glGetDoublev( GL_MODELVIEW_MATRIX, mv );
	fprintf( mds->m_rayFile,
		"transform(¥n	 (%f,%f,%f,%f),¥n	 (%f,%f,%f,%f),¥n	  (%f,%f,%f,%f),¥n	  (%f,%f,%f,%f),¥n",
		mv[0], mv[4], mv[8], mv[12],
		mv[1], mv[5], mv[9], mv[13],
		mv[2], mv[6], mv[10], mv[14],
		mv[3], mv[7], mv[11], mv[15] );
}

void _dump_current_material( void )
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	if (mds->m_rayFile == NULL)
	{
		fprintf(stderr, "No .ray file opened for writing, bailing out.¥n");
		exit(-1);
	}

	fprintf( mds->m_rayFile,
		"material={¥n	 diffuse=(%f,%f,%f);¥n	  ambient=(%f,%f,%f);¥n}¥n",
		mds->m_diffuseColor[0], mds->m_diffuseColor[1], mds->m_diffuseColor[2],
		mds->m_diffuseColor[0], mds->m_diffuseColor[1], mds->m_diffuseColor[2]);
}

// ****************************************************************************

// Initially assign singleton instance to NULL
ModelerDrawState* ModelerDrawState::m_instance = NULL;

ModelerDrawState::ModelerDrawState() : m_drawMode(NORMAL), m_quality(MEDIUM)
{
	float grey[]  = {.5f, .5f, .5f, 1};
	float white[] = {1,1,1,1};
	float black[] = {0,0,0,1};

	memcpy(m_ambientColor, black, 4 * sizeof(float));
	memcpy(m_diffuseColor, grey, 4 * sizeof(float));
	memcpy(m_specularColor, white, 4 * sizeof(float));

	m_shininess = 0.5;

	m_rayFile = NULL;
}

// CLASS ModelerDrawState METHODS
ModelerDrawState* ModelerDrawState::Instance()
{
	// Return the singleton if it exists, otherwise, create it
	return (m_instance) ? (m_instance) : m_instance = new ModelerDrawState();
}

// ****************************************************************************
// Modeler functions for your use
// ****************************************************************************
// Set the current material properties

void setAmbientColor(float r, float g, float b)
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	mds->m_ambientColor[0] = (GLfloat)r;
	mds->m_ambientColor[1] = (GLfloat)g;
	mds->m_ambientColor[2] = (GLfloat)b;
	mds->m_ambientColor[3] = (GLfloat)1.0;

	if (mds->m_drawMode == NORMAL)
		glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, mds->m_ambientColor);
}

void setDiffuseColor(float r, float g, float b, float a)
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	mds->m_diffuseColor[0] = (GLfloat)r;
	mds->m_diffuseColor[1] = (GLfloat)g;
	mds->m_diffuseColor[2] = (GLfloat)b;
	mds->m_diffuseColor[3] = (GLfloat)a;

	if (mds->m_drawMode == NORMAL)
		glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mds->m_diffuseColor);
	else
		glColor3f(r,g,b);
}

void setSpecularColor(float r, float g, float b)
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	mds->m_specularColor[0] = (GLfloat)r;
	mds->m_specularColor[1] = (GLfloat)g;
	mds->m_specularColor[2] = (GLfloat)b;
	mds->m_specularColor[3] = (GLfloat)1.0;

	if (mds->m_drawMode == NORMAL)
		glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mds->m_specularColor);
}

void setShininess(float s)
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	mds->m_shininess = (GLfloat)s;

	if (mds->m_drawMode == NORMAL)
		glMaterialf( GL_FRONT, GL_SHININESS, mds->m_shininess);
}

void setDrawMode(DrawModeSetting_t drawMode)
{
	ModelerDrawState::Instance()->m_drawMode = drawMode;
}

void setQuality(QualitySetting_t quality)
{
	ModelerDrawState::Instance()->m_quality = quality;
}

bool openRayFile(const char rayFileName[])
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	fprintf(stderr, "Ray file format output is buggy (ehsu)¥n");

	if (!rayFileName)
		return false;

	if (mds->m_rayFile)
		closeRayFile();

	mds->m_rayFile = fopen(rayFileName, "w");

	if (mds->m_rayFile != NULL)
	{
		fprintf( mds->m_rayFile, "SBT-raytracer 1.0¥n¥n" );
		fprintf( mds->m_rayFile, "camera { fov=30; }¥n¥n" );
		fprintf( mds->m_rayFile,
			"directional_light { direction=(-1,-1,-1); color=(0.7,0.7,0.7); }¥n¥n" );
		return true;
	}
	else
		return false;
}

void _setupOpenGl()
{
	ModelerDrawState *mds = ModelerDrawState::Instance();
	switch (mds->m_drawMode)
	{
	case NORMAL:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glShadeModel(GL_SMOOTH);
		break;
	case FLATSHADE:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glShadeModel(GL_FLAT);
		break;
	case WIREFRAME:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glShadeModel(GL_FLAT);
	default:
		break;
	}

}

void closeRayFile()
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	if (mds->m_rayFile)
		fclose(mds->m_rayFile);

	mds->m_rayFile = NULL;
}

void drawSphere(double r)
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	_setupOpenGl();

	if (mds->m_rayFile)
	{
		_dump_current_modelview();
		fprintf(mds->m_rayFile, "scale(%f,%f,%f,sphere {¥n", r, r, r );
		_dump_current_material();
		fprintf(mds->m_rayFile, "}))¥n" );
	}
	else
	{
		int divisions;
		GLUquadricObj* gluq;

		switch(mds->m_quality)
		{
		case HIGH:
			divisions = 32; break;
		case MEDIUM:
			divisions = 20; break;
		case LOW:
			divisions = 12; break;
		case POOR:
			divisions = 8; break;
		}

		gluq = gluNewQuadric();
		gluQuadricDrawStyle( gluq, GLU_FILL );
		gluQuadricTexture( gluq, GL_TRUE );
		gluSphere(gluq, r, divisions, divisions);
		gluDeleteQuadric( gluq );
	}
}

// p は楕円体の中心。v1, v2, v3 は楕円体の主軸で、互いに直交しており、
// p±v1, p±v2, p±v3なる点が楕円体の表面上にある。
// 上のコードでは、原点中心の単位球を描いて、(1,0,0)→v1, (0,1,0)→v2, (0,0,1)→v3 と座標変換して
// p だけ平行移動している。
void drawEllipsoid(float *p, float *v1, float *v2, float *v3, int sect)
{
	GLfloat mat[16];
	mat[0] = v1[0]; mat[1] = v1[1]; mat[2] = v1[2]; mat[3] = 0;
	mat[4] = v2[0]; mat[5] = v2[1]; mat[6] = v2[2]; mat[7] = 0;
	mat[8] = v3[0]; mat[9] = v3[1]; mat[10] = v3[2]; mat[11] = 0;
	mat[12] = p[0]; mat[13] = p[1]; mat[14] = p[2]; mat[15] = 1;
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mat);
	glEnable(GL_NORMALIZE);
//	  glutSolidSphere(1, sect, sect);
	drawSphere(sect);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}


void drawBox( double x, double y, double z )
{
	ModelerDrawState *mds = ModelerDrawState::Instance();

	_setupOpenGl();

	if (mds->m_rayFile)
	{
		_dump_current_modelview();
		fprintf(mds->m_rayFile,
			"scale(%f,%f,%f,translate(0.5,0.5,0.5,box {¥n", x, y, z );
		_dump_current_material();
		fprintf(mds->m_rayFile,  "})))¥n" );
	}
	else
	{
		/* remember which matrix mode OpenGL was in. */
		int savemode;
		glGetIntegerv( GL_MATRIX_MODE, &savemode );

		/* switch to the model matrix and scale by x,y,z. */
		glMatrixMode( GL_MODELVIEW );
		glPushMatrix();
		glScaled( x, y, z );

		glBegin( GL_QUADS );

		glNormal3d( 0.0, 0.0, -1.0 );
		glVertex3d( 0.0, 0.0, 0.0 ); glVertex3d( 0.0, 1.0, 0.0 );
		glVertex3d( 1.0, 1.0, 0.0 ); glVertex3d( 1.0, 0.0, 0.0 );

		glNormal3d( 0.0, -1.0, 0.0 );
		glVertex3d( 0.0, 0.0, 0.0 ); glVertex3d( 1.0, 0.0, 0.0 );
		glVertex3d( 1.0, 0.0, 1.0 ); glVertex3d( 0.0, 0.0, 1.0 );

		glNormal3d( -1.0, 0.0, 0.0 );
		glVertex3d( 0.0, 0.0, 0.0 ); glVertex3d( 0.0, 0.0, 1.0 );
		glVertex3d( 0.0, 1.0, 1.0 ); glVertex3d( 0.0, 1.0, 0.0 );

		glNormal3d( 0.0, 0.0, 1.0 );
		glVertex3d( 0.0, 0.0, 1.0 ); glVertex3d( 1.0, 0.0, 1.0 );
		glVertex3d( 1.0, 1.0, 1.0 ); glVertex3d( 0.0, 1.0, 1.0 );

		glNormal3d( 0.0, 1.0, 0.0 );
		glVertex3d( 0.0, 1.0, 0.0 ); glVertex3d( 0.0, 1.0, 1.0 );
		glVertex3d( 1.0, 1.0, 1.0 ); glVertex3d( 1.0, 1.0, 0.0 );

		glNormal3d( 1.0, 0.0, 0.0 );
		glVertex3d( 1.0, 0.0, 0.0 ); glVertex3d( 1.0, 1.0, 0.0 );
		glVertex3d( 1.0, 1.0, 1.0 ); glVertex3d( 1.0, 0.0, 1.0 );

		glEnd();

		/* restore the model matrix stack, and switch back to the matrix
		mode we were in. */
		glPopMatrix();
		glMatrixMode( savemode );
	}
}

void drawTextureBox( double x, double y, double z )
{
	// NOT IMPLEMENTED, SORRY (ehsu)
}

void drawCylinder( double h, double r1, double r2 )
{
	ModelerDrawState *mds = ModelerDrawState::Instance();
	int divisions;

	_setupOpenGl();

	switch(mds->m_quality)
	{
	case HIGH:
		divisions = 32; break;
	case MEDIUM:
		divisions = 20; break;
	case LOW:
		divisions = 12; break;
	case POOR:
		divisions = 8; break;
	}

	if (mds->m_rayFile)
	{
		_dump_current_modelview();
		fprintf(mds->m_rayFile,
			"cone { height=%f; bottom_radius=%f; top_radius=%f;¥n", h, r1, r2 );
		_dump_current_material();
		fprintf(mds->m_rayFile, "})¥n" );
	}
	else
	{
		GLUquadricObj* gluq;

		/* GLU will again do the work.	draw the sides of the cylinder. */
		gluq = gluNewQuadric();
		gluQuadricDrawStyle( gluq, GLU_FILL );
		gluQuadricTexture( gluq, GL_TRUE );
		gluCylinder( gluq, r1, r2, h, divisions, divisions);
		gluDeleteQuadric( gluq );

		if ( r1 > 0.0 )
		{
		/* if the r1 end does not come to a point, draw a flat disk to
			cover it up. */

			gluq = gluNewQuadric();
			gluQuadricDrawStyle( gluq, GLU_FILL );
			gluQuadricTexture( gluq, GL_TRUE );
			gluQuadricOrientation( gluq, GLU_INSIDE );
			gluDisk( gluq, 0.0, r1, divisions, divisions);
			gluDeleteQuadric( gluq );
		}

		if ( r2 > 0.0 )
		{
		/* if the r2 end does not come to a point, draw a flat disk to
			cover it up. */

			/* save the current matrix mode. */
			int savemode;
			glGetIntegerv( GL_MATRIX_MODE, &savemode );

			/* translate the origin to the other end of the cylinder. */
			glMatrixMode( GL_MODELVIEW );
			glPushMatrix();
			glTranslated( 0.0, 0.0, h );

			/* draw a disk centered at the new origin. */
			gluq = gluNewQuadric();
			gluQuadricDrawStyle( gluq, GLU_FILL );
			gluQuadricTexture( gluq, GL_TRUE );
			gluQuadricOrientation( gluq, GLU_OUTSIDE );
			gluDisk( gluq, 0.0, r2, divisions, divisions);
			gluDeleteQuadric( gluq );

			/* restore the matrix stack and mode. */
			glPopMatrix();
			glMatrixMode( savemode );
		}
	}

}

void drawTriangle( double x1, double y1, double z1,
                   double x2, double y2, double z2,
                   double x3, double y3, double z3 )
{
	ModelerDrawState *mds = ModelerDrawState::Instance();
	
	_setupOpenGl();
	
	if (mds->m_rayFile)
	{
		_dump_current_modelview();
		fprintf(mds->m_rayFile,
			"polymesh { points=((%f,%f,%f),(%f,%f,%f),(%f,%f,%f)); faces=((0,1,2));¥n", x1, y1, z1, x2, y2, z2, x3, y3, z3 );
		_dump_current_material();
		fprintf(mds->m_rayFile, "})¥n" );
	}
	else
	{
		double a, b, c, d, e, f;
		
		/* the normal to the triangle is the cross product of two of its edges. */
		a = x2-x1;
		b = y2-y1;
		c = z2-z1;
		
		d = x3-x1;
		e = y3-y1;
		f = z3-z1;
		
		glBegin( GL_TRIANGLES );
		glNormal3d( b*f - c*e, c*d - a*f, a*e - b*d );
		glVertex3d( x1, y1, z1 );
		glVertex3d( x2, y2, z2 );
		glVertex3d( x3, y3, z3 );
		glEnd();
	}
}

//1,2,3番目の点が張る平面上に4番目の点があることを仮定している
void drawRectangle( double x1, double y1, double z1,
                    double x2, double y2, double z2,
                    double x3, double y3, double z3,
                    double x4, double y4, double z4 )
{
	double a, b, c, d, e, f;
	a = x2-x1;
	b = y2-y1;
	c = z2-z1;
	
	d = x3-x1;
	e = y3-y1;
	f = z3-z1;
	
	glBegin( GL_QUADS );
	glNormal3d( b*f - c*e, c*d - a*f, a*e - b*d );
	glVertex3d( x1, y1, z1 );
	glVertex3d( x2, y2, z2 );
	glVertex3d( x3, y3, z3 );
	glVertex3d( x4, y4, z4 );
	glEnd();
}


void drawTriangularPrism( double x1, double y1, double z1,
                          double x2, double y2, double z2,
                          double x3, double y3, double z3, double h ){
	double a, b, c, d, e, f,nx, ny, nz;
	
	/* the normal to the triangle is the cross product of two of its edges. */
	a = x2-x1;
	b = y2-y1;
	c = z2-z1;
	
	d = x3-x1;
	e = y3-y1;
	f = z3-z1;
	nx = b*f - c*e;
	ny = c*d - a*f;
	nz = a*e - b*d;
	
	glBegin( GL_TRIANGLES );
	glNormal3d(nx, ny, nz);
	glVertex3d( x1, y1, z1 );
	glVertex3d( x2, y2, z2 );
	glVertex3d( x3, y3, z3 );
	glEnd();
	glBegin( GL_TRIANGLES );
	glNormal3d(-nx, -ny, -nz);//逆の平面の法線は逆向き
	glVertex3d( x1, y1+h, z1 );
	glVertex3d( x3, y3+h, z3 );
	glVertex3d( x2, y2+h, z2 );
	glEnd();
	drawRectangle( x1 , y1   , z1 ,
	               x1 , y1+h , z1 ,
	               x2 , y2+h , z2 ,
	               x2 , y2   , z2);
	drawRectangle( x2 , y2   , z2 ,
	               x2 , y2+h , z2 ,
	               x3 , y3+h , z3 ,
	               x3 , y3   , z3);
	drawRectangle( x3 , y3   , z3 ,
	               x3 , y3+h , z3 ,
	               x1 , y1+h , z1 ,
	               x1 , y1   , z1);
}
