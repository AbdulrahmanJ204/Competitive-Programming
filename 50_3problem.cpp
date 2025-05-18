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
void PrintHeader(){
  PrintSeparator();
  cout<<setw(12)<<left<<"| "<<"Account Number";
  cout<<setw(12)<<left<<"| "<<"Pin Code";
  cout<<setw(40)<<left<<"| "<<"Client Name";
  cout<<setw(12)<<left<<"| "<<"Phone";
  cout<<setw(12)<<left<<"| "<<"Balance";
  PrintSeparator();
}
void PrintClientInTable(stClient &client){
  cout<<setw(12)<<left<<"| "<<client.AccountNumber;
  cout<<setw(12)<<left<<"| "<<client.PINcode;
  cout<<setw(40)<<left<<"| "<<client.Name;
  cout<<setw(12)<<left<<"| "<<client.PhoneNumber;
  cout<<setw(12)<<left<<"| "<<to_string(client.Balance);
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

void EraseFile(string path){
  fstream File;
  File.open(path,ios::out);
  if(File.is_open()){
    File.close();
  }
}

void saveClientToFile(string path , stClient &client){
  fstream clientsFile;
  clientsFile.open(path,ios::out | ios:: app);
  if(clientsFile.is_open()){

    clientsFile<<RecordToLine(client);
    clientsFile<<endl;
    

    clientsFile.close();
  }
}

bool FindClientByID(vector<stClient> &clients , int &index , string AccNumber){ 
  int counter=0;
  for(stClient &c : clients) 
  if(c.AccountNumber==AccNumber)
  {
    index=counter;
   return true;
  }
  else counter++; 
  return false;
}
void DeleteClientById(vector<stClient> &clients){
  
  cout<<"Enter Account Number :"<<endl;
  string AccNumber=ReadLine();
  int index=0;
  if(FindClientByID(clients,index,AccNumber))
  {
  PrintClientCard(clients[index]);
  cout<<"\nDo You Want To Delete This Client ? Y/N \n\n";
  char c;
  cin>>c;
  if(tolower(c)!='y') {
    cout<<"Client was not Deleted."<<endl;
    return;
  } 
    // cout<<"\n\nBefore : \n\n";
    // PrintClientsTable(clients);
    clients.erase(clients.begin()+index);
    // cout<<"\n\nAfter : \n\n";
    // PrintClientsTable(clients);

    EraseFile("D:\\cpp Problems\\Clients.txt");
    for(stClient &c : clients) saveClientToFile("D:\\cpp Problems\\Clients.txt",c);
    cout<<"Client with ID ("<<AccNumber<<") Was Deleted Successfully!"<<endl;
  }
  else
  cout<<"Client With Account Number ("<<AccNumber<<") Not Found!"<<endl;


}
int main(){
  vector<stClient> clients;
  ReadClientsFromFile("D:\\cpp Problems\\Clients.txt",clients);
  // PrintClientsTable(clients);
  // stClient client;
  DeleteClientById(clients);
  
  // system()
  return 0;
}