/* Importing necessary libraries */
#include <iostream> /* Allows for the use of input and output such as cout/cin */
#include <windows.h> /* Allows for the printing of coloured text */
#include <iostream> /* Used for opening files and writing to them */
#include <fstream> /* Used for opening files and writing to them */

using namespace std; /* Tells the code we're using the standard C++ library */

/* Creating a main function, start of the program */
int main() {
    string userName; /* Variable that will store the user's name */
    char userFoodOption; /* Variable that will store the user input for the chosen food */
    double totalPrice = 0; /* Variable that will store the total price of the item */
    string chosenFood; /* Variable that will store the string of the item name chosen */

    system("Color 6"); /* Setting the text colour to yellow */

    /* Displaying the prompt for the user to give their name */
    cout << "BRANDONS BURGERS\n----------------\n\nPlease provide your first name below. We use your name to validate your order." << endl;

    cin >> userName; /* Setting the userName variable to the input the user made */

    /* Logging to the console the menu items */
    cout << "BRANDONS BURGERS\n----------------\n\nHey " << userName << ", here's your options:\n\nA. Brandon Burger (1.50)\nB. Beast Burger (3.30)\nC. Baby Burger (5.70)\nD. Brilliant Burger (8.70)\n\nSelect your answer using A - D." << endl;

    cin >> userFoodOption; /* Setting the userFoodOption variable to the input the user made */

    /* Switch statement, if the provided userFoodOption (set to lowercase so its insensitive) is equal to A, B or C then give a response, otherwise default to showing the invalid option message. */
    switch (tolower(userFoodOption)) {
    case 'a': /* If user types in option A, store price and chosen food in variable */
        totalPrice = 1.50;
        chosenFood = "Brandon Burger";
        break;
    case 'b': /* If user types in option B, store price and chosen food in variable */
        totalPrice = 3.30;
        chosenFood = "Beast Burger";
        break;
    case 'c':  /* If user types in option C, store price and chosen food in variable */
        totalPrice = 5.70;
        chosenFood = "Baby Burger";
        break;
    case 'd':
        totalPrice = 8.70;
        chosenFood = "Brilliant Burger";
        break;
    default: /* If user doesn't input a valid option, log to console and inform user */
        cout << "You haven't selected a valid option." << endl;
        break;
    }

    /* If the total price isn't 0, do the following... prevents prompt being ran when invalid option is chosen*/
    if (totalPrice) {
        string validDiscount = "BACKONTHEBURGERS"; /* Create a variable with a string of the discount code */
        string inputtedDiscount; /* Variable that will store the user input of the discount code */

        /* Send to console the discount message, prompting them to enter a code or skip by typing anything*/
        cout << "\n\nBURGER BUDGET\n----------------\n\nHey " << userName << ", just one last thing:\n\nDo you work for Brandon's Burgers? Redeem your 20% off today by inputting your work discount code.\n\nNot an employee? Type anything to skip to the next prompt." << endl;

        cin >> inputtedDiscount; /* Setting the inputtedDiscount variable to the input the user made */

        /* If the valid discount is the same as the one the user inputted, do the following... */
        if (validDiscount == inputtedDiscount) {
            ofstream orderReceipt("receipt.txt"); /* Creates the text document */
    
            orderReceipt << "\n***********************\nYOUR ORDER NUMBER IS\n        0001\n***********************\nBrandon's Burgers\n105 Page's Walk\nLondon SE1 4HD\n***********************\n" << "ITEM: " << chosenFood << "\nTOTAL: " << totalPrice << "\n\n" << "DISCOUNTED PRICE: " << totalPrice - totalPrice / 5 << "\n***********************\n";
            orderReceipt.close(); /* Close the text document */

           /* Log to console the thank you message, referring the user to the receipt.txt file */
            cout << "\n\nTHANK YOU!\n----------------\n\nHey " << userName << ",\n\nYour order has been processed successfully. The discount has also been applied to the order.\n\nPlease refer to the receipt.txt file created in your directory for your proof of purchase.";
        }
        /* If the discount isn't the same as the one stored, apply no discount and send receipt message */
        else {
            ofstream orderReceipt("receipt.txt"); /* Creates the text document */

            /* Writes to the text document */
            orderReceipt << "\n***********************\nYOUR ORDER NUMBER IS\n        0001\n***********************\nBrandon's Burgers\n105 Page's Walk\nLondon SE1 4HD\n***********************\n" << "ITEM: " << chosenFood << "\nTOTAL: " << totalPrice << "\n***********************\n";

            /* Log to console the thank you message, referring the user to the receipt.txt file */
            cout << "\n\nTHANK YOU!\n----------------\n\nHey " << userName << ",\n\nYour order has been processed successfully. No discount has been applied to the order.\n\nPlease refer to the receipt.txt file created in your directory for your proof of purchase." << endl;
        }
    }

    system("pause"); /* Pauses the console window and prompts the user to continue by pressing any key */

    return 0; /* Exits the application by returning a value from the main function */
}