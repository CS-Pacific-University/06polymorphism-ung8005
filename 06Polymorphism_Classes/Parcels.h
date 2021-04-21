//***************************************************************************
// File name:	 Parcels.h
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment:  
// Purpose:		 
//***************************************************************************

#pragma once

#include <iostream>

using namespace std;

class Parcels {
  public:                                                                       //check
    Parcels (int trackingNumber = 0, string sender = "", string reciever = "", // check intialized correctly and correct constructor 
             int weight = 0, int travelDistance = 0);

    virtual void addInsurance ();
    virtual void addRush ();
    virtual double getCost () const = 0;
   double getWeight () const;                                // protected 
   double getInsuranceStatus () const;                    //protected
   double getRushedStatus () const;                       //protected
  
    virtual void print (std::ostream& rcOutStream) const;
    virtual bool read (istream& rcIn);

  private:
    int mTrackingNumber; 
    string mSenderAddress; 
    string mRecieverAddress;
    int mWeightInOunces; 
    int mTravelDistance;  
    bool mbIsInsured; 
    bool mbIsRushed; 
};

