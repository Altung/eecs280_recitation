#include <cassert>


int main(int argc, char **arv) {

  assert(5 > 4);            // Execution continues as usual
  assert(7 * 2 == 20);      // The program dies and prints an error message

}
