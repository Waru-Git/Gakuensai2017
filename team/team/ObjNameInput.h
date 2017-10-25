#pragma once

//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ネーム入力
class CObjNameInput :public CObj
{
public:
	CObjNameInput(int rank);
	~CObjNameInput() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	bool KeyInput(int number);//ネーム入力のキーボードから文字を読み取る関数

private:
	char m_name[6];		//入力された名前の保存用
	bool m_first_flag;	//最初の1回だけ処理しないようにするためのフラグ
	bool m_key_flag;	//キーが入力可能な状態かどうかを表すフラグ
	bool m_input_flag;	//キー入力されたかどうかを表すフラグ
	int m_input_count;//入力した回数のカウンター。
	int m_rank;	//ランキング
};