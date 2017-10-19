// Napon Krassner
// CSC 2430, Homework 4
// 2-6-2015
// Due: 2-11-2015
// Name: Computer Info Tracker
// Description: This client program implements the functions from the Computer class.
//				Uses function to create a formatted output using ac

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "computerInfoTracker.h"

using namespace std;

// Function prototype
void printInfoFormatted(Computer);
void fillComputerArray(Computer[], int);
void printComputerArray(Computer[], int);

const int MAX = 10;

int main()
{
	// Construct/Declare
	Computer com1(12345, "Dell", 1.0, 1000.00, 5);  // Create with all given info
	Computer com2;  // Default to be set
	Computer com3;  // Default to be set all
	Computer com4(2341, "Dell", 2.0);  // Create with 3 given info
	Computer comArr[10];  // Array of 10 computers

	// Mutate one member var at a time
	com2.setModelNumber(2468);
    com2.setManufacturer("ASUS");
    com2.setCPUSpeed(4.5);
    com2.setPricePerComp(2000.00);
    com2.setQuantity(2);

	// Mutate all member var at once
    com3.setAll(8888, "RAZER", 6.2, 4500.00, 12);

	// Read file into array of computer object
	fillComputerArray(comArr, MAX);
	
	// Output
	cout<< "*****Welcome to the Computer Info Tracker! By Napon Krassner (Jett)*****" << endl << endl;
	cout << "---Constructed with all 5 values given:" << endl;
	com1.printInfo();  // Class print funtion
	printInfoFormatted(com1);  // Client formatted print
	cout << "---Constructed default, then set one member var at a time: " << endl;
	com2.printInfo();  // Class print funtion
	printInfoFormatted(com2);  // Client formatted print
	cout << "---Constructed default, then set all 5 member var: " << endl;
	com3.printInfo();  // Class print funtion
	printInfoFormatted(com3);  // Client formatted print
	cout << "---Constructed with 3 member var and the rest to default: " << endl;
	com4.printInfo();  // Class print funtion
	printInfoFormatted(com4);  // Client formatted print
	// Print from the array
	printComputerArray(comArr, MAX);

	return 0;
}

// Parameters: computer object
// Returns: nothing
// Description: Get values by using accessors and calcValue.
//				Prints the computer info to console with formatted output
void printInfoFormatted(Computer com)
{
	// Access all member variables (one at a time) and store to local vars
	unsigned short modelNum = com.getModelNumber();
	string manu = com.getManufacturer();
	float CPU = com.getCPUSpeed();
	float price = com.getPricePerComp();
	int quantity = com.getQuantity();

	float compValue;
	compValue = com.calcValue();  // Calculate and store to local var

	// Print/output with formatting
	cout << "-Formatted printing:" << endl;
	cout << fixed << showpoint;
	cout << "Model #: " << modelNum << ", Manufacturer: " << manu << ", Speed: "<< setprecision(1) << CPU << "GHz" << endl;
	cout << quantity << " on hand at price: "<< setprecision(2) << price << " gives the total value of " << compValue << endl << endl;
}

// Parameters: array of computer object, int for max, ifstream for the txt file
// Returns: nothing
// Description: Fills the array with the computer info values from the input txt file.
void fillComputerArray(Computer comArray[], int max)
{
	// File stream to work with array
	ifstream inFile;

	inFile.open("..\\computerInfoTracking\\computers.txt");  // location of file

	if (inFile.fail())  // Check if file corrupted
	{
		cout << "Error, failed to open file!" << endl;
		exit(1);
	}

	// Local vars
	unsigned short modelNum;
	string manu;
	float CPU;
	float price;
	int quantity;
	int index = 0;

	// Prime read
	inFile >> modelNum >> manu >> CPU >> price >> quantity;  
	comArray[index].setAll(modelNum, manu, CPU, price, quantity);
	index++;

	// Go through and store values from file into array
	while (index < max && inFile.good())
	{
		inFile >> modelNum >> manu >> CPU >> price>> quantity;
		comArray[index].setAll(modelNum, manu, CPU, price, quantity);
		index++;
	}

	inFile.close();  // Close file
}

// Parameters: array of computer object, int for max
// Return: nothing
// Description: Iterate through and print all elements in computer array until max.
void printComputerArray(Computer comArray[], int max)
{
	cout << "----------Printing all computer objects from the array...----------" << endl;
	for (int i = 0; i < max; i++)
	{
		comArray[i].printInfo();
		printInfoFormatted(comArray[i]);
	}
}