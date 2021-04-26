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

class Parcel {
  public:  
    Parcel (int trackingNumber = 0, string sender = "", string reciever = "",   
            int weight = 0, int travelDistance = 0);

    int getWeight () const; 
    int getDistance () const;    
    bool getInsured () const;  
    bool getRushed () const; 
    int getTID () const; 

    void setCost (double);             
  
    virtual bool read (istream& rcIn);
    virtual void print (ostream& rcOut) const;

    virtual int getDeliveryDay () const = 0;
    virtual double getCost () const = 0;

  protected : 
    int mWeight;
    int mTravelDistance;
    bool mbIsInsured;
    bool mbIsRushed;
    bool mbIsDelivered; 

  private:
    string mSenderAddress;
    string mRecieverAddress;
    int mTrackingNumber;  
    double mCost; 
};

