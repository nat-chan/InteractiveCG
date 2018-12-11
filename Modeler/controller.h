//=============================================================================
// �t�@�C��: controller.h
//=============================================================================
// �X���C�_�R���g���[���̐ݒ�
//=============================================================================

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

// �w�b�_�t�@�C���̃C���N���[�h
#include "modelerapp.h"

// �t���[���ԍ��̍ő�l
extern int max_frame_count;

// �R���g���[�����ʗp�̗񋓎q
enum CONTROLLERS {

	FRAME_CONTROLS,   // �t���[���R���g���[���i�ύX���Ȃ�����)
	// �`�`�`�񋓎q��ǉ��`�`�`
	X_POSITION,
	Y_POSITION,
	Z_POSITION,
	X_ROTATE,
	Y_ROTATE,
	Z_ROTATE,
	THETA,

	NUM_CONTROLS,	// �R���g���[�����i�K�������ɒǉ��j
};

// �R���g���[���̐ݒ�
//�iNUM_CONTROLS������CONTROLLERS�񋓎q�ƂP�F�P�ɑΉ��t����j
void SetController( ModelerControl* controls )
{
	// �t���[���ԍ��̐���p�X���C�_
	controls[FRAME_CONTROLS] = ModelerControl( "Frame Number", 0, (float)max_frame_count, 1, 0 );

	// �`�`�`�X���C�_��ǉ��`�`�`
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
