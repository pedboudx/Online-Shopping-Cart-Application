#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Functions.h"

using namespace std;

int main()
{
    char proceed_choice = ' '; 

    cout << "Welcome to our C++ Kitchen Shopping Cart Console Application!\nWould you like to proceed? (Y/N)" << endl;
    cin >> proceed_choice;
    proceed_choice = toupper(proceed_choice);

    if (proceed_choice == 'N') // Closes the program if the user choses not to proceed.
    {
        cout << "Closing Program..." << endl;
    }
    else if (proceed_choice == 'Y') // If user chooses to proceed, goes to main program
    {
        // Creates vectors of Item* to be the items for sale and the user's cart.
        vector<Item *> available_items = createShop();
        vector<Item *> cart_items;

        int user_action;
        char go_to_cart = ' ';

        cout << "List of Shop Items for Sale: " << endl;
        viewItemList(available_items); // Displays the items for sale.

        do // Loops user action until they decide to exit the program.
        {
            cout << "\nEnter Item # to view more information.\nEnter 0 to close the program.\nEnter -1 to proceed to cart.\nEnter -2 to regenerate item list.\n";
            cin >> user_action;

            if (user_action == 0) // Closes the program if user decides to do so.
            {
                cout << "Closing Program..." << endl;
            }
            else if (user_action > 0 && user_action <= available_items.size()) // Option to view item
            { // Checks to see if user entered an item number inside the appropriate range.
                char cart_action = ' ';
                do
                {   // Displays that item in more detail and asks user if they'd like to add to cart.
                    viewItem(user_action - 1, available_items);
                    cout << "Would you like to add this item to your cart?" << endl;
                    cout << "Enter A to add item to cart.\nEnter B to go back to item list.\n";
                    cin >> cart_action;

                    if (cart_action == 'A')
                    {
                        cart_items.push_back(available_items[user_action - 1]);
                        // Once Item is added to cart asks user if they want to see their cart or go back to shop.
                        cout << "Item successfully added to cart.\n";
                        cout << "Enter X to view contents of your cart.\nEnter N to go back to available item list without viewing cart contents.\n";
                        cin >> go_to_cart;

                        if (go_to_cart == 'X')
                        {
                            // Shows the users cart items, containing the newly added item.
                            cout << "Cart Items: \n";
                            viewItemList(cart_items);
                            cout << "\nEnd of Cart Items.\n\n";
                            cart_action = 'B';
                        }
                        else if (go_to_cart == 'N')
                        {
                            // Goes back to the main shop and reloads the item list.
                            cout << "\n\nRegenerating Available Item List: \n\n";
                            viewItemList(available_items);
                            go_to_cart = ' ';
                        }
                    }
                    else if (cart_action == 'B')
                    {
                        // Goes back to the shop without adding the new item to the cart.
                        cout << "Going back. \n\n";
                    }
                    else
                    {
                        // Tells user their input is invalid.
                        cout << "Invalid Input. \n\n";
                        cart_action = ' ';
                    }

                } while (cart_action != 'A' && cart_action != 'B');
            }
            else if (user_action == -1) // Option to proceed to cart.
            {
                char print_receipt = ' ';

                do
                {
                    showReceipt(cart_items);
                    cout << "Would you like to continue shopping, remove an item from the cart, or print the receipt?" << endl;
                    cout << "Enter R to remove an item from the cart.\nEnter X to print the receipt and exit the program.\nEnter N to continue shopping.\n";
                    cin >> print_receipt;

                    if (print_receipt == 'R')
                    {
                        RemoveFromCart(cart_items);
                    }
                    else if (print_receipt == 'X')
                    {
                        cout << "Printing the receipt. \n";
                        printReceipt(cart_items);
                        user_action = 0;
                    }
                    else
                    {
                        cout << "Returning to main store..\n\n";
                    }
                } while (print_receipt != 'N' && print_receipt != 'X');
            }
            else if (user_action == -2) // Option to reload the item list.
            {
                cout << "\n\nRegenerating Available Item List: \n\n";
                viewItemList(available_items);
            }
            else // Tells user they entered an invalid number and they should try again.
            {
                cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
            }
        } while (user_action != 0);
    }

    return 0;
}
