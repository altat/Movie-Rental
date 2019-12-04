#include "Movie.h"

// constructor
Movie::Movie()
{
  Stock = -1;
  InitialStock = -1;
  Year = 0;
}

// destructor
Movie::~Movie()
{
}

// getter for Stock
int Movie::getStock() const
{
  return Stock;
}

// returns amount that was borrowed
int Movie::getBorrowed() const
{
  return InitialStock - Stock;
}

// increments Stock
void Movie::increaseStock()
{
  Stock++;
}

// decrements Stock
void Movie::decreaseStock()
{
  Stock--;
}

// getter for InitialStock
int Movie::getInitialStock() const
{
  return InitialStock;
}

// getter for Genre (implemented in child class)
string Movie::getGenre()
{
  return string();
}

// sets data from file
bool Movie::setData(ifstream& File)
{
  string Temp;
  File >> Stock >> Temp;
  setDT(File);
  File >> Year;
  InitialStock = Stock;
  return true;
}

// sets data from transaction file (implemented in child class)
void Movie::setTData(ifstream&)
{
}

// all operator overloads are implemented in child class
bool Movie::operator==(const Movie&) const
{
  return false;
}

bool Movie::operator<(const Movie&) const
{
  return false;
}

// displays Movie information neatly in one line
void Movie::display() const {
  cout << left << setw(35) << Title << setw(19) << Director << setw(5) <<
    Year << " " << "Borrowed: " << setw(3) << getBorrowed() << " " <<
    "Remaining: " << Stock << endl;
}

// displays sorting information (implemented in child)
string Movie::tDisplay() const
{
  return string();
}

// helper function for setData
// sets Director and Title information
void Movie::setDT(ifstream& File)
{
  setD(File);
  setT(File);
}

// helper function for setDT
// sets Director information
void Movie::setD(ifstream& File)
{
  string Temp;
  File >> Director;
  // while last character in Director is not comma
  while (Director.back() != ',') {
    File >> Temp; // get next string
    Director += " ";
    Director += Temp; // concenate to Director
  }
  Director.pop_back(); //remove comma
}

// helper for setDT
// sets Title
void Movie::setT(ifstream& File)
{
  string Temp;
  File >> Title;
  // while last character in Title is not comma
  while (Title.back() != ',') {
    File >> Temp; // get next string
    Title += " ";
    Title += Temp; // add to Title
  }
  Title.pop_back(); // remove comma
}
