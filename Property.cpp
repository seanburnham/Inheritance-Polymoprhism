//
//  realEstate.cpp
//  Lab10
//
//  Created by Sean Burnham on 11/26/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#include "Property.hpp"

Property::Property()
{
    ;
}

Property::Property(int propertyId, string type, int rentalType, double value, int occupied, string address)
{
    _propertyId = propertyId;
    _type = type;
    _isRental = rentalType;
    _value = value;
    _isOccupied = occupied;
    _address = address;
   
}

Property::~Property() { }

//Property::Property(int propertyId, string type, int rentalType, double value, int occupied, double discountRate, string address)
//{
//    _propertyId = propertyId;
//    _type = type;
//    _isRental = rentalType;
//    _value = value;
//    _isOccupied = occupied;
//    _address = address;
//    _discountRate = discountRate;
//    
//}

double Property::getTax()
{
    return tax;
}

string Property::getAddress()
{
    return _address;
}