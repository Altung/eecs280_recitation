#include <iostream>
using namespace std;


int main(int argc, char **argv) {

  //
  //  Single-dimensional arrays
  //

  double weather_forecast[10];

  // Make predictions
  double degrees_fahrenheit = 29;
  for(int i = 0; i != 10; i++) {
    weather_forecast[i] = degrees_fahrenheit;
    degrees_fahrenheit *= 0.8;
  }

  // Output results
  cout << "Upcoming temperatures for Ann Arbor, MI:" << endl;
  for(int i = 0; i != 10; i++) {
    cout << "Feb " << (i + 4) << ": ";
    cout << weather_forecast[i];
    cout << " °F" << endl;
  }

  //
  //  Multi-dimensional arrays
  //

  char checkerboard[8][8];
  const char EMPTY = '.';
  const char BLACK = 'B';
  const char RED = 'R';

  // Initialize the board as empty
  for(int row = 0; row != 8; row++) {
    for(int col = 0; col != 8; col++) {
      checkerboard[row][col] = EMPTY;
    }
  }

  // Place the black checkers
  for(int row = 0; row != 3; row++) {
    int start_col = (row + 1) % 2;
    for(int col = start_col; col < 8; col += 2) {
      checkerboard[row][col] = BLACK;
    }
  }

  // Place the red checkers
  for(int row = 5; row != 8; row++) {
    int start_col = (row + 1) % 2;
    for(int col = start_col; col < 8; col += 2) {
      checkerboard[row][col] = RED;
    }
  }

  // Output results
  cout << "-----------------" << endl;
  for(int row = 0; row != 8; row++) {
    for(int col = 0; col != 8; col++) {
      cout << checkerboard[row][col];
    }
    cout << endl;
  }

  return 0;
}
