#pragma once
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Movie.h"

//----------------------------------------------------------------------------
// Class: TransactionFactory
// factory class for building of movie objects. Creates a child of 
// Movie based on a predefined Genre type) 
//  
//----------------------------------------------------------------------------

class MovieFactory
{
public:
  MovieFactory();
  ~MovieFactory();

  // creates a child of Movie based on the Genre (paramter)
  static Movie* create(const string&);

private:

};

