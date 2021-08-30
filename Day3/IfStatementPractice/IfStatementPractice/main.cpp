//
//  main.cpp
//  IfStatementPractice
//
//  Created by ChaoCHinYang and ZengPing Li on 8/25/21.
//

#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "please enter your age: ";
    cin >> age;
    
    if(age>=18){
        cout << "The user is old enough to vote\n";
    }
    if(age<18){
        cout << "The user is not old enough to vote\n";
    }
    
    if(age>=30){
        cout << "The user is old enough to run for senate\n";
    }
    if(age<30){
        cout << "The user is not old enough to run for senate\n";
    }
    
    if(age>80){
        cout << "You are the greatest generation\n";
    }
    if(age>60 && age<=80){
        cout << "You are the baby boomers\n";
    }
    if(age>40 && age<=60){
        cout << "You are the generation X\n";
    }
    if(age>20 && age<=40){
        cout << "You are the millennial\n";
    }
    if(age<=20){
        cout << "You are the iKid\n";
    }
    cout << "-------------------------------------------\n";
    
    char weekdayResponse;
    cout << "Enter whether or not it's a weekday:(Y/N) ";
    cin >> weekdayResponse;
    
    if(weekdayResponse=='Y'||weekdayResponse=='y'){
        cout << "It is a workday. Can't sleep!\n";
    }
    if(weekdayResponse=='N'||weekdayResponse=='n'){
        cout << "It is not a workday. You can get to sleep!\n";
    }
    
    cout << "Enter whether or not it's a holiday:(Y/N) ";
    cin >> weekdayResponse;
    if(weekdayResponse=='Y'||weekdayResponse=='y'){
        cout << "It is a holiday. You can get to sleep!\n";
    }
    if(weekdayResponse=='N'||weekdayResponse=='n'){
        cout << "It is not a holiday. Can't sleep!\n";
    }
    
    cout << "Enter whether or not have young children:(Y/N) ";
    cin >> weekdayResponse;
    //bool isWeekday;
    if(weekdayResponse=='Y'||weekdayResponse=='y'){
        cout << "Have young children. Can't sleep!\n";
    }
    if(weekdayResponse=='N'||weekdayResponse=='n'){
        cout << "Have no young children. You can get to sleep!\n";
    }
    
    return 0;
}
