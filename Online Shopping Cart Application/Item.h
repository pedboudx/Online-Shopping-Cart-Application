#pragma once
#include <iostream>
#include <string>
using namespace std;

//Hey I made a change -Aadesh

class Item
{
private: 
	string name;
	double price;
	string description;

public:
	Item() {
		name = "";
		price = 0;
		description = "";
	}

	Item(string _name, double _price, string _description) {
		name = _name;
		price = _price;
		description = _description;
	}

	string getDescription() {
		return description;	
	}

	void setDescription(string _description) {
		description = _description;
	}

	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
	void setName(string _name) {
		name = _name;
	}
	void setPrice(double _price) {
		 price = _price;
	}

	virtual void print() {
		cout << "Item Name: " << name << "\nPrice: " << price << endl;
	}
};

class CutleryKit : public Item {
private:
	string colour;

public:
	CutleryKit() {
		colour = "";
	}
	CutleryKit(string _name, double _price, string _colour, string _description)
	{ 
		setName(_name);
		setPrice(_price);
		colour = _colour;
		setDescription(_description);
	}

	void setColour(string _colour) {
		colour = _colour;
	}

	string getColour() {
		return colour;
	}

	void print() override {
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nColour: " << colour << endl;
		cout << endl;
	}

};

class Appliance : public Item {
private:
	string type;

public:
	Appliance() {
		type = "";
	}
	Appliance(string _name, double _price, string _colour, string _description)
	{
		setName(_name);
		setPrice(_price);
		type = _colour;
		setDescription(_description);

	}

	void setType(string _type) {
		type = _type;
	}

	string getType() {
		return type;
	}

	void print() override {
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nType: " << type << endl;
		cout << endl;

	}

};

class DishSet : public Item {
private:
	string material;

public:
	DishSet() {
		material = "";
	}
	DishSet(string _name, double _price, string _material, string _description)
	{
		setName(_name);
		setPrice(_price);
		material = _material;
		setDescription(_description);

	}

	void setMaterial(string _material) {
		material = _material;
	}

	string getMaterial() {
		return material;
	}

	void print() override {
		cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nMaterial: " << material << endl;
		cout << endl;

	}

};