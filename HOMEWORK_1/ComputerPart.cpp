#include "ComputerPart.h"

//Delete string data
void ComputerPart::erase()
{
	delete[] brand;
	delete[] model;
}

//Copy function for every setter
void ComputerPart::copy(const ComputerPart& other)
{
	setWarranty(other.warranty);
	setPrice(other.price);
	setBrand(other.brand);
	setModel(other.model);
}

//Default Constructor
ComputerPart::ComputerPart()
{
	warranty = 0;
	price = 0.0;
	brand = nullptr;
	model = nullptr;
}

//Operator =
ComputerPart& ComputerPart::operator=(const ComputerPart& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

//Copy Constructor
ComputerPart::ComputerPart(const ComputerPart& other)
{
	copy(other);
}

//Destructor
ComputerPart::~ComputerPart()
{
	erase();
}

//Setter for the warranty
void ComputerPart::setWarranty(const int warranty)
{
	if (warranty < 0) {
		throw "The warranty has to be greater than zero!";
	}
	this->warranty = warranty;
}

//Setter for the price
void ComputerPart::setPrice(double price)
{
	if (price < 0) {
		throw "The price has to be greater than zero!";
	}
	this->price = price;
}

// Setter for the brand
void ComputerPart::setBrand(const char* brand)
{
	int length = strlen(brand);
	if (length == 0) {
		throw "Invalid name for brand!";
	}
	for (int i = 0; i < length; i++) {
		if ((brand[i] < 'a' || brand[i] > 'z') && (brand[i] < 'A' || brand[i] > 'Z') && brand[i] != ' ') {
			throw "The brand's name has to contain only letters from a-z & (A-Z) and whitespace ' ' !";
		}
	}
	this->brand = new char[length + 1];
	strcpy_s(this->brand , length + 1 , brand);
}

//Setter for the model
void ComputerPart::setModel(const char* model)
{
	int length = strlen(model);
	if (length == 0) {
		throw "Invalid model name!";
	}
	for (int i = 0; i < length; i++) {
		if ((model[i] < 'a' || model[i] > 'z') && (model[i] < 'A' || model[i] > 'Z') && (model[i] != ' ')) {
			throw "The model's name has to contain only letters from a-z & (A-Z) and whitespace ' ' !";
		}
	}
}

//Getter for the warranty
int ComputerPart::getWarranty() const
{
	return warranty;
}

//Getter for the price
double ComputerPart::getPrice() const
{
	return price;
}

//Getter for the brand
char* ComputerPart::getBrand() const
{
	return brand;
}

//Getter for the model
char* ComputerPart::getModel() const
{
	return model;
}