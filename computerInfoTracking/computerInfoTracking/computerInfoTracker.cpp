// Napon Krassner
// CSC 2430, Homework 4
// 2-6-2015
// Due: 2-11-2015
// Name: Computer Info Tracker
// Description: This is the class implementation file of Computer class.
//		It contains all the constructors, mutators, accessors, and utility functions.

#include <iostream>
#include <string>
#include <iomanip>
#include "computerInfoTracker.h"

using namespace std;

// Construct default params
Computer::Computer()
{
    modelNumber = 0;
    manufacturer = "";
    cpuSpeed = 0.0;
    pricePerComp = 0.0;
    quantityAvail = 0;
}

// Construct 5 given params
Computer::Computer(unsigned short modelNum, string manu, float CPU, float price, int quantity)
{
    modelNumber = modelNum;
    manufacturer = manu;
    
    // Validate CPU speed
    if (CPU < 0.0)
    {
        cpuSpeed = 1.0;
    }
    else
    {
        cpuSpeed = CPU;
    }
    
    // Validate price per computer
    if (price <= 0.0)
    {
        pricePerComp = 0.01;
    }
    else
    {
        pricePerComp = price;
    }
    
    // Validate quantity
    if (quantity < 0)
    {
        quantityAvail = 0;
    }
    else
    {
        quantityAvail = quantity;
    }
}

// Construct 3 given params and 2 default params
Computer::Computer(unsigned short modelNum, string manu, float CPU)
{
    modelNumber = modelNum;
    manufacturer = manu;
    
    // Validate CPU speed
    if (CPU < 0.0)
    {
        cpuSpeed = 1.0;
    }
    else
    {
        cpuSpeed = CPU;
    }
    
    pricePerComp = 0.01;
    quantityAvail = 0;
}

// Mutate model number
void Computer::setModelNumber(unsigned short modelNum)
{
    modelNumber = modelNum;
}

// Mutate manufacturer
void Computer::setManufacturer(string manu)
{
    manufacturer = manu;
}

// Mutate cpu speed
void Computer::setCPUSpeed(float CPU)
{
    // Validate CPU speed
    if (CPU <= 0.0)
    {
        cpuSpeed = 0.0;
    }
    else
    {
        cpuSpeed = CPU;
    }
}

// Mutate price per computer
void Computer::setPricePerComp(float price)
{
    // Validate price per computer
    if (price <= 0.0)
    {
        pricePerComp = 0.01;
    }
    else
    {
        pricePerComp = price;
    }
}

// Mutate computer quantity on hand
void Computer::setQuantity(int quantity)
{
    // Validate computer quantity
    if (quantity < 0)
    {
        quantityAvail = 0;
    }
    else
    {
        quantityAvail = quantity;
    }
}

// Mutate all member vars for computer
void Computer::setAll(unsigned short modelNum, string manu, float CPU, float price, int quantity)
{
    modelNumber = modelNum;
    manufacturer = manu;
    
    // Validate CPU speed
    if (CPU < 0.0)
    {
        cpuSpeed = 1.0;
    }
    else
    {
        cpuSpeed = CPU;
    }
    
    // Validate price per computer
    if (price <= 0.0)
    {
        pricePerComp = 0.01;
    }
    else
    {
        pricePerComp = price;
    }
    
    // Validate quantity
    if (quantity < 0)
    {
        quantityAvail = 0;
    }
    else
    {
        quantityAvail = quantity;
    }
}

// Access model number
unsigned short Computer::getModelNumber() const
{
    return modelNumber;
}

// Access manufacturer name
string Computer::getManufacturer() const
{
    return manufacturer;
}

// Access CPU speed
float Computer::getCPUSpeed() const
{
    return cpuSpeed;
}

// Access price per computer
float Computer::getPricePerComp() const
{
    return pricePerComp;
}

// Access quantity of computer
int Computer::getQuantity() const
{
    return quantityAvail;
}

// Calculate value of computer
float Computer::calcValue() const
{
	float compValue = pricePerComp * quantityAvail;  // Calculate
	return compValue;
}

// Print/output computer information on the screen/console
void Computer::printInfo()
{
	float compValue = Computer::calcValue();
	cout << "-Unformatted printing:" << endl;
	cout << fixed << showpoint;
	cout << modelNumber << " " << manufacturer << " "<< setprecision(1) << cpuSpeed << "GHz "<< setprecision(2) << pricePerComp << " " << compValue << endl;
}