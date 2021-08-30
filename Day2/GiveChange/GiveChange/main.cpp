//
//  main.cpp
//  GiveChange
//
//  Created by max on 8/24/21.
//

#include <iostream>
using namespace std;

int main() {
    int price,paid,change,num_quarters,num_dime,num_nickle,num_penny;
    cout << "Enter item price in cents:\n";
    cin >> price;
    cout << "Enter amount paid in cents:\n";
    cin >> paid;
    while(paid<price && paid>0){
        cout << "Error: number of cents can't be less than item price. Enter again: ";
        cin >> paid;
    }
    while(paid<0){
        cout << "Error: number of cents can't be negative. Enter again: ";
        cin >> paid;
    }
    
    
    change=paid-price;
    cout << "Change = " << change << "\n";
    
    num_quarters=change/25;
    if(num_quarters>2){
        change-=50;
        num_quarters=2;
    }
    else{
        change-=(25*num_quarters);
        
    }
    
    num_dime=change/10;
    
    if(num_dime>2){
        change-=20;
        num_dime=2;
    }
    else{
        change-=(10*num_dime);
    }
    
    num_nickle=change/5;
    
    if(num_nickle>2){
        change-=10;
        num_nickle=2;
    }
    else{
        change-=(5*num_nickle);
    }
    
    num_penny=change;
    if(change>2){
        cout << "Unable to return change, out of coins!\n";
    }
    else{
        cout<<"Quarters: "<< num_quarters<<"\n";
        cout<<"Dimes: "<<num_dime<<"\n";
        cout<<"Nickle: "<<num_nickle<<"\n";
        cout<<"Pennies: "<<num_penny<<"\n";
    }
    
    return 0;
}
