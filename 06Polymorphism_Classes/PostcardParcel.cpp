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
// Parameters:	trackingNumber    - the tracking number to store  
//							sender            - parcel's sender  
//              reciever          - parcel's reciever 
//              weight            - parcel's weight 
//              travelDistance    - distance package will travel  
//              message           - message on the postcard
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

  deliveryDay += mTravelDistance / MILES_PER_DAY;                        // check

  if (mbIsRushed && deliveryDay > MINIMUM_DAY) {
    deliveryDay -= RUSHED_DAY;
  }

  return deliveryDay;
}

//***************************************************************************
// Function:	  getInsuranceCost
//
// Description:	Obtains the insurance cost if the postcard is insured. The 
//              insurance cost is $0.15.  
//
// Parameters:	none
//
// Returned:		The cost of the insurance. 
//***************************************************************************
double PostcardParcel::getInsuranceCost () {
  double const INSURANCE_COST = 0.15;
  double cost = 0;

  if (mbIsInsured) {
    cost = INSURANCE_COST;
  }
  return cost;
}

//***************************************************************************
// Function:	  getRushCost
//
// Description:	Obtains the rush cost if the postcard is rushed. The rush 
//              cost is $0.25. 
//
// Parameters:	none
//
// Returned:		The rush cost for the postcard. 
//***************************************************************************
double PostcardParcel::getRushCost () {
  const double RUSH_COST = 0.25;
  double cost = 0;
  if (mbIsRushed) {
    cost = RUSH_COST;
  }
  return cost;
}

//***************************************************************************
// Function:	  getParcelCost
//
// Description:	Obtains the cost of the Parcel. The cost of a postcard is 
//              $0.15 regardless of the postcard's weight. 
//
// Parameters:	none
//
// Returned:		The cost of the postcard. 
//***************************************************************************
double PostcardParcel::getParcelCost () {
  double const POSTCARD_COST = 0.15;
  return POSTCARD_COST;
}

//***************************************************************************
// Function:	  getCost
//
// Description:	Returns the total cost of the postcard parcel, after taking 
//              into account whether the postcard is rushed or insured. If 
//              rushed, the rush price is added, if insured, then the 
//              insurance price is added to the cost. 
//
// Parameters:	none
//
// Returned:		The total cost of the postcard parcel. 
//***************************************************************************
double PostcardParcel::getCost () {
  return getInsuranceCost () + getRushCost () + getParcelCost ();
}

//***************************************************************************
// Function:	  setInsurance 
//
// Description:	If the parcel is insured, the default bool for mbIsInsured is 
//              reassigned with "true". 
//
// Parameters:	none
//
// Returned:		none 
//***************************************************************************
void PostcardParcel::setInsurance () {
  mbIsInsured = true;
}

//***************************************************************************
// Function:	  setRush
//
// Description:	If the parcel is rushed, the default bool for mbIsRushed is 
//              reassigned with "true". 
//
// Parameters:	none 
//
// Returned:		none 
//***************************************************************************
void PostcardParcel::setRush () {
  mbIsRushed = true;
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
bool PostcardParcel::read (istream &rcIn) {
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
void PostcardParcel::print (ostream &rcOut) const {

  Parcel::print (rcOut);

  rcOut << mMessage; 

  if (mbIsInsured) {
    rcOut << "INSURED\t";
  }

  if (mbIsRushed) {
    rcOut << "RUSH\t";
  }
}