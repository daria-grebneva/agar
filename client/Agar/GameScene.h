#pragma once

#include <json.hpp>
#include <AudioPlayer.h>

#include "SocketMaster.h"
#include "Assets.h"
#include "Agar.h"
#include "Enemies.h"
#include "Meal.h"
#include "sheet.h"
#include "RatingTable.h"

using json = nlohmann::json;

class CGameScene
{
public:
	CGameScene() = delete;
	CGameScene(sf::RenderWindow & window, CAssets assets, SocketMaster & socketMaster);
	~CGameScene();

	SceneInfo Advance(float dt, bool isConnected);

private:
	void CheckKeyboardEvents(const sf::Event & event);
	void CheckKeyPressed(const sf::Event & event);
	void Update(float dt);
	void Render() const;
	void CheckEvents();
	void ProcessUpdateData(const std::string & path);
	std::string GetId(const std::string & path) const;
	void CheckMouseEvents(const sf::Event & event);
	void UpdateEnemies(size_t arrSize, const json & obj);
	void UpdateFood(size_t arrSize, const json & obj);
	void UpdatePlayers(const json & obj);
	const sf::Vector2f SetTableTextPosition(const sf::Vector2f & center, float addingCoeff);
	void DrawTable() const;
	void DrawConnectedInfo(bool isConnected) const;
	void UpdateTable();

	SceneType m_nextSceneType = SceneType::—GameScene;
	sf::RenderWindow & m_window;
	sf::Vector2i m_mousePosition;
	CAgar m_agarView;
	CAssets m_assets;
	std::array<CEnemy, NUMBER_ENEMIES> m_enemies;
	std::array<CMeal, NUMBER_MEAL> m_meal;
	sf::View m_view;
	sf::Clock m_clock;
	std::array<sf::Color, NUMBER_MEAL> m_meal_color;
	std::vector<CAgar> m_agarics;
	std::string m_heroId; 
	std::string m_heroNickname;
	CAgar m_agar; 
	sf::Sprite m_background;
	CAudioPlayer m_audioPlayer;
	SocketMaster & m_socketMaster;
	RatingTable m_tableBackground;
	std::vector<sf::Text> m_allTableNicknames;
	json m_table;
	bool m_isDataInited = false;
};
