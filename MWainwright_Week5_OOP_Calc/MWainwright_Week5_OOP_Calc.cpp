/* MWainwright_Week5_OOP_Calc.cpp : Defines the entry point for the console application.
Michael J Wainwright
July 10, 2017
Jon Jensen
Progam Description : Will perform simple calculator functions, Addition, Subtraction, Division, & Multiplication. Gathers input from user, which must be a
CSV string ex. 3, 26, 5, 69. Uses a vector<double> to store inputted numbers after separating them out in the 'loadvector' function.
The vector is then processed into a double type and loaded into the 'total' variable using the 'processOperation' function.
*/


#include "stdafx.h"
#include "SimpleMath.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;



vector<double> loadVector(string userArrayInput);		// gathers input from user and creates a vector<int>
bool response();										// sets true if user wants to repeat after invalid data is entered
int menu();												// user selects calculator operation.ion, still using this to verify that multiple integers were entered.
bool isSelectionCorr();									// prompt user if to verfy selected menu item
int menuSelection{ 0 };									// used to determine which operation to perform
double processOperation(vector<double> input);			// go through each number entered and perform the desired operation

// overriding the what() function in eception class
class ExcHndlr : public exception{
	const char* msg;
	ExcHndlr(){}

public:
	ExcHndlr(const char * s) throw() : msg(s) {	}
	const char* what() const throw(){ return msg; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	string userArrayInput;		// string input of numbers separated by a comma
	vector<double> inputVector;	// vector storing doubles output of loadVector funct
	double total{ 0 };			// running total of all entered number

	cout << "Welcome to the simple calculator!" << endl;

start:
	menuSelection = menu();
	switch (menuSelection)
	{
	case 1:
			cout << "You have entered Addition!" << endl;
			break;
		case 2:
			cout << "You have entered Subtraction!" << endl;
			break;
		case 3:
			cout << "You have entered Multiplication!" << endl;
			break;
		case 4:
			cout << "You have entered Division!" << endl;
			break;
		case 5:
			cout << "You have decided to exit the program!" << endl;
			break;
		default:
			cout << "You have entered an incorrect selection. Please try again!" << endl;
			goto start;
	}
	// Verifying the user selected the correct operation before performing the operation
	bool correct = isSelectionCorr();
	if (!correct)
	{
		goto start;
	}
	if (menuSelection == 5)
	{
		return 0; // exiting program if the user selected this option. Giving user option to change mind.
	}

	cout << "Please enter an array of numbers with each separated by a comma (ex. 3,5,35)" << endl;
	cout << "Please note that the numbers can be an integer or floating-point (ex. 35 OR 35.050)" << endl;
	cin >> userArrayInput;
	cout << endl;
	try {
		inputVector = loadVector(userArrayInput);		// convert entered string to usable ints
		if (inputVector.size() < 2)						// user is required to enter >= 2 nunbers
		{
			throw ExcHndlr("Please enter more than one number spearated by a comma");	// overrinding normal what() to display own msg
		}
		total = processOperation(inputVector);			// calculating total of the entered numbers
		cout << "The result of the operation you performed is: " << total << endl;
	}
	catch (ExcHndlr &e)		// catching created exception class to get more info
	{

		cout << "Invalid input entered: " << userArrayInput << endl;	// repeating user entered info
		cout << e.what() << endl;										// outputting exception to get more info
		bool repeat = response();										// ask user if want to repeat program
		if (repeat)
		{
			goto start;
		}
	}

	system("pause");

	return 0;


}

// gathers input from user and creates a vector<int>
vector<double> loadVector(string userArrayInput){

	istringstream iss(userArrayInput);			// string stream based on user input
	string item;								// temp string to store individual string # from input
	vector<double> vi;								// temp vector<int> to return back to main
	int i{};									// iterator to add numbers to the vector<int>
	double userInput;								// temp converted int from string number

	while (getline(iss, item, ',')) {			// breaking up the CSV string input ex. 1,2,3
		userInput = stod(item,nullptr);	// convert the input string to an int w/ base 10
		cout << userInput << endl;			// print out each element to screen - used for debug
		vi.insert(vi.begin() + i, userInput);	// add each integer to the vector
		i++;									// increment i
	}
	return vi;
}

// prompt user if to verfy selected menu item
bool isSelectionCorr(){
	char response;						// used to see if user wants to repeat program if entered wrong info
	bool ans = false;					// set true if answered yes
	cout << "Is this correct? Enter 'Y' for yes: " << endl;
	cin >> response;							// get actual response
	if (response == 'Y' || response == 'y')		// can be upper or lower case
	{
		ans = true;
	}
	return ans;
}

// prompt user if they wants to repeat the program
bool response(){
	char response;						// used to see if user wants to repeat program if entered wrong info
	bool ans = false;					// set true if answered yes
	cout << "Do you wish to try again? Enter 'Y' for yes: " << endl;
	cin >> response;							// get actual response
	if (response == 'Y' || response == 'y')		// can be upper or lower case
	{
		ans = true;
	}
	return ans;
}

// user selects desired calculator operation.
int menu(){
	int selection{ 0 };
	cout << "Please select which operation you would like to perform." << endl;
	cout << "1. Addition"  << endl;
	cout << "2. Subtraction"  << endl;
	cout << "3. Multiplication"  << endl;
	cout << "4. Division" << endl;
	cout << "5. End Program"  << endl;
	cout << "-------------------"  << endl;
	cin >> selection;
	cout << endl;
	return selection;
}

// go through each number entered and perform the desired operation. NOTE: menuSelection needs to be within the scope of the entire program
double processOperation(vector<double> input){	 
	double tot = input[0];		// set local total to the first element of the vector

	// performing operation on all numbers entered, starting at 2nd element in vector because setting 1st element to total
	for (int i = 1; i < input.size() ; i++)
	{
		if (menuSelection == 1)
		{
			Addition myAddition;
			tot = myAddition.add(tot,input[i]);
		}
		else if (menuSelection == 2){
			Subtration mySubtraction;
			tot = mySubtraction.subtract(tot, input[i]);
		}
		else if (menuSelection == 3){
			Multiplication myMultiplication;
			tot = myMultiplication.multiply(tot, input[i]);
		}
		else if (menuSelection == 4){
			Division myDivision;
			if (input[i] == 0)	// verifying divisor is not 0 to prevent error.
			{
				cout << "\nIt is not possible to divide by zero!!" << endl;
				cout << "The input of zero has been removed from the sequence of numbers!!\n" << endl;
				tot = tot;
			}
			else
			{
				tot = myDivision.divide(tot, input[i]);
			}
		}
		else
		{
			tot = tot;
		}
	}
	return tot;
}