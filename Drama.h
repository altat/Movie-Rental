#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Class: Drama
// child class of Movie
// sorting attributes is Director then Title
//----------------------------------------------------------------------------

class Drama :
  public Movie
{
public:
  Drama();
  ~Drama();

  string getGenre();
  void setTData(ifstream&);
  bool operator==(const Movie&) const;
  bool operator<(const Movie&) const;
  string tDisplay() const;

private:
  const string GENRE = "D";
};

