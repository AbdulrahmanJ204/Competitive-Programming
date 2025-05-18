#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

struct stClient{
  string AccountNumber, Name,PINcode,PhoneNumber;
  float Balance;
};

string ReadLine(){
  string s;
  while(s.empty()){
  getline(cin>>ws,s);
  }
  return s;
}

string JoinString(vector<string> &vString , string delim){
  string s = "";
  for(string &s1 : vString)
  s+= s1+delim;
  s.erase(s.length()-delim.length(),delim.length());
  return s;
}

stClient ReadClientInfo(){
  stClient client;
  cout<<"Enter Account Number? ";
  client.AccountNumber=ReadLine();
  cout<<"Enter PinCode? ";
  client.PINcode=ReadLine();
  cout<<"Enter Name? ";
  client.Name=ReadLine();
  cout<<"Enter Phone ? ";
  client.PhoneNumber=ReadLine();
  cout<<"Enter Account Balance? ";
  cin>>client.Balance;
  return client;
}

vector<string> SpiltString(string s , string &delim){
  string word="";
  vector<string> vWords;
  int pos=0;
  while((pos=s.find(delim))!=std::string::npos){
    word=s.substr(0,pos);
    if(word!=""){
      vWords.push_back(word);
    }
    s.erase(0,pos+delim.length());
  }
  if(s!="") vWords.push_back(s);
  return vWords;
}

stClient LineToRecord(string &Line , string delim){
  vector<string> vInfo=SpiltString(Line, delim);
  stClient client;
  client.AccountNumber=vInfo[0];
  client.PINcode=vInfo[1];
  client.Name=vInfo[2];
  client.PhoneNumber=vInfo[3];
  client.Balance=stod(vInfo[4]);
  return client;
}

string RecordToLine(stClient &client){
  vector<string> vInfo;
  vInfo.push_back(client.AccountNumber);
  vInfo.push_back(client.PINcode);
  vInfo.push_back(client.Name);
  vInfo.push_back(client.PhoneNumber);
  vInfo.push_back(to_string(client.Balance));
  return JoinString(vInfo,"#//#");
}

void ReadClientsFromFile(string path ,  vector<stClient> &clients){
  fstream clientsFile;
  clientsFile.open(path,ios::in);
  if(clientsFile.is_open()){
    string Line;
    while(getline(clientsFile,Line)){
      if(Line!="")
    clients.push_back(LineToRecord(Line,"#//#"));
    }
    clientsFile.close();
  }
}


void PrintSeparator(){
  cout<<endl;
  string s="";
  for (int i = 0; i < 88; i++)
    s+="_";
  cout<<s;
  cout<<endl;
  cout<<endl;
}
void PrintAccountNumber(string s){
  s="| "+ s;
  cout<<setw(18)<<left<<s;
}
void PrintPinCode(string s){
  s="| "+ s;
  cout<<setw(12)<<left<<s;
}
void PrintName(string s){
  s="| "+ s;
  cout<<setw(32)<<left<<s;
}
void PrintPhoneNumber(string s){
  s="| "+ s;
  cout<<setw(12)<<left<<s;
}
void PrintBalance(string s){
  s="| "+ s;
  cout<<setw(12)<<left<<s;
}
void PrintHeader(){
  PrintSeparator();
  PrintAccountNumber("Account Number");
  PrintPinCode("Pin Code");
  PrintName("Client Name");
  PrintPhoneNumber("Phone");
  PrintBalance("Balance");
  PrintSeparator();
}
void PrintClientInTable(stClient &client){
  PrintAccountNumber(client.AccountNumber);
  PrintPinCode(client.PINcode);
  PrintName(client.Name);
  PrintPhoneNumber(client.PhoneNumber);
  PrintBalance(to_string(client.Balance));
  cout<<endl;
}
void PrintClientsTable(vector<stClient> &clients){
  cout<<endl;
  cout<<setw(40)<<"Clients List ("<<clients.size()<<") Client(s).";
  PrintHeader();
  for(stClient &client : clients) PrintClientInTable(client);
  PrintSeparator();
  
}
void PrintClientCard(stClient client){
  cout<<"Client Info : \n\n";

  cout<<setw(12)<<"Account Number";
  cout<<": "<<client.AccountNumber<<endl;
  cout<<setw(12)<<"Pin Code";
  cout<<": "<<client.PINcode<<endl;
  cout<<setw(12)<<"Name";
  cout<<": "<<client.Name<<endl;
  cout<<setw(12)<<"Phone";
  cout<<": "<<client.PhoneNumber<<endl;
  cout<<setw(12)<<"Balance";
  cout<<": "<<client.Balance<<endl;
}
void FindClientByID(){
  cout<<"Enter Account Number :"<<endl;
  string AccNumber=ReadLine();
  vector<stClient> clients;
  ReadClientsFromFile("Clients.txt",clients);
  for(stClient &client : clients) 
  if(client.AccountNumber==AccNumber)
  {
   PrintClientCard(client);
   return;
  } 
  cout<<"Client With Account Number ("<<AccNumber<<") Not Found!"<<endl;
}
int main(){
  vector<stClient> clients;
  ReadClientsFromFile("Clients.txt",clients);
  PrintClientsTable(clients);
  FindClientByID();
  // system()
  return 0;
}