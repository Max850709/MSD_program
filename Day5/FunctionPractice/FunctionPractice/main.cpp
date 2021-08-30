//
//  main.cpp
//  FunctionPractice
//
//  Created by max on 8/27/21.
//

#include <iostream>
#include <math.h>
using namespace std;

double fuc_hypotenuse(int num1, int num2){
    double temp = (double)(2*num1*num2);
    double number= sqrt (temp);
    return number;
}

bool isCapitalized(string s){
    if(s[0]>=65 && s[0]<=90){
        return true;
    }
    else{
        return false;
    }
    
}

string boolToString(bool bo){
    string a="true", b="false";
    if(bo==1){
        return a;
    }
    return b;
}

bool isPrime(int n){
    int temp=1,factor=0;
    while(temp<=n){
        if(n%temp==0){
            factor+=1;
        }
        temp++;
    }
    if(factor==2){
        return true;
    }
    return false;
}

int main() {
    int first_side,second_side;
    cout << "enter the first side lengths of a triangle: ";
    cin >> first_side;
    cout << "enter the second side lengths of a triangle: ";
    cin >> second_side;
    double temp = (double)(2*first_side*second_side);
    double hypotenuse= sqrt (temp);
    cout << "hypotenuse is: " << hypotenuse << "\n";
    cout << "-----------------------------------\n";
    
    double speed,angle;
    cout << "input the speed: ";
    cin >> speed;
    cout << "enter the angle: ";
    cin >> angle;
    
    double x = speed*cos(angle);
    double y = speed*sin(angle);
    cout << "X velocity is " << x << "\n";
    cout << "Y velocity is " << y << "\n";
    cout << "-----------------------------------\n";
    
    std::time_t result = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&result))
                  << result << " seconds since the Epoch\n";
    cout << "The fuction time returns the current calendar time. asctime converts the given calendar time of structure tm to a character representation. Localtime returns the local time. \n";
    cout << "-----------------------------------\n";
    
    cout << "The funciton that performs the hypotenuse is " << fuc_hypotenuse(first_side,second_side) << "\n";
    cout << "-----------------------------------\n";
    
    cout << "Because the function can only return one value. However we can put the two values into a vector or array and return that one.";
    cout << "-----------------------------------\n";
    
    string str;
    cout << "enter a string: ";
    cin >> str;
    cout << str;
    cout << "The first word is capital (1/0): " << isCapitalized(str) << "\n";
    cout << "-----------------------------------\n";
    
    cout << "The first word is capital (true/false): " << boolToString(isCapitalized(str)) << "\n";
    cout << "-----------------------------------\n";
    
    int num;
    cout << "enter a number: ";
    cin >> num;
    cout << "The number is a prime(1/0): " << isPrime(num) <<"\n";
    return 0;
}
