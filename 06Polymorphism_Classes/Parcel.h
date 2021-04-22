//***************************************************************************
// File name:	 Parcel.h
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory. 
// Purpose:		 Declares a programmer-defined parent class Parcel representing 
//             information for one mail parcel. 
//***************************************************************************

#pragma once

#include <iostream>

using namespace std;

class Parcels {
  public:  
                                                                      // 2 constructors? 
    //Parcel ();
    Parcel (int trackingNumber = 0, string sender = "", string reciever = "",   // check intialized correctly and correct constructor 
            int weight = 0, int travelDistance = 0);
    //~Parcel ();                                                                 // are we using destructors?  

    virtual void addInsurance ();
    virtual void addRush ();

    virtual double getCost () const = 0;                    //pure virtual function 
    double getWeight () const;                             // protected 
    double getInsuranceStatus () const;                    // protected
    double getRushedStatus () const;                       // protected
  
    virtual void print (std::ostream& rcOut) const;
    virtual bool read (istream& rcIn);

  private:
    string mSenderAddress;
    string mRecieverAddress;
    int mTrackingNumber; 
    int mWeightInOunces; 
    int mTravelDistance;  
    bool mbIsInsured; 
    bool mbIsRushed; 
};

