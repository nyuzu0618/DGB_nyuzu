#include "HCGameModeManager.h"
#include "HCSeccenGameModeBase.h"
#include "HCTitleSeccenManager.h"
#include "HCMainSeccenManager.h"
#include "HCResultSeccenManager.h"

#include <typeinfo>
#include <windows.h>

HCGameModeManager::HCGameModeManager()
{
    // 起動時はタイトル画面に設定
    SetGameMode(EGameMode::Title);
}

HCGameModeManager::~HCGameModeManager()
{
    // 終了時にメモリリークを防ぐため解放
    if (m_pCurrentScene != nullptr) {
        delete m_pCurrentScene;
        m_pCurrentScene = nullptr;
    }
}

void HCGameModeManager::SetGameMode(EGameMode SetToGameMode)
{
    // 同じモードが指定されたら何もしない
    if (m_currentGameMode == SetToGameMode) return;

    // 1. 古いシーンのメモリを解放
    if (m_pCurrentScene != nullptr) {
        delete m_pCurrentScene;
        m_pCurrentScene = nullptr;
    }

    // 2. モードを更新
    m_currentGameMode = SetToGameMode; // 💡 GameModeとm_currentGameMode、2つ持っているので注意（下記コメント参照）

    // 3. 新しいシーンのインスタンスを生成
    switch (m_currentGameMode)
    {
    case EGameMode::Title:
        m_pCurrentScene = new HCTitleSeccenManager();
        break;
    case EGameMode::Main:
        m_pCurrentScene = new HCMainSeccenManager();
        break;
    case EGameMode::Result:
        m_pCurrentScene = new HCResultSeccenManager();
        break;
    default:
#ifdef _DEBUG
        OutputDebugStringA("HCGameModeManager::SetGameMode - Unknown EGameMode!\n");
#endif
        break;
    }

#ifdef _DEBUG
    if (m_pCurrentScene != nullptr) {
        OutputDebugStringA(typeid(*m_pCurrentScene).name());
        OutputDebugStringA(" に切り替わりました\n");
    }
#endif
}

void HCGameModeManager::ChangeGameMode(EGameMode nextGameMode)
{
    SetGameMode(nextGameMode);
}

void HCGameModeManager::draw()
{
    if (m_pCurrentScene != nullptr) {
        m_pCurrentScene->draw();
    }
}

void HCGameModeManager::update() 
{
    if (m_pCurrentScene != nullptr) {
        m_pCurrentScene->update();
    }
}