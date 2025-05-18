#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

string ReadLine(){
  cout<<"Please Enter A String : \n";
  string s;
  getline(cin,s);
  return s;
}
string TrimLeft(string s){
  int pos=0;
  while(s[pos]==' ' && pos<s.size()) pos++;
  if(pos>0)
  s.erase(0,pos);
  return s;
}
string TrimRight(string s){
  int pos=s.size()-1;
  while(s[pos]==' ' && pos>=0) pos--;
  s= s.substr(0,pos+1);
  return s;
}
string Trim(string s){
  s=TrimLeft(s);
  s=TrimRight(s);
  return s;
}
string JoinString(vector<string> &vString , string delim){
  string s = "";
  for(string &s1 : vString)
  s+= s1+delim;
  s.erase(s.length()-delim.length(),delim.length());
  return s;
}
string JoinString(string arrString[], int len , string delim){
  string s = "";
  for(int i= 0; i<len; i++)
  s+= arrString[i]+delim;
  s.erase(s.length()-delim.length(),delim.length());
  return s;
}

int main(){
  // string s= ReadLine();
  // cout<<"Size = "<<s.size()<<endl;   
  // cout<<setw(12)<<"\nTrim Left :"<<TrimLeft(s)<< " Size = "<<TrimLeft(s).size();
  // cout<<setw(12)<<"\nTrim Right :"<<TrimRight(s)<<" Size = "<<TrimRight(s).size();
  // cout<<setw(12)<<"\nTrim :"<<Trim(s)<<" Size = "<<Trim(s).size();
  vector<string > vString = {"abd" ,"Alrahman" , "aljomaat"};
  cout<<JoinString(vString,"_")<<endl;
  string s[3]={"ABOOD", "IS ", "IDK what is he"};
  cout<<JoinString(s,3,"###");
  return 0;
}