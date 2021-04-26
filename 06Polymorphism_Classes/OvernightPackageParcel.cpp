//***************************************************************************
// File name:	 OvernightPackageParcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment: A class hierarchy on mail services demonstrating the use of 
//             polymorphism, virtual functions, and dynamic memory.
// Purpose:		 Defines each of the function prototypes associated with the
//             child class OvernightPackageParcel.
//***************************************************************************

#include "OvernightPackageParcel.h"
#include <iostream>

//***************************************************************************
// Constructor:	OvernightPackageParcel
//
// Description:	Call the OvernightPackageParcel default constructor, set   
//              mVolume to zero.  
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
OvernightPackageParcel::OvernightPackageParcel () : Parcel () {
  mVolume = 0;
}

//***************************************************************************
// Constructor:	OvernightPackageParcel
//
// Description:	Call the Parcels constructor, set mVolume equal to the given 
//              parameter. 
//
// Parameters:	
//
// Returned:		none
//***************************************************************************
OvernightPackageParcel::OvernightPackageParcel (int trackingNumber,           // check coding standards 
                                                std::string sender,     
                                                std::string reciever, 
                                                int weight, 
                                                int travelDistance, 
                                                int volume) : 
                                                Parcel (trackingNumber, 
                                                        sender, reciever,
                                                        weight, 
                                                        travelDistance) {
  mVolume = volume; 
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
int OvernightPackageParcel::getDeliveryDay () const {
  const int RUSHED_DELIVERY_DAY = 1;
  const int ONE_DAY = 1; 
  const int TWO_DAYS = 2;
  const int LONG_DISTANCE_MILES = 1000;

  int deliveryDay; 

  if (mbIsRushed) {
    deliveryDay = RUSHED_DELIVERY_DAY;
  }
  else if (mTravelDistance <= LONG_DISTANCE_MILES) {
    deliveryDay = ONE_DAY;
  }
  else {
    deliveryDay = TWO_DAYS;
  }

  return deliveryDay;
}

//***************************************************************************
// Function:	  getCost
//
// Description:	
//
// Parameters:	none
//
// Returned:		The total cost of the overnight package parcel. 
//***************************************************************************
double OvernightPackageParcel::getCost () const {
  const int HIGH_VOLUME = 100;
  const int HIGH_VOLUME_COST = 20; 
  const int LOW_VOLUME_COST = 12; 
  const double INSURANCE_RATE = 1.25;
  const double RUSH_RATE = 1.75;

  double returnAmount = 0;

  if (mVolume > HIGH_VOLUME) {
    returnAmount = HIGH_VOLUME_COST;
  }
  else {
    returnAmount = LOW_VOLUME_COST;
  }

  if (mbIsInsured) {
    returnAmount *= INSURANCE_RATE;
  }

  if (mbIsRushed) {
    returnAmount *= RUSH_RATE; 
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
void OvernightPackageParcel::setInsurance (bool insured) {             
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
void OvernightPackageParcel::setRush (bool rushed) {
  mbIsRushed = rushed;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the OvernightPackageParcel to the stream if the read 
//              in data is valid. 
//
// Parameters:	rcIn - the stream to read from 
//
// Returned:		True, if the OvernightPackageParcel volume is read in; else, 
//              false. 
//***************************************************************************
bool OvernightPackageParcel::read (istream& rcIn) {
  bool bIsRead = Parcel::read (rcIn);

  if (rcIn >> mWeight >> mTravelDistance >> mVolume) {
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
// Description:	Print the OvernightPackageParcel to the stream.
//
// Parameters:	rcOut - the stream to print to
//
// Returned:	  none
//***************************************************************************
void OvernightPackageParcel::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  if (mbIsInsured) {                                                      // order?
    rcOut << "OVERNIGHT\t" << "INSURED\t";
  }

  if (mbIsRushed) {
    rcOut << "OVERNIGHT\t" <<"RUSHED\t";
  }
}