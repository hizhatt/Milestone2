#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib> // for EXIT_FAILURE
#include <sstream> // for converting strings to numbers during importing a file

#include "StoreItem.h"

using namespace std;

// Function prototype
void p2c();
int searchText(const vector<StoreItem>, int, string);
//int searchNumCostPrice(const vector<StoreItem>, int, string,)

// --------- START OF MAIN FUNCTION ----------
int main()
{
  // Welcome message
  cout << "\n\n\n\n\n\n\n\n-- Hello, welcome to the Data Management software (2.0) --\n";
  // Declaring variables
    // Escape variable for exiting program
    bool escape = false;
    // Variables for the object
    vector<StoreItem> myVector; // Creation of the vector myVector to store Items
    int unitsStored,
        unitsSold,
        year,
        month,
        day;
    double  sellPrice,
            costPrice;
    string  ID,
            name,
            description,
            category,
            manufacturer;
    // Variables for user input
    int vectorSize, // the number of items the user wants to enter into vector
        choice, // user choice in menus
        p, // the pointer is choice - 1 that will point to the correct index
        vSize; // size of vector for searching function
    string text; // search for text
    unsigned int size; // for the .size() which gives unsigned value
    // Placeholder variable (temporary variable before putting into mutator function)
    string s; // s = string
    double d; // d = double
    int n; // n = number

  // Looping main menu
  while(escape == false)
  {
    //Show main menu
    cout << "\n======= MAIN MENU =========\n\n";
    cout << "1. Enter a new item\n";
    cout << "2. Update a data field\n";
    cout << "3. Delete a data field\n";
    cout << "4. Delete a record\n";
    cout << "5. Display all of records\n";
    cout << "6. Display selected data field(s)\n";
    cout << "7. Search\n";
    cout << "8. Sort selected data field\n";
    cout << "9. Save the table into a text file\n";
    cout << "10. Load a table from a text file\n";
    cout << "11. Exit\n";
    cout << "\nChoose a number to proceed: ";
    cin >> choice;
    // If user choose to exit the program
    if (choice == 11)
      escape = true;
    // If user choose other than to exit the program
    else
    {
      switch(choice)
      {
        case 1: // Fill in vector with new item(s)
                cout << endl;
                cout << ">> Entering new item(s)\n";
                // Asking the user how many items to be inputted
                cout << "How many items do you want to enter?  ";
                cin >> vectorSize;
                cout << endl;
                // The loop for each slot in vector as the user indicated above
                for (int i = 0; i < vectorSize; i++)
                {
                  cout << "Enter item ID: ";
                  cin.ignore(); // Ignore the Return character
                  getline(cin, ID);
                  cout << "Enter item name: ";
                  getline(cin, name);
                  cout << "Enter item description: ";
                  getline(cin, description);
                  cout << "Enter item category: ";
                  getline(cin, category);
                  cout << "Enter item manufacturer: ";
                  getline(cin, manufacturer);
                  cout << "Enter item selling price: ";
                  cin >> sellPrice;
                  cout << "Enter item cost price: ";
                  cin >> costPrice;
                  cout << "Enter units in store: ";
                  cin >> unitsStored;
                  cout << "Enter units sold: ";
                  cin >> unitsSold;
                  cout << "Enter item year introduced: ";
                  cin >> year;
                  cout << "Enter item month introduced: ";
                  cin >> month;
                  cout << "Enter item day introduced: ";
                  cin >> day;

                  StoreItem Item(ID, name, description, category, manufacturer, sellPrice,
                  costPrice, unitsStored, unitsSold, year, month, day);
                  myVector.push_back(Item);
                  cout << endl;
                }
                cout << ">> You have finished entered all the items...";
                p2c();
                break;
        case 2: // Updating a data field
                  // Like before, show which items are available
                  cout << endl << "-- Item List --\n";
                  size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                  for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                  {
                    cout << "Item " << i+1 << " : "; // i + 1 because index start with 0
                    cout << myVector[i].getName() << endl;
                  }
                  // Let the user choose an item
                  cout << "\nChoose the item number to update: ";
                  cin >> choice;
                  p = choice - 1;
                  // Loop so the user can update many data fields
                  while (choice != -1)
                  {
                  // Then show the data fields of the given item
                  cout << endl;
                  cout << "1.  ID:           " << myVector[p].getID() << endl;
                  cout << "2.  Name:         " << myVector[p].getName() << endl;
                  cout << "3.  Description:  " << myVector[p].getDescription() << endl;
                  cout << "4.  Category:     " << myVector[p].getCategory() << endl;
                  cout << "5.  Manufacturer: " << myVector[p].getManufacturer() << endl;
                  cout << "6.  Sell price:   RM " << myVector[p].getSellPrice() << endl;
                  cout << "7.  Cost price:   RM " << myVector[p].getCostPrice() << endl;
                  cout << "8.  Units stored: " << myVector[p].getUnitsStored() << endl;
                  cout << "9.  Units sold:   " << myVector[p].getUnitsSold() << endl;
                  cout << "10. Intro year:   " << myVector[p].getYear() << endl;
                  cout << "11. Intro month:  " << myVector[p].getMonth() << endl;
                  cout << "12. Intro day:    " << myVector[p].getDay() << endl;
                  cout << endl;
                  cout << "Which data field do you want to update? (-1 to finish) ";
                  cin >> choice;
                  // Now switch for editing the specified data field
                  switch(choice)
                  {
                    case 1: cout << "Enter a new ID: ";
                            cin.ignore();
                            getline(cin, s);
                            myVector[p].setID(s);
                            break;
                    case 2: cout << "Enter a new name: ";
                            cin.ignore();
                            getline(cin, s);
                            myVector[p].setName(s);
                            break;
                    case 3: cout << "Enter a new description: ";
                            cin.ignore();
                            getline(cin, s);
                            myVector[p].setDescription(s);
                            break;
                    case 4: cout << "Enter a new category: ";
                            cin.ignore();
                            getline(cin, s);
                            myVector[p].setCategory(s);
                            break;
                    case 5: cout << "Enter a new manufacturer: ";
                            cin.ignore();
                            getline(cin, s);
                            myVector[p].setManufacturer(s);
                            break;
                    case 6: cout << "Enter a new sell price: ";
                            cin >> d;
                            myVector[p].setSellPrice(d);
                            break;
                    case 7: cout << "Enter a new cost price: ";
                            cin >> d;
                            myVector[p].setCostPrice(d);
                            break;
                    case 8: cout << "Enter a new units stored: ";
                            cin >> n;
                            myVector[p].setUnitsStored(n);
                            break;
                    case 9: cout << "Enter a new units sold: ";
                            cin >> n;
                            myVector[p].setUnitsSold(n);
                            break;
                    case 10:cout << "Enter a new year: ";
                            cin >> n;
                            myVector[p].setYear(n);
                            break;
                    case 11:cout << "Enter a new month: ";
                            cin >> n;
                            myVector[p].setMonth(n);
                            break;
                    case 12:cout << "Enter a new day: ";
                            cin >> n;
                            myVector[p].setDay(n);
                            break;
                  } // End of switch for editing one data field
                } // End of while loop for editing multiple data field
                break;
        case 3: // Deleting data fields of specified one item
                  // First show the list of item names available
                  cout << endl << "-- Item List --\n";
                  size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                  for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                  {
                    cout << "Item " << i+1 << " : "; // i + 1 because index start with 0
                    cout << myVector[i].getName() << endl;
                  }
                  // Let the user choose an item
                  cout << "\n>>Choosing to delete a data field\nChoose the item number: ";
                  cin >> choice;
                  p = choice - 1;
                  // Loop so the user can delete many data fields
                  while (choice != -1)
                  {
                  // Then show the data fields of the given item
                  cout << endl;
                  cout << "1.  ID:           " << myVector[p].getID() << endl;
                  cout << "2.  Name:         " << myVector[p].getName() << endl;
                  cout << "3.  Description:  " << myVector[p].getDescription() << endl;
                  cout << "4.  Category:     " << myVector[p].getCategory() << endl;
                  cout << "5.  Manufacturer: " << myVector[p].getManufacturer() << endl;
                  cout << "6.  Sell price:   RM " << myVector[p].getSellPrice() << endl;
                  cout << "7.  Cost price:   RM " << myVector[p].getCostPrice() << endl;
                  cout << "8.  Units stored: " << myVector[p].getUnitsStored() << endl;
                  cout << "9.  Units sold:   " << myVector[p].getUnitsSold() << endl;
                  cout << "10. Intro year:   " << myVector[p].getYear() << endl;
                  cout << "11. Intro month:  " << myVector[p].getMonth() << endl;
                  cout << "12. Intro day:    " << myVector[p].getDay() << endl;
                  cout << endl;
                  cout << "Which data field do you want to DELETE? (-1 to finish) ";
                  cin >> choice;
                  // Now switch for editing the specified data field
                  switch(choice)
                  {
                    case 1: cout << "Deleting ID... ";
                            s = "-blank-";
                            myVector[p].setID(s);
                            break;
                    case 2: cout << "Deleting name... ";
                            s = "-blank-";
                            myVector[p].setName(s);
                            break;
                    case 3: cout << "Deleting description... ";
                            s = "-blank-";
                            myVector[p].setDescription(s);
                            break;
                    case 4: cout << "Deleting category... ";
                            s = "-blank-";
                            myVector[p].setCategory(s);
                            break;
                    case 5: cout << "Deleting manufacturer... ";
                            s = "-blank-";
                            myVector[p].setManufacturer(s);
                            break;
                    case 6: cout << "Deleting sell price... ";
                            d = -1;
                            myVector[p].setSellPrice(d);
                            break;
                    case 7: cout << "Deleting cost price... ";
                            d = -1;
                            myVector[p].setCostPrice(d);
                            break;
                    case 8: cout << "Deleting units stored... ";
                            n = -1;
                            myVector[p].setUnitsStored(n);
                            break;
                    case 9: cout << "Deleting units sold... ";
                            n = -1;
                            myVector[p].setUnitsSold(n);
                            break;
                    case 10:cout << "Deleting year... ";
                            n = -1;
                            myVector[p].setYear(n);
                            break;
                    case 11:cout << "Deleting month... ";
                            n = -1;
                            myVector[p].setMonth(n);
                            break;
                    case 12:cout << "Deleting day... ";
                            n = -1;
                            myVector[p].setDay(n);
                            break;
                  } // End of switch for deleting one data field
                } // End of while loop for deleting multiple data field

                break;
        case 4: // Deleting a records
                cout << "\n------- Deleting a record -------\n\n";
                // Show full data of all the items available by displaying all record
                size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                { cout << "> ITEM " << i+1 << " <" << endl; // i + 1 because index start with 0
                  cout << "ID:           " << myVector[i].getID() << endl;
                  cout << "Name:         " << myVector[i].getName() << endl;
                  cout << "Description:  " << myVector[i].getDescription() << endl;
                  cout << "Category:     " << myVector[i].getCategory() << endl;
                  cout << "Manufacturer: " << myVector[i].getManufacturer() << endl;
                  cout << "Sell price:   RM " << myVector[i].getSellPrice() << endl;
                  cout << "Cost price:   RM " << myVector[i].getCostPrice() << endl;
                  cout << "Units stored: " << myVector[i].getUnitsStored() << endl;
                  cout << "Units sold:   " << myVector[i].getUnitsSold() << endl;
                  cout << "Intro year:   " << myVector[i].getYear() << endl;
                  cout << "Intro month:  " << myVector[i].getMonth() << endl;
                  cout << "Intro day:    " << myVector[i].getDay() << endl;
                  cout << endl;
                }
                cout << ">> Deleting a record...\n";
                cout << "Enter the item number: ";
                cin >> choice;
                p = choice -1; // pointing to the right index
                // Now time to delete the respective record;
                myVector.erase(myVector.begin()+p);
                cout << "\n>> The record for item no." << choice << " has been deleted";
                cout << "\n>> Attention:\n>> The item number has been RESORTED\n";
                cout << "\n>> Showing all data...";
                p2c();
                // Maybe display all of the records again to show that the item number has changed
                cout << "\n\n--- Showing all data ---\n\n";
                size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                { cout << "> ITEM " << i+1 << " <" << endl; // i + 1 because index start with 0
                  cout << "ID:           " << myVector[i].getID() << endl;
                  cout << "Name:         " << myVector[i].getName() << endl;
                  cout << "Description:  " << myVector[i].getDescription() << endl;
                  cout << "Category:     " << myVector[i].getCategory() << endl;
                  cout << "Manufacturer: " << myVector[i].getManufacturer() << endl;
                  cout << "Sell price:   RM " << myVector[i].getSellPrice() << endl;
                  cout << "Cost price:   RM " << myVector[i].getCostPrice() << endl;
                  cout << "Units stored: " << myVector[i].getUnitsStored() << endl;
                  cout << "Units sold:   " << myVector[i].getUnitsSold() << endl;
                  cout << "Intro year:   " << myVector[i].getYear() << endl;
                  cout << "Intro month:  " << myVector[i].getMonth() << endl;
                  cout << "Intro day:    " << myVector[i].getDay() << endl;
                  cout << endl;
                }
                cout << ">> All data shown...";
                p2c(); // !ATTENTION! Idk why we need to press twice to continue...
                break;
        case 5: // Display all records
                cout << "\n\n--- Showing all data ---\n\n";
                size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                { cout << "> ITEM " << i+1 << " <" << endl; // i + 1 because index start with 0
                  cout << "ID:           " << myVector[i].getID() << endl;
                  cout << "Name:         " << myVector[i].getName() << endl;
                  cout << "Description:  " << myVector[i].getDescription() << endl;
                  cout << "Category:     " << myVector[i].getCategory() << endl;
                  cout << "Manufacturer: " << myVector[i].getManufacturer() << endl;
                  cout << "Sell price:   RM " << myVector[i].getSellPrice() << endl;
                  cout << "Cost price:   RM " << myVector[i].getCostPrice() << endl;
                  cout << "Units stored: " << myVector[i].getUnitsStored() << endl;
                  cout << "Units sold:   " << myVector[i].getUnitsSold() << endl;
                  cout << "Intro year:   " << myVector[i].getYear() << endl;
                  cout << "Intro month:  " << myVector[i].getMonth() << endl;
                  cout << "Intro day:    " << myVector[i].getDay() << endl;
                  cout << endl;
                }
                cout << ">> All data shown...";
                p2c();
                break;
        case 6: // Display selected data field(s)
                //Which data field(s) to display
                cout << "Which data field do you want to display?";
                break;
        case 7: // Custom search
                choice = 0; // Resets the choice as precaution
                // switch case for text or numbers
                while (choice != 3)
                {
                  cout << "\n>> Do you want to search for texts or numbers?";
                  cout << "\n1. Texts\n2. Numbers\n3. End search\nEnter your choice: ";
                  cin >> choice;
                  switch (choice)
                  {
                    case 1: // Search for texts
                              cout << "\nEnter either ID, or name, or description, or manufacturer of the item: \n";
                              cin.ignore();
                              getline(cin, text);
                              //cout << text << endl;
                              vSize = myVector.size();
                              //cout << vSize;
                              p = searchText(myVector, vSize, text);
                              if (p == -1)
                                cout << "\n>> No match.\n";
                              else
                              {
                                cout << "\n>> Found a match:\n";
                                cout << "\n --- Item " << p+1 << " ---\n";
                                cout << "ID:           " << myVector[p].getID() << endl;
                                cout << "Name:         " << myVector[p].getName() << endl;
                                cout << "Description:  " << myVector[p].getDescription() << endl;
                                cout << "Category:     " << myVector[p].getCategory() << endl;
                                cout << "Manufacturer: " << myVector[p].getManufacturer() << endl;
                              }
                            break;
                    case 2: // Seach for numbers
                            break;
                  }
                }
                cout << "\n>> Finished searching";
                p2c();
                break;
        case 8: // Sort
                break;
        case 9: { // Save to text file
                ofstream newfile;
                newfile.open("Exported Data.txt");
                // Now we want to put in all the data from objects in vector to the file
                size = myVector.size(); // Put the value in size so that it doesn't have to keep finding the size in each for loop
                for(unsigned i = 0; i < size; i++ ) // Unsigned i because .size() gives unsigned value
                { string s1,s2,s3,s4,s5; // temporary data placeholder before we put into the file
                  int a1,a2,a3,a4,a5,a6,a7;
                  cout << "Saving item " << i+1 << " to the text file..." << endl; // i + 1 because index start with 0
                  s1 = myVector[i].getID();
                  s2 = myVector[i].getName();
                  s3 = myVector[i].getDescription();
                  s4 = myVector[i].getCategory();
                  s5 = myVector[i].getManufacturer();
                  a1 = myVector[i].getSellPrice();
                  a2 = myVector[i].getCostPrice();
                  a3 = myVector[i].getUnitsStored();
                  a4 = myVector[i].getUnitsSold();
                  a5 = myVector[i].getYear();
                  a6 = myVector[i].getMonth();
                  a7 = myVector[i].getDay();
                  newfile << s1 << endl << s2 << endl << s3 << endl <<
                          s4 << endl << s5 << endl << a1 << endl << a2 <<
                          endl << a3 << endl << a4 << endl << a5 << endl <<
                          a6 << endl << a7 << endl;
                }
                newfile.close();
                cout << "\n\n>> The data has been successfully exported to 'Exported Data.txt' file";
                p2c();
                break;
                }
        case 10:/*{// Load from text file
                  // User input file name to be imported
                  string input;
                  string word;
                  size = myVector.size();
                  int counter1 = 0, // For the 12 data fields
                      counter2 = 0, // For the number of items to be imported
                  cout << "\nEnter the file name to be imported: ";
                  cin.ignore();
                  getline(cin, input);
                  ifstream impfile;
                  impfile.open(input);
                  // some safety measure if file can't be open
                  if(!impfile.is_open())
                  {
                    cout << ">> ERROR!";
                    exit(EXIT_FAILURE);
                  }
                  else
                  getline(impfile, word);
                  while (counter2 <= size )
                  {
                    // PUT THE CODES HERE
                    while (counter1 <= 12)
                    {
                      myVector.setID(word);
                      myVector.setName();
                      myVector.setDescription();
                      myVector.setCategory();
                      myVector.setManufacturer();
                      myVector.setSellPrice();
                      myVector.setCostPrice();
                      myVector.setUnitsStored();
                      myVector.setUnitsSold();
                      myVector.setYear();
                      myVector.setMonth();
                      myVector.setDay();

                    }



                    // END HERE
                    cout << word << endl;
                    getline(impfile, word); // read the next line
                  }

                break;
              }*/
        default: cout << choice << " is not a valid input!\n\n";
                break;
      }
    }
  }
  cout << "\n>> You have choose to exit the program...";
  cout << "\n-- The program has ended --\n";
  cout << "----- by Hizri Hatta -----\n\n\n\n\n\n\n\n\n\n\n\n";
  return 0;
}
// ---- END OF MAIN FUNCTION ----

// PRESS TO CONTINUE function (p2c) definition
void p2c()
{
  cout << "\nPress to continue...";
  cin.ignore();
  cin.get(); // Press to continue
}

// Search text function
int searchText(const vector<StoreItem> myVector, int size, string key )
{
  int index = 0;
  int position = -1;
  bool found = false;

  while (index < size && !found)
  {
    if (myVector[index].getID() == key)
    {
      found = true;
      position = index;
    }
    else if (myVector[index].getName() == key)
    {
      found = true;
      position = index;
    }
    else if (myVector[index].getDescription() == key)
    {
      found = true;
      position = index;
    }
    else if (myVector[index].getCategory() == key)
    {
      found = true;
      position = index;
    }
    else if (myVector[index].getManufacturer() == key)
    {
      found = true;
      position = index;
    }
    else
      index++;
  }
  return position;
}
