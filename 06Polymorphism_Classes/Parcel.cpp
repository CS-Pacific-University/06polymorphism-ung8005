//***************************************************************************
// File name:	 Parcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory. 
// Purpose:		 Defines each of the function prototypes associated with the
//             parent class Parcel.
//***************************************************************************

#include "Parcel.h"
#include <iostream>
#include <string>

//***************************************************************************   // do this hear or in .h file? 
// Constructor:	Parcel
//
// Description:	Initialize the to and from to an empty string, the weight, 
//              tracking number, and travel distance to zero. 
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
//Parcel::Parcel () : Parcel () {
//  int mTrackingNumber = 0; 
//  string mSenderAddress = "";
//  string mRecieverAddress = ""; 
//  int mWeightInOunces = 0; 
//  int mTravelDistance = 0;
//
//}

//***************************************************************************
// Constructor:	Parcel
//
// Description:	Initialize the to and from address, weight, and travel 
//              distance equal to the given parameters.  
//
// Parameters:	trackingNumber    - the tracking number to store  
//							senderAndReciever - parcel's sender and reciever address
//              weight            - parcel's weight in ounces 
//              travelDistance    - distance package will travel  
//
// Returned:		none
//***************************************************************************
Parcel::Parcel (int trackingNumber, std::string sender, 
                std::string reciever, int weight, int travelDistance) {
  mTrackingNumber = trackingNumber;
  mSenderAddress = sender; 
  mRecieverAddress = reciever;
  mWeightInOunces = weight;
  mTravelDistance = travelDistance; 
}

//***************************************************************************
// Function:	  print
//
// Description:	Output the Parcel to the stream
//
// Parameters:	rcOut   - the stream to output to 
//
// Returned:		ostream - the output stream
//***************************************************************************
void Parcel::print (std::ostream& rcOut) const {
  rcOut << "TID: " << mTrackingNumber << " From: " << mSenderAddress 
        << " To: " << mRecieverAddress;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Parcel to the stream if the read in data is 
//              valid. 
//
// Parameters:	rcIn - the stream to read from 
//
// Returned:		True, if the Parcel TID, to and from address is read in; 
//              else, false. 
//***************************************************************************
bool Parcel::read (istream& rcIn) {
  bool bIsRead = true;
  if (rcIn >> mTrackingNumber >> mSenderAddress >> mRecieverAddress) {
    bIsRead = true;
  }
  else {
    bIsRead = false;
  }
  return bIsRead;
}

//***************************************************************************
// Function:	  addInsurance 
//
// Description:	
//
// Parameters:	 
//
// Returned:		 
//***************************************************************************
void Parcel::addInsurance () {
  mbIsInsured = true;
}

//***************************************************************************
// Function:	  addRush
//
// Description:	 
//
// Parameters:	 
//
// Returned:		 
//***************************************************************************
void Parcel::addRush() {
  mbIsRushed = true;
}

//***************************************************************************
// Function:	  getWeight 
//
// Description:	Returns the value of the weight. 
//
// Parameters:	none
//
// Returned:		The weight in ounces. 
//***************************************************************************
double Parcel::getWeight () const {
  return mWeightInOunces;
}

//***************************************************************************
// Function:	  getInsuranceStatus
//
// Description:	Returns whether the parcel has insurance or not. 
//
// Parameters:	none
//
// Returned:		The status of the parcel, if it is insured or not. 
//***************************************************************************
double Parcel::getInsuranceStatus () const {
  return mbIsInsured; 
}

//***************************************************************************
// Function:	  getRushedStatus 
//
// Description:	Returns whether the parcel is rushed or not 
//
// Parameters:	none
//
// Returned:		The status of the parcel, if it is rushed or not. 
//***************************************************************************
double Parcel::getRushedStatus () const {
  return mbIsRushed; 
}