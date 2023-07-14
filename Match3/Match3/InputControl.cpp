//InputControl
#include "DxLib.h"
#include "InputControl.h"

//変数宣言
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/*
	入力制御機能；初期化処理
	引　数：なし
	戻り値：なし
*/

void Input_Initialize(void)
{

	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;

}

/*
	入力制御：更新処理
	引　数：なし
	戻り値：なし
*/

void Input_Updata(void)
{

	//マウス入力の情報の取得
	old_button = now_button;
	now_button = GetMouseInput();

	//マウスカーソル座標の習得
	GetMousePoint(&mouse_position_x, &mouse_position_y);

}
]
/*
	入力制御機能：ESCキー入力チェック
	引　数：なし
	戻り値：なし
*/

int Input_Escape(void)
{
	int ret = FALSE;

	//ESCキーが押されたらループから抜ける
	if (ChackHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;

}

/*
	入力制御機能：入力情報習得処理（離した瞬間）
	引　数：指定するマウスのボタン
	戻り値：TRUE（入力された）、FALSE（未入力）
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
	* 入力制御機能：入力情報取得処理（押した瞬間）
	*引　数：指定するマウスのボタン
	*戻り値：TRUE（入力された）、FALSE（未入力）
*/

int ret = FALSE;
int keyflg = now_button & old_button;

if()