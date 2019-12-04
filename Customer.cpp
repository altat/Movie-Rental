#include "Customer.h"
#include "Transaction.h"

Customer::Customer() {
  ID = -1;
  First = "";
  Last = "";
}

Customer::~Customer() {
  for (auto T : History) {
    delete T;
  }
}

int Customer::getID() {
  return ID;
}

// adds parameter to History
void Customer::addTransaction(Transaction* T)
{
  History.push_back(T);
}

// displays each Transaction in History
void Customer::displayHistory()
{
  cout <<
    "--------------------------------------------------------------" << endl <<
    "Customer " << ID << "'s History:" << endl;
  for (auto T : History)
    T->display();

  cout <<
    "--------------------------------------------------------------" << endl;
}

// sets data from file. assumes formatting is correct
bool Customer::setData(std::ifstream& File)
{
  File >> ID >> Last >> First;
  return (ID >= MIN_ID && ID <= MAX_ID);
}

// returns true if Movie is currently being borrowed
bool Customer::hasMovie(Movie* M)
{
  int B = 0;
  int R = 0;
  // for each Transaction in History
  for (auto T : History) {
    // if M (parameter) is found in Borrowed Transaction
    if (T->getCommand() == 'B' && T->getTMovie()->tDisplay() == M->tDisplay())
      B++; // increment B
    // do the same for Return transaction
    else if (T->getCommand() == 'R' &&
      T->getTMovie()->tDisplay() == M->tDisplay())
      R++;
  }
  return R < B; // return whether number of Returns is less than Borrows
}

