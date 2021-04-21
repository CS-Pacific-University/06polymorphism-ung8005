//***************************************************************************
// File name:	 OvernightPackageParcel.h
// Author:		 Ashley Ung
// Date:			 4/20/2021
// Class:			 CS 250
// Assignment: A subclass OvernightPackageParcel representing the information
//             for one overnight package parcel.
// Purpose:		 Defines each of the function prototypes associated with 
//             subclass OvernightPackageParcel.
//***************************************************************************

#pragma once 

#include "OvernightPackageParcel.h"
#include "Parcels.h"
#include <string>
#include <iostream>

using namespace std;

class OvernightPackageParcel : public Parcels {

public:
  OvernightPackageParcel ();
  OvernightPackageParcel (int trackingNumber, string sender, string reciever,
                          int weight, int travelDstance, int volume);

  virtual void addInsurance ();
  virtual void addRush ();
  virtual double getCost () const;

  virtual void print (std::ostream& rcOutStream) const;
  virtual bool read (istream& rcIn);


  bool read (istream& rcIn);

private:
  double mVolume;

};