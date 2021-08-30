//
//  main.cpp
//  VolumeConvert
//
//  Created by max on 8/24/21.
//

#include <iostream>
using namespace std;

int main() {
    float ounce;
    cout << "Enter volume in ounces:\n";
    cin >> ounce;
    cout << "Ounces: " << ounce << endl;
    cout << "Cups: " << ounce/8 << endl;
    cout << "Pints: " << ounce/16 << endl;
    cout << "Gallons: " << ounce/128 << endl;
    cout << "Liters: " << ounce*0.0296 << endl;
    cout << "Cubic Inches: " << ounce*1.8 << endl;
    
    return 0;
}
