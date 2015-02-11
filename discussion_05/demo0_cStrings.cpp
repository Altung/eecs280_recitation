// USAGE:
// g++ demo0_cStrings.cpp -o demo0
// ./demo0

#include <iostream>
#include <cstring>

using namespace std;


void demo_0();
void demo_1();
void demo_2();
unsigned int cstring_length(const char *a);
void cstring_shift(char a[]);


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
  char my_string[] = "hello world";

  // We can output the entire c-string or index in like an array
  cout << "my_string:    " << my_string << endl;
  cout << "my_string[6]: " << my_string[6] << endl;

  // Changing an element (char) of the c-string/array
  my_string[1] = 'a';
  cout << "my_string:    " << my_string << endl;
}


void demo_1() {
  char a[] = "hello world";
  int j;

  // Print c-string by printing each element
  for(int i = 0; i != 11; i++) {
    cout << a[i];
  }
  cout << endl;

  // strlen() returns length of c-string
  for(int i = 0; i != strlen(a); i++) {
    cout << a[i];
  }
  cout << endl;

  // The last character of a c-string is always '\0', which marks the end
  j = 0;
  while(a[j] != '\0') {
    cout << a[j];
    j++;
  }
  cout << endl;

  // Similar to above. '\0' == 0 so we can use this loop too
  j = 0;
  while(a[j]) {
    cout << a[j];
    j++;
  }
  cout << endl;

  // Similar to above, but now with pointers. *p gets the value p points to
  char *p = a;
  while(*p) {
    cout << *p;
    p++;
  }
  cout << endl;
}


void demo_2() {
  char a[] = "hello world";

  cout << "Original: " << a << endl;
  cout << "Length:   " << cstring_length(a) << endl;

  // Pass the c-string by pointer, meaning the function can make changes to
  // the values we have "out here" as long as the argument isn't declared const
  cstring_shift(a);

  cout << "Shifted:  " << a << endl;
}


unsigned int cstring_length(const char *a) {
  unsigned int count = 0;

  // Get the memory address of the beginning of the c-string
  const char *const begin = a;

  // Scan over each element until we hit '\0'. We can't change the value of
  // *end, but we change where it points to
  const char *end = a;
  while(*end) {
    end++;
  }

  // We can subtract pointers of the same type and get an int result
  return end - begin;
}


void cstring_shift(char a[]) {
  // Scan over each element in the c-string and increment its value
  for(unsigned int i = 0; i != strlen(a); i++) {
    a[i]++;
  }
}
