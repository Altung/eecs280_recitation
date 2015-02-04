#include <iostream>
using namespace std;


int main(int argc, char **argv) {

  // Our two "normal" variables
  double degrees_fahrenheit = 29;
  double inches_of_snow = 12;

  cout << "degrees_fahrenheit = " << degrees_fahrenheit << endl;
  cout << "inches_of_snow = " << inches_of_snow << endl;
  cout << endl;

  // Declare a pointer and use it to change degrees_fahrenheit
  double *ptr = nullptr;
  ptr = &degrees_fahrenheit;
  *ptr = 20;

  cout << "degrees_fahrenheit = " << degrees_fahrenheit << endl;
  cout << "inches_of_snow = " << inches_of_snow << endl;
  cout << endl;

  // Reassign the pointer (this doesn't affect degrees_fahrenheit) and use it
  // to change inches_of_snow
  ptr = &inches_of_snow;
  *ptr = 14;

  cout << "degrees_fahrenheit = " << degrees_fahrenheit << endl;
  cout << "inches_of_snow = " << inches_of_snow << endl;
  cout << endl;

  return 0;
}
