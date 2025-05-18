#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReadLine(){
  cout<<"Please Enter A String : \n";
  string s;
  getline(cin,s);
  return s;
}

void CountWordsOfString(string s){
  string delim=" ";
  string word="";
  int pos=0;
  int cnt=0;
  while((pos=s.find(delim))!=std::string::npos){
    word=s.substr(0,pos);
    if(word!="")cnt++;
    // cout<<"s = "<<s<<"  pos = "<<pos<<endl;
    s.erase(0,pos+delim.length());
  }
  if(s!="") cnt++;
  cout<<"Words Count = "<<cnt<<endl;
}

void SpiltString(string s){
  string delim=" ";
  string word="";
  vector<string> vWords;
  int pos=0;
  while((pos=s.find(delim))!=std::string::npos){
    word=s.substr(0,pos);
    if(word!=""){
      vWords.push_back(word);
    }
    // cout<<"s = "<<s<<"  pos = "<<pos<<endl;
    s.erase(0,pos+delim.length());
  }
  if(s!="") vWords.push_back(s);
  cout<<"Tokens : "<<vWords.size()<<endl;
  for(string &x : vWords) cout<<x<<endl;
}

void PrintWordsOfString(string s){
  string delim=" ";
  string word="";
  int pos=0;
  while((pos=s.find(delim))!=std::string::npos){
    word=s.substr(0,pos);
    if(word!=""){

    cout<<word<<endl;
    }
    // cout<<"s = "<<s<<"  pos = "<<pos<<endl;
    s.erase(0,pos+delim.length());
  }
  if(s!="") cout<<s<<endl;
}


int main(){

  // PrintWordsOfString(ReadLine());
  // CountWordsOfString(ReadLine());
  SpiltString(ReadLine());
  return 0;
}