#include "TransactionFactory.h"

TransactionFactory::TransactionFactory()
{
}

TransactionFactory::~TransactionFactory()
{
}

// creates a child of Transaction based on the transaction type
// parameter is transaction type. Valid types are currently B, R, H, and I.
// returns nullptr if invalid type is passed
Transaction* TransactionFactory::create(const string& Type)
{
  if (Type == "B") return new Borrow();
  if (Type == "R") return new Return();
  if (Type == "H") return new History();
  if (Type == "I") return new Inventory();
  cout << "Invalid command code" << endl;
  return nullptr;
}
