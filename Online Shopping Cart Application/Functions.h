#pragma once
#include <iostream> 
#include "Item.h"   
#include "Appliance.h" 
#include "CutleryKit.h"    
#include "DishSet.h"    
#include <vector>   
#include <string>   
#include <iomanip>  
#include <fstream>  

using namespace std;

// Function to create the shop with the available items
vector<Item*> createShop()
{
   // Vector which stores availale items
   vector<Item*> available_items;

   // List of Product Catalouge with their descriptions
   available_items.push_back(new CutleryKit("Silver Cutlery Set", 29.99, "Silver", "Exuding elegance, our Silver Cutlery Set is crafted from premium silver, adding sophistication to your dining experience."));
   available_items.push_back(new CutleryKit("Stainless Steel Cutlery Set", 14.99, "Grey", "Our Stainless Steel Cutlery Set, made from durable stainless steel, combines modern style and functionality for everyday use."));
   available_items.push_back(new CutleryKit("Gold Plated Cutlery Set", 49.99, "Gold", "Indulge in luxury with our Gold Plated Cutlery Set, crafted with exquisite detail and featuring a lavish gold finish."));
   available_items.push_back(new Appliance("Toaster", 39.99, "White", "Our sleek Toaster, made from high-quality materials, offers versatile toasting options for your morning routine."));
   available_items.push_back(new Appliance("Blender", 29.99, "Black", "Effortlessly create delicious blends with our powerful Blender, designed with a modern black finish for a stylish addition to your kitchen."));
   available_items.push_back(new Appliance("Coffee Maker", 59.99, "Black", "Brew perfect cups of coffee with our Coffee Maker, crafted with precision and featuring a sleek black design."));
   available_items.push_back(new Appliance("Microwave", 39.99, "White", "Conveniently heat up meals with our Microwave, made from durable materials and designed for easy use in any kitchen."));
   available_items.push_back(new DishSet("Porcelain Dinnerware Set", 69.99, "Porcelain", "Elevate your table with our Porcelain Dinnerware Set, crafted from fine porcelain for timeless elegance."));
   available_items.push_back(new DishSet("Stoneware Dinnerware Set", 49.99, "Stone", "Add rustic charm to your meals with our Stoneware Dinnerware Set, made from durable stoneware for lasting quality."));
   available_items.push_back(new DishSet("Platinum Dinnerware Set", 99.99, "Platinum", "Dine in luxury with our Platinum Dinnerware Set, featuring stunning platinum accents and crafted for exquisite dining experiences."));
   available_items.push_back(new DishSet("Golden Dinnerware Set", 79.99, "Gold", "Make a statement with our Golden Dinnerware Set, designed with opulent gold detailing for unforgettable dining occasions."));


   return available_items; // returns vector of available items
}

// Function that displays available itmes
void viewItemList(vector<Item*> _available_items)
{
   unsigned short index = 0;

   // look at available items and print their details
   for (const auto& item : _available_items)
   {
       cout << "Item #: " << index + 1 << endl;
       item->print(); // Call the print function of each item
       cout << "\n";
       index++;
   }
}

// Function that allows user to view details of a specific item
void viewItem(int itemIndex, vector<Item*>& _available_items)
{
   cout << "Viewing Item " << itemIndex + 1 << ": \n\n";
   _available_items[itemIndex]->print(); // Print details of the specified item
   cout << "Description: " << _available_items[itemIndex]->getDescription() << endl << endl;
}

// Function to calculate the total price of the items in the cart
double calculateTotalPrice(vector<Item*>& cart_items)
{
   double totalPrice = 0; // Variable that stores total price
   unsigned short index = 0;

   // goes through cart items and adds their prices
   for (const auto& item : cart_items)
   {
       totalPrice += item->getPrice(); // Add each item's price to the total
       index++;
   }

   return totalPrice; // Return the total price
}

// Function to display the contents of the cart and calculate the total price
void showReceipt(vector<Item*>& cart_items)
{
   cout << "Viewing Cart Contents: \n\n";
   viewItemList(cart_items); // Display items in the cart
   cout << "\n\nEnd of Cart Items.\n\n";

   // Display subtotal, HST, and total price
   cout << setprecision(4) << "SUBTOTAL: " << calculateTotalPrice(cart_items);
   cout << setprecision(4) << "\nHST: " << calculateTotalPrice(cart_items) * 0.13;
   cout << setprecision(4) << "\nTOTAL: " << calculateTotalPrice(cart_items) * 1.13 << "\n\n";
}

// Function that prints the receipt to a file
void printReceipt(vector<Item*>& cart_items)
{
   // Open a file named "printed_receipt.txt" for writing
   ofstream Receipt("printed_receipt.txt");

   if (!Receipt) // Check if file opening failed
   {
       cout << "printReceipt function broken.\n"; // Display error message
   }
   else
   {
       // Write item details to the file
       Receipt << "Price:\t" << "Item:" << endl;
       for (const auto& item : cart_items)
       {
           Receipt << item->getPrice() << "\t" << item->getName() << endl;
       }

       // Calculate and write subtotal, HST, and total to the file
       Receipt << "\nSUBTOTAL:    $" << fixed << setprecision(2) << calculateTotalPrice(cart_items) << endl;
       Receipt << "HST:         $" << fixed << setprecision(2) << (calculateTotalPrice(cart_items) * 0.13) << endl;
       Receipt << "TOTAL:       $" << fixed << setprecision(2) << (calculateTotalPrice(cart_items) * 1.13) << endl;
   }
}

// Function to remove an item from the cart
void RemoveFromCart(vector<Item*>& cart_items)
{
   int item_index; // Variable to store the index of the item to be removed

   do
   {
       cout << "Enter the index of the item you want to remove from the cart: ";
       cin >> item_index;

       // Check if the entered index is valid
       if (item_index >= 1 && item_index <= cart_items.size())
       {
           // Remove the item from the cart
           cout << "Removing item \"" << cart_items[item_index - 1]->getName() << "\" from the cart." << endl;
           cart_items.erase(cart_items.begin() + item_index - 1);
           return; // Exit the function after successful removal
       }
       else
       {
           cout << "Invalid item index. Please enter a number between 1 and " << cart_items.size() << ". Try again." << endl;
       }
   } while (true); // Repeat until a valid index is entered
}
