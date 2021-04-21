//***************************************************************************
// File name:	 LetterParcel.h
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment:  
//***************************************************************************

#pragma once

#include "Parcels.h"
#include <string>
#include <iostream>

using namespace std;

class LetterParcel : public Parcels {
  public:
    LetterParcel (int trackingNumber = 0, string sender = "", string reciever = "", // check intialized correctly and correct constructor 
      int weight = 0, int travelDistance = 0);

    virtual void addInsurance ();
    virtual void addRush ();


    virtual double getInsuranceCost () const; 
    virtual double getRushCost () const;
    virtual double getTotalCost () const; 
    virtual double getWeightCost () const;


    virtual void print (std::ostream& rcOutStream) const;
    virtual bool read (istream& rcIn);

  private:
    double mInsuranceCost; 

};