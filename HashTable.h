#pragma once
#include <iostream>

//----------------------------------------------------------------------------
// Class: HashTable
// Stores values in Table at index equal to hash of key
// Value is Customer pointer, Key is Customer's ID
// 
//----------------------------------------------------------------------------

// constants
const int MAX_ENTRIES = 9000;

// forward declarations
class Customer;

class HashTable
{
public:
  HashTable();
  ~HashTable();

  int hash(int) const; // returns hash of param
  bool add(Customer*); // inserts value into Table
  Customer* retrieve(int) const; // retrieves Customer from Table by key

  void clear(); // clears Table

private:
  Customer *Table[MAX_ENTRIES];
  int TotalEntries;

  void initialize(); // initializes Table array
};

