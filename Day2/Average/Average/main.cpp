//
//  main.cpp
//  Average
//
//  Created by max on 8/24/21.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int grade,total=0;
    cout<<"Enter 5 assignment scores:\n";
    for(int i=0;i<5;i++){
        cin>>grade;
        total+=grade;
    }
    cout<<"Avg: "<< (float)total/5 <<"\n";
    return 0;
}
