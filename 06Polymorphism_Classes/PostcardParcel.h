//***************************************************************************
// File name:	 PostcardParcel.h
// Author:		 Ashley Ung
// Date:			 4/20/2021
// Class:			 CS 250
// Assignment: A subclass PostcardParcel representing the information for 
//             one postcard parcel.
// Purpose:		 Defines each of the function prototypes associated with 
//             subclass PostcardParcel.  
//***************************************************************************

#pragma once 

#include "PostcardParcel.h"
#include "Parcels.h"
#include <string>
#include <iostream>

using namespace std;

class PostcardParcel : public Parcels {

public:
  PostcardParcel ();
  PostcardParcel (int trackingNumber, string sender, string reciever,
                  int weight, int travelDstance, string message);

  //virtual void addInsurance ();
  //virtual void addRush ();
  //virtual double getCost () const;

  //virtual void print (std::ostream& rcOutStream) const;
  //virtual bool read (istream& rcIn);


private:
  string mMessage;

};