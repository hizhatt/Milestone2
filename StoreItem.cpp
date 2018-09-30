// Function definitions

#include "StoreItem.h"

// ---- DEFAULT CONSTRUCTOR ----
StoreItem::StoreItem()
{}

// ---- OVERLOAD CONSTRUCTOR ----
  // For reference:
  // StoreItem(string, string, string, string, string, double, double, int, int, int, int, int);
  // (ID, Name, Description, Category, Manufacturer, Selling, Cost, Store, Sold, Year, Month, Day)
StoreItem::StoreItem(string s1, string s2, string s3, string s4, string s5,
  double d1, double d2, int i1, int i2, int i3, int i4, int i5)
{
  newID = s1;
  newName = s2;
  newDescription = s3;
  newCategory = s4;
  newManufacturer = s5;
  newSellPrice = d1;
  newCostPrice = d2;
  newUnitsStored = i1;
  newUnitsSold = i2;
  newYear = i3;
  newMonth = i4;
  newDay = i5;
  // Setting the values from user input to the member variables
}
// ---- END OF OVERLOAD CONSTRUCTOR ----

// ---- DECONSTRUCTOR ----

StoreItem::~StoreItem()
{}

// ---- ACCESSOR ----

string StoreItem::getID() const {
  return newID;
}

string StoreItem::getName() const {
  return newName;
}

string StoreItem::getDescription() const {
  return newDescription;
}

string StoreItem::getCategory() const {
  return newCategory;
}

string StoreItem::getManufacturer() const {
  return newManufacturer;
}

double StoreItem::getSellPrice() const {
  return newSellPrice;
}

double StoreItem::getCostPrice() const {
  return newCostPrice;
}

int StoreItem::getUnitsStored() const {
  return newUnitsStored;
}

int StoreItem::getUnitsSold() const {
  return newUnitsSold;
}

int StoreItem::getYear() const {
  return newYear;
}

int StoreItem::getMonth() const {
  return newMonth;
}

int StoreItem::getDay() const {
  return newDay;
}

// ---- END OF ACCESSOR ----

// ---- MUTATOR ----

void StoreItem::setID(string ID) {
  newID = ID;
}

void StoreItem::setName(string name) {
  newName = name;
}

void StoreItem::setDescription(string description) {
  newDescription = description;
}

void StoreItem::setCategory(string category) {
  newCategory = category;
}

void StoreItem::setManufacturer(string manufacturer) {
  newManufacturer = manufacturer;
}

void StoreItem::setSellPrice(double sellPrice) {
  newSellPrice = sellPrice;
}

void StoreItem::setCostPrice(double costPrice) {
  newCostPrice = costPrice;
}

void StoreItem::setUnitsStored(int unitsStored) {
  newUnitsStored = unitsStored;
}

void StoreItem::setUnitsSold(int unitsSold) {
  newUnitsSold = unitsSold;
}

void StoreItem::setYear(int year) {
  newYear = year;
}

void StoreItem::setMonth(int month) {
  newMonth = month;
}

void StoreItem::setDay(int day) {
  newDay = day;
}

// ---- END OF MUTATOR ----
