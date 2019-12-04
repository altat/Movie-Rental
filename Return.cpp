#include "Return.h"

Return::Return()
{
  CustomerID = 0;
  TMovie = nullptr;
}

Return::~Return() {
  delete TMovie;
}

// sets data from transaction file
// returns true if data in file was valid
bool Return::setData(ifstream& File)
{
  string Genre;
  File >> CustomerID >> MediaType >> Genre;
  TMovie = MovieFactory::create(Genre); //create Movie based on Genre
  if (!TMovie) return false; //invalid Movie Genre
  TMovie->setTData(File); //set Movie's sorting attributes
  return true;
}

// processes the Return
void Return::doTransaction(const vector<Movie*>& M, const HashTable& Customers) 
{
  // find Customer
  Customer* TCustomer;
  TCustomer = Customers.retrieve(CustomerID);
  if (!TCustomer) cout << "Customer " << CustomerID << " not found, ";

  // find Media
  Movie* Temp = retrieveMovie(M, TMovie);
  if (!Temp) cout << "Movie: " << TMovie->tDisplay() << " not found, ";

  // if both found
  if (TCustomer && Temp) {
    // if customer has borrowed Movie
    if (TCustomer->hasMovie(Temp)) {
      // update Customer's History
      TCustomer->addTransaction(this);
      // increase Stock
      Temp->increaseStock();
    }
    else { // Movie was never borrowed
      cout << "Return failed: Customer hasn't borrowed Movie: " 
        + Temp->tDisplay() << endl;
      delete this;
    }
  }

  // otherwise send error
  else {
    cout << "Return failed." << endl;
    delete this;
  }
}

// displays this Return's data members
void Return::display() const {
  cout << "Return: " << MediaType << " " << TMovie->tDisplay() << endl;
}

char Return::getCommand() const
{
  return COMMAND;
}

Movie* Return::getTMovie() const
{
  return TMovie;
}
