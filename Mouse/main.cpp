//メモリリークを調べる
//#define _CRTDBG_MAP_ALLOC
//#include<stdlib.h>
//#include<crtdbg.h>

#include "./dxlib/DxLib.h"
#include"KeyBoard.h"
#include"mouse.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//メモリリーク確認
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//log.txtを作成しない
	SetOutApplicationLogValidFlag(FALSE);
	// 画面モードの設定
	//画面サイズ設定
	SetGraphMode(640, 640, 32);//ウィンドウのサイズを決める
	ChangeWindowMode(TRUE);// ウィンドウモード変更

	//ウィンドウタイトル
	SetMainWindowText("The Dash");

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return -1; };//dxlibがないなら終了

	KeyBoard::initialize();
	//-------------------------------------------------
	SetDrawScreen(DX_SCREEN_BACK);//裏画面設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新＆メッセージ処理&画面殺害		
		KeyBoard::update();
		Mouse::update();

		if (Mouse::left_mouse_down())		DrawString(0, 0, "左　　押した瞬間", GetColor(255, 0, 0));
		if(Mouse::left_mouse_press())		DrawString(0, 50, "左　　押されている", GetColor(255, 0, 0));
		if(Mouse::left_mouse_up())			DrawString(0, 100, "左　　離した瞬間", GetColor(255, 0, 0));
		if(Mouse::left_mouse_not_press())	DrawString(0, 150, "左　　離している", GetColor(255, 0, 0));

		if (Mouse::right_mouse_down())		DrawString(150, 0, "右　　押した瞬間", GetColor(255, 0, 0));
		if (Mouse::right_mouse_press())     DrawString(150, 50, "右　　押されている", GetColor(255, 0, 0));
		if (Mouse::right_mouse_up())        DrawString(150, 100, "右　　離した瞬間", GetColor(255, 0, 0));
		if (Mouse::right_mouse_not_press()) DrawString(150, 150, "右　　離している", GetColor(255, 0, 0));

		//Escキーを押されたら終了する
		if (KeyBoard::key_down(KEY_INPUT_ESCAPE)) {
			break;
		}
	}
	KeyBoard::finalize();

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ゲーム終了
}
	