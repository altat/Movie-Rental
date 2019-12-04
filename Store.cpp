#include "Store.h"

// constructor
Store::Store()
{
}

// destructor
Store::~Store()
{
  for (auto F : Comedies) delete F;
  for (auto D : Dramas) delete D;
  for (auto C : Classics) delete C;

  while (!Commands.empty()) {
    auto T = Commands.front();
    Commands.pop();
    delete T;
  }
}

// readMovies creates and stores movie from a file
void Store::readMovies(ifstream& File)
{
  cout << "Start readMovies" << endl;
  Movie* M = nullptr;
  bool SuccessfulRead = false;
  string Genre;

  // loop over file
  for (;;) {
    File >> Genre;
    if (File.eof()) break; // stop if end of file reached
    Genre.pop_back(); // remove comma
    M = MovieFactory::create(Genre); // create correct type of Movie
    if (!M) { // discard and continue if Genre not found
      discardLine(File);
      continue;
    }
    SuccessfulRead = M->setData(File); // set Movie's data from file

    if (SuccessfulRead) addInventory(M, Genre); // add if file read correctly
    else delete M;
  }
  cout << "End readMovies" << endl;
}

// readCustomers creates and stores customers from a file
void Store::readCustomers(ifstream& File)
{
  cout << "Start readCustomers" << endl;
  Customer* C = nullptr;
  bool SuccessfulRead = false;

  // loop over file
  for (;;) {
    C = new Customer();
    SuccessfulRead = C->setData(File); // set data from file

    if (File.eof()) { // end of file reached
      delete C;
      break;
    }

    if (SuccessfulRead) Customers.add(C); // add if data is valid
    else {
      delete C;
      cout << "Invalid Customer ID" << endl;
    }
  }
  cout << "End readCustomers" << endl;
}

// readCommands creates and stores transactions from a file
void Store::readCommands(ifstream& File)
{
  cout << "Start readCommands" << endl;
  Transaction* T = nullptr;
  bool SuccessfulRead = false;
  string Type;

  // loop over file
  for (;;) {
    File >> Type;
    if (File.eof()) break; // end of file reached
    T = TransactionFactory::create(Type);
    if (!T) { // invalid transaction type
      discardLine(File);
      continue;
    }
    SuccessfulRead = T->setData(File); // set transaction data from file

    if (SuccessfulRead) Commands.push(T); // add if data was valid
    else { // otherwise discard line and delete transaction
      discardLine(File);
      delete T;
    }
  }
  cout << "End readCommands" << endl;
}

// addInventory adds a Movie to the correct movie container
// first param is Movie to add and second is Genre of Movie
// returns true if added, false if not
bool Store::addInventory(Movie* M, const string& Genre)
{
  return addHelper(getInventory(Genre), M);
}
// addHelper is helper function to addInventory.
// first param is movie container to add Movie to
// second param is Movie to add
// inserts movie into container in sorted order
// returns true if added, false if not
bool Store::addHelper(vector<Movie*>& S, Movie* M)
{
  // if empty just add
  if (S.empty()) {
    S.push_back(M);
    return true;
  }

  // otherwise find index to insert into
  auto It = S.begin();
  for (auto I : S) {
    // if Movie is already in container, then don't add
    if (*M == *I) {
      delete M;
      return false;
    }
    // if Movie is less than current, add
    if (*M < *I) {
      S.insert(It, M);
      return true;
    }
    It++; // increment iterator to index and continue
  }
  // index not found so insert at end
  S.push_back(M);
  return true;
}

// discardLine discards a line in the given file (param)
void Store::discardLine(ifstream& F)
{
  F.ignore(1000, '\n');
}

// getInventory returns a reference to one of the movie containers
//              based on Genre (param)
vector<Movie*>& Store::getInventory(const string& Genre)
{
  if (Genre == "F") return Comedies;
  if (Genre == "D") return Dramas;
  if (Genre == "C") return Classics;
  return Dummy; // return Dummy if Genre doesn't exist
}

// getter for Customers container
HashTable& Store::getCustomers()
{
  return Customers;
}

// displays each movie in sorted order. Starts from Comedies, then Dramas, and finally
// Classics.
void Store::displayInventory()
{
  cout <<
    "--------------------------------------------------------------" << endl;
  cout << "Comedies:" << endl;
  for (auto F : Comedies)
    F->display();
  
  cout <<
    "--------------------------------------------------------------" << endl;
  cout << "Dramas:" << endl;
  for (auto D : Dramas)
    D->display();

  cout <<
    "--------------------------------------------------------------" << endl;
  cout << "Classics:" << endl;
  for (auto C : Classics)
    C->display();

  cout <<
    "--------------------------------------------------------------" << endl;
}

// buildStore builds the movie, customer, and transaction containers from file
// first param is name of movie file, second is customer file name, and third
// is transaction file name.
// returns true if files can be opened and read, false if not
bool Store::buildStore(const string& MFile, const string& CFile, const string& 
  TFile)
{
  cout << "Start buildStore" << endl;
  ifstream InFileM(MFile);
  ifstream InFileC(CFile);
  ifstream InFileT(TFile);

  // files can't be read
  if (!InFileM || !InFileC || !InFileT) {
    cout << "Could not open files" << endl;
    return false;
  }

  readMovies(InFileM);
  readCustomers(InFileC);
  readCommands(InFileT);
  cout << "End buildStore" << endl;
  return true;
}

// execute processes each transaction in the Commands queue
void Store::execute()
{
  cout << "Start execute" << endl;
  // loop over Commands queue
  while (!Commands.empty()) {
    auto T = Commands.front();
    Commands.pop(); // remove front
    char C = T->getCommand();
    if (C == 'I') { // display inventory if front transaction is Inventory
      displayInventory();
      delete T;
    }
    else if (C == 'H') {// History does not need movie container
      T->doTransaction(Dummy, Customers);
      delete T;
    }
    // process normally for other transaction types
    else T->doTransaction(getInventory(T->getTMovie()->getGenre()), Customers);
  }
  cout << "End execute" << endl;
}
