//
//  main.cpp
//  Palindromes
//
//  Created by max on 8/26/21.
//

#include <iostream>
using namespace std;

int main() {
    
    string str;
    getline(cin,str);
    int left=0,right=str.size()-1;
    while(left<right){
        if(str[left]!=str[right]){
            cout << str << " is not a palindromes.\n";
            return 0;
        }
        left++;
        right--;
    }
    cout << str << " is a palindromes.\n";
    return 0;
}
