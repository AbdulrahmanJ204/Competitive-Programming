#include<iostream>
#include<string>
#include<vector>
#include<fstream>
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

// stClient LineToRecord(string &Line , string &delim){
//   vector<string> vInfo=SpiltString(Line, delim);
//   stClient client;
//   client.AccountNumber=vInfo[0];
//   client.PINcode=vInfo[1];
//   client.Name=vInfo[2];
//   client.PhoneNumber=vInfo[3];
//   client.Balance=stod(vInfo[4]);
//   return client;
// }
string RecordToLine(stClient &client){
  vector<string> vInfo;
  vInfo.push_back(client.AccountNumber);
  vInfo.push_back(client.PINcode);
  vInfo.push_back(client.Name);
  vInfo.push_back(client.PhoneNumber);
  vInfo.push_back(to_string(client.Balance));
  return JoinString(vInfo,"#//#");
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
void AddClient(){
  char c='Y';
  while(c=='Y'||c=='y'){
    cout<<"\nAdding A new Client : "<<endl<<endl;
    stClient client=ReadClientInfo();
    saveClientToFile("Clients.txt",client);
    cout<<"Client Added Successfully , do you want to add more ? Y/n"<<endl;
    cin>>c;
  }
}
int main(){

  AddClient();
  system("cls");
  // system()
  return 0;
}