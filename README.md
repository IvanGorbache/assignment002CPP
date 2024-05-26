# CPP Assignment 002 / Operator Overloading

0) Namespace ariel:

0-0)class Graph:

    printGraph() A function that returns a string representation of the adjacency matrix.

    operator+ An overloading of the + operator that adds up two given matrices and returns a new matrix.

    operator+ An overloading the unary + operator that returns the matrix as is.

    Graph& operator++ An overloaing of the ++ operator that increments all cells where i!=j.
    
    Graph& operator++ An overloading of the pre increment operator that calls the increment operator.

    void operator+= An overloading of the += operator that adds the value of another same size matrix to our matrix

    operator- An overloading of the + operator that subtracts two given matrices and returns a new matrix.

    operator- An overloading the unary - operator that returns the matrix multiplied by -1

    operator-= An overloading of the -= operator that subtracts the value of another same size matrix to our matrix

    operator-- An overloaing of the -- operator that decrement all cells where i!=j.

    operator-- An overloading of the pre decrement -- operator that calls the decrement operator.

    operator* An overloaing of the * operator that multiplies the given matrix by a float scalar and returns a new matrix.

    operator*= An overloaing of the * operator that multiplies the given matrix by a float scalar.

    operator* An overloading of the * operator that multiplies two given matrices and returns a new matrix only and only if the new matrix is square

    operator*= An overloading of the *= operator that multiplies two given matrices and assigns it to us only and only if the new matrix is square 

    operator/ An overloaing of the / operator that divides the given matrix by a float scalar and returns a new matrix.

    operator/= An overloaing of the /= operator that divides the given matrix by a float scalar.

    operator> An operator that checks if a given graph is much larger than the other graph if it contains it if the original graph contains all the same edges and has more edges/vertecies

    operator< simply turns a<b into b>a && a!=b

    operator== checks if !(a>b) && !(b>a)

    operator!= checks !(a==b)

    operator>= checks a>b || a== b

    operator<= checks a<b || a== b