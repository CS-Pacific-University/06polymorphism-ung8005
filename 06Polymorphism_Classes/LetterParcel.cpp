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
// Description:	Call the LetterParcel default constructor, set mInsuranceCost  
//              to the insurance cost of a letter, 0.45.   
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
LetterParcel::LetterParcel () : Parcel () { 
  mInsuranceCost = 0.45;                                                      // intialize to zero or 0.45??? 
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
LetterParcel::LetterParcel (int trackingNumber, std::string sender,
                            std::string reciever, int weight,
                            int travelDistance, double insuranceCost) :
                            Parcel (trackingNumber, sender, reciever,
                            weight, travelDistance) {
  mInsuranceCost = insuranceCost;
}

//***************************************************************************
// Function:	  addInsurance 
//
// Description:	 
//
// Parameters:	none
//
// Returned:		 
//***************************************************************************
void LetterParcel::addInsurance () {
  const double INSURANCE_COST = 0.45;
  cout << "$" << INSURANCE_COST << endl;
}

//***************************************************************************
// Function:	  addRushed
//
// Description:	 
//
// Parameters:	none
//
// Returned:		 
//***************************************************************************
void addRush () {
  mbIsRush = true;
}

//***************************************************************************
// Function:	  getTotalCost
//
// Description:	Returns the total cost of the letter parcel, after taking 
//              into account whether the letter is rushed, insured and the 
//              weight of the letter. 
//
// Parameters:	none
//
// Returned:		The total cost of the letter parcel. 
//***************************************************************************
double LetterParcel::getTotalCost () const {
  double returnAmount;
  if (getInsuranceStatus () && getRushedStatus ()) {                    //protected 
    returnAmount = getRushCost () + getInsuranceCost () + getWeightCost ();
  }
  else if (getInsuranceStatus ()) {                                    //protected
    returnAmount = getInsuranceCost () + getWeightCost ();
  }
  else if (getRushedStatus ()) {
    returnAmount = getRushCost () + getWeightCost ();
  }
  else {
    returnAmount = getWeightCost ();
  }
}

//***************************************************************************
// Function:	  getWeightCost
//
// Description:	Returns the cost of the letter regarding how heavy it is. 
//              Each letter costs $0.45 per ounce. 
//
// Parameters:	none
//
// Returned:		The cost of the letter based on it's weight.  
//***************************************************************************
double LetterParcel::getWeightCost () const {
  double const COST_PER_OUNCE = 0.45;
  return COST_PER_OUNCE * getWeightCost ();
}

//***************************************************************************
// Function:	  getRushCost
//
// Description:	Returns the cost of the letter if it is rushed. If the letter
//              is rushed, there is an extra 10% charge added to the current 
//              cost. 
//              
// Parameters:	none
//
// Returned:		The cost of the letter based on an additional rushed price. 
//***************************************************************************
double LetterParcel::getRushCost () const {
  const int TEN_PERCENT_CONVERSION = 0.10;
  return getTotalCost () * TEN_PERCENT_CONVERSION;                    
}

//***************************************************************************
// Function:	  getInsuranceCost
//
// Description:	Returns the cost of the letter if it has an insurance. If the
//              letter has insuranced, the insurance cost for a letter is 
//              $0.45.
//
// Parameters:	none
//
// Returned:		The total cost of the letter parcel. 
//***************************************************************************
double LetterParcel::getInsuranceCost () const {
  return mInsuranceCost;
}