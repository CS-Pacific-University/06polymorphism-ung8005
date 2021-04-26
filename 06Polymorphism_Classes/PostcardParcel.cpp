//***************************************************************************
// File name:	 PostcardParcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:		 Defines each of the function prototypes associated with the
//             child class PostcardParcel. 
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
PostcardParcel::PostcardParcel () : Parcel () {
  mMessage = "";
}

//***************************************************************************
// Constructor:	PostcardParcel 
//
// Description:	Call the Parcel constructor, set mMessage equal to the
//              given parameter. 
//
// Parameters:	
//
// Returned:		none
//***************************************************************************
PostcardParcel::PostcardParcel (int trackingNumber, std::string sender,
                                std::string reciever, int weight,
                                int travelDistance, std::string message) :
                                Parcel (trackingNumber, sender, reciever,
                                weight, travelDistance) {
  mMessage = message;
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
  const int MINIMUM_DAY = 1;
  const int RUSHED_DAY = 2;
  const int MILES_PER_DAY = 10;

  int deliveryDay = MINIMUM_DAY;

  deliveryDay += getDistance () / MILES_PER_DAY;                        // check

  if (mbIsRushed && deliveryDay > MINIMUM_DAY) {
    deliveryDay -= RUSHED_DAY;
  }

  return deliveryDay;
}

//***************************************************************************
// Function:	  getCost
//
// Description:	Returns the total cost of the postcard parcel, after taking 
//              into account whether the postcard is rushed or insured. 
//
// Parameters:	none
//
// Returned:		The total cost of the postcard parcel. 
//***************************************************************************
double PostcardParcel::getCost () const {
  double const POSTCARD_COST = 0.15;
  double const INSURANCE_COST = 0.15;
  double const RUSH_COST = 0.25;

  double returnAmount = POSTCARD_COST;;

  if (mbIsInsured) {
    returnAmount += INSURANCE_COST;
  }

  if (mbIsRushed) {
    returnAmount += RUSH_COST;
  }

  return returnAmount;
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
void PostcardParcel::setInsurance (bool insured) {
  mbIsRushed = insured;
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
void PostcardParcel::setRush (bool rushed) {
  mbIsRushed = rushed;
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
  bool bIsRead = Parcel::read (rcIn);

  if (rcIn >> mWeight >> mTravelDistance >> mMessage) {
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
void PostcardParcel::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  if (mbIsInsured) {                                                      // order?
    rcOut << mMessage << "INSURED\t";
  }

  if (mbIsRushed) {
    rcOut << mMessage << "RUSHED\t";
  }
}