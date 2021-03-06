//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneVsCP.h"
#include "GameHead.h"

//コンストラクタ
CSceneVsCP::CSceneVsCP()
{
}

//デストラクタ
CSceneVsCP::~CSceneVsCP()
{

}

//ゲームメインの初期化メソッド
void CSceneVsCP::InitScene()
{
	//音楽の読み込み宣言
	Audio::LoadAudio(2,L"Hit.WAV",EFFECT);	       //ブロックとブロック、ブロックと一番最初の真ん中であたったときの音
	Audio::LoadAudio(3,L"bomb.WAV",EFFECT);        //爆発音
	Audio::LoadAudio(4,L"Ojama.WAV",EFFECT);       //お邪魔発射音
	Audio::LoadAudio(5,L"SetOjama.WAV",EFFECT);    //お邪魔設置音
	Audio::LoadAudio(7,L"Win.wav"   ,BACK_MUSIC);  //勝負がついた時に流れる
	Audio::LoadAudio(8,L"Fight.wav" , BACK_MUSIC); //戦闘ミュージック

	Audio::LoadAudio(9,L"Start1.wav" , EFFECT);     //スタートシグナル(3~1)
	Audio::LoadAudio(10,L"Start0.wav" , EFFECT);     //スタートシグナル(start)
	
	//戦闘ミュージック開始
	Audio::Start(8);

	//ボリュームを増やす
	
	//音楽スタート
	float Volume2 = Audio::Volume(-0.4f,2);//設置音
	float Volume3 = Audio::Volume(-0.7f,3);//爆発音
	float Volume4 = Audio::Volume(1.0f,4);//お邪魔発射音
	float Volume5 = Audio::Volume(1.0f,5);//お邪魔設置音
	float Volume7 = Audio::Volume(-0.2f,7);//勝利音
	float Volume8 = Audio::Volume(-0.6f,8);//戦闘BGM
	float Volume9 = Audio::Volume(-0.3f,9);//スタートシグナル
	float Volume10 = Audio::Volume(-0.3f,10);//スタートシグナル
	
	//ブロック 0~5 & 6
	Draw::LoadImage(L"ColorBlue.png"  ,0,TEX_SIZE_64);
	Draw::LoadImage(L"ColorRed.png"   ,1,TEX_SIZE_64);
	Draw::LoadImage(L"ColorGreen.png" ,2,TEX_SIZE_64);
	Draw::LoadImage(L"ColorYellow.png",3,TEX_SIZE_64);
	Draw::LoadImage(L"ColorPink.png"  ,4,TEX_SIZE_64);
	Draw::LoadImage(L"ColorPurple.png" ,5,TEX_SIZE_64);
	Draw::LoadImage(L"Intervention.png",6,TEX_SIZE_32);//お邪魔ブロック

	//背景 7~8
	Draw::LoadImage(L"background1.png",7,TEX_SIZE_512);//背景
	Draw::LoadImage(L"background2.png",8,TEX_SIZE_512);//背景枠有
	Draw::LoadImage(L"blueback.png",9,TEX_SIZE_512);//マップの枠線

	//主人公&爆発エフェクト 9
	Draw::LoadImage(L"image.png",10,TEX_SIZE_512);

	//カウントダウン用数字
	Draw::LoadImage(L"3.png",11,TEX_SIZE_256);
	Draw::LoadImage(L"2.png",12,TEX_SIZE_256);
	Draw::LoadImage(L"1.png",13,TEX_SIZE_256);
	Draw::LoadImage(L"START.png",14,TEX_SIZE_256);
	
	//ゲージ
	Draw::LoadImage(L"gauge.png",15,TEX_SIZE_600);

	//主人公オブジェクト作成
	CObjHero*obj=new CObjHero();//主人公オブジェクトの作成
	Objs::InsertObj(obj,OBJ_HERO,10);//作った主人公オブジェクトをオブジェクトマネージャーに登録
	
	//CPオブジェクト作成
	CObjCP*obj_cp=new CObjCP();//CPオブジェクトの作成
	Objs::InsertObj(obj_cp,OBJ_CP,10);//CPオブジェクトをマネージャーに登録
	
	//背景オブジェクト作成
	CObjBackground *obj_b=new CObjBackground();//背景オブジェクトの作成
	Objs::InsertObj(obj_b,OBJ_BACK_GROUND,1);//背景オブジェクトをオブジェクトマネージャーに登録

	//マップオブジェクト
	CObjMain* p=new CObjMain(true);//マップオブジェクトの作成
	Objs::InsertObj(p,OBJ_MAIN,5);//マップオブジェクトをオブジェクトマネージャーに登録
}

//ゲームメインの実行中メソッド
void CSceneVsCP::Scene()
{
	
}


