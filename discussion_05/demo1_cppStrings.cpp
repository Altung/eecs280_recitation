// USAGE:
// g++ demo1_cppStrings.cpp -o demo1
// ./demo1

#include <iostream>
#include <string>

using namespace std;


void demo_0();
void demo_1();
void demo_2();
void string_shift(string &str);


int main(int argc, char **argv) {
  cout << endl << ".... Running demo_0()" << endl;
  demo_0();

  cout << endl << ".... Running demo_1()" << endl;
  demo_1();

  cout << endl << ".... Running demo_2()" << endl;
  demo_2();

  return 0;
}


void demo_0() {
  // Acts similar to the code: char my_string[] = "hello world";
  string my_string = "hello world";

  // We can output the entire string or index in like an array
  cout << "my_string:    " << my_string << endl;
  cout << "my_string[6]: " << my_string[6] << endl;

  // Changing an element (char) of the string
  my_string[1] = 'a';
  cout << "my_string:    " << my_string << endl;

  // Concatenating strings
  string other = "! It's a good day";
  my_string = my_string + other;
  cout << "modified:     " << my_string << endl;
}


void demo_1() {
  string a = "hello world";
  int j;

  // Print string by printing each element
  for(int i = 0; i != 11; i++) {
    cout << a[i];
  }
  cout << endl;

  // string.length() returns length of a string
  for(int i = 0; i != a.length(); i++) {
    cout << a[i];
  }
  cout << endl;

  // The last character of a string is NOT '\0'
  cout << a[a.length() - 1] << endl;
}


void demo_2() {
  string a = "hello world";

  cout << "Original: " << a << endl;
  cout << "Length:   " << a.length() << endl;

  // Pass the string by pointer, meaning the function can make changes to
  // the values we have "out here" as long as the argument isn't declared const
  string_shift(a);

  cout << "Shifted:  " << a << endl;
}


void string_shift(string &a) {
  // Scan over each element in the string and increment its value
  for(int i = 0; i != a.length(); i++) {
    a[i] = a[i] + 1;
  }
}
