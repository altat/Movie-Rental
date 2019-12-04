#pragma once
#include "Movie.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//----------------------------------------------------------------------------
// Class: Customer
// Represents a Customer's Account. Stores ID and name.
// setData assumes customer file is formatted as ID First Last
// assumes each transaction has display function and each movie has
// tDisplay
//----------------------------------------------------------------------------

// constants
const int MIN_ID = 1000;
const int MAX_ID = 9999;

//forward declarations
class Transaction;

class Customer
{
public:
  Customer(); 
  ~Customer();

  int getID(); //getter for ID
  void addTransaction(Transaction*); //adds Transaction to History vector
  void displayHistory(); // displays each Transaction in History
  bool setData(std::ifstream&); //sets data from file
  bool hasMovie(Movie*); // checks if Movie has been borrowed

private:
  int ID;
  std::string Last;
  std::string First;
  std::vector<Transaction*> History;
};

