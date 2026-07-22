#include "HCSelectSeccenManager.h"

HCSelectSeccenManager::HCSelectSeccenManager() {
}

HCSelectSeccenManager::~HCSelectSeccenManager() {
}

void HCSelectSeccenManager::SelectToChangeGameModeRequest() {
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Select) {
        return;
    }
    HCGameModeManager::GetInstance().ChangeGameMode(EGameMode::Main);
}

void HCSelectSeccenManager::draw() {
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Select) {
        return;
    }
    DrawString(0, 0, _T("Select"), GetColor(255, 255, 255));
}

void HCSelectSeccenManager::update() {
    if (Input::isKeyTrigger(KEY_INPUT_SPACE)) {
        SelectToChangeGameModeRequest();
    }
}