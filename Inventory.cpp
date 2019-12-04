#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

bool Inventory::setData(ifstream&)
{
  return true;
}

void Inventory::doTransaction(const vector<Movie*>&, const HashTable&)
{
}

void Inventory::display() const
{
}

char Inventory::getCommand() const
{
  return COMMAND;
}

Movie* Inventory::getTMovie() const
{
  return nullptr;
}
