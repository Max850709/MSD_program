//
//  main.cpp
//  DateFormats
//
//  Created by ChaoChinYang and Matthew on 8/26/21.
//

#include <iostream>
using namespace std;

int main() {
    string date;
    string US_date;
    
    cout << "enter a date:\n";
    cin>>date;
    std::size_t m = date.find("/");
    string month=date.substr(0,m);
    
    string left=date.substr(m+1,8);
    std::size_t d = left.find("/");
    string day=date.substr(m+1,d);
    
    string year=left.substr(d+1,6);
    try{
        if(stoi(month)>12 || stoi(month)<1){
            cout<<"Invalid date";
        }
        
        //can't over 28 in FEB
        if(stoi(month)==2){
            if(stoi(day)<1 || stoi(day)>28){
                cout<<"Invalid date";
                return 0;
            }
            if(stoi(year)%4==0){
                
            }
        }
        
        
        //can't over 30 in even months not includes FEB
        if(stoi(month)==4 || stoi(month)==6 || stoi(month)==9 || stoi(month)==11){
            if(stoi(day)<1 || stoi(day)>30){
                cout<<"Invalid date";
            }
        }
        
        //can't over 31 in odd months
        if(stoi(month)==1 || stoi(month)==3 || stoi(month)==5 || stoi(month)==7 || stoi(month)==8 || stoi(month)==10 || stoi(month)==12){
            if(stoi(day)<1 || stoi(day)>31){
                cout<<"Invalid date";
                return 0;
            }
        }
        
        
        if(stoi(year)>9999 || stoi(year)<1000){
            cout<<"Invalid date";
            return 0;
        }
        
        
        
        
        //convert number to English month
        if(stoi(month)==1){
            US_date+="January ";
        }
        else if(stoi(month)==2){
            US_date+="Febuary ";
        }
        else if(stoi(month)==3){
            US_date+="March ";
        }
        else if(stoi(month)==4){
            US_date+="April ";
        }
        else if(stoi(month)==5){
            US_date+="May ";
        }
        else if(stoi(month)==6){
            US_date+="June ";
        }
        else if(stoi(month)==7){
            US_date+="July ";
        }
        else if(stoi(month)==8){
            US_date+="August ";
        }
        else if(stoi(month)==9){
            US_date+="Spetember ";
        }
        else if(stoi(month)==10){
            US_date+="Octber ";
        }
        else if(stoi(month)==11){
            US_date+="November ";
        }
        else if(stoi(month)==12){
            US_date+="December ";
        }
    }catch(invalid_argument){
        cout << "Invalid date";
        return 0;
    }
    
    US_date+=day;
    US_date+=", ";
    US_date+=year;
    cout<<US_date <<"\n";

    return 0;
}
