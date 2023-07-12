#include "GameClearScene.h"
#include "DxLib.h"
#include "SceneManager.h"

//�ϐ��錾
int GameClearImage;
int GameClearSE;
int GameClearFlag;

/*
	�Q�[���N���A��ʁF����������
	�����F�Ȃ�
	�߂�l�G�G���[���
*/

int GameClearScene_Initialize(void) 
{
	int ret = 0;

		//�摜�̓ǂݍ���
	GameClearImage = LoadGraph("images/gameclear.png");
		//�����̓ǂݍ���
	GameClearSE = LoadSoundMem("sounds/gameclear_se.mp3");

	GameClearFlag = 0;

	//�G���[�`�F�b�N
	if (GameClearImage == -1)
	{
		ret = -1;
	}
	if (GameClearSE == -1)
	{
		ret = -1;
	}

	return ret;

}
/*
�Q�[���N���A��ʁF�X�V����
�����F�Ȃ�
�߂�l�F�Ȃ�
*/

