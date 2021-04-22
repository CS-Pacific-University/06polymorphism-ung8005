//***************************************************************************
// File name:	 LetterParcel.h
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:    Declares a programmer-defined child class LetterParcel 
//             representing information for a letter parcel. 
//***************************************************************************

#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class LetterParcel : public Parcel {

  public:
    LetterParcel ();
    LetterParcel (int trackingNumber, string sender, string reciever,         // intialize here or make two diff constructors? 
                  int weight, int travelDistance, double insuranceCost);
    //~LetterParcel ();                                                                 // destructors? 

    virtual void addInsurance ();
    virtual void addRush ();

    virtual double getCost () const;                                            // is the = 0 just for the parent class? 
    virtual double getInsuranceCost () const; 
    virtual double getRushCost () const;
    virtual double getTotalCost () const; 
    virtual double getWeightCost () const;

    virtual void print (std::ostream& rcOut) const;
    virtual bool read (istream& rcIn);

  private:
    double mInsuranceCost; 

};