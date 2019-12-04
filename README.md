# Movie Store

## Replace all TODO with actual information

Author(s): Tanvir Tatla

GitHub URL: https://github.com/uwbclass/movies-altat

Expected Mark: 100%

## Checklist

Development Platform: Windows

Tested on CSS Linux Lab: Yes

Tested on Travis: Yes

clang-tidy messages: None

Excluded clang-tidy checks:
- Wunused-parameter: allow unused parameters (overridden functions require parameters but they don't always need to be used)
- readability-implicit-bool-conversion: allow (!Ptr) instead of (Ptr == nullptr)
- readability-implicit-bool-cast: allow (!Ptr) instead of (Ptr == nullptr)
- hicpp-use-override: allow lack of override for child class functions
- modernize-use-override: allow lack of override for child class functions
- readability-named-parameter: allow parameters to be unnamed (mostly in h files)
- hicpp-use-equals-default: allow lack of = default; for constructors
- modernize-use-equals-default: allow lack of = default; for constructors
- modernize-use-default: allow lack of = default; for constructors
- cppcoreguidelines-pro-type-member-init: allow constructors to not initialize fields
- hicpp-member-init: allow constructors to not initialize fields
- modernize-loop-convert: allow for (int I; I < Value; I++) loops
- llvm-include-order: allow out of order includes
- google-runtime-references: allow non-const reference params
- performance-unnecessary-value-param: allow passing values that are copied once

valgrind messages: None

## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: TransactionFactory's create function

invalid movie type: MovieFactory's create function

invalid customer ID: Store's readCustomer function
 
invalid movie: Borrow and Return's doTransaction function

factory classes: MovieFactory and TransactionFactory

hashtable: Used to store Customers. Used in Store.

container used for comedy movies: Store.h vector<Movie*> Comedies

function for sorting comedy movies: Comedy's operator< is used by Store's addHelper to insertion sort Movies

function where comedy movies are sorted: Store's addHelper inserts movies into the container in sorted order. addHelper assumes the Movie has an operator<

functions called when retrieving a comedy movie based on title and year: Transaction's retrieveMovie function

functions called for retrieving and printing customer history: Customer's displayHistory function, Transaction's display function

container used for customer history: Customer.h vector<Transaction*> History

functions called when borrowing a movie: Borrow's doTransaction

explain borrowing a movie that does not exist: Borrow's doTransaction

explain borrowing a movie that has 0 stock: Borrow's doTransaction

explain returning a movie that customer has not checked out: Return's doTransaction

any static_cast or dynamic_cast used: Comedy, Drama, and Classic's operator== and operator<


