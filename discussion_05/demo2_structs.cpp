#include <iostream>

using namespace std;


// Crayon is a struct. It describes a kind of "object" which has some set of
// properties. You can relate structs with real-world objects. Every single
// Crayon object has its own copy of color and length, just like the real world.
struct Crayon {
  string color;
  int length;
};


void demo_0();
void demo_1();
void demo_2();
void demo_3();
void demo_4();
void double_my_array(int arr[], unsigned int size);
void shorten_crayons(Crayon arr[], unsigned int size);


int main(int argc, char **argv) {
  if(argc != 2) {
    cout << "usage: " << argv[0] << " <0-4>" << endl;
    return 0;
  }

  // An array of function pointers -- don't worry about this for now
  void (*demo_functions[5])() = {demo_0, demo_1, demo_2, demo_3, demo_4};

  if(argv[1][0] >= '0' && argv[1][0] <= '4') {
    cout << "Running demo_" << argv[1][0] << "()..." << endl << endl;

    // Calling the function pointer -- hacky char arithmetic
    demo_functions[argv[1][0] - '0']();

    cout << endl;
  } else {
    cout << "usage: " << argv[0] << " <0-4>" << endl;
  }

  return 0;
}


void demo_0() {
  // The variable "array" holds 7 strings. Indexes 0-6 are valid
  string array[7];
  array[0] = "hello";
  array[1] = "EECS";
  array[2] = "280";
  array[3] = "this";
  array[4] = "is";
  array[5] = "an";
  array[6] = "array";

  // Watch out for that end condition -- we can't access array[7]
  for(int i = 0; i != 7; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


void demo_1() {
  // An easier way to initialize an array
  string array[4] = {"check", "out", "this", "initialization"};

  for(int i = 0; i != 4; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


void double_my_array(int arr[], unsigned int size) {
  // We expect an array of ints. We can access/modify them as we please and
  // the changes will show up "outside" the function

  for(int i = 0; i != size; i++) {
    arr[i] = arr[i] * 2;
  }
}


void demo_2() {
  // Create an array of 5 ints, 01234
  int array[5];
  for(int i = 0; i != 5; i++) {
    array[i] = i;
  }

  // Output original values
  cout << "Before: ";
  for(int i = 0; i != 5; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  // We pass the array *by reference* to the function, which expects int arr[]
  double_my_array(array, 5);

  // The values "out here" were modified by the function
  cout << "After:  ";
  for(int i = 0; i != 5; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


void demo_3() {
  // Variable "array" holds 3 Crayon objects, which act just like normal
  Crayon array[3];
  array[0].color = "Red";
  array[0].length = 10;
  array[1].color = "Green";
  array[1].length = 3;
  array[2].color = "Blue";
  array[2].length = 8;

  // Orignal values
  cout << "Before: ";
  for(int i = 0; i != 3; i++) {
    cout << array[i].color << " " << array[i].length << ", ";
  }
  cout << endl;

  // Overwrite one of the elements in the array
  Crayon other_crayon;
  other_crayon.color = "Purple";
  other_crayon.length = 17;

  array[1] = other_crayon;

  // New values
  cout << "After:  ";
  for(int i = 0; i != 3; i++) {
    cout << array[i].color << " " << array[i].length << ", ";
  }
  cout << endl;
}


void shorten_crayons(Crayon arr[], unsigned int size) {
  // We expect an array of Crayons. It acts just like the array of ints from
  // double_my_array -- structs instead of ints doesn't matter

  for(int i = 0; i != size; i++) {
    // We can access struct values by reference as if it were a local, and
    // they'll change "on the outside". We first index in i spots, then
    // access the length variable inside the struct
    arr[i].length = arr[i].length - 1;
  }
}


void demo_4() {
  // Variable "array" holds 3 Crayon objects, which act just like normal
  Crayon array[3];
  array[0].color = "Red";
  array[0].length = 10;
  array[1].color = "Green";
  array[1].length = 3;
  array[2].color = "Blue";
  array[2].length = 8;

  // Output original values
  cout << "Before: ";
  for(int i = 0; i != 3; i++) {
    cout << array[i].color << " " << array[i].length << ", ";
  }
  cout << endl;

  // Like demo_2, pass in the array by reference. The array having structs
  // instead of ints doesn't change anything
  shorten_crayons(array, 3);

  // The values "out here" were modified by the function
  cout << "After:  ";
  for(int i = 0; i != 3; i++) {
    cout << array[i].color << " " << array[i].length << ", ";
  }
  cout << endl;
}
