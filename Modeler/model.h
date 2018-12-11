//=============================================================================
// �t�@�C��: model.h
//=============================================================================
// ���f���̐ݒ�E�`��𐧌�
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// �w�b�_�t�@�C���̃C���N���[�h
#include "animator.h"

// �t���[���ԍ��̍ő�l
int max_frame_count = 450;

// Model�N���X�̒�`�iModelerView�N���X���p���j
class Model : public ModelerView {
private:
	//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
	//---------------------------------------------------------------------

	// �t���[���ԍ�
	int frame_count;
	
	//-------------------------------------------------------------------------
	// ����ϐ�
	//-------------------------------------------------------------------------

		// �`�`�`�ϐ���ǉ��`�`�`
		double theta;


	//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


public:
	// �R���X�g���N�^�i�X�[�p�[�N���X�̃R���X�g���N�^���Ăяo���j
	Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
	{
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
		//---------------------------------------------------------------------

		// �t���[���ԍ��̏�����
		frame_count = 0;
		
		//---------------------------------------------------------------------
		// ������
		//---------------------------------------------------------------------

			// �`�`�`�ϐ����������`�`�`
			theta = 0;


		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	}

	//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
	//---------------------------------------------------------------------

	// �����A�j���[�V�����̐ݒ�
	void SetAutomaticAnimation()
	{
		//-----------------------------------------------------------------
		// �A�j���[�V����
		//-----------------------------------------------------------------

			// �`�`�`�v���O�������L�q�`�`�`
		theta = sin(frame_count*M_PI/30);

		//-----------------------------------------------------------------
	}

	// �蓮�A�j���[�V�����̐ݒ�
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// �A�j���[�V����
		//-----------------------------------------------------------------

			// �`�`�`�v���O�������L�q�`�`�`
		theta = GetSliderValue(THETA);

		//-----------------------------------------------------------------
	}

	//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


	// �`��̑O����
	void BeginPaint()
	{
		// ������������L����
		glEnable( GL_BLEND );
		// �������@�̎w��
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	}

	// �`��̌㏈��
	void EndPaint()
	{
		// �����������𖳌���
		glDisable( GL_BLEND );
	}

	void drawArm(double r1, double r2){
		glPushMatrix();//��̘r
			glTranslated(-2.5, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.6);
			drawCylinder(2,0.5,0.5);
			glPushMatrix();//�O�r
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
			glPopMatrix();//�O�r
		glPopMatrix();//��̘r
	}

	void drawLeg(double r1, double r2){
		glPushMatrix();//������
			glTranslated(-1, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.7);
			double adjust = 0.5;
			double adjust2= 0.1;
			drawCylinder(2+ adjust,0.5+adjust2,0.5+adjust2);
			glPushMatrix();//�ӂ���͂�
				glTranslated(0, 0, 2.4+ adjust);
				glRotated(r2, 1, 0, 0);
				drawSphere(0.6);
				glTranslated(0, 0, 0.4);
				drawCylinder(2,0.5+adjust2,0.5+adjust2);
				glTranslated(0,0,2.1);
				drawSphere(0.4);
				glTranslated(-0.5, -1.4, 0.1);
				drawBox(1,1.8,0.8);
			glPopMatrix();//�ӂ���͂�
		glPopMatrix();//������
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


	// �I�u�W�F�N�g�̕`��
	void draw()
	{
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
		//---------------------------------------------------------------------
		// �����A�j���[�V�����̏���
		if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
			// �t���[���ԍ��̍X�V
			SetSliderValue( FRAME_CONTROLS, ++frame_count );
			// �����A�j���[�V����
			SetAutomaticAnimation();
		}
		// �蓮�A�j���[�V�����̏���
		else {
			// �t���[���ԍ����擾
			frame_count = (int)GetSliderValue( FRAME_CONTROLS );
			// �蓮�A�j���[�V����
			SetManualAnimation();			 
		}
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


		// �X�[�p�[�N���X�̕`�惁�\�b�h���R�[���i�K�{�j
		ModelerView::draw();


		// �`��J�n
		BeginPaint();

		//---------------------------------------------------------------------
		// �I�u�W�F�N�g��`��
		//---------------------------------------------------------------------

		 // �`�`�`�v���O�������L�q�`�`�`
		setAmbientColor(0.5,0.4,0.3); //����
		setSpecularColor(0,1,0); //���ʔ��ˌ�
		setShininess(20.0); //�n�C���C�g�̋���

		glPushMatrix();//Rotate=0�Œ��������邽�߂ɑS��-90����]
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, thetaBody(theta));
			glTranslated(GetSliderValue(X_POSITION),
			             GetSliderValue(Y_POSITION),
			             GetSliderValue(Z_POSITION));
			//�����Ă���͍̂ł��������悭�����鏉���ʒu
			glRotated( 20+GetSliderValue(X_ROTATE), 1, 0, 0);
			glRotated(  0+GetSliderValue(Y_ROTATE), 0, 1, 0);
			glRotated(330+GetSliderValue(Z_ROTATE), 0, 0, 1);
			setDiffuseColor(0.3,0,0.3,1); //�g�U���ˌ� ��
			glPushMatrix();//����
				glScaled(1.2,0.9,1);
				float up1 = 3.5;
				drawCylinder(up1,1,2);
				glPushMatrix();//��
					glTranslated(0, 0, up1);
					float up2 = 1.;
					drawCylinder(up2,2,1);
				glPopMatrix();//��
				drawSphere(1);
			glPopMatrix();
			glPushMatrix();//��
				float up3 = up1 + up2 + 1.2;
				glTranslated(0.0, 0.0, up3); glRotated(0, 1, 0, 0); glScaled(1.0, 1.0, 1.5);
				drawSphere(0.9);
				setDiffuseColor(0.5,0,0,1); //�g�U���ˌ� ��
				drawTriangularPrism(
				0  +0.1 , 0.5 , 0.1  ,
				1  +0.1 , 0.5 , -0.2 ,
				1.9+0.1 , 0.5 , 1.6  , 0.5);
				drawTriangularPrism(
				-1  -0.1 , 0.5 , -0.2 ,
				0   -0.1 , 0.5 , 0.1  ,
				-1.9-0.1 , 0.5 , 1.6  , 0.5 );
			setDiffuseColor(0.3,0,0.3,1); //�g�U���ˌ� ��
			glPopMatrix();//��
			glPushMatrix();//��
				glTranslated(0, 0, up1);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawArm(thetaArm1(theta), thetaArm2(theta));
				glScaled(-1,1,1);
				drawArm(thetaArm1(-theta), thetaArm2(-theta));
			glPopMatrix();//��
			glPushMatrix();//��
				glTranslated(0, 0, -0.7);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawLeg(thetaLeg1(-theta), thetaLeg2(-theta));
				glScaled(-1,1,1);
				drawLeg(thetaLeg1(theta), thetaLeg2(theta));
			glPopMatrix();//��
		glPopMatrix();//Rotate=0�Œ��������邽�߂ɑS��90����]

		//---------------------------------------------------------------------

		// �`��I��
		EndPaint();
	}
};

// __MODEL_H__
#endif
