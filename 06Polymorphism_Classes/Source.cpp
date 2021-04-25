//***************************************************************************
// File name:	 main.cpp
// Author:		 Ashley Ung
// Date:			 4/20/2021
// Class:			 CS 250
// Assignment: A class hierarchy to demonstrate the use of polymorphism, 
//             virtual functions, and dynamic memory. 
// Purpose:		 Driver used to read various mail parcels from a data file and 
//             allows the user to view the parcels, add insurance, rush 
//             delivery, or deliver any parcel. 
// Hours:		   5  
// Computer:	 WindowsOS
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LetterParcel.h"
#include "PostcardParcel.h"
#include "OvernightPackageParcel.h"

using namespace std;

bool openFileForRead (ifstream& rcInFile, string fileName);
void printMenuHeading ();

/****************************************************************************
Function:		  main

Description:	The main driver for Parcel using Classes to show how each 
              member function in Parcel can be used.

Parameters:		none

Returned:			exit status
****************************************************************************/
int main() {
  const string INPUT_FILE = "parcels.txt";
  const int MAX_PARCEL = 25;
  const int PRINT_ALL = 1; 
  const int ADD_INSURANCE = 2; 
  const int ADD_RUSH = 3; 
  const int DELIVER = 4;
  const int QUIT = 5; 
  char const LETTER = 'L';
  char const POSTCARD = 'P';
  char const OVERNIGHT_PACKAGE = 'O';

  Parcel* apcParcel[MAX_PARCEL] = { nullptr }; 
  int numParcels = 0;
  char parcelType;
  int choice;

  ifstream inFile; 

  //if (openFileForRead (inFile, INPUT_FILE)) {                             // not sure what to do here 
  //  while (!inFile.eof ()) {
  //  }
  //}

  cout << "Mail Simulator!"; 

  do {
    printMenuHeading ();
    cout << endl << "Choice> ";
    cin >> choice;
    cout << endl;
  } while (!(PRINT_ALL == choice || ADD_INSURANCE == choice
           || ADD_RUSH == choice || DELIVER == choice || QUIT == choice)); 

  while (inFile >> parcelType) {
    switch (parcelType) {
      case LETTER: 
        apcParcel[numParcels] = new LetterParcel; 
        apcParcel[numParcels]->read (inFile);                             // makethis into a function an the ones belwo iy oo 
        numParcels++;
        break; 
      case POSTCARD:
        apcParcel[numParcels] = new PostcardParcel;                      // makethis into a function a
        apcParcel[numParcels]->read (inFile); 
        numParcels++;
        break; 
      case OVERNIGHT_PACKAGE:
        apcParcel[numParcels] = new OvernightPackageParcel;              // makethis into a function a
        apcParcel[numParcels]->read (inFile);
        numParcels++;
        break;
      default :
        break; 
    }
  }

  return EXIT_SUCCESS;
}

/****************************************************************************
Function:     openFileForRead

Description:  Checks if the file is open, if the file is not open, the
              program will return false, else, true.

Parameters:   inFile   - reading in the file stream
              fileName - the name of the file

Returned:			True if the file is open; else, false.
****************************************************************************/
bool openFileForRead (ifstream& rcInFile, string fileName) {
  bool bIsOpen = true;

  rcInFile.open (fileName);

  if (!rcInFile.is_open ()) {
    cout << "Error opening file.";
    bIsOpen = false;
  }
  return bIsOpen;
}

/****************************************************************************
Function:    printMenuHeading

Description: Prints the possible menu selections.

Parameters:  none

Returned:		 none
****************************************************************************/
void printMenuHeading () {
  const string OPTION_PRINT_ALL = "1. Print All";
  const string OPTION_ADD_INSURANCE = "2. Add Insurance";
  const string OPTION_ADD_RUSH = "3. Add Rush";
  const string OPTION_DELIVER = "4. Deliver";
  const string OPTION_QUIT = "5. Quit"; 

  cout << OPTION_PRINT_ALL << endl << OPTION_ADD_INSURANCE << endl
       << OPTION_ADD_RUSH << endl << OPTION_DELIVER << OPTION_QUIT << endl;
}