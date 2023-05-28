/*
 * Position.cpp
 *
 *  Created on: 05.05.2023
 *      Author: bklaric
 */

#include "Position.h"
#include <iostream>
#include <math.h>
#include <sstream>

int Position::getX()
{
	return x;
}

void Position::setX(int x)
{
	this->x = x;
}

int Position::getY()
{
	return y;
}

void Position::setY(int y)
{
	this->y = y;
}

std::string Position::to_string() const
{
	std::stringstream ss;
	std::string returnString;
	ss<<"Position: "<< "x = "<<x<<"  y = "<<y<<std::endl;
	ss >> returnString;
	return returnString;
}

Position Position::operator+(const Position& rhs)
{
	Position ergebnis;
	ergebnis.x = this->x + rhs.x;
	ergebnis.y = this->y + rhs.y;
	return ergebnis;
}

Position Position::operator-(const Position& rhs)
{
	Position ergebnis;
	ergebnis.x = this->x - rhs.x;
	ergebnis.y = this->y - rhs.y;
	return ergebnis;
}

int Position::distanceManhattan(const Position& p)
{
	int distanz = (abs(x - p.x) + abs(y - p.y));
	return distanz;
}

Position::Position(): x(0), y(0) {}

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position::~Position()
{
	free(this);
}

std::ostream& operator<<(std::ostream& os, const Position& rhs)
{
	os << rhs.to_string();
	return os;
}
