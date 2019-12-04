/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "Store.h"
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cassert>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string CFile = "testcommands-1.txt";
  stringstream Out;
  ifstream Fs(CFile);
  assert(Fs.is_open());
  char CommandType;
  string Discard;
  while (Fs >> CommandType) {
    Out << CommandType;
    getline(Fs, Discard);
  }
  Fs.close();
  string Result = "IHHBRIBBIH";
  assert(Out.str() == Result);
  cout << "End testStore1" << endl;
}

void testStoreT() {
  Customer C;
  auto M = new Comedy(10, "Carl Sagan", "Space", 1990);
  auto M2 = new Comedy(10, "Carl Sagan", "Space", 1991);
  Comedy M3(10, "Carl Sagan", "Pirates", 1990);
  auto T = new Borrow(M, 1234);
  C.addTransaction(T);

  assert(C.hasMovie(M));
  assert(!C.hasMovie(M2));

  assert(*M < *M2);
  assert(M3 < *M);
  delete M2;
}

void testStore15() {
  cout << "=====================================" << endl;
  cout << "Start TestStore1.5" << endl;
  Store S;
  if (S.buildStore("data4movies.txt", "data4customers.txt",
    "testcommands-1.txt"))
    S.execute();
  cout << "End TestStore1.5" << endl;
  cout << "=====================================" << endl;
}

void testStore2() {
  cout << "=====================================" << endl;
  cout << "=====================================" << endl;
  cout << "Start testStore2" << endl;
  Store S;
  if (S.buildStore("testmovies.txt", "testcustomers.txt",
    "testcommands.txt"))
    S.execute();
  cout << "End testStore2" << endl;
  cout << "=====================================" << endl;
  cout << "=====================================" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store S;
  if (S.buildStore("data4movies.txt", "data4customers.txt",
    "data4commands.txt"))
    S.execute();
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStoreT();
  testStore15();
  testStore2();
  testStoreFinal();
}
