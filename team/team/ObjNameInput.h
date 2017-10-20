#pragma once

//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ネーム入力
class CObjNameInput :public CObj
{
public:
	CObjNameInput() {};
	~CObjNameInput() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void KeyInput(int number);//ネーム入力のキーボードから文字を読み取る関数

private:
	char m_name[6];//入力された名前の保存用
	bool m_flag;//最初の1回かどうかの判断用
	bool m_key_flag;//キーが押されているかどうかのフラグ
	int m_input_count;//入力した回数のカウンター。
};