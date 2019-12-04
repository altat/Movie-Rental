#pragma once
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <fstream>
#include <set>

//----------------------------------------------------------------------------
// Class: Borrow
// child of transaction. Used when customer borrows a movie from the store.
// setData assumes line from transaction file is formatted as:
// B CustomerID D Genre (Movie's sorting attributes)
// setData should start reading after B
//----------------------------------------------------------------------------

class Borrow : public Transaction
{
public:
  Borrow();
  Borrow(Movie*, int);
  ~Borrow();

  // sets data from transaction file
  bool setData(ifstream&);
  // process/executes the transaction
  void doTransaction(const vector<Movie*>&, const HashTable&);
  void display() const; // display this Borrow's data members
  char getCommand() const; // getter
  const char COMMAND = 'B';
  Movie* getTMovie() const; // getter

private:
  Movie* TMovie;
  int CustomerID;
};

