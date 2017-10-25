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
	m_end_flag = false;
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
		/*while (m_input_count < 5)
		{*/
		if(m_end_flag == false)	//入力が終了していなければ
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

			if (m_input_count >= 1)	//1文字以上入力されていれば
				m_end_flag = InputEndCheck();//文字列が終えているかどうかを調べる
			else
				;//入力を促す文章の追加予定
			
			//デバッグ用---------------------------------------
			wchar_t str[256];
			swprintf_s(str, L"m_input_count:%d", m_input_count);
			OutputDebugStringW(str);
			//--------------------------------------------------------
		}
		else		//入力が完了したら
		{
			//名前をユーザーデータにコピー
			strcpy(((UserData*)Save::GetData())->mRankingNameData[m_rank - 1], m_name);					

			Save::Seve();//UserDataの作成（セーブ）する。

			//タイトルシーンに移動
			Scene::SetScene(new CSceneTitle());
		}
	}

	m_first_flag = false;

}

//ドロー
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//文字の描画
	Font::StrDraw(L"名前を入力してください(半角5文字以内)", 50, 300, 60, c);
}

//ネーム入力のキーボードから文字を読み取る関数
//引数:入力された文字を入れる配列の要素数
//戻り値：対応しているkeyが押されたら:true 何処も押されていなければ:false
bool CObjNameInput::KeyInput(int number)
{
	//EnterKeyが押されたとき
	if (Input::GetVKey(VK_RETURN) == true)
	{
		m_name[number] = '\0';	//\0を入れる
		return true;
	}
	
	////バックスペースが押されたとき
	//if (Input::GetVKey(VK_BACK) == true)
	//{
	//	if (m_input_count != 0)//未入力の状態でなければ
	//	{
	//		m_name[number] = ' ';	//初期にもどして
	//		m_input_count--;		//保存位置を一文字前にずらす
	//	}
	//	return true;
	//}

	//keyの状態を調べる
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			m_name[number] = key;	//押されたkeyを配列に保存
			
			if( m_input_count < 5)//5文字目までなら
				m_input_count++;		//保存位置を一文字進める

			return true;
		}
	}
	return false;
	
}

//文字列入力が終わっているか(\0があるか)調べる関数
//戻り値：\0があれば:true なければ:false 
bool CObjNameInput::InputEndCheck()
{
	//配列の中身を確認していく
	for (int i = 0; i < 6;i++)
	{
		//\0があれば
		if (m_name[i] == '\0')
			return true;
	}

	return false;
}
