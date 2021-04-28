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
// Hours:		   14 
// Computer:	 WindowsOS
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LetterParcel.h"
#include "PostcardParcel.h"
#include "OvernightPackageParcel.h"

using namespace std;

bool openFileForRead (ifstream &rcInFile, string fileName);
void printMenuHeading ();
void populatingArray (Parcel* apcParcel[], int &numParcels, 
                      ifstream &inFile);
void printAll (Parcel* apcParcel[], int& numParcels);
void addInsurance (Parcel* apcParcel[], int& numParcels);
void addRush (Parcel* apcParcel[], int& numParcels);

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

  Parcel *apcParcel[MAX_PARCEL] = { nullptr }; 
  int numParcels = 0;
  char parcelType;
  int choice;
  int TID; 

  ifstream inFile; 

  openFileForRead (inFile, INPUT_FILE);

  cout << "Mail Simulator!" << endl; 

  while (inFile >> parcelType) { 
    switch (parcelType) {
      case LETTER: 
        apcParcel[numParcels] = new LetterParcel; 
        populatingArray (apcParcel, numParcels, inFile);
        break; 

      case POSTCARD:
        apcParcel[numParcels] = new PostcardParcel;
        populatingArray (apcParcel, numParcels, inFile);
        break; 

      case OVERNIGHT_PACKAGE:
        apcParcel[numParcels] = new OvernightPackageParcel;
        populatingArray (apcParcel, numParcels, inFile);
        break;

      default :
        break; 
    }
  }

  do {

    do {
      printMenuHeading ();
      cout << endl << "Choice> ";
      cin >> choice;
    } while (!(PRINT_ALL == choice || ADD_INSURANCE == choice
             || ADD_RUSH == choice || DELIVER == choice || QUIT == choice));

    switch (choice) {
      case PRINT_ALL:
        printAll (apcParcel, numParcels);
        break;

      case ADD_INSURANCE:
        addInsurance (apcParcel, numParcels);
        break;

      case ADD_RUSH:
        addRush (apcParcel, numParcels);
        break;

      //case DELIVER:
      //  cout << "TID> ";
      //  cin >> TID;
      //  apcParcel[TID - INDEX_ADJUSTMENT]->setDeliveryDay ();                            // need to create this in each class
      //  cout << "Delivered!" << apcParcel[TID - INDEX_ADJUSTMENT]->getDeliveryDay ();   // re-edit this in each class 
      //  apcParcel[TID - INDEX_ADJUSTMENT]->print (cout);
      //  break;
    }
  } while (choice != QUIT); 
    
                                              // need to delete the populated arrays 
  inFile.close ();

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
bool openFileForRead (ifstream &rcInFile, string fileName) {
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

  cout << endl << OPTION_PRINT_ALL << endl << OPTION_ADD_INSURANCE << endl
       << OPTION_ADD_RUSH << endl << OPTION_DELIVER << endl << OPTION_QUIT 
       << endl;
}

/****************************************************************************
Function:    populatingArray

Description:  

Parameters:   

Returned:		 none
****************************************************************************/
void populatingArray (Parcel *apcParcel[], int &numParcels, 
                      ifstream &inFile) {
  apcParcel[numParcels]->read (inFile);
  numParcels++;
}

/****************************************************************************
Function:    printAll

Description:

Parameters:

Returned:		 none
****************************************************************************/
void printAll (Parcel *apcParcel[], int &numParcels) {
  for (int i = 0; i < numParcels; i++) {
    apcParcel[i]->print (cout);
  }
}

/****************************************************************************
Function:    addInsurance 

Description:

Parameters:

Returned:		 none
****************************************************************************/
void addInsurance (Parcel *apcParcel[], int &numParcels) {
  const int INDEX_ADJUSTMENT = 1;
  int TID;

  cout << "TID> ";
  cin >> TID;
  if (apcParcel[TID - INDEX_ADJUSTMENT] != nullptr) {
    apcParcel[TID - INDEX_ADJUSTMENT]->setInsurance ();
    cout << "Added Insurance for $" 
         << apcParcel[TID - INDEX_ADJUSTMENT]->getInsuranceCost ();
    apcParcel[TID - INDEX_ADJUSTMENT]->print (cout);
  }
}

/****************************************************************************
Function:    addRush

Description:

Parameters:

Returned:		 none
****************************************************************************/
void addRush (Parcel *apcParcel[], int &numParcels) {
  const int INDEX_ADJUSTMENT = 1;
  int TID;

  cout << "TID> ";
  cin >> TID;
  if (apcParcel[TID - INDEX_ADJUSTMENT] != nullptr) {
    apcParcel[TID - INDEX_ADJUSTMENT]->setRush ();
    cout << "Added Rush for $" << apcParcel[TID - INDEX_ADJUSTMENT]->getRushCost ();
    apcParcel[TID - INDEX_ADJUSTMENT]->print (cout);
  }
}
/****************************************************************************
Function:

Description:

Parameters:

Returned:		 none
****************************************************************************/

/****************************************************************************
Function:

Description:

Parameters:

Returned:		 none
****************************************************************************/

/****************************************************************************
Function:

Description:

Parameters:

Returned:		 none
****************************************************************************/