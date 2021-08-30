//
//  main.cpp
//  RoadTripCalculator
//
//  Created by max on 8/24/21.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    float miles,efficiency, cost;
    cout << "enter the driving distance, in (whole) miles: ";
    cin >> miles;
    cout << "enter the vehicle's miles per gallon efficiency: ";
    cin >> efficiency;
    cout << "enter the cost of gas in dollars per gallon: ";
    cin >> cost;
    
    cout << "The total cost of the trip is: " << (miles/efficiency)*cost << endl;
    
    
    return 0;
}
