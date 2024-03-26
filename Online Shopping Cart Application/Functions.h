#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

vector<Item *> createShop()
{

    cout << endl
         << "List of Shop Items for Sale: " << endl;

    vector<Item *> available_items;

    // Hardcode Shop Items under here:
    available_items.push_back(new CutleryKit("Silver Cutlery Set", 29.99, "Silver", "Shiny, silvery, idk descirption here"));
    available_items.push_back(new CutleryKit("Stainless Steel Cutlery Set", 14.99, "Grey", "ADD DESCRIPTION HERE"));
    available_items.push_back(new CutleryKit("Gold Plated Cutlery Set", 49.99, "Gold", "ADD DESCRIPTION HERE"));
    available_items.push_back(new Appliance("Toaster", 39.99, "White", "ADD DESCRIPTION HERE"));
    available_items.push_back(new Appliance("Blender", 29.99, "Black", "ADD DESCRIPTION HERE"));
    available_items.push_back(new Appliance("Coffee Maker", 59.99, "Black", "ADD DESCRIPTION HERE"));
    available_items.push_back(new Appliance("Microwave", 39.99, "White", "ADD DESCRIPTION HERE"));
    available_items.push_back(new DishSet("Porcelain Dinnerware Set", 69.99, "Porcelain", "ADD DESCRIPTION HERE"));
    available_items.push_back(new DishSet("Stoneware Dinnerware Set", 49.99, "Stone", "ADD DESCRIPTION HERE"));
    available_items.push_back(new DishSet("Platinum Dinnerware Set", 99.99, "Platinum", "ADD DESCRIPTION HERE"));
    available_items.push_back(new DishSet("Golden Dinnerware Set", 79.99, "Gold", "ADD DESCRIPTION HERE"));

    // ^^ Add more items above as needed

    return available_items;
}

void viewItemList(vector<Item *> _available_items)
{
    unsigned short index = 0;

    for (const auto &item : _available_items)
    {
        cout << "Item #: " << index + 1 << endl;
        item->print();
        cout << "\n";
        index++;
    }
}

void viewItem(int itemIndex, vector<Item *> &_available_items)
{
    cout << "Viewing Item " << itemIndex + 1 << ": \n\n";
    _available_items[itemIndex]->print();
    cout << "Description: " << _available_items[itemIndex]->getDescription() << endl
         << endl;
}

double calculateTotalPrice(vector<Item *> &cart_items)
{

    double totalPrice = 0;
    unsigned short index = 0;

    for (const auto &item : cart_items)
    {
        totalPrice += item->getPrice();
        index++;
    }

    return totalPrice;
}

void showReceipt(vector<Item *> &cart_items)
{
    cout << "Viewing Cart Contents: \n\n";
    viewItemList(cart_items);
    cout << "\n\nEnd of Cart Items.\n\n";

    cout << setprecision(4) << "SUBTOTAL: " << calculateTotalPrice(cart_items);
    cout << setprecision(4) << "\nHST: " << calculateTotalPrice(cart_items) * 0.13;
    cout << setprecision(4) << "\nTOTAL: " << calculateTotalPrice(cart_items) * 1.13 << "\n\n";
}

void printReceipt(vector<Item*> &cart_items) 
{
    ofstream Receipt("printed_receipt.txt");

    if (!Receipt)
    {
        cout << "printReceipt function broken.\n";
    } 
    else 
    {
        Receipt << "Item" << "Price" << endl;

        for (const auto &item : cart_items) 
        {
            Receipt << item->getName() << item->getPrice() << endl;
        }
        
        Receipt << "SUBTOTAL:" << calculateTotalPrice(cart_items) << endl;
        Receipt << "HST:" << (calculateTotalPrice(cart_items)*0.13) << endl;
        Receipt << "TOTAL:" << (calculateTotalPrice(cart_items)*1.13) << endl;


    }

}
