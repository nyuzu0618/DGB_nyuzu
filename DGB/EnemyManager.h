#pragma once
#include "Umbrella.h"
#include "HCEnemyBase.h"
#include "HCEnemy1.h"

class EnemyManager;

// どこからでもEnemyManagerのインスタンスにアクセスできるようにするためのグローバルポインタ
extern EnemyManager* g_pEnemyManager;

class EnemyManager {
public:
	EnemyManager( ) {
		g_pEnemyManager = this;
	}

	// countで指定した数だけHCEnemy1をまとめて出現させる（省略時は1体。全員Umbrella.hのデフォルトルート）
	void spawnEnemy1( int count = 1 ) {
		for ( int i = 0; i < count; i++ ) {
			auto enemy = std::make_unique<HCEnemy1>( );
			enemy->setup( );
			enemies.push_back( std::move( enemy ) );
		}
	}

	// エリア番号のリストでルートを指定してHCEnemy1を1体出現させる
	void spawnEnemy1( const std::vector<int>& routeLabels ) {
		auto enemy = std::make_unique<HCEnemy1>( );
		enemy->setup( routeLabels );
		enemies.push_back( std::move( enemy ) );
	}

	// 複数体のHCEnemy1を、それぞれ別のルート（エリア番号のリスト）を指定してまとめて出現させる
	// 例: spawnEnemy1Group({ {7,13,19}, {1,6,11}, {25,20,15} });
	void spawnEnemy1Group( const std::vector<std::vector<int>>& routes ) {
		for ( const auto& route : routes ) {
			spawnEnemy1( route );
		}
	}

	void update( ) {
		// 1. 全員更新
		for ( auto& e : enemies ) {
			e->update( );
		}

		// 2. 死んだ敵をまとめて削除
		std::erase_if( enemies, [ ] ( const std::unique_ptr<HCEnemyBase>& e ) {
			return e->isDead( );
		} );
	}

	void draw( ) {
		for ( auto& e : enemies ) {
			e->draw( );
		}
	}

	// ボールと当たっている敵を1体探して返す（いなければnullptr）
	// posはボールの座標、radiusは当たり判定の半径
	HCEnemyBase* CheckCollision( const HSPoint& pos, int radius ) const {
		for ( const auto& e : enemies ) {
			if ( e->isDead( ) ) continue;

			HSPoint enemyPos = e->GetPosition( );
			int dx = enemyPos.nX - pos.nX;
			int dy = enemyPos.nY - pos.nY;
			int distSq = dx * dx + dy * dy;

			if ( distSq <= radius * radius ) {
				return e.get( );
			}
		}
		return nullptr;
	}

private:
	std::vector<std::unique_ptr<HCEnemyBase>> enemies;
};