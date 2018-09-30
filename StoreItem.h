// Header file
#ifndef STOREITEM_H
#define STOREITEM_H
// prevents duplicates of header file (include guard)

#include <iostream>
#include <string>

using namespace std;

class StoreItem //Class StoreItem
{
public:
  // Default Constructor
  StoreItem();

  // Overload Constructor
  StoreItem(string, string, string, string, string, double, double, int, int, int, int, int);
  // (ID, Name, Description, Category, Manufacturer, Selling, Cost, Store, Sold, Year, Month, Day)

  // Deconstructor
  ~StoreItem();

  // Accessor Functions
  string getID() const;
  string getName() const;
  string getDescription() const;
  string getCategory() const;
  string getManufacturer() const;
  double getSellPrice() const;
  double getCostPrice() const;
  int getUnitsStored() const;
  int getUnitsSold() const;
  int getYear() const;
  int getMonth() const;
  int getDay() const;

  // Mutator Functions
  void setID(string);
  void setName(string);
  void setDescription(string);
  void setCategory(string);
  void setManufacturer(string);
  void setSellPrice(double);
  void setCostPrice(double);
  void setUnitsStored(int);
  void setUnitsSold(int);
  void setYear(int);
  void setMonth(int);
  void setDay(int);

private:
  // Member Variables
  int newUnitsStored,
      newUnitsSold,
      newYear,
      newMonth,
      newDay;
  double  newSellPrice,
          newCostPrice;
  string  newID,
          newName,
          newDescription,
          newCategory,
          newManufacturer;
};

#endif
// End of include guards
