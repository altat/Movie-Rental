#include "Customer.h"
#include "HashTable.h"

HashTable::HashTable() {
  initialize();
}

HashTable::~HashTable() {
  clear();
}

// hash inputs parameter into hash function and returns result
int HashTable::hash(int C) const {
  return C - 1000;
}

// add adds Customer to Table
// returns true if added, false if not
bool HashTable::add(Customer* C) {
  // invalid customer
  if (C->getID() < MIN_ID || C->getID() > MAX_ID) return false;
  // Customer already exists
  if (Table[hash(C->getID())] != nullptr) {
    std::cout << "Customer ID already exist" << std::endl;
    delete C;
    return false;
  }
  // Valid Customer that doesn't exist yet
  Table[hash(C->getID())] = C;
  TotalEntries++;
  return true;
}

// retrieve finds and returns Customer pointer by their ID
Customer* HashTable::retrieve(int C) const {
  if (C < MIN_ID || C > MAX_ID) return nullptr;
  return Table[hash(C)];
}

// clear empties Table and reinitializes it
void HashTable::clear() {
  for (auto C : Table)
    delete C;

  initialize();
}

// initializes Table array
void HashTable::initialize()
{
  for (int I = 0; I < MAX_ENTRIES; I++)
    Table[I] = nullptr;
  TotalEntries = 0;
}
