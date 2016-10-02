//
//  Farm.hpp
//  Lab10
//
//  Created by Sean Burnham on 12/9/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#ifndef Farm_hpp
#define Farm_hpp

#include <stdio.h>
#include "Property.hpp"

class Farm: public Property
{
public:
    string toString();
    Farm(int propertyId,string type, int rentalType, double value, int occupied, double discountRate, string address);
    ~Farm();
    string computeTaxes();
};

#endif /* Farm_hpp */
