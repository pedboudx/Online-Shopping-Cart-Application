#pragma once
#include <iostream> 
#include <string>   
using namespace std;

// Creating Item class
class Item
{
private:
   string name;        // Name of the item
   double price;       // Price of the item
   string description; // Description of the item

public:
   // Default constructor initializing member variables
   Item()
   {
       name = "";
       price = 0;
       description = "";
   }

   // Overloaded Constructor
   Item(string _name, double _price, string _description)
   {
       name = _name;
       price = _price;
       description = _description;
   }

   // Getter function to retrieve the description of the item
   string getDescription()
   {
       return description;
   }

   // Setter function to set the description of the item
   void setDescription(string _description)
   {
       description = _description;
   }

   // Getter function to retrieve the name of the item
   string getName()
   {
       return name;
   }

   // Getter function to retrieve the price of the item
   double getPrice()
   {
       return price;
   }

   // Setter function to set the name of the item
   void setName(string _name)
   {
       name = _name;
   }

   // Setter function to set the price of the item
   void setPrice(double _price)
   {
       price = _price;
   }

   // Pure virtual function to be implemented by derived classes for printing item details
   virtual void print() = 0;
};
