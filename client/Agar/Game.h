#pragma once

#include "Assets.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "StartScene.h"
#include "SocketMaster.h"

class CGame
{
public:
	CGame();

	void DoGameLoop();

private:
	bool IsConnected() const;
	SocketMaster m_socketMaster;
	CAssets m_assets;
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	�GameScene m_gameScene;
	CPauseScene m_pauseScene;
	CStartScene m_startScene;
}; 