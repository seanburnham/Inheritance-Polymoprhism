//
//  Commercial.hpp
//  Lab10
//
//  Created by Sean Burnham on 11/29/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#ifndef Commercial_hpp
#define Commercial_hpp


#include <stdio.h>
#include "Property.hpp"

class Commercial: public Property
{
    
public:
    string toString();
    Commercial(int propertyId,string type, int rentalType, double value, int occupied, double discountRate, string address);
    ~Commercial();
    string computeTaxes();
    
};



#endif /* Commercial_hpp */
