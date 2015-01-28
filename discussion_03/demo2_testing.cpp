#include <cassert>


bool divisible_by_7(int num);


int main(int argc, char **arv) {
  int test_case = 21;

  bool my_solution = divisible_by_7(test_case);
  bool correct_solution = true;

  assert(my_solution == correct_solution);    // This will fail; we have a bug!
}


// Returns true iff the number is divisible by 7
bool divisible_by_7(int num) {
  bool result = num % 8 == 0;   // Oops
  return result;
}
