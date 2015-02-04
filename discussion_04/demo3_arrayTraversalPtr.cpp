#include <iostream>
using namespace std;


int main(int argc, char **argv) {

  //
  //  Single-dimensional arrays
  //

  double weather_forecast[10];

  // Make predictions
  double degrees_fahrenheit = 29;
  for(double *ptr = weather_forecast; ptr != weather_forecast + 10; ptr++) {
    *ptr = degrees_fahrenheit;
    degrees_fahrenheit *= 0.8;
  }

  // Output results
  cout << "Upcoming temperatures for Ann Arbor, MI:" << endl;
  for(double *ptr = weather_forecast; ptr != weather_forecast + 10; ptr++) {
    cout << "Feb " << (ptr - weather_forecast + 4) << ": ";
    cout << *ptr;
    cout << " °F" << endl;
  }

  return 0;
}
