
#include <iostream>
#include "GameObject.h"
#include "Console.h"

GameObject::GameObject() : symbol(' '), playground(NULL) {}

GameObject::GameObject(Position p, char symbol, Playground* playground)
{
	this->p = p;
	this->symbol = symbol;
	this->playground = playground;
}

void GameObject::draw(bool offset)
{
	if(offset == false)
	{
		Console::zeichne_punkt(this->p.getX(), this->p.getY(), this->symbol);
	}
	else if(offset == true)
	{
		int x = this->p.getX() + Configuration::PLAYGROUND_OFFSETX + Configuration::PLAYGROUND_BORDERWIDTH;
		int y = this->p.getY() + Configuration::PLAYGROUND_OFFSETY + Configuration::PLAYGROUND_BORDERWIDTH;

		Console::zeichne_punkt(x, y, this->symbol);
	}

	if(this->top_ptr != NULL)
	{
		draw(offset);
	}
}

void GameObject::setPosition(Position p)
{
	//this->p = p;
	this->p.setX(p.getX());
	this->p.setY(p.getY());
}

void GameObject::setPlayground(Playground* pg)
{
	playground = pg;
}

void GameObject::setTop(GameObject* go_ptr)
{
	top_ptr = go_ptr;
}

Position GameObject::getPosition()
{
	return this->p;
}

char GameObject::getType()
{
	return this->symbol;
}
