#pragma once
#include <iostream>
#include "Item.h"

class DishSet : public Item
{
private:
	string material;

public:
	DishSet()
	{
		material = "";
	}

	DishSet(string _name, double _price, string _material, string _description)
	{
		setName(_name);
		setPrice(_price);
		material = _material;
		setDescription(_description);
	}

	void setMaterial(string _material)
	{
		material = _material;
	}

	string getMaterial()
	{
		return material;
	}

	void print() override
	{
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nMaterial: " << material << endl;
	}
};