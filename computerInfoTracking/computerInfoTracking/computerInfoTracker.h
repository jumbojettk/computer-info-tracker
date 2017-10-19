// Napon Krassner
// CSC 2430, Homework 4
// 2-6-2015
// Due: 2-11-2015
// Name: Computer Info Tracker
// Description: This is the header file for the computer info tracker program which includes
//				the class instantiation, class constructors/accessors/mutators function prototypes
//				and member variables.

#ifndef COMPUTER_INFO_TRACKER
#define COMPUTER_INFO_TRACKER

#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
	// **********CONSTRUCTORS**********

	// Parameters: None
	// Returns: Nothing
	// Description: Default constructor with no params.
	//				Sets all numeric items to 0 and string to empty.
	Computer();

	// Parameters: unsigned short for model number,
	//				string for manufacturer name,
	//				float for CPU speed,
	//				float for price per computer,
	//				int for quantity on hand
	// Returns: Nothing
	// Description: Constructor that sets all 5 params for each data member.
	//				If price <= 0, sets to 0.01,
	//				if quantity < 0, sets to 0,
	//				if clock speed is < 0, set to 1.0
	Computer(unsigned short, string, float, float, int);

	// Parameters: unsigned short for model number,
	//				string for manufacturer name
	//				float for CPU speed
	// Returns: Nothing
	// Description: Constructor that sets the first 3 parameters and 2 params to default values.
    //              if price = 0.01, quantity = 0.
    Computer(unsigned short, string, float);

    
	// **********MUTATORS**********
    
    // Parameters: unsigned short for model number
    // Returns:  nothing
    // Description:  Sets the model number with the given param.
    void setModelNumber(unsigned short);
    
    // Parameters: string for manufacturer name
    // Returns: nothing
    // Description:  Sets the manufacturer name with the given param.
    void setManufacturer(string);
    
    // Parameters: float for CPU speed
    // Returns:  nothing
    // Description:  Sets the CPU with the given param.
    //               if CPUspeed <= 0, set to 1.0
    void setCPUSpeed(float);
    
    // Parameters: float for price per computer
    // Returns:  nothing
    // Description: sets the price per computer with the given param.
    //              if price <= 0, set to 0.01
    void setPricePerComp(float);
    
    // Parameters: int for quantity on hand
    // Returns: nothing
    // Description: Sets the quantity of the computer on hand.
    //              if quantity < 0, set to 0
    void setQuantity(int);
    
    // Parameters: unsigned short for model number,
    //				string for manufacturer name,
    //				float for CPU speed,
    //				float for price per computer,
    //				int for quantity on hand
    // Returns: nothing
    // Description: Sets all 5 params for each data member with the given value.
    //              if pricePerComp <= 0, set to 0.01
    //              if quantity < 0, set to 0
    //              if CPUspeed <=0, set to 1.0
    void setAll(unsigned short, string, float, float, int);

    
	// **********ACCESSORS**********
    
    // Parameters: nothing
    // Returns: unsigned short for model number,
    // Description: Access the model number of the computer and returns as unsigned short.
    unsigned short getModelNumber() const;
    
    // Parameters: nothing
    // Returns:	string for manufacturer name
    // Description: Access the manufacturer name of the computer and returns as string.
    string getManufacturer() const;
    
    // Parameters: nothing
    // Returns: float for CPU speed
    // Description: Access the CPU speed of the computer and returns as float.
    float getCPUSpeed() const;
    
    // Parameters: nothing
    // Returns: float for price per computer
    // Description: Access the price per computer and returns as float.
    float getPricePerComp() const;
    
    // Parameters: nothing
    // Returns: int for quantity on hand
    // Description: Access the quantity of the computer on hand and returns as int.
    int getQuantity() const;


	//**********Utility**********
	
	// Parameters: float for price per comp, int for quantity
	// Returns: float for value for given number for comp
	// Description: Calculates and returns the value for given number of computer.
	//				price per comp * quantity
	float calcValue() const;

	// Parameters: unsigned short for model number,
	//				string for manufacturer name,
	//				float for CPU speed,
	//				float for price per computer,
	//				int for quantity on hand
	// Returns: nothing
	// Description: Prints information for all data members plus the value for the item (using calcValue).
	//				No descriptive text, but clock speed needs GHz after the float value.
	//				1 decimal point for GHz, 2 decimal points?
	void printInfo();


private:
	// Member variables
	unsigned short modelNumber;
	string manufacturer;
	float cpuSpeed;
	float pricePerComp;
	int quantityAvail;

};
#endif