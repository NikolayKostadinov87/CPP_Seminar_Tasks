#pragma once
#include <cstring>

class ComputerPart {
private:
	//The type of the product
	enum type{
		MONITOR,
		COMPUTER,
		LAPTOP,
		MOUSE,
		KEYBOARD,
		HEADPHONES,
		CAMERA
	};

	//The warranty of the product
	//The number is poisitive integer
	int warranty;

	//The price of the product
	//The number is positive real number
	double price;

	//The Brand of the product
	//String with random capacity
	char* brand;

	//The model of the product
	//String with random capacity
	char* model;

private:
	//Delete string data
	void erase();
	//Copy setters information
	void copy(const ComputerPart&);

private:

	//Setter for the warranty
	void setWarranty(const int);
	// Setter for the brand
	void setBrand(const char*);
	// Setter for the model
	void setModel(const char*);

public:
	//Default Constructor
	ComputerPart();
	//Operator =
	ComputerPart& operator=(const ComputerPart&);
	//Copy Constructor
	ComputerPart(const ComputerPart&);
	//Destructor
	~ComputerPart();

	// Setter for the price
	void setPrice(double);

	//Getter for the warranty
	int getWarranty() const;
	//Getter for the price
	double getPrice() const;
	//Getter for the brand
	char* getBrand() const;
	//Getter for the model
	char* getModel() const;
};
