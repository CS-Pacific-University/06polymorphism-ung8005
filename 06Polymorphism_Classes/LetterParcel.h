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
    LetterParcel (int trackingNumber, string sender, string reciever,       
                  int weight, int travelDistance);

    int getDeliveryDay () const override;                                  // can i put overide ?
    double getCost () const override;                                  // can i put overide ? also how come the uml did not show this function? should pures be in all subclasses?

    virtual double setInsurance (bool mbIsInsured);
    virtual double setRush (bool mbIsRushed);

    virtual bool read (istream& rcIn);
    virtual void print (ostream& rcOut) const;
};