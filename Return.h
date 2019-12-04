#pragma once
#include "Customer.h"
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

//----------------------------------------------------------------------------
// Class: Return
// child of transaction. Used when customer returns a movie to the store.
// setData assumes line from transaction file is formatted as:
// R CustomerID D Genre (Movie's sorting attributes)
// setData should start reading after R
//----------------------------------------------------------------------------

class Return :
  public Transaction
{
public:
  Return();
  ~Return();

  // sets data from file
  bool setData(ifstream&);
  // processes Return
  void doTransaction(const vector<Movie*>&, const HashTable&);
  void display() const; // displays members of this
  char getCommand() const; //getter
  const char COMMAND = 'R';
  Movie* getTMovie() const; //getter

private:
  Movie* TMovie; // movie to be returned
  int CustomerID; // Customer that's doing the return
};

