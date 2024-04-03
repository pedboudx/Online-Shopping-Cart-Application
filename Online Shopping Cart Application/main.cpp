#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Functions.h"

using namespace std;

int main()
{
    char proceed_choice = ' ';

    cout << "Welcome to our C++ Online Shopping Cart Console Application!\nWould you like to proceed? (Y/N)" << endl;
    cin >> proceed_choice;
    proceed_choice = toupper(proceed_choice);

    if (proceed_choice == 'N')
    {
        cout << "Closing Program..." << endl;
    }
    else if (proceed_choice == 'Y')
    {
        vector<Item*> available_items = createShop();
        vector<Item*> cart_items;

        int user_action;
        char go_to_cart = ' ';

        cout << "List of Shop Items for Sale: " << endl;
        viewItemList(available_items);

        do
        {
            cout << "\nEnter Item # to view more information.\nEnter 0 to close the program.\nEnter -1 to proceed to cart.\nEnter -2 to regenerate item list.\n";
            cin >> user_action;

            if (user_action == 0)
            {
                cout << "Closing Program..." << endl;
            }
            else if (user_action > 0 && user_action <= available_items.size())
            {
                char cart_action = ' ';
                do
                {
                    viewItem(user_action - 1, available_items);
                    cout << "Would you like to add this item to your cart?" << endl;
                    cout << "Enter A to add item to cart.\nEnter B to go back to item list.\n";
                    cin >> cart_action;

                    if (cart_action == 'A')
                    {
                        cart_items.push_back(available_items[user_action - 1]);
                        cout << "Item successfully added to cart.\n";
                        cout << "Enter X to view contents of your cart.\nEnter N to go back to available item list without viewing cart contents.\n";
                        cin >> go_to_cart;

                        if (go_to_cart == 'X')
                        {
                            cout << "Cart Items: \n";
                            viewItemList(cart_items);
                            cout << "\nEnd of Cart Items.\n\n";
                            cart_action = 'B';
                        }
                        else if (go_to_cart == 'N')
                        {
                            cout << "\n\nRegenerating Available Item List: \n\n";
                            viewItemList(available_items);
                            go_to_cart = ' ';
                        }
                    }
                    else if (cart_action == 'B')
                    {
                        cout << "Going back. \n\n";
                    }
                    else
                    {
                        cout << "Invalid Input. \n\n";
                        cart_action = ' ';
                    }

                } while (cart_action != 'A' && cart_action != 'B');
            }
            else if (user_action == -1)
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
            else if (user_action == -2)
            {
                cout << "\n\nRegenerating Available Item List: \n\n";
                viewItemList(available_items);
            }
            else
            {
                cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
            }
        } while (user_action != 0);
    }

    return 0;
}
