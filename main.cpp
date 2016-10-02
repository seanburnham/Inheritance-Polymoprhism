//
//  main.cpp
//  Lab10
//
//  Created by Sean Burnham on 11/25/15.
//  Copyright © 2015 Sean Burnham. All rights reserved.
//

#include "Property.hpp"
#include "Residential.hpp"
#include "Commercial.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//Uses the getTax() function to return the amount previously
// found in printing the Taxes portion and sorts it from lowest to highest.
void sortByTaxes(vector<Property*> &properties);

//Uses bubbles sorting to first look at the numbers and then moves on
// from there if they are the same number to bubble sort the letters in each name.
void sortByAddress(vector<Property*> &properties);

int main()
{
    vector<Property*> properties;
    string type;
    int rentalType;
    double value;
    int occupied;
    string address;
    double discountRate;
    static const int ResidentialSpaces = 6; //Allows us to count the correct number of spaces found in the files we load in for Residential
    static const int CommercialSpaces = 7; //Allows us to count the correct number of spaces found in the files we load in for Commercial
    
    cout << "Which file would you like to load?" << endl;
    string filelocation; //= "/Users/SeanBurnham/Desktop/Test2.txt";
    getline(cin,filelocation);
    
    ifstream myfile;
    myfile.open(filelocation);
    
    // If the file open didnt work, print out an error
    if(myfile.fail())
    {
        cout << "Unable to load file" << endl;
        return 0;
    }
    
    
    string line; //Variable for each line of the file loaded into the program
    int propertyId = 0;// Used to increment the list of properties once run to the toString() function
    while (getline(myfile, line)) // reads the line
    {
        size_t numSpaces = count(line.begin(), line.end(), ' '); //Counts the line up to each space found in file we load in

        stringstream ss(line);
    
        ss >> type; //Always outputs the type of property first to error check
        
        if (type == "Residential" && numSpaces >= ResidentialSpaces)
        {
            
            ss >> rentalType;
            ss >> value;
            ss >> occupied;
            int temp = int(ss.tellg()); //Gets the input in sequence up to the point we are at and returns the position of the current character in the input stream.
            address = line.substr(temp + 1, line.length() - temp - 1);
            
            //create new Residential object
            Residential* prop = new Residential(propertyId, type, rentalType, value, occupied, address);
            properties.push_back(prop);
            
            propertyId++; //Increments so that it will be outputed in a list in the toString() function.
            
        }
        else if (type == "Commercial" && numSpaces >= CommercialSpaces)
        {
            ss >> rentalType;
            ss >> value;
            ss >> occupied;
            ss >> discountRate;
            int temp = int(ss.tellg()); //Gets the input in sequence up to the point we are at and returns the position of the current character in the input stream.
            address = line.substr(temp + 1, line.length() - temp - 1);
            
            //create new Commercial object
            Commercial* prop = new Commercial(propertyId, type, rentalType, value, occupied, discountRate, address);
            properties.push_back(prop);
            
            propertyId++; //Increments so that it will be outputed in a list in the toString() function.
        }
        else
        {
            if (type == "Residential")
            {
               cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
            }
            else if (type == "Commercial")
            {
                cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
            }
            else if (line[0] == '\n')
            {
                cout << "Ignoring bad input in input file: " << line << endl;
            }
            else
            {
                cout << "Ignoring unknown types of properties appearing in the input file: " << line << endl;
            }
                
        }
        
    }
    
    cout << "\nAll Valid Properties:" << endl << endl;
    
    for(int i = 0; i < properties.size(); i++)
    {
        cout << properties[i]->toString() << endl;
    }
    
    char input;
    cout << "\nWould you like to see the report sorted by Taxes Due or Addresses? (T or A) ";
    cin >> input;
    

    
    cout << "\nNOW PRINTING TAX REPORT:" << endl << endl;

    for(int i = 0; i < properties.size(); i++)
    {
        properties[i]->computeTaxes();
    }
    
    if (input == 'T')
    {
        sortByTaxes(properties);
    }
    else
    {
        sortByAddress(properties);
    }
    
    for(int i = 0; i < properties.size(); i++)
    {
      cout << properties[i]->computeTaxes() <<  endl;
    }
    
    return 0;
}


//Uses the getTax() function to return the amount previously
// found in printing the Taxes portion and sorts it from lowest to highest.
void sortByTaxes(vector<Property*> &properties)
{
    for (int j = 0; j < properties.size() - 1; j++)
        for (int i = 0; i < properties.size() - 1; i++)
        {
            if (properties[i]->getTax() > properties[i+1]->getTax())
            {
                Property * temp = properties[i];
                properties[i] = properties[i+1];
                properties[i+1] = temp;
            }
        }
}

//Uses bubbles sorting to first look at the numbers and then moves on
// from there if they are the same number to bubble sort the letters in each name.
void sortByAddress(vector<Property*> &properties)
{
    vector<int>addressNum;
    vector<string>roadName;
    
    //for (int l = 0; l < properties.size(); l++)
    for (int j = 0; j < properties.size(); j++)
    {
        int i = 0;
        for (; i < properties[j]->getAddress().size(); i++)
            if (!(properties[j]->getAddress()[i] >= '0' && properties[j]->getAddress()[i] <= '9'))
                break;
        
        string num = properties[j]->getAddress().substr(0, i);
        string road = properties[j]->getAddress().substr(0 + i+1, properties[j]->getAddress().size() - (0 + i+1));
    
        int addressNumber;
        istringstream convert(num);
        if ( !(convert >> addressNumber) )
            addressNumber = 0;
    
        addressNum.push_back(addressNumber);
        roadName.push_back(road);
    }
    
    
    for (int j = 0; j < addressNum.size() - 1; j++)
        for (int i = 0; i < addressNum.size() - 1; i++)
        {
            if (addressNum[i] > addressNum[i+1])
            {
                int tempAddress = addressNum[i];
                addressNum[i] = addressNum[i+1];
                addressNum[i+1] = tempAddress;
                
                string tempName = roadName[i];
                roadName[i] = roadName [i+1];
                roadName[i+1] = tempName;
                
                Property * temp = properties[i];
                properties[i] = properties[i+1];
                properties[i+1] = temp;
            }
            else if (addressNum[i] == addressNum[i+1])             {
                for (int k = 0; k < roadName[i].size(); k++)
                {
                    if (roadName[i][k] > roadName[i+1][k])
                    {
                        string tempName = roadName[i];
                        roadName[i] = roadName [i+1];
                        roadName[i+1] = tempName;
                        
                        Property * temp = properties[i];
                        properties[i] = properties[i+1];
                        properties[i+1] = temp;
                        break;
                    }
                    else if (roadName[i][k] < roadName[i+1][k])
                    {
                        break;
                    }
                }
            }
            
        }
    
}










