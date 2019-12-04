#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Class: Comedy
// child class of Movie
// sorting attributes are Year then Month then ActorFirst then ActorLast
// setData assumes data in file is correctly formatted
//----------------------------------------------------------------------------

class Classic : public Movie
{
public:
  Classic();
  ~Classic();

  string getGenre();
  bool setData(ifstream&);
  void setTData(ifstream&);
  bool operator==(const Movie&) const;
  bool operator<(const Movie&) const;
  void display() const;
  string tDisplay() const;

private:
  const string GENRE = "C";
  string ActorFirst;
  string ActorLast;
  int Month;
};

