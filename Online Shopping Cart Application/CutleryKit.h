#pragma once
#include <iostream>
#include "Item.h"

class CutleryKit : public Item
{
private:
	string colour;

public:
	CutleryKit()
	{
		colour = "";
	}

	CutleryKit(string _name, double _price, string _colour, string _description)
	{
		setName(_name);
		setPrice(_price);
		colour = _colour;
		setDescription(_description);
	}

	void setColour(string _colour)
	{
		colour = _colour;
	}

	string getColour()
	{
		return colour;
	}

	void print() override
	{
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nColour: " << colour << endl;
	}
};