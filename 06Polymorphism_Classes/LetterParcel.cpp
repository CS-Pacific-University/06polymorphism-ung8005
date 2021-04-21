//***************************************************************************
// File name:	 Parcel.cpp
// Author:		 Ashley Ung 
// Date:		   4/20/2021
// Class:		   CS 250
// Assignment:  
// Purpose:		  
//***************************************************************************

#include "LetterParcel.h"
#include <iostream>

//*************************************************************************** // need to work on constructor 
// Constructor:	LetterParcel                                                   // this class is mainly like the parentclass so do i even need it? 
//
// Description:	Call the Parcels default constructor 
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
LetterParcel::LetterParcel (int trackingNumber = 0, string sender = "", string reciever = "", // check intialized correctly and correct constructor 
  int weight = 0, int travelDistance = 0) : Parcels ()  { 
  mInsuranceCost = 0.45;
}
void LetterParcel::addInsurance () {
  const double letterInsuranceCost = 0.45; //caps
  cout << "$" << letterInsuranceCost << endl;
}

double LetterParcel::getTotalCost () const {
  double returnAmount; 
  if (getInsuranceStatus () && getRushedStatus ()) {              //protected 
    returnAmount = getRushCost () + getInsuranceCost () + getWeightCost ();
  }
  else if (getInsuranceStatus ()) {                             //protected
    returnAmount = getInsuranceCost () getWeightCost ();
  }
  else if (getRushedStatus ()) {
    returnAmount = getRushedCost + getWeightCost ();
  }
  else {
    returnAmount = getWeightCost ();
  }

double LetterParcel::getWeightCost () const {
  double const COST_PER_OUNCE = 0.45;
  return COST_PER_OUNCE * getWeight ();
}

double LetterParcel::getRushCost () const {
  return getTotalCost () * .10;                           //const
}
double LetterParcel::getInsuranceCost () const {
  return mInsuranceCost;
}


void addRush () {
  mbIsRush = true; 
}