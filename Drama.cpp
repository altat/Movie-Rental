#include "Drama.h"

// constructor
Drama::Drama()
{
}

// destructor
Drama::~Drama()
{
}

// getter for Genre
string Drama::getGenre()
{
  return GENRE;
}

// sets Data from transaction file
void Drama::setTData(ifstream& File)
{
  Movie::setDT(File);
}

// returns true if Rhs is equal to this
bool Drama::operator==(const Movie& Rhs) const
{
  const auto D = dynamic_cast<const Drama&>(Rhs);
  return (GENRE == D.GENRE && Director == D.Director && Title == D.Title);
}

// returns true if Rhs is less than this
// compares Director first, then Title
bool Drama::operator<(const Movie& Rhs) const
{
  const auto D = dynamic_cast<const Drama&>(Rhs);
  if (Director < D.Director) return true;
  return (Director == D.Director && Title < D.Title);
}

// returns string containing sorting attributes (Director then Title)
string Drama::tDisplay() const
{
  string Ret;
  Ret += GENRE + " " + Director + ", " + Title;
  return Ret;
}

