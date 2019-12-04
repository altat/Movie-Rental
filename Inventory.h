#pragma once
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

//----------------------------------------------------------------------------
// Class : History
// child of transaction, displays the transaction history for the
// specified customer. Doesn't actually do anything.
// 
//----------------------------------------------------------------------------

class Inventory :
  public Transaction
{
public:
  Inventory();
  ~Inventory();

  bool setData(ifstream&);
  void doTransaction(const vector<Movie*>&, const HashTable&);
  void display() const;
  char getCommand() const;
  const char COMMAND = 'I';
  Movie* getTMovie() const;

private:
  
};

