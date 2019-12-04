#include "History.h"

History::History()
{
  CustomerID = 0;
}

History::~History()
{
}

// sets data from transaction file
bool History::setData(ifstream& File)
{
  File >> CustomerID;
  return true;
}

// executes the displayHistory command for the specified customer
void History::doTransaction(const vector<Movie*>&, const HashTable& Customers)
{
  // find Customer
  Customer* C = Customers.retrieve(CustomerID);

  if (C) C->displayHistory();
  else cout << "Customer " << CustomerID << " not found, History failed" 
    << endl;
}

void History::display() const
{
}

char History::getCommand() const
{
  return COMMAND;
}

Movie* History::getTMovie() const
{
  return nullptr;
}
