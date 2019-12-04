#include "Comedy.h"

// constructor
Comedy::Comedy()
{
}

Comedy::Comedy(int S, const string& D, const string& T, int Y)
{
  Stock = S;
  InitialStock = S;
  Director = D;
  Title = T;
  Year = Y;
}

// destructor
Comedy::~Comedy()
{
}

string Comedy::getGenre()
{
  return GENRE;
}

// sets data from transaction file
void Comedy::setTData(ifstream& File)
{
  Movie::setT(File);
  File >> Year;
}

// returns true if Rhs' sorting attributes are equal to this
bool Comedy::operator==(const Movie& Rhs) const
{
  const auto F = dynamic_cast<const Comedy&>(Rhs);
  return (GENRE == F.GENRE && Title == F.Title && Year == F.Year);
}

// returns true if Rhs' sorting attribtues are less than this
bool Comedy::operator<(const Movie& Rhs) const
{
  const auto F = dynamic_cast<const Comedy&>(Rhs);
  if (Title < F.Title) return true;
  if (Title == F.Title && Year < F.Year) return true;
  return false;
}

// returns string containing sorting attributes
string Comedy::tDisplay() const
{
  string Ret;
  Ret += GENRE + " " + Title + ", " + std::to_string(Year);
  return Ret;
}
