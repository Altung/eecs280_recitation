#include <iostream>

using namespace std;


bool is_big_number(int i);
bool is_odd(int i);
int multiply(int i, int j);

void output_result(bool (*fn)(int), int i);


int main(int argc, char **argv) {
  // We create a function pointer called fn.  Right now it isn't pointing to
  // anything -- it's "empty"
  bool (*fn)(int);

  // Make fn point to is_big_number().  Notice that the function declarations
  // (return type, number and type of arguments) are the same.  When we call
  // fn(), it will call is_big_number()
  fn = is_big_number;
  cout << fn(5) << ", " << fn(200) << endl;
  
  // Change what fn points to
  fn = is_odd;
  cout << fn(5) << ", " << fn(200) << endl;

  // Notice that we're passing in the bare function name, *not* with (). If we
  // also had the (), i.e. is_big_number(), we'd be making call to
  // is_big_number(), which returns a bool, and so would be passing in a bool
  // to the output_result() function instead of a function pointer like
  // it expects.
  output_result(is_big_number, 19);

  // output_result doesn't care what function we pass in as long as the type
  // declaration is correct
  output_result(is_odd, 19);

  // INCORRECT! The multiply() function has the wrong type declaration
  // output_result(multiply, 19);
}


// Returns true iff the number is big
bool is_big_number(int i) {
  return i > 100;
}


// Returns true iff the number is odd
bool is_odd(int i) {
  return (i % 2) == 1;
}

// Multiplies the two numbers together and returns the result
int multiply(int i, int j) {
  return i * j;
}

// Calls a bool function on some int and outputs the result
void output_result(bool (*fn)(int), int i) {
  // Calling fn() could do anything -- we don't know or care
  bool result = fn(i);
  
  cout << "The result is: " << result << endl;
}
