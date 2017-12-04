/**
 * Programmer: Argin Aslanian
 * Purpose: A self-checkout program that will calculate the subtotal,
 *          tax amount, and the total for a customer.
 *          The customer may enter how ever many items they want to purchase,
 *          and with the tax rate of 8.5%, their final price will be calculated.
 */

#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

//Declare functions.
double getUserValidatedInput();
double getSubtotal();

int main() {
    //Declare variables needed and a double constant for the tax rate.
    const double TAX_RATE = 8.5;
    double subtotal, tax, total;

    //Calculate subtotal, tax, and total.
    subtotal = getSubtotal();
    tax = subtotal * (TAX_RATE / 100);
    total = subtotal + tax;

    //Display the results to the user with 2 decimal places.
    cout << fixed << setprecision(2) << endl;
    cout << "Subtotal : $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;

    return 0;
}

//This function will ask for the price and quantity of the item the customer is purchasing and
//will calculate the subtotal based on the customer's inputs.
double getSubtotal() {
    //Declare variables needed.
    double subtotal = 0, price;
    int quantity;
    char sentinel = 'y', moreItems;

    do {
        //Get item price.
        cout << "Item price: ";
        price = getUserValidatedInput();

        //Get item quantity.
        cout << "Quantity? ";
        quantity = (int) getUserValidatedInput();

        //Calculate subtotal by adding the price of the item times it's quantity.
        subtotal += price * quantity;

        //Ask the customer if they have more items to purchase.
        cout << endl << "More items? [ y , n ] ";
        cin >> moreItems;

    } while (moreItems == sentinel);

    return subtotal;
}

//Validate user inputs.
//NOTE: RECURSIVE FUNCTION!
double getUserValidatedInput() {
    double retVal = 0;

    //Input has to be double.
    while(!(cin >> retVal)) {
        cout << "Try again. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //Input cannot less than 0.
    if (retVal < 0) {
        cout << "Try again. ";
        retVal = getUserValidatedInput();
    }

    return retVal;
}