//=============================================================================
// ƒtƒ@ƒCƒ‹: model.h
//=============================================================================
// ƒ‚ƒfƒ‹‚Ìİ’èE•`‰æ‚ğ§Œä
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ƒwƒbƒ_ƒtƒ@ƒCƒ‹‚ÌƒCƒ“ƒNƒ‹[ƒh
#include "animator.h"

// ƒtƒŒ[ƒ€”Ô†‚ÌÅ‘å’l
int max_frame_count = 450;

// ModelƒNƒ‰ƒX‚Ì’è‹`iModelerViewƒNƒ‰ƒX‚ğŒp³j
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

		// ```•Ï”‚ğ’Ç‰Á```
		double theta;


	//```````````````````````````````````


public:
	// ƒRƒ“ƒXƒgƒ‰ƒNƒ^iƒX[ƒp[ƒNƒ‰ƒX‚ÌƒRƒ“ƒXƒgƒ‰ƒNƒ^‚ğŒÄ‚Ño‚·j
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

			// ```•Ï”‚ğ‰Šú‰»```
			theta = 0;


		//```````````````````````````````````
	}

	//```````````````````````````````````
	//‘æ3T‰Û‘è
	//---------------------------------------------------------------------

	// ©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìİ’è
	void SetAutomaticAnimation()
	{
		//-----------------------------------------------------------------
		// ƒAƒjƒ[ƒVƒ‡ƒ“
		//-----------------------------------------------------------------

			// ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```
		theta = sin(frame_count*M_PI/30);

		//-----------------------------------------------------------------
	}

	// è“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìİ’è
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// ƒAƒjƒ[ƒVƒ‡ƒ“
		//-----------------------------------------------------------------

			// ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```
		theta = GetSliderValue(THETA);

		//-----------------------------------------------------------------
	}

	//```````````````````````````````````


	// •`‰æ‚Ì‘Oˆ—
	void BeginPaint()
	{
		// ”¼“§–¾ˆ—‚ğ—LŒø‰»
		glEnable( GL_BLEND );
		// ¬‡•û–@‚Ìw’è
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	}

	// •`‰æ‚ÌŒãˆ—
	void EndPaint()
	{
		// ”¼“§–¾ˆ—‚ğ–³Œø‰»
		glDisable( GL_BLEND );
	}

	void drawArm(double r1, double r2){
		glPushMatrix();//“ñ‚Ì˜r
			glTranslated(-2.5, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.6);
			drawCylinder(2,0.5,0.5);
			glPushMatrix();//‘O˜r
				glTranslated(0, 0, 2.4);
				glRotated(r2, 1, 0, 0);
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
		glPopMatrix();//“ñ‚Ì˜r
	}

	void drawLeg(double r1, double r2){
		glPushMatrix();//‘¾‚à‚à
			glTranslated(-1, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.7);
			double adjust = 0.5;
			double adjust2= 0.1;
			drawCylinder(2+ adjust,0.5+adjust2,0.5+adjust2);
			glPushMatrix();//‚Ó‚­‚ç‚Í‚¬
				glTranslated(0, 0, 2.4+ adjust);
				glRotated(r2, 1, 0, 0);
				drawSphere(0.6);
				glTranslated(0, 0, 0.4);
				drawCylinder(2,0.5+adjust2,0.5+adjust2);
				glTranslated(0,0,2.1);
				drawSphere(0.4);
				glTranslated(-0.5, -1.4, 0.1);
				drawBox(1,1.8,0.8);
			glPopMatrix();//‚Ó‚­‚ç‚Í‚¬
		glPopMatrix();//‘¾‚à‚à
	}
	double thetaBody(double theta){
		return 2*(theta*theta) -2;
	}
	double thetaArm1(double theta){
		return 50*(theta-0.3);
	}
	double thetaArm2(double theta){
		return 40*(theta*theta) + 100;
	}
	double thetaLeg1(double theta){
		return 50*(theta+0.3);
	}
	double thetaLeg2(double theta){
		return -50*(theta*theta) - 50;
	}


	// ƒIƒuƒWƒFƒNƒg‚Ì•`‰æ
	void draw()
	{
		//```````````````````````````````````
		//‘æ3T‰Û‘è
		//---------------------------------------------------------------------
		// ©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
		if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
			// ƒtƒŒ[ƒ€”Ô†‚ÌXV
			SetSliderValue( FRAME_CONTROLS, ++frame_count );
			// ©“®ƒAƒjƒ[ƒVƒ‡ƒ“
			SetAutomaticAnimation();
		}
		// è“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
		else {
			// ƒtƒŒ[ƒ€”Ô†‚ğæ“¾
			frame_count = (int)GetSliderValue( FRAME_CONTROLS );
			// è“®ƒAƒjƒ[ƒVƒ‡ƒ“
			SetManualAnimation();			 
		}
		//```````````````````````````````````


		// ƒX[ƒp[ƒNƒ‰ƒX‚Ì•`‰æƒƒ\ƒbƒh‚ğƒR[ƒ‹i•K{j
		ModelerView::draw();


		// •`‰æŠJn
		BeginPaint();

		//---------------------------------------------------------------------
		// ƒIƒuƒWƒFƒNƒg‚ğ•`‰æ
		//---------------------------------------------------------------------

		 // ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```
		setAmbientColor(0.5,0.4,0.3); //ŠÂ‹«Œõ
		setSpecularColor(0,1,0); //‹¾–Ê”½ËŒõ
		setShininess(20.0); //ƒnƒCƒ‰ƒCƒg‚Ì‹­‚³

		glPushMatrix();//Rotate=0‚Å’¼—§‚³‚¹‚é‚½‚ß‚É‘S‘Ì-90‹‰ñ“]
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, thetaBody(theta));
			glTranslated(GetSliderValue(X_POSITION),
			             GetSliderValue(Y_POSITION),
			             GetSliderValue(Z_POSITION));
			//‰Á‚¦‚Ä‚¢‚é‚Ì‚ÍÅ‚à‚©‚Á‚±‚æ‚­Œ©‚¦‚é‰ŠúˆÊ’u
			glRotated( 20+GetSliderValue(X_ROTATE), 1, 0, 0);
			glRotated(  0+GetSliderValue(Y_ROTATE), 0, 1, 0);
			glRotated(330+GetSliderValue(Z_ROTATE), 0, 0, 1);
			setDiffuseColor(0.3,0,0.3,1); //ŠgU”½ËŒõ ‡
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
				setDiffuseColor(0.5,0,0,1); //ŠgU”½ËŒõ Ô
				drawTriangularPrism(
				0  +0.1 , 0.5 , 0.1  ,
				1  +0.1 , 0.5 , -0.2 ,
				1.9+0.1 , 0.5 , 1.6  , 0.5);
				drawTriangularPrism(
				-1  -0.1 , 0.5 , -0.2 ,
				0   -0.1 , 0.5 , 0.1  ,
				-1.9-0.1 , 0.5 , 1.6  , 0.5 );
			setDiffuseColor(0.3,0,0.3,1); //ŠgU”½ËŒõ ‡
			glPopMatrix();//Šç
			glPushMatrix();//Œ¨
				glTranslated(0, 0, up1);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawArm(thetaArm1(theta), thetaArm2(theta));
				glScaled(-1,1,1);
				drawArm(thetaArm1(-theta), thetaArm2(-theta));
			glPopMatrix();//Œ¨
			glPushMatrix();//˜
				glTranslated(0, 0, -0.7);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawLeg(thetaLeg1(-theta), thetaLeg2(-theta));
				glScaled(-1,1,1);
				drawLeg(thetaLeg1(theta), thetaLeg2(theta));
			glPopMatrix();//Œ¨
		glPopMatrix();//Rotate=0‚Å’¼—§‚³‚¹‚é‚½‚ß‚É‘S‘Ì90‹‰ñ“]

		//---------------------------------------------------------------------

		// •`‰æI—¹
		EndPaint();
	}
};

// __MODEL_H__
#endif
