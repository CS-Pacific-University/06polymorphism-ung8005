//***************************************************************************
// File name:	 PostcardParcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: Demonstrates inheritance. This is a subclass PostcardParcel 
//             that represents the information for one postcard parcel. 
// Purpose:		 Declares a programmer-defined subclass PostcardParcel for a
//             parcel. 
//***************************************************************************

#include "PostcardParcel.h"
#include <iostream>

//***************************************************************************
// Constructor:	PostcardParcel 
//
// Description:	Call the PostcardParcel default constructor, set mMessage to  
//              an empty string.
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
PostcardParcel::PostcardParcel () : Parcels () {
  mMessage = "";
}

//***************************************************************************
// Constructor:	PostcardParcel 
//
// Description:	Call the Parcels constructor, set mMessage equal to the
//              given parameter. 
//
// Parameters:	
//
// Returned:		none
//***************************************************************************
PostcardParcel::PostcardParcel (int trackingNumber, std::string sender,
                                std::string reciever, int weight,
                                int travelDistance, std::string message) :
                                Parcels (trackingNumber, sender, reciever,
                                weight, travelDistance) {
  mMessage = message;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the PostcardParcel to the stream if the read in data
//              is valid. 
//
// Parameters:	rcIn - the stream to read from 
//
// Returned:		True, if the PostcardParcel volume is read in; else, false. 
//***************************************************************************
bool PostcardParcel::read (istream& rcIn) {
  bool bIsRead = Parcels::read (rcIn);

  if (rcIn >> mMessage) {
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
// Description:	Print the PostcardParcel to the stream.
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//***************************************************************************
//void PostcardParcel::print (ostream& rcOut) const {
//
//  Parcels::print (rcOut);
//
//  rcOut << mMessage; 
//}
