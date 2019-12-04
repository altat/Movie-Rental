#pragma once
#include "Movie.h"
#include <fstream>
#include <string>
#include <vector>

//----------------------------------------------------------------------------
// Class: Transaction
// parent class of Borrow, Return, History, and Inventory. 
// most functions are implemented in children
//----------------------------------------------------------------------------

// forward declaration
class HashTable;

using namespace std;

class Transaction
{
public:
  // constructors and destructor
  Transaction();
  virtual ~Transaction();

  virtual bool setData(ifstream&); // sets data from file
  // processes transaction
  virtual void doTransaction(const vector<Movie*>&, const HashTable&);
  virtual void display() const;
  virtual char getCommand() const;
  virtual Movie* getTMovie() const;

  // finds and retrieves a Movie from the first paramter 
  Movie* retrieveMovie(const vector<Movie*>&, Movie*) const;

protected:
  string MediaType = "D";
};

