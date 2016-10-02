//
//  realEstate.hpp
//  Lab10
//
//  Created by Sean Burnham on 11/26/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//


#ifndef Property_hpp
#define Property_hpp

#include <stdio.h>

#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Property
{
protected:
    int _propertyId = 0;
    string _type = "";
    int _isRental = 0;
    double _value = 0;
    int _isOccupied = 0;
    string _address = "";
    double _discountRate = 0;
    double tax;
    
public:
    // Default Constructor
    Property();
    
    //Residential Constructor
    Property(int propertyId, string type, int rentalType, double value, int occupied, string address);
    ~Property();
    
    //Commercial Constructor
//    Property(int propertyId, string type, int rentalType, double value, int occupied, double discountRate, string address);
    
    
    virtual string toString() = 0;
    virtual string computeTaxes() = 0;
    
    double getTax();
    string getAddress();
   
};


#endif