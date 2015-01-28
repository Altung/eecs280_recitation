#include <iostream>
#include "recursive.h"

using namespace std; 

void print_tree_trav(tree_t tree);


int main() {
  int elt = 1; 

  tree_t tree_l = tree_make(elt, tree_make(), tree_make());
  elt++;
  tree_t tree_r = tree_make(elt, tree_make(), tree_make());
  elt++;
  tree_t tree_tot1 = tree_make(elt, tree_l, tree_r);
  //tree_print(tree_tot1);
  elt++;
  tree_l = tree_make(elt, tree_make(), tree_make());
  elt++;
  tree_r = tree_make(elt, tree_make(), tree_make());
  elt++;
  tree_t tree_tot2 = tree_make(elt, tree_l, tree_r);
  //tree_print(tree_tot2);
  elt++;
  tree_t tree_tot = tree_make(elt, tree_tot1, tree_tot2);
  tree_print(tree_tot);

  print_tree_trav(tree_tot);

}


void print_tree_trav(tree_t tree) {
  if (tree_isEmpty(tree)) {
    return; 
  }
  int elt = tree_elt(tree);
  //pre
  print_tree_trav(tree_left(tree));
  //in
  cout << elt << endl; 
  print_tree_trav(tree_right(tree));
  //post
}
