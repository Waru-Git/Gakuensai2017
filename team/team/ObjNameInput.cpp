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

	//nameの初期化
	for (int i = 0; i < 5; i++)
	{
		m_name[i] = '-';
	}

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"名前を入力してください(半角5文字以内)\n");
}

//アクション
void CObjNameInput::Action()
{


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