/*
Some fun things to explore:

g++ demo.cpp -o demo

Try getting the number of factors of a large number like 123456789 -- the
iterative version did fine, but the tail-recursive version konks out!  Why?
The way we invoked g++ didn't turn on any compiler optimizations, meaning that
tail-recursive calls aren't optimized and are no better than their recursive
counterparts!  We created about 123456789 stack frames and ran out of memory.

g++ demo.cpp -O3 -o demo

Hoozah!  This time, we used the -O3 (uppercase oh, not zero) g++ option to turn
on compiler optimizations.  Tail-recursive calls are optimized like discussed in
class, so we only ever used about one stack frame for all of those 1234567879
recursive function calls.
*/

#include <iostream>

using namespace std;


// Usually these would go have RME's, but this is simply a demo
int count_factors_iter(int n);
int count_factors_tail(int n);
int count_factors_tail_help(int n, int i, int so_far);


int main(int argc, char **argv) {
  // Get a value for n from the user
  int num;
  cout << "Enter an integer >= 1 to compute number of factors: ";
  do {
    cin >> num;
  } while(num < 1);

  // Compute n in two ways
  cout << "Iterative:      " << count_factors_iter(num) << endl;
  cout << "Tail-recursive: " << count_factors_tail(num) << endl;

  return 0;
}


int count_factors_iter(int n) {
  int i = 1;                          // PART A: initialization
  int so_far = 0;

  while(i <= n) {                     // PART B: base case
    if(n % i == 0) {                  // PART C: logic
      so_far++;
    }
    i++;
  }                                   // PART D: loop

  return so_far;
}


int count_factors_tail(int n) {
  int i = 1;                          // PART A: initialization
  int so_far = 0;

  return count_factors_tail_help(n, i, so_far);
}


int count_factors_tail_help(int n, int i, int so_far) {
  if(!(i <= n)) {                     // PART B: base case
    return so_far;
  }

  if(n % i == 0) {                    // PART C: logic
    so_far++;
  }
  i++;

  return count_factors_tail_help(n, i, so_far);   // PART D: loop
}
