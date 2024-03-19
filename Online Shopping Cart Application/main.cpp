#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Functions.h"

using namespace std;

int main() {

	char go_to_main_program = ' ';

	// Greets user with welcome message and asks them if they'd like to proceed to the main application.
	do {
		cout << "Welcome to our C++ Online Shopping Cart Console Application! \nWould you like to proceed? (Y/N)" << endl;
		cin >> go_to_main_program;
	} while (go_to_main_program != 'Y' && go_to_main_program != 'N');

	// If user chooses not to proceed, closes the application
	if (go_to_main_program == 'N') {
		cout << "Closing Program..." << endl;
	}

	// Main application goes inside of this loop
	if (go_to_main_program == 'Y') {

		vector<Item*> available_items = createShop(); // Creates a vector array of Items and populates it with the items that are up for sale
		vector<Item*> cart_items;
		int user_action = 789; // 789 is the default user_action
		viewItemList(available_items); // Prints out list of available Items for the user to see

		do { 

			cout << "Enter Item # to view more information. \nEnter 0 to close the program.\n";
			cin >> user_action;

			if (user_action == 0) {
				cout << "Closing Program...\n";
			}
			else if (user_action < 1 || user_action > available_items.size()) {
                cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
            }
			else if (user_action <= available_items.size() && user_action >= 1){ //View Item goes in here

				cout << "viewing " << user_action << "item\n"; // Temporary Line
				viewItem( user_action, available_items);
				char item_action =' ';

				while (item_action != 'E'); {
					
					cout << "If you would like to add Item " << user_action << " to your cart enter X\nIf you'd like to go back enter E";
					cin >> item_action;

					if (item_action != 'E' && item_action != 'X') {

						cout << "Entered input is invalid. Not a valid option. Try Again \n";
						item_action = ' ';

					} else if (item_action == 'X') {

						cart_items.push_back(available_items[user_action -1]);
						cout << "Item successfully added to cart. " << endl;
						user_action = 789;
						item_action = 'E';

					}

				}
			}

		} while (user_action != 0);
	}
}