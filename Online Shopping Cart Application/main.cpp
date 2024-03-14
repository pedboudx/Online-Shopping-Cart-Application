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
		int user_action;
		viewItemList(available_items); // Prints out list of available Items for the user to see

		do { 

			cout << "Enter Item # to view more information. \nEnter 0 to close the program.\n";
			cin >> user_action;

			if (user_action == 0) {
				cout << "Closing Program...\n";
			}
			else if (user_action < 1 || user_action > size(available_items)) {
				cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
			}
		} while (user_action != 0);
	}
}