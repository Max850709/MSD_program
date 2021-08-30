//
//  main.cpp
//  StringAnalyzer
//
//  Created by max on 8/27/21.
//

#include <iostream>
using namespace std;

int NumWords(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if((s[i]=='.' || s[i]==',' || s[i]=='!' || s[i]==' ' || s[i]=='?') && (s[i-1] != NULL && s[i-1]!='.' && s[i-1]!=',' && s[i-1]!='!' && s[i-1]!= ' ' && s[i-1]!='?')){
            count+=1;
        }
    }
    return count;
}

int NumSentences(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if((s[i]=='.' || s[i]=='!' || s[i]=='?') && (s[i-1] != NULL)){
            count+=1;
        }
    }
    return count;
}

int NumVowels(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            count+=1;
        }
    }
    return count;
}

int NumConsonants(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U' && s[i]!=' ' && s[i]!='!' && s[i]!=',' && s[i]!='.' && s[i]!='?'){
            count+=1;
        }
    }
    return count;
}

int main() {
    string str;
    while(1){
        cout << "Enter a string containing one or more sentences:\n";
        getline(cin,str);
        if(str=="done"){
            cout << "Goodbye." << "\n";
            break;
        }
        
        cout << "Number of words: " << NumWords(str) << "\n";
        cout << "Number of sentences: " << NumSentences(str) << "\n";
        cout << "Number of vowels: " << NumVowels(str) << "\n";
        cout << "Number of consonants: " << NumConsonants(str) << "\n";
        cout << "Reading level (average word length): " << (float(NumVowels(str))+float(NumConsonants(str)))/float(NumWords(str)) << "\n";
        cout << "Average vowels per word: " << float(NumVowels(str))/float(NumWords(str)) << "\n";
    }
    
    return 0;
}
