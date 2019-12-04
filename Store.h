// author Tanvir Tatla
#pragma once
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include "TransactionFactory.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <queue>

//----------------------------------------------------------------------------
// Class: Store
// stores all movies, customers, and transactions within class.
// creates, processes, and manipulates data involving these object types
//
//----------------------------------------------------------------------------

class Store
{
public:
  Store(); //constructor
  ~Store(); //destructor

  // builds movie, customer, and transaction containers from file
  bool buildStore(const string&, const string&, const string&);
  // execute processes transactions in Commands container
  void execute();
  // getInventory returns the correct movie container based on Genre
  vector<Movie*>& getInventory(const string&);
  // returns the customer container
  HashTable& getCustomers();
  // displays every movie in each movie container
  void displayInventory();

private:
  HashTable Customers; // customer container
  // movie containers for each genre
  vector<Movie*> Comedies;
  vector<Movie*> Classics;
  vector<Movie*> Dramas;
  vector<Movie*> Dummy;
  queue<Transaction*> Commands; // transaction container

  // helper functions for buildStore
  void readMovies(ifstream&);
  void readCustomers(ifstream&);
  void readCommands(ifstream&);

  // adds Movie to one of the containers
  bool addInventory(Movie*, const string&); 
  bool addHelper(vector<Movie*>&, Movie*); // helper function for addInventory
  void discardLine(ifstream&); // discards rest of line in a file
};

