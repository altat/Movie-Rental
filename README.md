# Movie Store

Author(s): Tanvir Tatla


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


