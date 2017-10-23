#pragma once

#include "sheet.h"

class CEnemy
{
public:
	CEnemy();

	void Update() const;
	void Draw(sf::RenderWindow & window) const;

	void SetPosition(const sf::Vector2f & pos);
	sf::Vector2f GetPosition() const;
	float GetRadius();

private:
	sf::CircleShape m_body;
}; 
