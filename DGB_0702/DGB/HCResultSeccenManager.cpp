#include "HCResultSeccenManager.h"

HCResultSeccenManager::HCResultSeccenManager() {

}

HCResultSeccenManager::~HCResultSeccenManager() {

}

void HCResultSeccenManager::ResultToChangeGameModeRequest() {

    // 📝 2. GetInstance() を経由して現在のモードを取得・判定
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Result) {
        return;
    }

    // 📝 3. GetInstance() を経由してゲームモードを切り替える
    // (※もし特定のモードに切り替えるなら SetGameMode(EGameMode::MainGame) などの場合もあります)
    HCGameModeManager::GetInstance().ChangeGameMode(EGameMode::Title);

}

void HCResultSeccenManager::draw() {
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Result) {
        return;
    }

    DrawString(0, 0, _T("Result"), GetColor(255, 255, 255));
}

void HCResultSeccenManager::update() {
    if (Input::isKeyTrigger(KEY_INPUT_SPACE)) {
        ResultToChangeGameModeRequest();
    }
}