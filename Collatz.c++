// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

#define CacheSize 1000000
short cache[CacheSize];

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i = 0;
    int j = 0;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int num = i;
    int max_num = j;
    int cycle_length = 1;
    
    //if(i == 0 || j == 0)
    //{
    //    cout<<"Invalid input"<< endl;
    //    return 0;
    //}
    
    
    //if(i == 1 && j == 1)
    //    return max_cycle_length;
    
    
    if(i > j)
    {
        max_num = i;
        num = j;
    }
    
    int max_cycle_length = 0;
    while (num <= max_num)
    {
        cycle_length = get_cycle_length(num);
        ++num;
        
        
        // Check if cl is greater than max cl.
        if (cycle_length > max_cycle_length)
            max_cycle_length = cycle_length;
    }
    
    
    //cout<<"The maximum cycle length between "<<i<<" and "<<j<<" is "<<max_cycle_length<<endl;
    return max_cycle_length;
}

// -------------
// get_cycle_length
// -------------
int get_cycle_length(int i)
{
    /*assert(i > 0);
     
     int c = 1;
     
     while (i > 1)
     {
     //if ((i % 2) == 0)
     if(i & 1)
     i = (3 * i) + 1;
     else
     //i = (i / 2);
     i = i>>1;
     ++c;}
     
     assert(c > 0);
     
     return c;*/
    
    // 1000000
    assert(i > 0);
    
    short cycle;
    
    if (i >= CacheSize || cache[i - 1] == 0)
    {
        unsigned int num;
        
        if (i & 1)
            num = i * 3 + 1;
        else
            //num = i / 2;
            num = i>>1;
        
        cycle = 1 + get_cycle_length (num);
        
        if (i < CacheSize)
            cache[i - 1] = cycle;
    }
    else
        cycle = cache[i - 1];
    
    return cycle;
}


// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    cache[0] = 1;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        if(v == 0)
            return;
        else
            collatz_print(w, i, j, v);}}
