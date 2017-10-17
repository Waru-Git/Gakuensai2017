#pragma once

//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ネーム入力
class CSceneNameInput :public CScene
{
public:
	CSceneNameInput() {};
	~CSceneNameInput() {};
	void InitScene();//ゲームメインの初期化のメソッド
	void Scene();//ゲームメインの実行中のメソッド
private:
};
