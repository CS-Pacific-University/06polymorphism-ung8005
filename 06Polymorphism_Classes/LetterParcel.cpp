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
  double returnAmount;

  if (mbIsInsured && mbIsRushed) {
    returnAmount = mbIsInsured + mbIsRushed + getWeightCost ();             // should i call the function or just be using the mbIs... 
  }
  else if (mbIsInsured) {
    returnAmount = mbIsInsured + getWeightCost ();
  }
  else if (mbIsRushed) {
    returnAmount = getRushCost (mbIsRushed) + getWeightCost ();
  }
  else {
    returnAmount = getWeightCost ();
  }
  return returnAmount;
}

// weight cost
//double LetterParcel::getWeightCost () const {
//  double const COST_PER_OUNCE = 0.45;
//  return COST_PER_OUNCE * getWeightCost ();
//}

//***************************************************************************
// Function:	  setInsurance 
//
// Description:	 
//
// Parameters:	
//
// Returned:		 
//***************************************************************************
double LetterParcel::setInsurance (bool mbIsInsured) {                          // should i do an if state. to check?? like the function below? 
  const double INSURANCE_COST = 0.45;
  mbIsInsured = INSURANCE_COST;
  return mbIsInsured;
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
double LetterParcel::setRush (bool mbIsRushed) {                              // is this correct? 
  const double TEN_PERCENT_CONVERSION = 0.10;
  double rushCost; 
  if (mbIsRushed) {
    rushCost = getCost () * TEN_PERCENT_CONVERSION;
    mbIsRushed = true;
  }
  else {
    mbIsRushed = false; 
  }
  return mbIsRushed; 
}

/***************************************************************************
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

  if (rcIn >>  ???????) {
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

  rcOut << ??????;
}
