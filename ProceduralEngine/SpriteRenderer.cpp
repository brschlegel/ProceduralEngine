#include "SpriteRenderer.h"

std::map<std::string, sf::Texture*> SpriteRenderer::textureMap;
SpriteRenderer::SpriteRenderer(std::string name)
{
	name += ".png";
	name = "Images/" + name;
	sf::Texture* texture = new sf::Texture();
	if (textureMap.find(name) == textureMap.end())
	{
		texture->loadFromFile(name);
		textureMap[name] = texture;
	}
	else
	{
		texture = textureMap[name];
	}
	sprite = sf::Sprite();
	sprite.setTexture(*texture);
	
}

void SpriteRenderer::draw(sf::RenderWindow* window)
{
	Transform* t = getGameObject()->getTransform();
	sprite.setPosition(DrawManager::convertToSF(t->getPosition()));
	setScale(t->getScale());
	setRotation(t->getRotation());

	window->draw(sprite);
}

void SpriteRenderer::setScale(b2Vec2 scale)
{	
	sf::Vector2f sfScale = sf::Vector2f(scale.x , scale.y);
	//sfScale *= PIXEL_PER_METER;
	sprite.setScale(sfScale);
}

void SpriteRenderer::setRotation(b2Rot rotation)
{
	sprite.setRotation(PMath::radToDeg(rotation.GetAngle()));
}

std::string SpriteRenderer::toString()
{
	return "SpriteRenderer";
}

void SpriteRenderer::init()
{
	setScale(gameObject->getTransform()->getScale());
	auto size = sprite.getLocalBounds();
	sprite.setOrigin(size.width / 2, size.height / 2);
}

void SpriteRenderer::unloadTextures()
{
	map<string, sf::Texture>::iterator it;
	for (auto const& x : textureMap)
	{
		delete x.second;
	}
}
