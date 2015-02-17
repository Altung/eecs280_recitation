/*
To compile: g++ demo2_fruitPerson.cpp -o demo
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


struct Person {
  string name;
  
  int weight;
  int height;

  Person *mother;
  Person *father;
};


void eat_fruit(Person *p, const Fruit *f);


int main(int argc, char **argv) {
  Person p;
  p.name = "Bob";
  p.weight = 170;

  Fruit f;
  f.name = "Giant apple";
  f.weight = 2;

  cout << p.name << " weights " << p.weight << " lbs" << endl;
  eat_fruit(&p, &f);
  cout << p.name << " weights " << p.weight << " lbs" << endl;

  return 0;
}


void eat_fruit(Person *p, const Fruit *f) {
  p->weight += f->weight;
  cout << p->name << " ate the " << f->name << endl;
}
