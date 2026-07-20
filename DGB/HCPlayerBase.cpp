#include "HCPlayerBase.h"
#include "Umbrella.h"

// どこからでもアクセスできる1P/2Pのグローバルポインタの実体
HCPlayerBase* g_pPlayer1 = nullptr;
HCPlayerBase* g_pPlayer2 = nullptr;

HCPlayerBase::HCPlayerBase( ) {
    m_position1.Set( 0, 0 );
    m_position2.Set( 0, 0 );
}

HCPlayerBase::~HCPlayerBase( ) {}

void HCPlayerBase::setup( ) {
    // 派生クラス（HCPlayer1 / HCPlayer2）側で初期位置などを設定する
}

void HCPlayerBase::update( ) {
    // 派生クラス側でキー割り当てを指定して Move() を呼び出す
}

void HCPlayerBase::draw( ) {
    // 派生クラス側で見た目（色・文字など）を指定する
}

void HCPlayerBase::Move( int upKey, int downKey, int leftKey, int rightKey ) {
    int moveX = 0;
    int moveY = 0;

    if ( Input::isKeyHeld( upKey ) ) { moveY -= m_speed; }
    if ( Input::isKeyHeld( downKey ) ) { moveY += m_speed; }
    if ( Input::isKeyHeld( leftKey ) ) { moveX -= m_speed; }
    if ( Input::isKeyHeld( rightKey ) ) { moveX += m_speed; }

    // 移動後の座標を仮計算
    int nextY1 = m_position1.nY + moveY;
    int nextY2 = m_position2.nY + moveY;
    int nextX1 = m_position1.nX + moveX;
    int nextX2 = m_position2.nX + moveX;

    // Y方向:画面上下端をはみ出さないかチェック
    if ( nextY1 >= 0 && nextY2 <= g_SCREEN_HEIGHT ) {
        m_position1.nY = nextY1;
        m_position2.nY = nextY2;
    }

    // X方向:画面左右端をはみ出さないかチェック
    if ( nextX1 >= 0 && nextX2 <= g_SCREEN_WIDTH ) {
        m_position1.nX = nextX1;
        m_position2.nX = nextX2;
    }
}