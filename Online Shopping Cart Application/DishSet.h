#pragma once
#include <iostream>
#include "Item.h"

class DishSet : public Item
{
private:
	string material;

public:
	DishSet() //default constructor
	{
		material = "";
	}

	DishSet(string _name, double _price, string _material, string _description)// value assigning constructor
	{
		setName(_name);
		setPrice(_price);
		material = _material; // New detail
		setDescription(_description);
	}

	void setMaterial(string _material) //Mutator
	{
		material = _material;
	}

	string getMaterial() //Accessor
	{
		return material;
	}

	void print() override               //print override function
	{
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nMaterial: " << material << endl;
	}
};