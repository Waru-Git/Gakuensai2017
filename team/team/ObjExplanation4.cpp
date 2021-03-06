//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include"ObjExplanation4.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjExplanation4::Init()
{
	m_key_flag = false;

}

//アクション
void CObjExplanation4::Action()
{
	//→かDキーを押すとモードセレクトへ移行
	if (Input::GetVKey(VK_RIGHT) == true || Input::GetVKey('D') == true)
	{
		if (m_key_flag == true)
		{
			CObjModeChoice* obj = new CObjModeChoice();
			Objs::InsertObj(obj, OBJ_MODE_CHOICE, 10);

			m_key_flag = false;

			this->SetStatus(false);

		}
	}
	//←かAキーを押すと説明3に移行する
	else if (Input::GetVKey(VK_LEFT) == true || Input::GetVKey('A') == true)
	{
		if (m_key_flag == true)
		{
			CObjExplanation3* obj = new CObjExplanation3();
			Objs::InsertObj(obj,OBJ_EXPLANATION3, 10);

			m_key_flag = false;

			this->SetStatus(false);
		}
	}

	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjExplanation4::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c2[4] = { 1.0f,1.0f,1.0f,2.0f };
	float moji[4] = { 1.0f,1.0f,1.0f,1.0f};

	RECT_F src;//描画元の切り取り位置
	RECT_F dst;//描画先の表示位置

//-----------文字表示-----------------------------
	Font::StrDraw(L"4/4", 950, 10, 30, moji);

	//タイム表示
	Font::StrDraw(L"00:41", 100, 210, 50, moji);

	//タイムの説明文
	Font::StrDraw(L"･タイムの説明",270,120,40,moji);

	Font::StrDraw(L"タイムは対戦開始から決着するまでの時間です。", 280, 190, 30, moji);
	Font::StrDraw(L"タイムの早い上位10人がランキングに", 280, 240, 30, moji);
	Font::StrDraw(L"表示･記録されます。", 280, 290, 30, moji);

	//Font::StrDraw(L"･お邪魔ブロックの説明", 270, 300, 40, c);
	//Font::StrDraw(L"お邪魔ブロックを間に挟む、又は", 280, 370, 30, c);
	//Font::StrDraw(L"お邪魔を端で挟んでも", 280, 420, 30, c);
	//Font::StrDraw(L"消すことはできない。", 280, 470, 30, c);


	////お邪魔の説明
	//Font::StrDraw(L"x0",130,550,80,moji);

	//Font::StrDraw(L"･お邪魔ブロックの説明2",270,540,40,moji);
	//Font::StrDraw(L"次に降ってくるお邪魔の数を表示しています。", 280, 590, 30, moji);

	//勝利判定の説明
	Font::StrDraw(L"･勝敗について", 270, 390, 40, c);
	Font::StrDraw(L"相手の端のマスが埋まり、一定時間が経過すると", 280, 460, 28, c);
	Font::StrDraw(L"勝利となる。", 280, 510, 28, c);


	Font::StrDraw(L"Mode Select : → / D", 360, 660, 32, c);
	Font::StrDraw(L"Back Page   : ← / A", 360, 692, 32, c);


//-----------絵の表示-----------------------------
	


}