#include <iostream> 
#include <vector>   
#include <string>   
#include "Item.h"   
#include "Functions.h" 

using namespace std;

int main() {
   char proceed_choice = ' '; // Variable to store user's choice to proceed or not

   // Welcome message and prompting the user to proceed
   cout << "Welcome to our C++ Online Shopping Cart Console Application!\nWould you like to proceed? (Y/N)" << endl;
   cin >> proceed_choice;
   proceed_choice = toupper(proceed_choice); // Change user input to upper case

   if (proceed_choice == 'N') {
       // runs if user chooses not to proceed, exit the program
       cout << "Closing Program..." << endl; 
       // If user chooses to proceed
   } else if (proceed_choice == 'Y') { 
       vector<Item*> available_items = createShop(); // Vector to store available items in the shop
       vector<Item*> cart_items; // Vector to store items added to the cart

       int user_action; // variable stores user's action choice
       char go_to_cart = ' '; // variable to control navigation between cart and available item list

       // Displays available items in the shop
       cout << "List of Shop Items for Sale: " << endl;
       viewItemList(available_items);

       // Main loop to handle user actions until user chooses to close the program
       do {
           // Prompt user for action
           cout << "\nEnter Item # to view more information.\nEnter 0 to close the program.\nEnter -1 to proceed to cart.\nEnter -2 to regenerate item list.\n";
           cin >> user_action;

           if (user_action == 0) {
               cout << "Closing Program..." << endl; // runs if user chooses to end the program
           } else if (user_action > 0 && user_action <= available_items.size()) {
               char cart_action = ' '; // Variable to store user's action related to cart

               // Loop to handle actions related to the selected item
               do {
                   viewItem(user_action - 1, available_items); // Display detailed information about the selected item
                   cout << "Would you like to add this item to your cart?" << endl;
                   cout << "Enter A to add item to cart.\nEnter B to go back to item list.\n";
                   cin >> cart_action;

                   if (cart_action == 'A') { // If user chooses to add the item to the cart
                       cart_items.push_back(available_items[user_action - 1]); // Add the item to the cart
                       cout << "Item successfully added to cart.\n";
                       cout << "Enter X to view contents of your cart.\nEnter N to go back to available item list without viewing cart contents.\n";
                       cin >> go_to_cart;

                       if (go_to_cart == 'X') { // If user chooses to view cart contents
                           cout << "Cart Items: \n";
                           viewItemList(cart_items); // Display items in the cart
                           cout << "\nEnd of Cart Items.\n\n";
                           cart_action = 'B'; // Exit the loop to go back to the item list
                       } else if (go_to_cart == 'N') { // If user chooses to go back to available item list
                           cout << "\n\nRegenerating Available Item List: \n\n";
                           viewItemList(available_items); // Display available items again
                           go_to_cart = ' ';
                       }
                   } else if (cart_action == 'B') {
                       cout << "Going back. \n\n"; // If user chooses to go back to the item list
                   } else {
                       cout << "Invalid Input. \n\n"; // If user enters invalid input
                       cart_action = ' '; // Reset cart action to continue loop
                   }
               } while (cart_action != 'A' && cart_action != 'B'); // Continue loop until user adds to cart or goes back

           } else if (user_action == -1) { // If user chooses to proceed to cart
               char print_receipt = ' '; // Variable to control navigation within the cart

               // Loop to handle actions related to the cart
               do {
                   showReceipt(cart_items); // Display current contents of the cart
                   cout << "Would you like to continue shopping, remove an item from the cart, or print the receipt?" << endl;
                   cout << "Enter R to remove an item from the cart.\nEnter X to print the receipt and exit the program.\nEnter N to continue shopping.\n";
                   cin >> print_receipt;

                   if (print_receipt == 'R') {
                       RemoveFromCart(cart_items); // If user chooses to remove an item from the cart
                   } else if (print_receipt == 'X') {
                       cout << "Printing the receipt. \n"; // If user chooses to print the receipt and exit
                       printReceipt(cart_items); // Print the receipt
                       user_action = 0; // Set user action to close the program
                   } else {
                       cout << "Returning to main store..\n\n"; // If user chooses to continue shopping
                   }
               } while (print_receipt != 'N' && print_receipt != 'X'); // Continue loop until user chooses to continue or print receipt

           } else if (user_action == -2) { // If user chooses to regenerate item list
               cout << "\n\nRegenerating Available Item List: \n\n";
               viewItemList(available_items); // Regenerate and display available items

           } else {
               cout << "Entered number is invalid. It is outside of shop item number range. \nTry Again.\n\n";
           }
       } while (user_action != 0); // Continue loop until user chooses to close the program
   }

   return 0;
}