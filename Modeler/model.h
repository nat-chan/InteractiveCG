//=============================================================================
// ƒtƒ@ƒCƒ‹: model.h
//=============================================================================
// ƒ‚ƒfƒ‹‚ÌÝ’èE•`‰æ‚ð§Œä
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ƒwƒbƒ_ƒtƒ@ƒCƒ‹‚ÌƒCƒ“ƒNƒ‹[ƒh
#include "animator.h"

// ƒtƒŒ[ƒ€”Ô†‚ÌÅ‘å’l
int max_frame_count = 500;

// ModelƒNƒ‰ƒX‚Ì’è‹`iModelerViewƒNƒ‰ƒX‚ðŒp³j
class Model : public ModelerView {
private:
	//```````````````````````````````````
	//‘æ3T‰Û‘è
	//---------------------------------------------------------------------

	// ƒtƒŒ[ƒ€”Ô†
	int frame_count;
	
	//-------------------------------------------------------------------------
	// §Œä•Ï”
	//-------------------------------------------------------------------------

		// ```•Ï”‚ð’Ç‰Á```


	//```````````````````````````````````


public:
	// ƒRƒ“ƒXƒgƒ‰ƒNƒ^iƒX[ƒp[ƒNƒ‰ƒX‚ÌƒRƒ“ƒXƒgƒ‰ƒNƒ^‚ðŒÄ‚Ño‚·j
	Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
	{
		//```````````````````````````````````
		//‘æ3T‰Û‘è
		//---------------------------------------------------------------------

		// ƒtƒŒ[ƒ€”Ô†‚Ì‰Šú‰»
		frame_count = 0;
		
		//---------------------------------------------------------------------
		// ‰Šú‰»
		//---------------------------------------------------------------------

			// ```•Ï”‚ð‰Šú‰»```


		//```````````````````````````````````
	}

	//```````````````````````````````````
	//‘æ3T‰Û‘è
	//---------------------------------------------------------------------

	// Ž©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚ÌÝ’è
	void SetAutomaticAnimation()
	{
		//-----------------------------------------------------------------
		// ƒAƒjƒ[ƒVƒ‡ƒ“
		//-----------------------------------------------------------------

			// ```ƒvƒƒOƒ‰ƒ€‚ð‹Lq```

		//-----------------------------------------------------------------
	}

	// Žè“®ƒAƒjƒ[ƒVƒ‡ƒ“‚ÌÝ’è
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// ƒAƒjƒ[ƒVƒ‡ƒ“
		//-----------------------------------------------------------------

			// ```ƒvƒƒOƒ‰ƒ€‚ð‹Lq```

		//-----------------------------------------------------------------
	}

	//```````````````````````````````````


	// •`‰æ‚Ì‘Oˆ—
	void BeginPaint()
	{
		// ”¼“§–¾ˆ—‚ð—LŒø‰»
		glEnable( GL_BLEND );
		// ¬‡•û–@‚ÌŽw’è
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	}

	// •`‰æ‚ÌŒãˆ—
	void EndPaint()
	{
		// ”¼“§–¾ˆ—‚ð–³Œø‰»
		glDisable( GL_BLEND );
	}

	// ƒIƒuƒWƒFƒNƒg‚Ì•`‰æ
	void draw()
	{
		//```````````````````````````````````
		//‘æ3T‰Û‘è
		//---------------------------------------------------------------------
		// Ž©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
		if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
			// ƒtƒŒ[ƒ€”Ô†‚ÌXV
			SetSliderValue( FRAME_CONTROLS, ++frame_count );
			// Ž©“®ƒAƒjƒ[ƒVƒ‡ƒ“
			SetAutomaticAnimation();
		}
		// Žè“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
		else {
			// ƒtƒŒ[ƒ€”Ô†‚ðŽæ“¾
			frame_count = (int)GetSliderValue( FRAME_CONTROLS );
			// Žè“®ƒAƒjƒ[ƒVƒ‡ƒ“
			SetManualAnimation();			 
		}
		//```````````````````````````````````


		// ƒX[ƒp[ƒNƒ‰ƒX‚Ì•`‰æƒƒ\ƒbƒh‚ðƒR[ƒ‹i•K{j
		ModelerView::draw();


		// •`‰æŠJŽn
		BeginPaint();

		//---------------------------------------------------------------------
		// ƒIƒuƒWƒFƒNƒg‚ð•`‰æ
		//---------------------------------------------------------------------

		 // ```ƒvƒƒOƒ‰ƒ€‚ð‹Lq```
		//TODO
		setAmbientColor(0.5,0.4,0.3); //ŠÂ‹«Œõ
		setSpecularColor(0,1,0); //‹¾–Ê”½ŽËŒõ
		setShininess(20.0); //ƒnƒCƒ‰ƒCƒg‚Ì‹­‚³

		glPushMatrix();//Rotate=0‚Å’¼—§‚³‚¹‚é‚½‚ß‚É‘S‘Ì-90‹‰ñ“]
			glRotated(-90, 1, 0, 0);
//			glTranslated(GetSliderValue(X_POSITION),
//			             GetSliderValue(Y_POSITION),
//			             GetSliderValue(Z_POSITION));
//			glRotated(   GetSliderValue(X_ROTATE), 1, 0, 0);
//			glRotated(   GetSliderValue(Y_ROTATE), 0, 1, 0);
//			glRotated(   GetSliderValue(Z_ROTATE), 0, 0, 1);
			setDiffuseColor(0.3,0,0.3,1); //ŠgŽU”½ŽËŒõ Ž‡
			glPushMatrix();//“·‘Ì
				glScaled(1.2,0.9,1);
				float up1 = 3.5;
				drawCylinder(up1,1,2);
				glPushMatrix();//Œ¨
					glTranslated(0, 0, up1);
					float up2 = 1.;
					drawCylinder(up2,2,1);
				glPopMatrix();//Œ¨
				drawSphere(1);
			glPopMatrix();
			glPushMatrix();//Šç
				float up3 = up1 + up2 + 1.2;
				glTranslated(0.0, 0.0, up3); glRotated(0, 1, 0, 0); glScaled(1.0, 1.0, 1.5);
				drawSphere(0.9);
				setDiffuseColor(0.5,0,0,1); //ŠgŽU”½ŽËŒõ Ô
				drawTriangularPrism(
				0  +0.1 , 0.5 , 0.1  ,
				1  +0.1 , 0.5 , -0.2 ,
				1.9+0.1 , 0.5 , 1.6  , 0.5);
				drawTriangularPrism(
				-1  -0.1 , 0.5 , -0.2 ,
				0   -0.1 , 0.5 , 0.1  ,
				-1.9-0.1 , 0.5 , 1.6  , 0.5 );
			glPopMatrix();//Šç
			glPushMatrix();//“ñ‚Ì˜r
				glTranslated(0, 0, up1);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				glPushMatrix();//‰E˜r
					glTranslated(-2.5, 0, 0);
					glRotated(GetSliderValue(X_ROTATE), 1, 0, 0);
					drawSphere(0.6);
					drawCylinder(2,0.5,0.5);
					glPushMatrix();//‘O˜r
						glTranslated(0, 0, 2.4);
						glRotated(GetSliderValue(Y_ROTATE), 1, 0, 0);
						drawSphere(0.6);
						glTranslated(0, 0, 0.4);
						drawCylinder(2,0.5,0.5);
						glTranslated(0,0,2.1);
						drawSphere(0.4);
						glTranslated(-0.2-0.2, -0.5, 0.1);
						drawBox(0.5,1,1.2);
						glPushMatrix();
							glTranslated(0, -0.3, 0);
							drawBox(0.5,0.6,0.5);
						glPopMatrix();
						glTranslated(0.3, 0, 0.7);
						drawBox(0.5,1,0.5);
					glPopMatrix();//‘O˜r
				glPopMatrix();//‰E˜r
			glPopMatrix();//“ñ‚Ì˜r
		glPopMatrix();//Rotate=0‚Å’¼—§‚³‚¹‚é‚½‚ß‚É‘S‘Ì90‹‰ñ“]

		//---------------------------------------------------------------------

		// •`‰æI—¹
		EndPaint();
	}
};

// __MODEL_H__
#endif
