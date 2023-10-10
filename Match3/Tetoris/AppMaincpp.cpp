#include "DxLib.h"
#include "FreamControl.h"
#include "ScenManager.h"
#include "InputControl.h"

//�}�N����`
#define SCREEN_HEIGHT (720)
#define SCREEN_WIDTH (1280)
#define SCREEN_COLORBIT	(32)
#define FONT_SIZE (20)


//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR ipCmdLine, _In_ int nShowCmd)
{

	//�^�C�g����ύX
	SetMainWindowText("�e�g���X");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�̌���
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dx���C�u�����̏���������

	if (DxLib_Init() == -1)
	{
		//�G���[�I��
		return -1;
	}

	//�t���[������@�\����������
	FreamContorol_Initialize();

	//�V�[���Ǘ��@�\����������
	SceneManager_Initialize(E_TITLE);

	//���͐���@�\����������
	InputControl_Initialize();

	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�����T�C�Y��ݒ�
	SetFontSize(FONT_SIZE);

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && GetExitButton() != TRUE && ErrorCheck() ==
		D_NORMALITY)
	{
		//�t���[������@�\�X�V����
		FrameControl_Update();

		//��ʂ̏�����
		ClearDrawScreen();

		//���͐���@�\�X�V����
		InputControl_Update();

		//�V�[���Ǘ��@�\�X�V����
		SceneManager_Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

	}

	//Dx���C�u�����g�p�̏I������

	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}