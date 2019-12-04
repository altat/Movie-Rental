#include "HashTable.h"
#include "Transaction.h"

Transaction::Transaction() 
{
}

Transaction::~Transaction()
{
}

bool Transaction::setData(ifstream&)
{
  return false;
}

void Transaction::doTransaction(const vector<Movie*>&, const HashTable&)
{
}

void Transaction::display() const
{
}

char Transaction::getCommand() const
{
  return ' ';
}

Movie* Transaction::getTMovie() const
{
  return nullptr;
}

// returns a Movie pointer from C (first parameter) if it finds Movie
// in C that equals M (second parameter)
// returns nullptr if not found
Movie* Transaction::retrieveMovie(const vector<Movie*>& M, Movie* Target) const
{
  for (auto I : M)
    if (*Target == *I)
      return I;
  return nullptr;
}
