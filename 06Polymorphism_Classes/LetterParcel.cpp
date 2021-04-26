//***************************************************************************
// File name:	 Parcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:		 Defines each of the function prototypes associated with the
//             child class LetterParcel.
//***************************************************************************

#include "LetterParcel.h"
#include <iostream>

LetterParcel::LetterParcel() : Parcel () {

}

//***************************************************************************
// Constructor:	LetterParcel 
//
// Description:	Call the Parcel constructor, set mInsurance equal to the  
//              given parameter. 
//
// Parameters:	
//
// Returned:		none
//***************************************************************************
LetterParcel::LetterParcel (int trackingNumber, std::string sender,             // what do i do for this constructor? what am i suppose to initialize? the protcted variables????
                            std::string reciever, int weight,
                            int travelDistance) :
                            Parcel (trackingNumber, sender, reciever,
                            weight, travelDistance) {
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
int LetterParcel::getDeliveryDay () const {
  const int MINIMUM_DAY = 1;
  const int RUSHED_DAY = 1;
  const int MILES_PER_DAY = 100;

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
// Description:	Returns the total cost of the letter parcel, after taking 
//              into account whether the letter is rushed, insured and the 
//              weight of the letter. 
//
// Parameters:	none
//
// Returned:		The total cost of the letter parcel. 
//***************************************************************************
double LetterParcel::getCost () const {
  double const COST_PER_OUNCE = 0.45;
  double const INSURANCE_COST = 0.45;
  double const TEN_PERCENT_CONVERSION = 1.1;

  double returnAmount = 0;

  returnAmount += COST_PER_OUNCE * mWeight;

  if (mbIsInsured) {
    returnAmount += INSURANCE_COST; 
  }

  if (mbIsRushed) {
    returnAmount *= TEN_PERCENT_CONVERSION;
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
void LetterParcel::setInsurance (bool insured) {                          // should i do an if state. to check?? like the function below? 
  mbIsInsured = insured; 
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
void LetterParcel::setRush (bool rushed) {
  mbIsRushed = rushed;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the LetterParcel to the stream if the read in data
//              is valid.
//
// Parameters:	rcIn - the stream to read from
//
// Returned:		True, if the LetterParcel is read in; else, false.
//***************************************************************************
bool LetterParcel::read (istream& rcIn) {
  bool bIsRead = Parcel::read (rcIn);

  if (rcIn >> mWeight >> mTravelDistance) {
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
// Description:	Print the LetterParcel to the stream.
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//***************************************************************************
void LetterParcel::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  if (mbIsInsured) {                                                      // order?
    rcOut << "INSURED\t";
  }

  if (mbIsRushed) {
    rcOut << "RUSHED\t";
  }
}