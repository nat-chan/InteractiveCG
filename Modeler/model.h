//=============================================================================
// ファイル: model.h
//=============================================================================
// モデルの設定・描画を制御
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ヘッダファイルのインクルード
#include "animator.h"

// フレーム番号の最大値
int max_frame_count = 450;

// Modelクラスの定義（ModelerViewクラスを継承）
class Model : public ModelerView {
private:
	//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
	//第3週課題
	//---------------------------------------------------------------------

	// フレーム番号
	int frame_count;
	
	//-------------------------------------------------------------------------
	// 制御変数
	//-------------------------------------------------------------------------

		// 〜〜〜変数を追加〜〜〜
		double theta;


	//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


public:
	// コンストラクタ（スーパークラスのコンストラクタを呼び出す）
	Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
	{
		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
		//第3週課題
		//---------------------------------------------------------------------

		// フレーム番号の初期化
		frame_count = 0;
		
		//---------------------------------------------------------------------
		// 初期化
		//---------------------------------------------------------------------

			// 〜〜〜変数を初期化〜〜〜
			theta = 0;


		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
	}

	//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
	//第3週課題
	//---------------------------------------------------------------------

	// 自動アニメーションの設定
	void SetAutomaticAnimation()
	{
		//-----------------------------------------------------------------
		// アニメーション
		//-----------------------------------------------------------------

			// 〜〜〜プログラムを記述〜〜〜
		theta = sin(frame_count*M_PI/30);

		//-----------------------------------------------------------------
	}

	// 手動アニメーションの設定
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// アニメーション
		//-----------------------------------------------------------------

			// 〜〜〜プログラムを記述〜〜〜
		theta = GetSliderValue(THETA);

		//-----------------------------------------------------------------
	}

	//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


	// 描画の前処理
	void BeginPaint()
	{
		// 半透明処理を有効化
		glEnable( GL_BLEND );
		// 混合方法の指定
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	}

	// 描画の後処理
	void EndPaint()
	{
		// 半透明処理を無効化
		glDisable( GL_BLEND );
	}

	void drawArm(double r1, double r2){
		glPushMatrix();//二の腕
			glTranslated(-2.5, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.6);
			drawCylinder(2,0.5,0.5);
			glPushMatrix();//前腕
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
			glPopMatrix();//前腕
		glPopMatrix();//二の腕
	}

	void drawLeg(double r1, double r2){
		glPushMatrix();//太もも
			glTranslated(-1, 0, 0);
			glRotated(r1, 1, 0, 0);
			drawSphere(0.7);
			double adjust = 0.5;
			double adjust2= 0.1;
			drawCylinder(2+ adjust,0.5+adjust2,0.5+adjust2);
			glPushMatrix();//ふくらはぎ
				glTranslated(0, 0, 2.4+ adjust);
				glRotated(r2, 1, 0, 0);
				drawSphere(0.6);
				glTranslated(0, 0, 0.4);
				drawCylinder(2,0.5+adjust2,0.5+adjust2);
				glTranslated(0,0,2.1);
				drawSphere(0.4);
				glTranslated(-0.5, -1.4, 0.1);
				drawBox(1,1.8,0.8);
			glPopMatrix();//ふくらはぎ
		glPopMatrix();//太もも
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


	// オブジェクトの描画
	void draw()
	{
		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
		//第3週課題
		//---------------------------------------------------------------------
		// 自動アニメーションの処理
		if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
			// フレーム番号の更新
			SetSliderValue( FRAME_CONTROLS, ++frame_count );
			// 自動アニメーション
			SetAutomaticAnimation();
		}
		// 手動アニメーションの処理
		else {
			// フレーム番号を取得
			frame_count = (int)GetSliderValue( FRAME_CONTROLS );
			// 手動アニメーション
			SetManualAnimation();			 
		}
		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


		// スーパークラスの描画メソッドをコール（必須）
		ModelerView::draw();


		// 描画開始
		BeginPaint();

		//---------------------------------------------------------------------
		// オブジェクトを描画
		//---------------------------------------------------------------------

		 // 〜〜〜プログラムを記述〜〜〜
		setAmbientColor(0.5,0.4,0.3); //環境光
		setSpecularColor(0,1,0); //鏡面反射光
		setShininess(20.0); //ハイライトの強さ

		glPushMatrix();//Rotate=0で直立させるために全体-90°回転
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, thetaBody(theta));
			glTranslated(GetSliderValue(X_POSITION),
			             GetSliderValue(Y_POSITION),
			             GetSliderValue(Z_POSITION));
			//加えているのは最もかっこよく見える初期位置
			glRotated( 20+GetSliderValue(X_ROTATE), 1, 0, 0);
			glRotated(  0+GetSliderValue(Y_ROTATE), 0, 1, 0);
			glRotated(330+GetSliderValue(Z_ROTATE), 0, 0, 1);
			setDiffuseColor(0.3,0,0.3,1); //拡散反射光 紫
			glPushMatrix();//胴体
				glScaled(1.2,0.9,1);
				float up1 = 3.5;
				drawCylinder(up1,1,2);
				glPushMatrix();//肩
					glTranslated(0, 0, up1);
					float up2 = 1.;
					drawCylinder(up2,2,1);
				glPopMatrix();//肩
				drawSphere(1);
			glPopMatrix();
			glPushMatrix();//顔
				float up3 = up1 + up2 + 1.2;
				glTranslated(0.0, 0.0, up3); glRotated(0, 1, 0, 0); glScaled(1.0, 1.0, 1.5);
				drawSphere(0.9);
				setDiffuseColor(0.5,0,0,1); //拡散反射光 赤
				drawTriangularPrism(
				0  +0.1 , 0.5 , 0.1  ,
				1  +0.1 , 0.5 , -0.2 ,
				1.9+0.1 , 0.5 , 1.6  , 0.5);
				drawTriangularPrism(
				-1  -0.1 , 0.5 , -0.2 ,
				0   -0.1 , 0.5 , 0.1  ,
				-1.9-0.1 , 0.5 , 1.6  , 0.5 );
			setDiffuseColor(0.3,0,0.3,1); //拡散反射光 紫
			glPopMatrix();//顔
			glPushMatrix();//肩
				glTranslated(0, 0, up1);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawArm(thetaArm1(theta), thetaArm2(theta));
				glScaled(-1,1,1);
				drawArm(thetaArm1(-theta), thetaArm2(-theta));
			glPopMatrix();//肩
			glPushMatrix();//腰
				glTranslated(0, 0, -0.7);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				drawLeg(thetaLeg1(-theta), thetaLeg2(-theta));
				glScaled(-1,1,1);
				drawLeg(thetaLeg1(theta), thetaLeg2(theta));
			glPopMatrix();//肩
		glPopMatrix();//Rotate=0で直立させるために全体90°回転

		//---------------------------------------------------------------------

		// 描画終了
		EndPaint();
	}
};

// __MODEL_H__
#endif
