//
//  Residential.cpp
//  Lab10
//
//  Created by Sean Burnham on 11/29/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#include "Residential.hpp"


string Residential::toString()
{
    stringstream ss;
    ss << "Property id: " << _propertyId << " Address: " << _address << " ";
    
    if (_isRental == 1)
    {
        ss << "Rental";
    }
    else
    {
        ss << "NOT rental";
    }
    
    ss << " Estimated Value: " << _value;
    
    if (_isOccupied == 1)
    {
        ss << " occupied";
    }
    else
    {
        ss << " NOT occupied";
    }

    return ss.str();
}

Residential::Residential(int propertyId, string type, int rentalType, double value, int occupied, string address) : Property(propertyId, type, rentalType, value, occupied, address)
{
    ;
}
Residential::~Residential() { }


string Residential::computeTaxes()
{
    double taxesDueOccupied = (_value * 0.006);
    double taxesDueOnNonOccupied = (_value * 0.009);
    
    stringstream ss;
    ss << "** Taxes due at: " << _address << endl << "\tProperty ID: "<< _propertyId << endl << "\tThis property has an estimated value of: " << _value << endl;
    if (_isOccupied == 1)
    {
        ss << "\tTaxes due on this property are: " << taxesDueOccupied << endl;
        tax = taxesDueOccupied;
    }
    else
    {
        ss << "\tTaxes due on this property are: " << taxesDueOnNonOccupied << endl;
        tax = taxesDueOnNonOccupied;
    }
    
    return ss.str();
}






