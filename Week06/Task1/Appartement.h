#pragma once
#include"Room.h"
#include<cstring>
#include<iostream>
#include<cassert>
class Appartement {
private:
	int list[10]{};
	Room* rooms;
	double squareAreaAppartement;
	char* descriptionOfAppartement;
	int numberOfRooms;
	void copy(const Appartement&);
	void erase();
public:
	//Canonisation
	Appartement();
	Appartement& operator=(const Appartement&);
	Appartement(const Appartement&);
	~Appartement();

	//Find the area of the Appartement
	double getAppartementArea() const;

	//[] operation returning certain room in the appartement
	char operator[](size_t index);

	//Add rooms to appartement
	void addRoomsToAppartement(const Room&);

	//Get the average square area of every appartement's rooms
	double getAverageSqAreaRoom() const;

	//Predefining <, <=, ==, >=, > operators for comparison between two appartements
	//Average room's square area is considered as more spacious
	friend bool operator<(const Appartement& first, const Appartement& second);
	friend bool operator<=(const Appartement& first, const Appartement& second);
	friend bool operator==(const Appartement& first, const Appartement& second);
	friend bool operator>=(const Appartement& first, const Appartement& second);
	friend bool operator>(const Appartement& first, const Appartement& second);

};