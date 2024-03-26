#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Functions.h"

using namespace std;

int main()
{

	char go_to_main_program = ' ';

	// Greets user with welcome message and asks them if they'd like to proceed to the main application.
	do
	{
		cout << "Welcome to our C++ Online Shopping Cart Console Application! \nWould you like to proceed? (Y/N)" << endl;
		cin >> go_to_main_program;
		go_to_main_program = toupper(go_to_main_program);
		
	} while (go_to_main_program != 'Y' && go_to_main_program != 'N');

	// If user chooses not to proceed, closes the application
	if (go_to_main_program == 'N')
	{
		cout << "Closing Program..." << endl;
	}

	// Main application goes inside of this loop
	if (go_to_main_program == 'Y')
	{

		vector<Item *> available_items = createShop(); // Creates a vector array of Items and populates it with the items that are up for sale
		vector<Item *> cart_items;
		int user_action;
		char go_to_cart = ' ';
		viewItemList(available_items); // Prints out list of available Items for the user to see

		do
		{

			cout << "\nEnter Item # to view more information. \nEnter 0 to close the program.\nEnter -1 to proceed to cart.\n";
			cin >> user_action;

			if (user_action == 0)
			{ // Exit Program
				cout << "Closing Program...\n";
			}

			else if (user_action <= available_items.size() && user_action > 0)
			{ // View Item Tree

				// This is where the main program and stuff starts
				int cart_action = 0;
				viewItem((user_action - 1), available_items);
				cout << "Would you like to add this item to your cart?" << endl;
				cout << "Enter 1 to add item to cart.\n"
					 << "Enter 0 to go back to item list.\n";
				cin >> cart_action;

				if (cart_action == 1)
				{

					cart_items.push_back(available_items[user_action - 1]);
					cout << "Item successfully added to cart.\n";
					cout << "Enter X to view contents of your cart.\nEnter N to go back to available item list without viewing cart contents.\n";
					cin >> go_to_cart;

					if (go_to_cart == 'X')
					{

						cout << "Cart Items: ";
						viewItemList(cart_items);
						cout << "\nEnd of Cart Items.\n\n";
					}
					else if (go_to_cart == 'N')
					{

						cout << "\n\nRegenerating Available Item List: \n\n";
						viewItemList(available_items);
						go_to_cart = ' ';
					}
				}
			}

			else if (user_action == -1)
			{ // Going to Cart Tree

				showReceipt(cart_items);
				char print_receipt = ' ';

				cout << "Would you like to continue shopping or print the receipt?" << endl;
				cout << "Enter X to print the receipt and exit the program.\nEnter N to continue shopping.\n";
				cin >> print_receipt;

				if (print_receipt == 'X')
				{
					// add receipt printing functionality here
					cout << "Printing the receipt. \n";
					printReceipt(cart_items);
					
					user_action = 0;
				}
				else
				{
					cout << "Returning to main store..\n\n";
				}
			}

			else if (user_action < 1 || user_action > available_items.size())
			{ // Input outside of range
				cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
			}

		} while (user_action != 0);
	}
}
