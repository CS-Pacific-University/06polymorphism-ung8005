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
                std::string reciever, int weight, int travelDistance) {       //initialize protected in constructrs? 
  mTrackingNumber = trackingNumber;
  mSenderAddress = sender; 
  mRecieverAddress = reciever;
  mWeight = weight;
  mTravelDistance = travelDistance; 
}

//***************************************************************************
// Function:	  getWeight 
//
// Description:	Retrieve the weight of the parcel.
//
// Parameters:	none 
//
// Returned:		The weight of the parcel. 
//***************************************************************************
int Parcel::getWeight () const {
  return mWeight; 
}

//***************************************************************************
// Function:	  getDistance
//
// Description: Retrieve the travel distance of the parcel. 
//
// Parameters:	none
//
// Returned:		The distance of the parcel.
//***************************************************************************
int Parcel::getDistance () const {
  return mTravelDistance;
}

//***************************************************************************
// Function:	 
//
// Description:	
//
// Parameters:	 
//
// Returned:		 
//***************************************************************************
bool Parcel::getInsured () const {
  return mbIsInsured;                                                         // is this correct?? 
}

//***************************************************************************
// Function:	 
//
// Description:	
//
// Parameters:	 
//
// Returned:		 
//***************************************************************************
bool Parcel::getRushed () const {
  return mbIsRushed;                                                          // is this correct? 
}

//***************************************************************************
// Function:	  getTID
//
// Description:	Retrieve the tracking ID number of the parcel. 
//
// Parameters:	none 
//
// Returned:		The tracking ID number of the parcel. 
//***************************************************************************
int Parcel::getTID () const {
  return mTrackingNumber;
}

//***************************************************************************
// Function:	 
//
// Description:	
//
// Parameters:	 
//
// Returned:		 
//***************************************************************************
void Parcel::setCost (double) {
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