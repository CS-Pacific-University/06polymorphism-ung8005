//***************************************************************************
// File name:	 OvernightPackageParcel.h
// Author:		 Ashley Ung
// Date:			 4/20/2021
// Class:			 CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:    Declares a programmer-defined child class 
//             OvernightPackageParcel representing information for an 
//             overnight package parcel. 
//***************************************************************************

#pragma once 

#include "OvernightPackageParcel.h"
#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class OvernightPackageParcel : public Parcel {

  public:
    OvernightPackageParcel ();
    OvernightPackageParcel (int trackingNumber, string sender, string reciever,
                            int weight, int travelDstance, int volume);
    ~OvernightPackageParcel ();                                         // destructors? 

    virtual void addInsurance ();
    virtual void addRush ();

    virtual double getCost () const;
    virtual double getInsuranceCost () const;
    virtual double getRushCost () const;
    virtual double getTotalCost () const;
    virtual double getWeightCost () const;

    virtual void print (ostream& rcOut) const;
    virtual bool read (istream& rcIn);

    bool read (istream& rcIn);

  private:
    int mVolume;

};