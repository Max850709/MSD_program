//
//  main.cpp
//  RomanNumerals
//
//  Created by max on 8/26/21.
//

#include <iostream>
using namespace std;

int main() {
    int decimal_date;
    cout << "enter a decimal number:\n";
    cin >> decimal_date;
    
    string roman_date;
    if(decimal_date<=0){
        cout << "Invalid input\n";
        cout << "enter a decimal number:\n";
        cin >> decimal_date;
    }
    while(decimal_date!=0){
        if(decimal_date>=1000){
            int a=decimal_date/1000;
            roman_date+=string(a,'M');
            decimal_date-=a*1000;
        }
        else if(decimal_date>=900 && decimal_date<1000){
            roman_date+="CM";
            decimal_date-=900;
        }
        else if(decimal_date>=500 && decimal_date<900){
            int a=decimal_date/500;
            roman_date+=string(a,'D');
            decimal_date-=a*500;
        }
        else if(decimal_date>=400 && decimal_date<500){
            roman_date+="CD";
            decimal_date-=400;
        }
        else if(decimal_date>=100 && decimal_date<400){
            int a=decimal_date/100;
            roman_date+=string(a,'C');
            decimal_date-=a*100;
        }
        else if(decimal_date>=90 && decimal_date<100){
            roman_date+="XC";
            decimal_date-=90;
        }
        else if(decimal_date>=50 && decimal_date<90){
            roman_date+="L";
            decimal_date-=50;
        }
        else if(decimal_date>=40 && decimal_date<50){
            roman_date+="XL";
            decimal_date-=40;
        }
        else if(decimal_date>=10 && decimal_date<40){
            int a=decimal_date/10;
            roman_date+=string(a,'X');
            decimal_date-=a*10;
        }
        else if(decimal_date>=9 && decimal_date<10){
            roman_date+="IX";
            decimal_date-=9;
        }
        else if(decimal_date>=5 && decimal_date<9){
            roman_date+="V";
            decimal_date-=5;
        }
        else if(decimal_date>=4){
            roman_date+="IV";
            decimal_date-=4;
        }
        else{
            roman_date+=string(decimal_date,'I');
            decimal_date=0;
        }
    }
    cout << "Roman numeral version:\n" << roman_date<<"\n";
    return 0;
}
