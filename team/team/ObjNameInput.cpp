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

//コンストラクタ
CObjNameInput::CObjNameInput(int rank)
{
	m_rank = rank;	//ランキング
}

//イニシャライズ
void CObjNameInput::Init()
{
	//フラグの初期化
	m_first_flag = true;
	m_key_flag = true;		//キー入力を可能な状態にする
	m_input_flag = false;
	m_input_count = 0;


	for (int i = 0; i <= 6; i++)
		m_name[i] = ' ';//半角空白で初期化

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"名前を入力してください(半角5文字以内)\n");
}

//アクション
void CObjNameInput::Action()
{
	//初めの2回目以降
	if (m_first_flag == false)	
	{
		while (m_input_count < 5)
		{
			if (m_key_flag == true)	//キーフラグがオンなら
			{
				m_input_flag = KeyInput(m_input_count);//名前の入力をさせる
				
				if(m_input_flag == true)//対応ボタンのどこかが押されたら
					m_key_flag = false;	//キーフラグをオフにする
			}
			else //キーフラグがオフなら
			{
				//1つ前の文字と同じ文字が押されていなければ
				if (Input::GetVKey(m_name[m_input_count - 1]) == false)
					m_key_flag = true;	//キーフラグをオンにする
			}

			//デバッグ用---------------------------------------
			wchar_t str[256];
			swprintf_s(str, L"m_input_count:%d", m_input_count);
			OutputDebugStringW(str);
			//--------------------------------------------------------
		}

		m_name[5] = '\0';//おわりに\0をいれる

		strcpy(((UserData*)Save::GetData())->mRankingNameData[m_rank - 1], m_name);		//名前			
		
		Save::Seve();//UserDataの作成（セーブ）する。

		//タイトルシーンに移動
		Scene::SetScene(new CSceneTitle());
	}

	m_first_flag = false;

}

//ドロー
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//文字の描画
	Font::StrDraw(L"名前を入力してください(半角5文字以内)\n", 340, 300, 60, c);
}

//ネーム入力のキーボードから文字を読み取る関数
//引数:入力された文字を入れる配列の要素数
//戻り値：対応しているkeyが押されたら:true 何処も押されていなければ:false
bool CObjNameInput::KeyInput(int number)
{
	//keyの状態を調べる
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			m_name[number] = key;	//押されたkeyを配列に保存
			m_input_count++;		//保存位置を一文字進める
			return true;
		}
	}
	return false;
	////バックスペースが押されたとき
	//if (Input::GetVKey(VK_BACK) == true)
	//{
	//	m_name[number] = ' ';	//初期にもどして
	//	m_input_count--;		//保存位置を一文字前にずらす
	//	return true;
	//}
}
