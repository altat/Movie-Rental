#include "Classic.h"

// constructor
Classic::Classic()
{
  Month = -1;
}

// destructor
Classic::~Classic()
{
}

// getter for Genre
string Classic::getGenre()
{
  return GENRE;
}

// set data from file
// always returns true
bool Classic::setData(ifstream& File)
{
  string Temp;
  File >> Stock >> Temp;
  Movie::setDT(File);
  File >> ActorFirst >> ActorLast >> Month >> Year;
  InitialStock = Stock;
  return true;
}

// sets data from trasaction file
void Classic::setTData(ifstream& File)
{
  File >> Month >> Year >> ActorFirst >> ActorLast;
}

// returns true if Rhs' sorting attributes are equal to this
bool Classic::operator==(const Movie& Rhs) const
{
  const auto C = dynamic_cast<const Classic&>(Rhs);
  return (ActorFirst == C.ActorFirst && ActorLast == C.ActorLast &&
    Month == C.Month && Year == C.Year);
}

// returns true if Rhs' sorting attributes are less than this
bool Classic::operator<(const Movie& Rhs) const
{
  const auto C = dynamic_cast<const Classic&>(Rhs);
  if (Year < C.Year) return true;
  if (Year == C.Year && Month < C.Month) return true;
  if (Year == C.Year && Month == C.Month && ActorFirst < C.ActorFirst) 
    return true;
  return (Year == C.Year && Month == C.Month && ActorFirst == C.ActorFirst &&
    ActorLast < ActorFirst);
}

// displays Classic's data members neatly in one line
void Classic::display() const
{
  string Actor = ActorFirst + " " + ActorLast;
  cout << left << setw(35) << Title << setw(19) << Director << setw(3) << 
    Month << setw(5) << Year << setw(19) << Actor << "Borrowed: " << setw(3) 
    << getBorrowed() << " " << "Remaining: " << Stock << endl;
}

// returns string containing Classic's sorting attributes
string Classic::tDisplay() const
{
  auto M = std::to_string(Month);
  auto Y = std::to_string(Year);
  string Ret;
  Ret += GENRE + " " + M + " " + Y + " " + ActorFirst + " " + ActorLast;
  return Ret;
}
