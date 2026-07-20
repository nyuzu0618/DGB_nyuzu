#pragma once

// EGameMode が "Umbrella.h" 内で定義されている場合は include が必要です。
// もし可能なら、EGameMode 自体を別ファイル（"GameModeTypes.h" など）に切り離すと
// さらに依存関係がスッキリします。
#include "Umbrella.h" 

class HCSeccenGameModeBase;

class HCGameModeManager
{
private:
    HCGameModeManager();
    ~HCGameModeManager();
    HCGameModeManager(const HCGameModeManager&) = delete;
    HCGameModeManager& operator=(const HCGameModeManager&) = delete;

    EGameMode m_currentGameMode = EGameMode::None; // 💡 名前をこちらに統一

public:
    HCSeccenGameModeBase* m_pCurrentScene = nullptr;

    static HCGameModeManager& GetInstance()
    {
        static HCGameModeManager instance;
        return instance;
    }

    EGameMode GetGameMode() const { return m_currentGameMode; }
    void SetGameMode(EGameMode SetToGameMode);
    void ChangeGameMode(EGameMode nextGameMode);
    void draw();
    void update();
};