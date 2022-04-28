#pragma once
#include <SFML/Graphics.hpp>
class Input
{
public:
	/// <summary>
	/// Has key been pressed this frame
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	static bool isPressed(sf::Keyboard::Key k);
	/// <summary>
	/// Is key currently down
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	static bool isDown(sf::Keyboard::Key k);
	static void clear();

	static void recordKeyPressed(sf::Keyboard::Key key);
	static void recordKeyReleased(sf::Keyboard::Key key);
private:
	static std::map<sf::Keyboard::Key, bool> isKeyPressed;
	static std::map<sf::Keyboard::Key, bool> isKeyReleased;
};

