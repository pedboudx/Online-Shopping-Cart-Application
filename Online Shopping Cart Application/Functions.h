#pragma once
#include <iostream>
#include "Item.h"	
#include <vector>
#include <string>
using namespace std;

vector<Item*> createShop() {

    cout << endl << "List of Shop Items for Sale: " << endl;

    vector<Item*> available_items;

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

void viewItemList(vector<Item*> _available_items) {
    unsigned short index = 0;

    for (const auto& item : _available_items) {
        cout << "Item #: " << index + 1 << endl;
        item->print();
        cout << endl;
        index++;
    }

}

void viewItem(int itemIndex, vector <Item*> _available_items) {
    cout << "\n\nDetails of Item #" << itemIndex << ":\n\n";
    _available_items[itemIndex-1]->print();
    cout << "Description: ";\
    _available_items[itemIndex-1]->getDescription();
    cout << "\n\n";

}

void addToCart(vector <Item>& cart_array) {

}

void printReceipt() {

}