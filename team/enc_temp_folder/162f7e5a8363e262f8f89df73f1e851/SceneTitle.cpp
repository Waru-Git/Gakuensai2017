//ＳＴＬデバッグ機能をＯＦＦにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneTitle.h"
#include "GameHead.h"
#include"GameL\DrawTexture.h"
#include "GameL\Audio.h"


//コンストラクタ
CSceneTitle::CSceneTitle()
{
	
}
//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameStart : PushEnterKey");
	Font::SetStrTex(L"タイトル");
	//Font::SetStrTex(L"説明");

	Draw::LoadImage(L"TitleBackground.png",6,TEX_SIZE_512);//タイトル背景
	Draw::LoadImage(L"Title.png",7,TEX_SIZE_512);//タイトルロゴ
	Draw::LoadImage(L"Intervention.png", 10, TEX_SIZE_32);//お邪魔ブロック
	Draw::LoadImage(L"W_key.png" , 13 , TEX_SIZE_32);//Wキー
	Draw::LoadImage(L"D_key.png" , 14 , TEX_SIZE_32);//Dキー
	Draw::LoadImage(L"A_key.png" , 15 , TEX_SIZE_32);//Aキー
	Draw::LoadImage(L"S_key.png" , 16 , TEX_SIZE_32);//Sキー
	Draw::LoadImage(L"UP_key.png" , 17 , TEX_SIZE_32);//↑キー
	Draw::LoadImage(L"DOWN_key.png" , 18 , TEX_SIZE_32);//↓キー
	Draw::LoadImage(L"LEFT_key.png" , 19 , TEX_SIZE_32);//←キー
	Draw::LoadImage(L"RIGHT_key.png" , 20 , TEX_SIZE_32);//→キー
	Draw::LoadImage(L"image.png",21,TEX_SIZE_512);//機体と爆発のエフェクト
	Draw::LoadImage(L"slide.png",22,TEX_SIZE_1024);//スライド
	Draw::LoadImage(L"gauge.png",23,TEX_SIZE_600);//ゲージ
	
	Audio::LoadAudio(9,L"Title.wav" , BACK_MUSIC);//タイトルミュージック
	Audio::LoadAudio(10,L"Exp.wav" , BACK_MUSIC);//説明画面時のミュージック

	//ブロック 0~5 & 6
	Draw::LoadImage(L"ColorBlue.png"  ,0,TEX_SIZE_64);
	Draw::LoadImage(L"ColorRed.png"   ,1,TEX_SIZE_64);
	Draw::LoadImage(L"ColorGreen.png" ,2,TEX_SIZE_64);
	Draw::LoadImage(L"ColorYellow.png",3,TEX_SIZE_64);
	Draw::LoadImage(L"ColorPink.png"  ,4,TEX_SIZE_64);
	Draw::LoadImage(L"ColorPurple.png" ,5,TEX_SIZE_64);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(9);

	//タイトルオブジェクト作成
	CObjTitle* obj=new CObjTitle();//タイトルオブジェクト作成
	Objs::InsertObj(obj,OBJ_TITLE,10);//タイトルオブジェクト作成

}

//ゲームメイン実行中のメソッド
void CSceneTitle::Scene()
{

}


