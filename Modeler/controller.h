//=============================================================================
// ファイル: controller.h
//=============================================================================
// スライダコントローラの設定
//=============================================================================

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

// ヘッダファイルのインクルード
#include "modelerapp.h"

// フレーム番号の最大値
extern int max_frame_count;

// コントローラ識別用の列挙子
enum CONTROLLERS {

	FRAME_CONTROLS,   // フレームコントローラ（変更しないこと)
	// ～～～列挙子を追加～～～
	X_POSITION,
	Y_POSITION,
	Z_POSITION,
	X_ROTATE,
	Y_ROTATE,
	Z_ROTATE,
	THETA,

	NUM_CONTROLS,	// コントローラ数（必ず末尾に追加）
};

// コントローラの設定
//（NUM_CONTROLSを除くCONTROLLERS列挙子と１：１に対応付ける）
void SetController( ModelerControl* controls )
{
	// フレーム番号の制御用スライダ
	controls[FRAME_CONTROLS] = ModelerControl( "Frame Number", 0, (float)max_frame_count, 1, 0 );

	// ～～～スライダを追加～～～
	// Label Min Max step Init

	controls[X_POSITION] = ModelerControl("X-Position" , -3.0f , 3.0f , 0.1f , 0.0f);
	controls[Y_POSITION] = ModelerControl("Y-Position" , -3.0f , 3.0f , 0.1f , 0.0f);
	controls[Z_POSITION] = ModelerControl("Z-Position" , -3.0f , 3.0f , 0.1f , 0.0f);
	controls[X_ROTATE]   = ModelerControl("X-Rotate"   , 0     , 360  , 1    , 0   );
	controls[Y_ROTATE]   = ModelerControl("Y-Rotate"   , 0     , 360  , 1    , 0   );
	controls[Z_ROTATE]   = ModelerControl("Z-Rotate"   , 0     , 360  , 1    , 0   );
	controls[THETA]      = ModelerControl("THETA"      , -1    , 1    , 0.01 , 0   );

}

// __CONTROLLER_H__
#endif
