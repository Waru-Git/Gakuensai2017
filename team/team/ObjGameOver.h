#pragma once

//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


//オブジェクト：タイトル
class CObjGameOver:public CObj
{
public:
	CObjGameOver(int p);
	~CObjGameOver(){};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	void Result();//パターンに応じて結果の文字をだす関数
	void RankingSort(int rank[11]);
private:
	int m_pattern;//勝敗パターン
	float m_y;  //文字のy位置
	float m_yy;  //文字のy位置
	int count;	//文字をずらすためのカウント
	bool m_cp_flag;	//CP戦かどうかを示すフラグ
};