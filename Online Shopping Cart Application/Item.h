#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	string name;
	double price;
	string description;

public:
	Item() //default constructor
	{
		name = "";
		price = 0;
		description = "";
	}

	Item(string _name, double _price, string _description) // values assigning constructor
	{
		name = _name;
		price = _price;
		description = _description;
	}

    //Accessors
	string getDescription()
	{
		return description;
	}

	string getName()
	{
		return name;
	}

	double getPrice()
	{
		return price;
	}

    //Mutators
	void setDescription(string _description)
	{
		description = _description;
	}

	void setName(string _name)
	{
		name = _name;
	}

	void setPrice(double _price)
	{
		price = _price;
	}

    //virtual print function
	virtual void print() = 0;
};
