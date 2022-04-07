#include "Appartement.h"

void Appartement::copy(const Appartement& other)
{
	squareAreaAppartement = other.squareAreaAppartement;
	descriptionOfAppartement = new char[strlen(other.descriptionOfAppartement) + 1];
	strcpy_s(descriptionOfAppartement, strlen(other.descriptionOfAppartement) + 1, other.descriptionOfAppartement);
}

void Appartement::erase()
{
	delete[] rooms;
	delete[] descriptionOfAppartement;
}

Appartement::Appartement()
{
	squareAreaAppartement = 0.0;
	descriptionOfAppartement = nullptr;
	rooms = new Room[numberOfRooms];
}

Appartement& Appartement::operator=(const Appartement& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Appartement::Appartement(const Appartement& other)
{
	copy(other);
}

Appartement::~Appartement()
{
	erase();
}

double Appartement::getAppartementArea() const
{
	double result = 0.0;
	for (int i = 0; i < numberOfRooms; i++) {
		result += rooms[i].getSquareArea();
	}
	return result;
}

char Appartement::operator[](size_t index)
{
	for (int index = 0; index < numberOfRooms; index++) {
		return *rooms[index].getDescription();
	}
}

void Appartement::addRoomsToAppartement(const Room& newRoom)
{
	rooms[numberOfRooms++] = newRoom;
}

double Appartement::getAverageSqAreaRoom() const
{
	double appSqArea = 0.0 , result;
	for (int i = 0; i < numberOfRooms; i++) {
		appSqArea += rooms[i].getSquareArea();
	}
	result = appSqArea / numberOfRooms;
	return result;
}

bool operator<(const Appartement& first, const Appartement& second)
{
	return (first.getAverageSqAreaRoom() < second.getAverageSqAreaRoom());
}

bool operator<=(const Appartement& first, const Appartement& second)
{
	return (first.getAverageSqAreaRoom() <= second.getAverageSqAreaRoom());
}

bool operator==(const Appartement& first, const Appartement& second)
{
	return (first.getAverageSqAreaRoom() == second.getAverageSqAreaRoom());
}

bool operator>=(const Appartement& first, const Appartement& second)
{
	return (first.getAverageSqAreaRoom() >= second.getAverageSqAreaRoom());
}

bool operator>(const Appartement& first, const Appartement& second)
{
	return (first.getAverageSqAreaRoom() > second.getAverageSqAreaRoom());
}
