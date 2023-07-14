//InputControl
#include "DxLib.h"
#include "InputControl.h"

//�ϐ��錾
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/*
	���͐���@�\�G����������
	���@���F�Ȃ�
	�߂�l�F�Ȃ�
*/

void Input_Initialize(void)
{

	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;

}

/*
	���͐���F�X�V����
	���@���F�Ȃ�
	�߂�l�F�Ȃ�
*/

void Input_Updata(void)
{

	//�}�E�X���͂̏��̎擾
	old_button = now_button;
	now_button = GetMouseInput();

	//�}�E�X�J�[�\�����W�̏K��
	GetMousePoint(&mouse_position_x, &mouse_position_y);

}
]
/*
	���͐���@�\�FESC�L�[���̓`�F�b�N
	���@���F�Ȃ�
	�߂�l�F�Ȃ�
*/

int Input_Escape(void)
{
	int ret = FALSE;

	//ESC�L�[�������ꂽ�烋�[�v���甲����
	if (ChackHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;

}

/*
	���͐���@�\�F���͏��K�������i�������u�ԁj
	���@���F�w�肷��}�E�X�̃{�^��
	�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
*/

int GetOldKey(int key)
{

	int ret = FALSE;

	if ((key & old_button) != FALSE)
	{

		ret = TRUE;

	}

	return 0;

}

/*
	* ���͐���@�\�F���͏��擾�����i�������u�ԁj
	*���@���F�w�肷��}�E�X�̃{�^��
	*�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
*/

int ret = FALSE;
int keyflg = now_button & old_button;

if()