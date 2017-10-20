//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjNameInput.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNameInput::Init()
{
	//フラグの初期化
	m_flag = false;

	for (int i = 0; i <= 6; i++)
		m_name[i] = ' ';//半角空白で初期化

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"名前を入力してください(半角5文字以内)\n");
}

//アクション
void CObjNameInput::Action()
{
	m_flag = KeyInput();//名前を入力させる関数

	if (m_flag == true)	//名前入力が終了したら
	{
		//タイトルシーンに移動
		Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//文字の描画
	Font::StrDraw(L"名前を入力してください(半角5文字以内)\n", 340, 300, 60, c);
}

//ネーム入力のキーボードから文字を読み取る関数
bool CObjNameInput::KeyInput()
{
	int i = 0;
	
	//while (i < 6)
	//{
		//keyの状態を調べる
		for (char key = 'A'; key <= 'Z'; key++)
		{
			if (Input::GetVKey(key) == true)
			{
				m_name[i++] = key;	//押されたkeyを配列に保存
				break;				//ループを抜ける
			}
		}
		
		//バックスペースが押されたとき
		if (Input::GetVKey(VK_BACK) == true)
		{
			m_name[i] = ' ';//初期にもどして
			i--;	//保存位置を一文字前にずらす
		}
	//}
		if (m_name[5] != ' ')
			return true;

	return false;
}
