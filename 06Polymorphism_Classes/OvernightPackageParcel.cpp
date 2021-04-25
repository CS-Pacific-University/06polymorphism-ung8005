//***************************************************************************
// File name:	 OvernightPackageParcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:		 Defines each of the function prototypes associated with the
//             child class OvernightPackageParcel.
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
OvernightPackageParcel::OvernightPackageParcel () : Parcel () {
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
OvernightPackageParcel::OvernightPackageParcel (int trackingNumber,           // check coding standards 
                                                std::string sender,     
                                                std::string reciever, 
                                                int weight, 
                                                int travelDistance, 
                                                int volume) : 
                                                Parcel (trackingNumber, 
                                                        sender, reciever,
                                                        weight, 
                                                        travelDistance) {
  mVolume = volume; 
}

//***************************************************************************
// Function:	  getDeliveryDay
//
// Description:	
//
// Parameters:	none
//
// Returned:		
//***************************************************************************
int PostcardParcel::getDeliveryDay () const {
}

//***************************************************************************
// Function:	  getCost
//
// Description:	
//
// Parameters:	none
//
// Returned:		The total cost of the overnight package parcel. 
//***************************************************************************
double OvernightPackageParcel::getCost () const {
}

//***************************************************************************
// Function:	  setInsurance 
//
// Description:	 
//
// Parameters:	
//
// Returned:		 
//***************************************************************************
double OvernightPackageParcel::setInsurance (bool mbIsInsured) {
}

//***************************************************************************
// Function:	  setRush
//
// Description:	 
//
// Parameters:	
//
// Returned:		
//***************************************************************************
double OvernightPackageParcel::setRush (bool mbIsRushed) {                  
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the OvernightPackageParcel to the stream if the read 
//              in data is valid. 
//
// Parameters:	rcIn - the stream to read from 
//
// Returned:		True, if the OvernightPackageParcel volume is read in; else, 
//              false. 
//***************************************************************************
bool OvernightPackageParcel::read (istream& rcIn) {
  bool bIsRead = Parcel::read (rcIn);

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
void OvernightPackageParcel::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << mVolume;
}

