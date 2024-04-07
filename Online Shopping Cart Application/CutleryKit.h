#pragma once
#include <iostream> 
#include "Item.h"   

// Creating CutleryKit class inheriting from the class Item
class CutleryKit : public Item
{
private:
   string colour; // Colour of the cutlery kit

public:
   // Default constructor
   CutleryKit()
   {
       colour = "";
   }

   // Overloaded Constructor
   CutleryKit(string _name, double _price, string _colour, string _description)
   {
       setName(_name);         // Set the name of the cutlery kit
       setPrice(_price);       // Set the price of the cutlery kit
       colour = _colour;       // Set the colour of the cutlery kit
       setDescription(_description); // Set the description of the cutlery kit
   }

   // Mutator function to set the colour of the cutlery kit
   void setColour(string _colour)
   {
       colour = _colour;
   }

   // Accessor function to retrieve the colour of the cutlery kit
   string getColour()
   {
       return colour;
   }

   // Overridden function to print details of the cutlery kit
   void print() override
   {
       cout << "Item Name: " << getName() << "\nPrice: " << getPrice() << "\nColour: " << colour << endl;
   }
};