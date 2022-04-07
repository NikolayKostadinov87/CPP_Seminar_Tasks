#pragma once

class Room {
private:
	double squareArea;
	char* description = new char[30];
	void copy(const Room&);
	void erase();
public:
	//Canonisation
	Room();
	Room& operator=(const Room&);
	Room(const Room&);
	~Room();
	//Setters
	void setSquareArea(double squareArea);
	void setDescription(const char* description);
	//Getters
	double getSquareArea() const;
	char* getDescription() const;
};
