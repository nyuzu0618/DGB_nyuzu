// Input.h
#pragma once

class Input {
private:
    // 256個のキーそれぞれの「押されているフレーム数」を保存
    static int keyData[256];

public:
    // 毎フレーム1回だけ呼び出して状態を更新する
    static void update();

    // 指定したキーが押されているか（押しっぱなし含む）
    static bool isKeyHeld(int keyCode);

    // 指定したキーが「今押された瞬間」か
    static bool isKeyTrigger(int keyCode);
};