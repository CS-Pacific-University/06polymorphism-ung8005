//***************************************************************************
// File name:	 Parcels.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment:  
// Purpose:		  
//***************************************************************************

#include "Parcels.h"
#include <iostream>
#include <string>

//***************************************************************************
// Constructor:	Parcels 
//
// Description:	Initialize the to and from address, weight, and travel 
//              distance with the parameters. 
//
// Parameters:	trackingNumber    - the tracking number to store  
//							senderAndReciever - parcel's sender and reciever address
//              weight            - parcel's weight in ounces 
//              travelDistance    - distance package will travel  
//
// Returned:		none
//***************************************************************************
Parcels::Parcels (int trackingNumber, std::string sender, 
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
// Parameters:	rcOutput - the stream to output to 
//
// Returned:		ostream - the output stream
//***************************************************************************
void Parcels::print (std::ostream& rcOutStream) const {
  rcOutStream << "TID: " << mTrackingNumber << " From: " << mSenderAddress 
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
// Returned:		True, if the Parcel TID, to and from address is read in; else, 
//              false. 
//***************************************************************************
bool Parcels::read (istream& rcIn) {
  bool bIsRead = true;
  if (rcIn >> mTrackingNumber >> mSenderAddress >> mRecieverAddress) {
    bIsRead = true;
  }
  else {
    bIsRead = false;
  }
  return bIsRead;
}



void Parcels::addInsurance () {
  mbIsInsured = true;
}

void Parcels::addRush() {
  mbIsRushed = true;
}

double Parcels::getWeight () const {
  return mWeightInOunces;
}

double Parcels::getInsuranceStatus () const {
  return mbIsInsured; 
}

double Parcels::getRushedStatus () const {
  return mbIsRushed; 
}