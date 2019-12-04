#pragma once
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
#include "Transaction.h"

//----------------------------------------------------------------------------
// Class: TransactionFactory
// factory class for building of transaction objects. Creates a child of 
// Transaction based on a predefined transaction type) 
//  
//----------------------------------------------------------------------------

class TransactionFactory
{
public:
  TransactionFactory();
  ~TransactionFactory();

  // creates a child of Transaction based on the transaction type (paramter)
  static Transaction* create(const string&);

private:
};

