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

	bool KeyInput();//ネーム入力のキーボードから文字を読み取る関数

private:
	char m_name[6];//入力された名前の保存用
	bool m_flag;//名前入力が終わったかどうかのフラグ
	
};