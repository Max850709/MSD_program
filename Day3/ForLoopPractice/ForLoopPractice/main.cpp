//
//  main.cpp
//  ForLoopPractice
//
//  Created by max on 8/25/21.
//

#include <iostream>
using namespace std;

int main() {
    
    for(int i=0;i<10;i++){
        cout << i+1 << " ";
    }
    cout<<"\n";
    int i=0;
    while(i<10){
        cout << i+1 << " ";
        i++;
    }
    cout<<"\n-------------------------------\n";
    
    int num1,num2;
    cout << "Enter two numbers: \n";
    cin >> num1 >> num2;
    
    if(num2>num1){
        for(int i=num1;i<=num2;i++){
            cout << i << " ";
        }
    }
    else if(num1>num2){
        for(int i=num2;i<=num1;i++){
            cout << i << " ";
        }
    }
    cout<<"\n-------------------------------\n";
    
    for(int i=1;i<=20;i++){
        if(i%2!=0){
            cout << i << " ";
        }
    }
    cout<<"\n";
    for(int i=1;i<=20;i+=2){
        cout << i << " ";
    }
    //I prefer the one with if statement, it shows the thinking process, from 1-20 and then pick the odd numbers out of all the numbers.
    cout<<"\n-------------------------------\n";
    
    int num, total=0;
    cout << "Enter number: ";
    cin >> num;
    while(num>0){
        total+=num;
        cout << "Enter number: ";
        cin >> num;
    }
    cout << "Total= " << total;
    cout<<"\n-------------------------------\n";
    
    for(int i=1;i<=5;i++){
        cout << i << "X*:";
        for(int j=i;j<=5*i;j+=i){
            printf("%3d",j);
            //cout << j << " ";
        }
        cout<<"\n";
    }
    return 0;
}
