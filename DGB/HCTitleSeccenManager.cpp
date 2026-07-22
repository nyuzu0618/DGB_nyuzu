#include "HCTitleSeccenManager.h"

HCTitleSeccenManager::HCTitleSeccenManager() {
}

HCTitleSeccenManager::~HCTitleSeccenManager() {
}

void HCTitleSeccenManager::TitleToChangeGameModeRequest() {
    // 📝 2. GetInstance() を経由して現在のモードを取得・判定
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Title) {
        return;
    }

    // 📝 3. GetInstance() を経由してゲームモードを切り替える
    // (※もし特定のモードに切り替えるなら SetGameMode(EGameMode::MainGame) などの場合もあります)
    HCGameModeManager::GetInstance().ChangeGameMode(EGameMode::Select);
}

void HCTitleSeccenManager::draw() {
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Title) {
        return;
    }
    DrawString(0, 0, _T("Title"), GetColor(255, 255, 255));
}

void HCTitleSeccenManager::update() {
    if (Input::isKeyTrigger(KEY_INPUT_SPACE)) {
        TitleToChangeGameModeRequest();
    }
}