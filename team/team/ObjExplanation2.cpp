//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjExplanation2.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjExplanation2::Init()
{
	m_key_flag=false;
}

//アクション
void CObjExplanation2::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if(Input ::GetVKey(VK_RETURN)==true)
	{
		if(m_key_flag==true)
		{
			//説明オブジェクト1作成
			CObjExplanation* obj=new CObjExplanation();//説明オブジェクト2作成
			Objs::InsertObj(obj,OBJ_EXPLANATION,10);

			this->SetStatus(false);//説明オブジェクト2破棄
			
		}
	}
	else
	{
		m_key_flag=true;
	}

}

//ドロー
void CObjExplanation2::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	
	//切り取り位置
	RectSet(0.0f,0.0f,1024.0f,1024.0f,src);

	//表示位置
	RectSet(0.0f,0.0f,1024.0f,768.0f,dst);
	
	Draw::Draw(22,&src,&dst,c,0.0f);//描画


	Font::StrDraw(L"1/3",950,10,30,c);

	Font::StrDraw(L"Next Page : PushEnterKey",300,540,32,c);
}