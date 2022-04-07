#include<cstring>
#include "Room.h"

void Room::copy(const Room& other)
{
	setDescription(other.description);
	setSquareArea(other.squareArea);
}

void Room::erase()
{
	delete[] description;
}

Room::Room()
{
	squareArea = 0.0;
	description = nullptr;
}

Room& Room::operator=(const Room& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Room::Room(const Room& other)
{
	copy(other);
}

Room::~Room()
{
	erase();
}

void Room::setSquareArea(double squareArea)
{
	this->squareArea = squareArea;
}

void Room::setDescription(const char* description)
{
	this->description = new char[strlen(description)];
	strcpy_s(this->description, strlen(description) + 1, description);
}

double Room::getSquareArea() const
{
	return squareArea;
}

char* Room::getDescription() const
{
	return description;
}
