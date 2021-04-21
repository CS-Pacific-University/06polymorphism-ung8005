//***************************************************************************
// File name:	 OvernightPackageParcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: Demonstrates inheritance. This is a subclass 
//             OvernightPackageParcel that represents the information for one 
//             overnight package parcel.
// Purpose:		 Declares a programmer-defined subclass OvernightPackageParcel 
//             for a parcel. 
//***************************************************************************

#include "OvernightPackageParcel.h"
#include <iostream>

//***************************************************************************
// Constructor:	OvernightPackageParcel
//
// Description:	Call the OvernightPackageParcel default constructor, set   
//              mVolume to zero.  
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
OvernightPackageParcel::OvernightPackageParcel () : Parcels () {
  mVolume = 0;
}

//***************************************************************************
// Constructor:	OvernightPackageParcel
//
// Description:	Call the Parcels constructor, set mVolume equal to the given 
//              parameter. 
//
// Parameters:	
//
// Returned:		none
//***************************************************************************
OvernightPackageParcel::OvernightPackageParcel(int trackingNumber, std::string sender,    //space parathesis 
  std::string reciever, int weight,
  int travelDistance, int volume) :
  Parcels (trackingNumber, sender, reciever,
    weight, travelDistance) {
  mVolume = volume; 
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the OvernightPackageParcel to the stream if the read in data
//              is valid. 
//
// Parameters:	rcIn - the stream to read from 
//
// Returned:		True, if the OvernightPackageParcel volume is read in; else, false. 
//***************************************************************************
bool OvernightPackageParcel::read (istream& rcIn) {
  bool bIsRead = Parcels::read (rcIn);

  if (rcIn >> mVolume) {
    bIsRead = true;
  }
  else {
    bIsRead = false;
  }
  return bIsRead;
}

//***************************************************************************
// Function:	  print
//
// Description:	Print the OvernightPackageParcel to the stream.
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//***************************************************************************
//void OvernightPackageParcel::print (ostream& rcOut) const {
//
//  Parcels::print (rcOut);
//
//  rcOut << mVolume;
//}

