#pragma once
#include "Customer.h"
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

//----------------------------------------------------------------------------
// Class : Inventory
// child of transaction, represents the command to display the Store's 
// inventory
// setData assumes line in transaction file is formatted as H CustomerID
// setData should start reading after H
//----------------------------------------------------------------------------

class History :
  public Transaction
{
public:
  History();
  ~History();

  bool setData(ifstream&);
  // executes the displayHistory command for the specified customer
  void doTransaction(const vector<Movie*>&, const HashTable&);
  void display() const;
  char getCommand() const;
  const char COMMAND = 'H';
  Movie* getTMovie() const;

private:
  int CustomerID;
};

