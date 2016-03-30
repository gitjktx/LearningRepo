// --------
// includes
// --------
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// ------------
// get_cycle_length
// ------------

/**
 * @param i the number for cycle length calculation
 * @return the max cycle length of the range [i, j]
 */
int get_cycle_length (int i);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int num = i;
    int max_num = j;
    int cycle_length = 1;
    int max_cycle_length = 1;
    
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
    long num = i;
    int cl = 1; // cycle length
    
    if (num == 1) // initial condition
    {
        //cout<<num<<" is odd, so multiply by 3 and add 1"<<endl;
        num=num*3+1;
        ++cl;
    }
    
    while (num != 1)
    {
        if (num & 1) // odd
        {
            //cout<<num<<" is odd, so multiply by 3 and add 1"<<endl;
            num=num*3+1;
            ++cl;
        }
        else // even
        {
            //cout<<num<<" is even, so divide by 2"<<endl;
            //num=num/2;
            num=num>>1;
            ++cl;
        }
    }
    
    //cout<<i<<" has the cycle length of "<<cl<<endl;
    return cl;
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
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}


// ----
// main
// ----
int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;
}
