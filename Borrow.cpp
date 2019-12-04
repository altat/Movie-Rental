#include "Borrow.h"

Borrow::Borrow() 
{
  CustomerID = 0;
  TMovie = nullptr;
}

Borrow::Borrow(Movie* M, int CID)
{
  TMovie = M;
  CustomerID = CID;
}

Borrow::~Borrow()
{
  delete TMovie;
}

// sets data from transaction file
// returns true if valid Movie Genre
bool Borrow::setData(ifstream& File)
{
  string Genre;
  File >> CustomerID >> MediaType >> Genre;
  TMovie = MovieFactory::create(Genre); //create Movie based on Genre
  if (!TMovie) return false; // invalid Genre
  TMovie->setTData(File); // set Movie's sorting attributes data
  return true;
}

void Borrow::doTransaction(const vector<Movie*>& M, const HashTable& Customers)
{
  // find customer
  Customer* TCustomer;
  TCustomer = Customers.retrieve(CustomerID);
  if (!TCustomer) cout << "Customer " << CustomerID << " not found, ";

  // find Media
  Movie* Temp = retrieveMovie(M, TMovie);
  if (!Temp) cout << "Movie: " + TMovie->tDisplay() << " not found, ";

  // if both found
  if (TCustomer && Temp) {
    // if Movie stock greater than zero
    if (Temp->getStock() > 0) {
      // update Customer's History
      TCustomer->addTransaction(this);
      // decrease Stock
      Temp->decreaseStock();
    }
    else { // out of stock error
      cout << "Borrow failed: Out of Stock: " << Temp->tDisplay() << endl;
      delete this;
    }
  }

  // otherwise send error
  else {
    cout << "Borrow failed" << endl;
    delete this;
  }
}

// display this Borrow's data members
void Borrow::display() const
{
  cout << "Borrow: " << MediaType << " " << TMovie->tDisplay() << endl;
}

char Borrow::getCommand() const
{
  return COMMAND;
}

Movie* Borrow::getTMovie() const
{
  return TMovie;
}
