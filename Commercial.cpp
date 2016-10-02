//
//  Commercial.cpp
//  Lab10
//
//  Created by Sean Burnham on 11/29/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#include "Commercial.hpp"



string Commercial::toString()
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
    
    // "_isOccupied" for the commercial constructor actually means discounted or not discounted
    if (_isOccupied == 1)
    {
        ss << " Discounted";
        ss << " Discount: " << _discountRate;
    }
    else
    {
        ss << " NOT discounted";
    }
    
    
    return ss.str();
}

Commercial::Commercial(int propertyId, string type, int rentalType, double value, int occupied, double discountRate, string address)
{
    _propertyId = propertyId;
    _type = type;
    _isRental = rentalType;
    _value = value;
    _isOccupied = occupied;
    _address = address;
    _discountRate = discountRate;
}

Commercial::~Commercial() { }

string Commercial::computeTaxes()
{
    double taxesDueOnRentalsWithRate = ((1 - _discountRate)* _value * 0.012);
    double taxesDueOnNonRentalsWithRate = ((1 - _discountRate)* _value * 0.01);
    double taxesDueOnRentals = (_value * 0.012);
    double taxesDueOnNonRentals = (_value * 0.01);
    
    stringstream ss;
    ss << "** Taxes due at: " << _address << endl << "\tProperty ID: " << _propertyId << endl << "\tThis property has an estimated value of: " << _value << endl;
    if (_isRental == 1 && _isOccupied == 1)
    {
        ss << "\tTaxes due on this property are: " << taxesDueOnRentalsWithRate << endl;
        tax = taxesDueOnRentalsWithRate;
    }
    else if(_isRental == 1 && _isOccupied == 0)
    {
        ss << "\tTaxes due on this property are: " << taxesDueOnRentals << endl;
        tax = taxesDueOnRentals;
    }
    else if(_isRental == 0 && _isOccupied == 1)
    {
        ss << "\tTaxes due on this property are: " << taxesDueOnNonRentalsWithRate << endl;
        tax = taxesDueOnNonRentalsWithRate;
    }
    else if(_isRental == 0 && _isOccupied == 0)
    {
        ss << "\tTaxes due on this property are: " << taxesDueOnNonRentals << endl;
        tax = taxesDueOnNonRentals;
    }
    
    return ss.str();
}








