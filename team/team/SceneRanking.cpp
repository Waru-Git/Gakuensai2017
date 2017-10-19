//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneRanking.h"
#include "GameHead.h"

//ゲーム初期化メソッド
void CSceneRanking::InitScene()
{
	//ランキング表示オブジェクト作成
	CObjRanking* ranking = new CObjRanking();
	Objs::InsertObj(ranking, OBJ_RANKING, 5);
}

//ゲーム実行中メソッド
void CSceneRanking::Scene()
{
	
}