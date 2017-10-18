//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjRanking.h"
#include"ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRanking::Init()
{
	m_key_flag = false;//キーフラグ

	//起動時一回だけランキング初期化
	static bool init_point = false;
	if (init_point == false)
	{
		//ランキング初期化
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->mRankingTimeData[i] = 0;
		}
		init_point = true;
	}
}

//アクション
void CObjRanking::Action()
{
	//エンターキーが押されたらモードセレクトへ戻す
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			CObjModeChoice* obj = new CObjModeChoice();
			Objs::InsertObj(obj, OBJ_MODE_CHOICE, 10);

			m_key_flag = false;

			this->SetStatus(false);//ランキング破棄
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjRanking::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ランキング
	Font::StrDraw(L"ランキング",350,30,60,c);

	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d位    %02d:%02d", i + 1, ((UserData*)Save::GetData())->mRankingTimeData[i]/60,((UserData*)Save::GetData())->mRankingTimeData[i]%60);
		Font::StrDraw(str, 350, 150 + 60 * i,40,c);
	}
}