//
//  Residential.hpp
//  Lab10
//
//  Created by Sean Burnham on 11/29/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#ifndef Residential_hpp
#define Residential_hpp

#include <stdio.h>
#include "Property.hpp"

class Residential: public Property
{
public:
    string toString();
    Residential(int propertyId, string type, int rentalType, double value, int occupied, string address);
    ~Residential();
    string computeTaxes();
    
};



#endif /* Residential_hpp */
