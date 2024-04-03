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
	Item()
	{
		name = "";
		price = 0;
		description = "";
	}

	Item(string _name, double _price, string _description)
	{
		name = _name;
		price = _price;
		description = _description;
	}

	string getDescription()
	{
		return description;
	}

	void setDescription(string _description)
	{
		description = _description;
	}

	string getName()
	{
		return name;
	}

	double getPrice()
	{
		return price;
	}

	void setName(string _name)
	{
		name = _name;
	}

	void setPrice(double _price)
	{
		price = _price;
	}

	virtual void print() = 0;
	
};




