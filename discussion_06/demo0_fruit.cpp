/*
To compile: g++ demo0_fruit.cpp -o demo
To run:     ./demo
*/

#include <iostream>
#include <string>

using namespace std;


struct Fruit {
  string name;
  string color;
  int weight;
  bool is_rotten;
};


void print_fruit(Fruit f);


int main(int argc, char **argv) {
  // Plain old structs

  Fruit pear;
  pear.name = "Pear";
  pear.color = "Green";

  Fruit banana;
  banana.name = "Banana";
  banana.color = "Yellow";

  // Arrays of structs

  Fruit basket[3];
  basket[0].name = "Apple";
  basket[0].color = "Red";
  basket[1] = pear;
  basket[2] = banana;

  // Passing structs to function by value

  for(int i = 0; i != 3; i++) {
    cout << "basket[" << i << "]: ";
    Fruit f = basket[i];
    print_fruit(f);
  }

  return 0;
}


// Passing a struct to a function by value
void print_fruit(Fruit f) {
  cout << f.color << " " << f.name << endl;
}
