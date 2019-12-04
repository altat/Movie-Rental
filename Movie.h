#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Class: Movie
//  parent to comedy, drama, amd classic.
//
//----------------------------------------------------------------------------

using namespace std;

class Movie
{
public:
  Movie(); //constructor
  virtual ~Movie(); //destructor

  int getStock() const; //getter for stock
  int getBorrowed() const; //getter for amount of Movies Borrowed
  void increaseStock(); //increments Stock by one
  void decreaseStock(); //decrements Stock by one
  int getInitialStock() const; //getter for InitialStock

  // getter for Genre
  virtual string getGenre();
  virtual bool setData(ifstream&); //sets data from file
  virtual void setTData(ifstream&); //sets data from transaction file
  virtual bool operator==(const Movie&) const; //returns equality
  virtual bool operator<(const Movie&) const; //relational operator
  virtual void display() const; // displays movie information
  virtual string tDisplay() const; // returns string containing sort info

protected:
  int Stock;
  int InitialStock;
  string Director;
  string Title;
  int Year;

  void setDT(ifstream&); // helper function for setData
  void setD(ifstream&); // helper function for setDT
  void setT(ifstream&); // helper function for setDT
};

