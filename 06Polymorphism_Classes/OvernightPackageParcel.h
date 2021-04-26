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

    int getDeliveryDay () const override;                                  // can i put overide ?
    double getCost () const override;                                  // can i put overide ? also how come the uml did not show this function? should pures be in all subclasses?

    virtual void setInsurance (bool insured);
    virtual void setRush (bool rushed);

    virtual bool read (istream& rcIn);
    virtual void print (ostream& rcOut) const;

  private:
    int mVolume;

};