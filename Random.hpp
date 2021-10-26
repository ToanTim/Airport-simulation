/* Program extracts from Appendix B of
   "Data Structures and Program Design in C++"
   by Robert L. Kruse and Alexander J. Ryba
   Copyright (C) 1999 by Prentice-Hall, Inc.  All rights reserved.
   Extracts from this file may be used in the construction of other programs,
   but this code will not compile or execute as given here. */

#include <time.h>
#include <limits.h>
#include <math.h>

// Section B.2:

class Random {
public:
   Random(bool pseudo = true);
//    Declare random-number generation methods here.
    double random_real();
    int random_integer(int low, int high);
    int poisson(double mean);
 private:
   int reseed(); //  Re-randomize the seed.
   int seed,
       multiplier, add_on; //  constants for use in arithmetic operations
};
