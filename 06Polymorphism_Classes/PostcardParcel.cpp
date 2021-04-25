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
  const double POSTCARD_COST = 0.15;
  double returnAmount;

  if (mbIsInsured && mbIsRushed) {
    returnAmount = setInsurance () + setRush () + POSTCARD_COST;             // should i call the function or just be using the mbIs... 
  }
  else if (mbIsInsured) {
    returnAmount = mbIsInsured + POSTCARD_COST;
  }
  else if (mbIsRushed) {
    returnAmount = setRush (mbIsRushed) + POSTCARD_COST;
  }
  else {
    returnAmount = POSTCARD_COST;
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
double PostcardParcel::setInsurance (bool mbIsInsured) {                          // should i do an if state. to check?? like the function below? 
  const double INSURANCE_COST = 0.15;
  double insuranceCost; 

  if (mbIsInsured) {
    insuranceCost = getCost () + INSURANCE_COST;                                // am i allowed to do this? 
    mbIsInsured = true;
  }
  else {
    mbIsInsured = false; 
  }
  return insuranceCost;
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
double PostcardParcel::setRush (bool mbIsRushed) {                              // is this correct? i feel like im doing two things at once 
  const double RUSH_COST = 0.25;
  double rushCost;

  if (mbIsRushed) {
    rushCost = getCost () + RUSH_COST;
    mbIsRushed = true;
  }
  else {
    mbIsRushed = false;
  }
  return rushCost;
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
void PostcardParcel::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << mMessage; 
}
