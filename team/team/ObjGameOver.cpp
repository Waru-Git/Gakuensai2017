//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameOver.h"
#include "ObjBackground.h"

#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;



//コンストラクタ
CObjGameOver::CObjGameOver(int p)
{
	m_pattern=p; //ゲーム勝利パターンをObjMainから持ってきて、m_patternに代入
}

//イニシャライズ
void CObjGameOver::Init()
{
	//位置の初期化
	m_y = 900.0f;
	m_yy = 800.0f;

	count=0;
	
	//CP戦かどうかしらべる------
	//マップオブジェクトの呼び出し
	CObjMain * obj = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	m_cp_flag=obj->ReturnCPflag();
	//-------------------------

	//Win.wav以外の音楽をとめる------
	//戦闘曲ストップ
	Audio::Stop(8);
	//勝敗ミュージック開始
	Audio::Start(7);
	//--------------------------------
}

//アクション
void CObjGameOver::Action()
{	
	count++;//カウントを増やしていく

	if( count > 300)//300を超えないようにする
		count = 300;

	//エンターキーがおされたら
	if(Input ::GetVKey(VK_RETURN)==true)
	{
		//マスターボリュームを1.0に戻す
		float v =Audio::VolumeMaster( 0 );
		v =Audio::VolumeMaster( (1.0-v) );

		//CP戦　かつ　左プレイヤーの勝利なら
		if (m_cp_flag == true && m_pattern == 1)
		{
			//マップオブジェクトの呼び出し
			CObjMain * obj_main = (CObjMain*)Objs::GetObj(OBJ_MAIN);

			//ランキングの最下位に今回のタイムを保存
			((UserData*)Save::GetData())->mRankingTimeData[10] = obj_main->ReturnTime();

			//ランキングのをソートする
			RankingSort(((UserData*)Save::GetData())->mRankingTimeData);

		}

		//タイトルへ移行
		Scene::SetScene(new CSceneTitle);		
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};//カラー
		
	Result();//結果を表示する
	Font::StrDraw(L"EnterKeyでタイトルに戻る",223,m_y - count,50,c);
	
}

//パターンに応じて
void CObjGameOver::Result()
{
	CObjCP* obj_cp = new CObjCP();

	float c[4]={1.0f,1.0f,1.0f,1.0f};//カラー
	
	switch(m_pattern)
	{
		case 0:
		{
			//引き分け表示
			Font::StrDraw(L"DROW",400,m_yy - count,100,c);
			break;
		}
		case 1:
		{
			if (obj_cp != nullptr)
			{
				//CPU勝利
				Font::StrDraw(L"YOU WIN", 350, m_yy - count, 100, c);
				break;
			}
			else//2人対戦時
			{
				//1Pwin表示
				Font::StrDraw(L"1P WIN", 350, m_yy - count, 100, c);
				break;
			}
		}
		case 2:
		{
			if (obj_cp != nullptr)//CPU対戦か否か判定
			{
				//CPU勝利
				Font::StrDraw(L"YOU LOSE", 350, m_yy - count, 100, c);
				break;
			}
			else//2人対戦時
			{
				//2Pwin表示
				Font::StrDraw(L"2P WIN", 350, m_yy - count, 100, c);
				break;
			}
		}
	}
}

//ランキングソートメソッド
//引数１int[16]:ランキング用は配列
//高い順でバブルソートを行う
void CObjGameOver::RankingSort(int rank[11])
{
	//値の交換用変数
	int w;

	//バブルソート
	for (int i = 0; i<10; i++)
	{
		for (int j = i + 1; j<11; j++)
		{
			if (rank[i]<=rank[j])
			{
				//値の交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
}
