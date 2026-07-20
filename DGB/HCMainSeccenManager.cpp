#include "HCMainSeccenManager.h"

HCMainSeccenManager::HCMainSeccenManager( ) {
    m_pPlayer1 = new HCPlayer1( );
    m_pPlayer2 = new HCPlayer2( );
    m_pMap = new Map( );

    m_pPlayer1->setup( );
    m_pPlayer2->setup( );
    m_pMap->setup( );

    // Umbrella.hのg_Enemy1_SpawnRoutes（プランナーが編集するルート一覧）に従って
    // 複数体のHCEnemy1を、それぞれ別ルートでまとめて出現させる
    enemyManage.spawnEnemy1Group( g_Enemy1_SpawnRoutes );

    // ボールの初期化（プレイヤーのsetup後に呼ぶ必要がある）
    m_ball.setup( );
}

HCMainSeccenManager::~HCMainSeccenManager( ) {
    delete m_pPlayer1;
    m_pPlayer1 = nullptr;

    delete m_pPlayer2;
    m_pPlayer2 = nullptr;

    delete m_pMap;
    m_pMap = nullptr;

    // enemyManageは値メンバなので、ここでのdeleteは不要
    // （unique_ptrで管理された敵たちも自動で解放される）
}

void HCMainSeccenManager::MainToChangeGameModeRequest( ) {

    // 2. GetInstance() を経由して現在のモードを取得・判定
    if ( HCGameModeManager::GetInstance( ).GetGameMode( ) != EGameMode::Main ) {
        return;
    }

    // 3. GetInstance() を経由してゲームモードを切り替える
    // (※もし特定のモードに切り替えるなら SetGameMode(EGameMode::MainGame) などの場合もあります)
    HCGameModeManager::GetInstance( ).ChangeGameMode( EGameMode::Result );

}

void HCMainSeccenManager::draw( ) {
    if ( HCGameModeManager::GetInstance( ).GetGameMode( ) != EGameMode::Main ) {
        return;
    }

    DrawString( 0, 0, _T( "Main" ), GetColor( 255, 255, 255 ) );

    m_pPlayer1->draw( );
    m_pPlayer2->draw( );
    m_pMap->draw( );

    enemyManage.draw( );  // 敵の描画
    m_ball.draw( );       // ボールの描画
}

void HCMainSeccenManager::update( ) {
    m_pPlayer1->update( );
    m_pPlayer2->update( );
    m_pMap->update( );

    enemyManage.update( );  // 敵の更新（死んだ敵は自動で削除される）
    m_ball.update( );       // ボールの更新（投げる・追従・当たり判定）

    if ( Input::isKeyTrigger( KEY_INPUT_SPACE ) ) {
        MainToChangeGameModeRequest( );
    }

}