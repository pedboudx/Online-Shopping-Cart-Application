#pragma once
#include <iostream>
#include "Item.h"

class Appliance : public Item
{
private:
	string type;

public:
	Appliance()
	{
		type = "";
	}

	Appliance(string _name, double _price, string _colour, string _description)
	{
		setName(_name);
		setPrice(_price);
		type = _colour;
		setDescription(_description);
	}

	void setType(string _type)
	{
		type = _type;
	}

	string getType()
	{
		return type;
	}

	void print() override
	{
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nType: " << type << endl;
	}
};