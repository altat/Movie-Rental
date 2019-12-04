#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Class: Comedy
// child class of Movie
// sorting attributes is Title then Year
//----------------------------------------------------------------------------

class Comedy :
  public Movie
{
public:
  Comedy();
  Comedy(int, const string&, const string&, int);
  ~Comedy();

  string getGenre();
  void setTData(ifstream&);
  bool operator==(const Movie&) const;
  bool operator<(const Movie&) const;
  string tDisplay() const;

private:
  const string GENRE = "F";
};

