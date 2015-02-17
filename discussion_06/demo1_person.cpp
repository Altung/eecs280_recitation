/*
To compile: g++ demo1_person.cpp -o demo
To run:     ./demo
*/

#include <iostream>
#include <string>

using namespace std;


struct Person {
  string name;
  
  int weight;
  int height;

  Person *mother;
  Person *father;
};


void feed_food(Person *p, int lbs);


int main(int argc, char **argv) {
  // Plain old structs

  Person mom;
  mom.name = "Alice";

  Person dad;
  dad.name = "Bob";

  Person me;
  me.name = "Mallory";
  me.weight = 140;
  me.height = 64;
  me.mother = &mom;
  me.father = &dad;

  cout << me.name << endl;

  // Using pointers to structs

  Person *ptr = NULL;
  cout << "Value of ptr: " << ptr << endl;
  
  ptr = &me;
  cout << "Value of ptr: " << ptr << endl;
  cout << "Value of ptr->name: " << ptr->name << endl;

  ptr->name = "Mallory Jr";
  cout << "Value of ptr->name: " << ptr->name << endl;  

  // Passing structs to functions by pointer

  cout << "ptr->weight: " << ptr->weight << endl;
  feed_food(ptr, 10);
  cout << "ptr->weight: " << ptr->weight << endl;

  return 0;
}


// Passing a struct to a function by pointer
void feed_food(Person *p, int lbs) {
  p->weight += lbs;

  // This would also work:
  // (*p).weight += lbs

  // This would compile, but p remains unchanged:
  // Person q = *p;
  // q.weight += lbs;

  // This would compile, and moves where our pointer is pointing to
  // p++;
}
