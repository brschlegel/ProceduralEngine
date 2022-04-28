#include "Input.h"

std::map<sf::Keyboard::Key, bool> Input::isKeyPressed;
std::map<sf::Keyboard::Key, bool> Input::isKeyReleased;
bool Input::isPressed(sf::Keyboard::Key k)
{
    return isKeyPressed[k];
}

bool Input::isDown(sf::Keyboard::Key k)
{
    return sf::Keyboard::isKeyPressed(k);
}

void Input::clear()
{
    for (int i = 0; i < sf::Keyboard::KeyCount; i++)
    {
        isKeyPressed[(sf::Keyboard::Key)i] = false;
        isKeyReleased[(sf::Keyboard::Key)i] = false;
    }
}

void Input::recordKeyPressed(sf::Keyboard::Key key)
{
    isKeyPressed[key] = true;
}

void Input::recordKeyReleased(sf::Keyboard::Key key)
{
    isKeyReleased[key] = true;
}
