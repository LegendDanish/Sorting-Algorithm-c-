#pragma once
#include <iostream>
using namespace std;
class Credential
{
public:
    int index;
    int founded;
    int noOfEmployees;
    string organizationID;
    string name;
    string website;
    string country;
    string description;
    string industry;

    Credential()
    {

    }
    Credential(int index, int founded, int noOfEmployees, string organizationID, string name, string website, string country, string description, string industry)
    {
        this->index = index;
        this->founded = founded;
        this->noOfEmployees = noOfEmployees;
        this->organizationID = organizationID;
        this->name = name;
        this->website = website;
        this->country = country;
        this->description = description;
        this->industry = industry;
    }
};

