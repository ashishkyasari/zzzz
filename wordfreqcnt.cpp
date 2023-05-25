#include<bits/stdc++.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string fname;
    cin>>fname;

    ifstream file(fname);

    if(!file){
        cout<<"Error Opening file ..."<<endl;
        return 1;
    }

    string word;
    unordered_map<string,int>wordcnt;

    while(file >> word){
        wordcnt[word]++;
    }

    cout<<"Word Frequencies: "<<endl;
    for(auto &i: wordcnt){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}