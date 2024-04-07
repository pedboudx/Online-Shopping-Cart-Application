#pragma once
#include <iostream> 
#include "Item.h"   

// Creating Appliance class inheriting from the class Item
class Appliance : public Item
{
private:
   string type; // Type of the appliance

public:
   // Default constructor
   Appliance()
   {
       type = "";
   }

   // Overloaded Constructor
   Appliance(string _name, double _price, string _colour, string _description)
   {
       setName(_name);         // Set the name of the appliance
       setPrice(_price);       // Set the price of the appliance
       type = _colour;         // Set the type of the appliance
       setDescription(_description); // Set the description of the appliance
   }

   // Mutator function to set the type of the appliance
   void setType(string _type)
   {
       type = _type;
   }

   // Accessor function to retrieve the type of the appliance
   string getType()
   {
       return type;
   }

   // Overridden function to print details of the appliance
   void print() override
   {
       cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nType: " << type << endl;
   }
};
