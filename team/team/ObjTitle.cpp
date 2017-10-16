//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"ObjBackground.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag=false;
	m_time = 0;

	//ランキング情報の初期化
	for (int i = 0; i < 11; i++)
	{
		((UserData*)Save::GetData())->mRankingTimeData[i] = 0;
	}
	Save::Open();

	

}

//アクション
void CObjTitle::Action()
{
	//Wキーを押して説明にに移行する
	if(Input ::GetVKey(VK_RETURN)==true)
	{
		if(m_key_flag==true)
		{
			
			//モード選択画面移動
			CObjModeChoice* obj=new CObjModeChoice();//説明オブジェクト作成
			Objs::InsertObj(obj,OBJ_MODE_CHOICE,10);//タイトルオブジェクト作成

			this->SetStatus(false);//タイトルオブジェクト削除

			//タイトル音ストップ
			Audio::Stop(9);
			
			//説明時のミュージック開始
			Audio::Start(10);
			
			m_key_flag=false;

		}
	}

	else
	{
		m_key_flag=true;
	}

}

//ドロー
void CObjTitle::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};
	RECT_F src;//描画元の切り取り位置
	RECT_F dst;//描画先の表示位置

//背景の描画-------------------------------------------------

	//切り取り位置の設定
	RectSet(0.0f,0.0f,512.0f,512.0f,src);

	//背景の表示位置の設定
	RectSet(0.0f,0.0f,WINDOW_SIZE_W,WINDOW_SIZE_H,dst);

	//描画
	Draw::Draw(6,&src,&dst,c,0.0f);

//背景の描画おわり------------------------------------------------------------

//タイトルロゴ描画-----------------------------------

	//切り取り位置の設定
	RectSet(0.0f,0.0f,512.0f,512.0f,src);

	//背景の表示位置の設定
	RectSet(150.0f,200.0f,812.0f,362.0f,dst);

	Draw::Draw(7,&src,&dst,c,0.0f);//描画

//タイトルロゴおわり--------------------------------

//文字表示-------------------------------------------
	m_time++;

	if (m_time >= 0 && m_time < 40)
	{
		Font::StrDraw(L"PushEnterKey", 340, 540, 60, c);
	}
	else if (m_time >= 80)
	{
		m_time = 0;
	}

}