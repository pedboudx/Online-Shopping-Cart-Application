#pragma once
#include <iostream> 
#include "Item.h"   

// Creating Child Class called DishSet class inheriting from the class Item
class DishSet : public Item
{
private:
   string material; // Material of the dish set

public:
   // Default constructor initializing member variables
   DishSet()
   {
       material = "";
   }

   // Overloaded Constructor
   DishSet(string _name, double _price, string _material, string _description)
   {
       setName(_name);         // Set the name of the dish set
       setPrice(_price);       // Set the price of the dish set
       material = _material;   // Set the material of the dish set
       setDescription(_description); // Set the description of the dish set
   }

   // Mutator function that sets the material of the dish set
   void setMaterial(string _material)
   {
       material = _material;
   }

   // Accessor function to retrieve the material of the dish set
   string getMaterial()
   {
       return material;
   }

   // Overridden function to print details of the dish set
   void print() override
   {
       cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nMaterial: " << material << endl;
   }
};