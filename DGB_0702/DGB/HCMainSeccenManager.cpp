#include "HCMainSeccenManager.h"

HCMainSeccenManager::HCMainSeccenManager() {
    m_pPlayer1 = new HCPlayer1();
    m_pPlayer2 = new HCPlayer2();

    m_pPlayer1->setup();
    m_pPlayer2->setup();
}

HCMainSeccenManager::~HCMainSeccenManager() {
    delete m_pPlayer1;
    m_pPlayer1 = nullptr;

    delete m_pPlayer2;
    m_pPlayer2 = nullptr;
}

void HCMainSeccenManager::MainToChangeGameModeRequest() {

    // 📝 2. GetInstance() を経由して現在のモードを取得・判定
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Main) {
        return;
    }

    // 📝 3. GetInstance() を経由してゲームモードを切り替える
    // (※もし特定のモードに切り替えるなら SetGameMode(EGameMode::MainGame) などの場合もあります)
    HCGameModeManager::GetInstance().ChangeGameMode(EGameMode::Result);

}

void HCMainSeccenManager::draw() {
    if (HCGameModeManager::GetInstance().GetGameMode() != EGameMode::Main) {
        return;
    }

    DrawString(0, 0, _T("Main"), GetColor(255, 255, 255));

    m_pPlayer1->draw();
    m_pPlayer2->draw();
}

void HCMainSeccenManager::update() {
    m_pPlayer1->update();
    m_pPlayer2->update();

    if (Input::isKeyTrigger(KEY_INPUT_SPACE)) {
        MainToChangeGameModeRequest();
    }
}