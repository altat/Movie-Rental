#include "MovieFactory.h"

MovieFactory::MovieFactory()
{
}

MovieFactory::~MovieFactory()
{
}

// creates a child of Transaction based on the Genre
// parameter is Genre. Valid Genres are currently F, D, and C.
// returns nullptr if invalid Genre is passed
Movie* MovieFactory::create(const string& Genre)
{
  if (Genre == "F") return new Comedy();
  if (Genre == "D") return new Drama();
  if (Genre == "C") return new Classic();
  cout << "Invalid Movie Genre" << endl;
  return nullptr;
}
