#include <iostream>
using namespace std;


void not_magic(int val);
void magic(int *ptr);


int main(int argc, char **argv) {

  // Our "normal" variable "outside"
  int normal_variable = 50;
  cout << "MAIN()" << endl;
  cout << "normal_variable = " << normal_variable << endl;
  cout << endl;

  // Pass the value of normal_variable
  not_magic(normal_variable);
  cout << "MAIN()" << endl;
  cout << "normal_variable = " << normal_variable << endl;
  cout << endl;

  // Pass the memory address of normal_variable
  magic(&normal_variable);
  cout << "MAIN()" << endl;
  cout << "normal_variable = " << normal_variable << endl;
  cout << endl;

  return 0;
}


void not_magic(int val) {
  // This change only affects our variable inside, since it's not a pointer
  val = 70;

  cout << "NOT_MAGIC()" << endl;
  cout << "val = " << val << endl;
  cout << endl;
}


void magic(int *ptr) {
  // Change the value "outside" of this function
  *ptr = 30;

  cout << "MAGIC()" << endl;
  cout << "ptr =  " << ptr << endl;
  cout << "*ptr = " << *ptr << endl;
  cout << endl;
}
