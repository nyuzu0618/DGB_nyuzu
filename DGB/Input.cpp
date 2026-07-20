// Input.cpp
#include "Input.h"
#include "DxLib.h"

// 静的変数の実体を定義し、0で初期化
int Input::keyData[256] = { 0 };

void Input::update() {
    // 現在の全キーの物理的な状態を取得するための配列
    char currentKeys[256];
    GetHitKeyStateAll(currentKeys);

    for (int i = 0; i < 256; i++) {
        if (currentKeys[i] != 0) {
            // 押されていればカウントを増やす
            keyData[i]++;
        }
        else {
            // 押されていなければカウントをリセット
            keyData[i] = 0;
        }
    }
}

bool Input::isKeyHeld(int keyCode) {
    return keyData[keyCode] > 0;
}

bool Input::isKeyTrigger(int keyCode) {
    // ちょうど1フレーム目（押した瞬間）だけ true になる
    return keyData[keyCode] == 1;
}