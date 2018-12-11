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
int max_frame_count = 500;

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

		//-----------------------------------------------------------------
	}

	// 手動アニメーションの設定
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// アニメーション
		//-----------------------------------------------------------------

			// 〜〜〜プログラムを記述〜〜〜

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
		//TODO
		setAmbientColor(0.5,0.4,0.3); //環境光
		setSpecularColor(0,1,0); //鏡面反射光
		setShininess(20.0); //ハイライトの強さ

		glPushMatrix();//Rotate=0で直立させるために全体-90°回転
			glRotated(-90, 1, 0, 0);
//			glTranslated(GetSliderValue(X_POSITION),
//			             GetSliderValue(Y_POSITION),
//			             GetSliderValue(Z_POSITION));
//			glRotated(   GetSliderValue(X_ROTATE), 1, 0, 0);
//			glRotated(   GetSliderValue(Y_ROTATE), 0, 1, 0);
//			glRotated(   GetSliderValue(Z_ROTATE), 0, 0, 1);
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
			glPopMatrix();//顔
			glPushMatrix();//二の腕
				glTranslated(0, 0, up1);
				glRotated(180, 1, 0, 0);
				glScaled(0.9,1.2,1);
				//TODO
				glPushMatrix();//右腕
					glTranslated(-2.5, 0, 0);
					glRotated(GetSliderValue(X_ROTATE), 1, 0, 0);
					drawSphere(0.6);
					drawCylinder(2,0.5,0.5);
					glPushMatrix();//前腕
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
					glPopMatrix();//前腕
				glPopMatrix();//右腕
			glPopMatrix();//二の腕
		glPopMatrix();//Rotate=0で直立させるために全体90°回転

		//---------------------------------------------------------------------

		// 描画終了
		EndPaint();
	}
};

// __MODEL_H__
#endif
