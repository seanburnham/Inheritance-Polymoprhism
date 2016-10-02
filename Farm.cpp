//
//  Farm.cpp
//  Lab10
//
//  Created by Sean Burnham on 12/9/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#include "Farm.hpp"

string Farm::toString()
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

Farm::Farm(int propertyId,string type, int rentalType, double value, int occupied, double discountRate, string address):Property(propertyId, type, rentalType, value, occupied, discountRate, address)
{
    ;
}

string Farm::computeTaxes()
{
    return "";
}
