#include "HCSeccenGameModeBase.h"

#include "DxLib.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウモードで起動するように設定
	ChangeWindowMode(TRUE);


	// DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1; // 初期化に失敗した場合はソフトを終了
	}

	//スクリーンのサイズを変更させる
	SetGraphMode(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, 32);
	SetWindowSize(g_SCREEN_WIDTH, g_SCREEN_HEIGHT);

	// 描画先を裏画面に設定（ちらつき防止）
	SetDrawScreen(DX_SCREEN_BACK);

	// 座標などの変数例
	double x = 320.0;
	double y = 240.0;



	// メインループ
	// ProcessMessage() : Windowsのメッセージ処理（必須）
	// ScreenFlip()     : 裏画面の内容を表画面に反映
	// ClearDrawScreen(): 裏画面の消去
	// CheckHitKey()    : ESCキーが押されていないかチェック

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		// ── A. 入力・更新処理 ──
				// (※もしInputクラスの更新処理などがあればここに入れます)
				// Input::Update();

				// ── B. 描画処理 ──
				// 💡 ここがポイント！
				// 画面がTitleだろうがMainGameだろうが、マネージャーにお任せで描画します。
				// マネージャーの内部で、現在アクティブなシーンの draw() が自動で呼び出されます。

		Input::update();
		HCGameModeManager::GetInstance().draw();
		HCGameModeManager::GetInstance().update();

		// ── C. 画面フリップ ──
		ScreenFlip(); // 裏画面に描いたものを一気に表画面に表示（チラつき防止）
	}

	// DXライブラリの使用終了処理
	DxLib_End();

	return 0;
}