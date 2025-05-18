#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std; 

enum enMainMenuOptions {
  CLIENTS_LIST = 1, ADD , DELETE , UPDATE , FIND , TRANSACTIONS, EXIT ,
};
enum enTransactionMenuOptions {
  DEPOSIT = 1, WITHDRAW , TOTAL_BALANCES , MAIN_MENU
};

struct stClient{
  string AccountNumber, Name,PINcode,PhoneNumber;
  float Balance;
  int index=-1;
  bool markToDelete = false;
};

string ClientFilePath="./Clients.txt";
void saveClientsToFile(string path , vector <stClient> &vClients);
void saveOneClientToFile(string path , stClient &client);
void ReadClientsFromFile(string path ,  vector<stClient> &vClients);
void showClientsListScreen(vector<stClient> & vClients);
void showAddNewClientScreen(vector<stClient> & vClients);
void showDeleteClientScreen(vector<stClient> & vClients);
void showUpdateClientScreen(vector<stClient> & vClients);
void showFindClientScreen(vector<stClient> & vClients);
void showTransactionsScreen(vector<stClient> & vClients);
void showDepositScreen(vector<stClient> & vClients);
void showWithdrawScreen(vector<stClient> & vClients);
void showTotalBalancesScreen(vector<stClient> & vClients);
void showTotalBalancesScreen(vector<stClient> & vClients);
void goBackToTransactionsScreen(vector<stClient> &vClients);
void goBackToMainMenu(vector<stClient> &vClients);
void PerformTransactionAction(vector<stClient> &vClients);
void Exit();
void PrintSeparator();
void PrintHeader();
void PrintClientInTable(stClient &client);
void PrintClientInBalancesTable(stClient &client);
void PerformAction(vector<stClient> &vClients);
void showClientsListScreen(vector<stClient> & vClients);
void PrintClientCard(stClient &client);
void showMainMenuScreen(vector<stClient> & vClients);
void PrintBalancesHeader();
bool FindClientByID(vector<stClient> &vClients , string AccNumber , stClient &client);
string ReadLine();
string JoinString(vector<string> &vString , string delim);
string RecordToLine(stClient &client);
stClient LineToRecord(string &Line , string delim);
stClient ReadClientInfo();
vector<string> SpiltString(string s , string &delim);

int main(){
  vector<stClient> vClients;
  ReadClientsFromFile(ClientFilePath,vClients);
  showMainMenuScreen(vClients);
  return 0;
}

void goBackToMainMenu(vector<stClient> &vClients){
  cout<<"Press Any Key To Go To Main Menu...\n\n";
  system("pause>0");
  showMainMenuScreen(vClients);
}

void PerformAction(vector<stClient> &vClients){
  cout<<"\nChoose What Do You Want ?  [1-7]. \n    "<<endl;
  int choice;
  cin>>choice;
  enMainMenuOptions Option= (enMainMenuOptions) choice;
  switch (Option)
  {
  case enMainMenuOptions::CLIENTS_LIST :
  {
    system("cls");
    showClientsListScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  }
  case enMainMenuOptions::ADD :
  {
    system("cls");
    showAddNewClientScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  } 
  case enMainMenuOptions::DELETE :
  {

    system("cls");
    showDeleteClientScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  }
  case enMainMenuOptions::UPDATE :
  {

    system("cls");
    showUpdateClientScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  }
  case enMainMenuOptions::FIND :
  {

    system("cls");
    showFindClientScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  }
  case enMainMenuOptions::TRANSACTIONS :
  {

    system("cls");
    showTransactionsScreen(vClients);
    goBackToMainMenu(vClients);
    break;
  }
  default:
    system("cls");
    Exit();
    break;
  }
}

void showMainMenuScreen(vector<stClient> &vClients){
  system("cls");
  cout<<"=========================================="<<endl;
  cout<<"                 Main Menu                "<<endl;
  cout<<"=========================================="<<endl;
  cout<<"           [1] Show Clients List.         "<<endl;
  cout<<"           [2] Add New Client.            "<<endl;
  cout<<"           [3] Delete Client.             "<<endl;
  cout<<"           [4] Update Client Info.        "<<endl;
  cout<<"           [5] Find Client.               "<<endl;
  cout<<"           [6] Transactions.              "<<endl;
  cout<<"           [7] Exit.                      "<<endl;
  cout<<"=========================================="<<endl;
  cout.flush();
  PerformAction(vClients);
}

void PrintBalancesHeader() {
  PrintSeparator();
  cout<<left<<setw(17)<<"| Account Number";
  cout<<left<<setw(40)<<"| Client Name";
  cout<<left<<setw(13)<<"| Balance";
  PrintSeparator();
}

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

void ReadClientsFromFile(string path ,  vector<stClient> &vClients){
  vClients.clear();
  fstream clientsFile;
  clientsFile.open(path,ios::in);
  if(clientsFile.is_open()){
    string Line;
    while(getline(clientsFile,Line)){
      if(Line!="")
    vClients.push_back(LineToRecord(Line,"#//#"));
    }
    clientsFile.close();
  }
}

void PrintSeparator(){
  cout<<endl;
  string s="";
  for (int i = 0; i < 95; i++)
    s+="_";
  cout<<s;
  cout<<endl;
  cout<<endl;
}

void PrintHeader(){
  PrintSeparator();
  cout<<left<<setw(17)<<"| Account Number";
  cout<<left<<setw(13)<<"| Pin Code";
  cout<<left<<setw(40)<<"| Client Name";
  cout<<left<<setw(13)<<"| Phone";
  cout<<left<<setw(13)<<"| Balance";
  PrintSeparator();
}

void PrintClientInTable(stClient &client){
  cout<<setw(17)<<left<<("| "+client.AccountNumber);
  cout<<setw(13)<<left<<("| "+client.PINcode);
  cout<<setw(40)<<left<<("| "+client.Name);
  cout<<setw(13)<<left<<("| "+client.PhoneNumber);
  cout<<setw(13)<<left<<("| "+to_string(client.Balance));
  cout<<endl;
}

void PrintClientInBalancesTable(stClient &client) {
  cout<<setw(17)<<left<<("| "+client.AccountNumber);
  cout<<setw(40)<<left<<("| "+client.Name);
  cout<<setw(13)<<left<<("| "+to_string(client.Balance));
  cout<<endl;
}

stClient ReadClientInfo(){
  stClient client;
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

void PrintClientCard(stClient &client){
  
  cout<<"\n--------------------------------\n";
  cout<<"           Client Info              ";
  cout<<"\n--------------------------------\n";

  cout<<setw(15)<<left<<"Account Number";
  cout<<": "<<client.AccountNumber<<endl;
  cout<<setw(15)<<left<<"Pin Code";
  cout<<": "<<client.PINcode<<endl;
  cout<<setw(15)<<left<<"Name";
  cout<<": "<<client.Name<<endl;
  cout<<setw(15)<<left<<"Phone";
  cout<<": "<<client.PhoneNumber<<endl;
  cout<<setw(15)<<left<<"Balance";
  cout<<": "<<client.Balance<<endl;
  cout<<"--------------------------------\n";
}

bool FindClientByID(vector<stClient> &vClients , string AccNumber , stClient &client){ 
  int cnt=0;
  for(stClient &c : vClients) 
  if(c.AccountNumber==AccNumber)
  {
   client=c;
   client.index=cnt;
   return true;
  }
  else cnt++; 
  return false;
}

void showClientsListScreen(vector<stClient> & vClients)
{
  cout<<endl;
  cout<<("\t\t\t\tClients List ("+to_string(vClients.size())+") Client(s).");
  PrintHeader();
  for(stClient &client : vClients) PrintClientInTable(client);
  PrintSeparator();
}

void saveOneClientToFile(string path , stClient &client){
  fstream clientsFile;
  clientsFile.open(path,ios::out | ios:: app);
  if(clientsFile.is_open()){
    clientsFile<<RecordToLine(client);
    clientsFile<<endl;
    clientsFile.close();
  }
}

void saveClientsToFile(string path , vector <stClient> &vClients){
  fstream clientsFile;
  clientsFile.open(path,ios::out);
  if(clientsFile.is_open()){

    for(stClient &client: vClients ){
    if(client.markToDelete)
     continue;    
    clientsFile<<RecordToLine(client);
    clientsFile<<endl;
    }

    clientsFile.close();
  }
}

void showAddNewClientScreen(vector<stClient> &vClients) {
  
  cout<<"--------------------------------\n";
  cout<<"      Add New Client Screen     \n";
  cout<<"--------------------------------\n";
  
  char c='Y';
  while(c=='Y'||c=='y'){
   cout<<"\nAdding A new Client : "<<endl<<endl;
   cout<<"Enter Account Number ? ";
   bool exist=true;
   string accountNumber;
   while(exist){
    accountNumber=ReadLine();
    exist=false;
    for(stClient & client : vClients) 
    if(accountNumber==client.AccountNumber){
      cout<<"Client with Account Number ["<<accountNumber<<"] Already Exists, Enter Another Account Number : \n";
      exist=true;
      break;
    }
   } 

    stClient client=ReadClientInfo();
    client.AccountNumber=accountNumber;
    saveOneClientToFile(ClientFilePath,client);
    cout<<"Client Added Successfully , do you want to add more ? Y/n"<<endl;
    cin>>c;
  }
  ReadClientsFromFile(ClientFilePath, vClients);

}

void showDeleteClientScreen(vector<stClient> &vClients) {

  cout<<"--------------------------------\n";
  cout<<"      Delete Client Screen      \n";
  cout<<"--------------------------------\n";
   
  cout<<"Enter Account Number :"<<endl;
  string AccNumber=ReadLine();
  stClient client;
  if(FindClientByID(vClients, AccNumber , client)){
   client;
   PrintClientCard(client);
   cout<<"\nDo You Want To Delete This Client ? Y/N"<<endl;
   char del;
   cin>>del;
   if(tolower(del)!='y') return;
   vClients[client.index].markToDelete=true;
   saveClientsToFile(ClientFilePath,vClients);
   ReadClientsFromFile(ClientFilePath,vClients);
   
   cout<<"\nClient Deleted Successfully !"<<endl;
  
  }
  else cout<<"Client With Account Number ("<<AccNumber<<") Not Found!"<<endl;
  

}

void showUpdateClientScreen(vector<stClient> &vClients) {

  cout<<"--------------------------------\n";
  cout<<"      Update Client Screen      \n";
  cout<<"--------------------------------\n";
   
  cout<<"Enter Account Number :"<<endl;
  string AccNumber=ReadLine();
  stClient client;
  if(FindClientByID(vClients,AccNumber,client)){

   PrintClientCard(client);
   cout<<"\nDo You Want To Update This Client ? Y/N"<<endl;
   char update;
   cin>>update;
   int index=client.index;
   if(tolower(update)!='y') return;
   client=ReadClientInfo();
   client.AccountNumber=AccNumber;
   
   vClients[index].AccountNumber=client.AccountNumber;
   vClients[index].PINcode=client.PINcode;
   vClients[index].Name=client.Name;
   vClients[index].PhoneNumber=client.PhoneNumber;
   vClients[index].Balance=client.Balance;
   saveClientsToFile(ClientFilePath,vClients);
   ReadClientsFromFile(ClientFilePath,vClients);
   cout<<"\nClient Updated Successfully !"<<endl;
  }
  else cout<<"Client With Account Number ("<<AccNumber<<") Not Found!"<<endl;
}

void showFindClientScreen(vector<stClient> &vClients) {


  cout<<"--------------------------------\n";
  cout<<"       Find Client Screen       \n";
  cout<<"--------------------------------\n";
   
  cout<<"Enter Account Number :"<<endl;
  string AccNumber=ReadLine();
  bool found = false;
  for(stClient &client : vClients) 
  if(client.AccountNumber==AccNumber)
  {
   PrintClientCard(client);
   found=true;
   break;
  } 
  if(!found)
  cout<<"Client With Account Number ("<<AccNumber<<") Not Found!"<<endl;
}

void showTransactionsScreen(vector<stClient> &vClients) {
  system("cls");
  cout<<"========================================"<<endl;
  cout<<"           Transactions Menu            "<<endl;
  cout<<"========================================"<<endl;
  cout<<"           [1] Deposit."<<endl;
  cout<<"           [2] Withdraw."<<endl;
  cout<<"           [3] Total Balances."<<endl;
  cout<<"           [4] Main Menu."<<endl;
  cout<<"========================================"<<endl;
  PerformTransactionAction(vClients);
}

void showDepositScreen(vector<stClient> &vClients) {
  cout<<"--------------------------------\n";
  cout<<"         Deposit Screen         \n";
  cout<<"--------------------------------\n";
  while(true){
  cout<<"\nPlease Enter Account Number : "<<endl;  
  string AccountNumber=ReadLine();
  stClient client;
  if(FindClientByID(vClients,AccountNumber,client)){
  int index= client.index;
  PrintClientCard(client);

  double depositAmount=-1;
  do{
    cout<<"Please Enter deposit Amount : "<<endl;
    cin>>depositAmount;


    
    if(depositAmount<0){
      cout<<"\n\nInvalid Input !"<<endl;
    }
  }while(depositAmount<0);
  
  cout<<"\nAre You Sure You Want To Do This Transaction ? Y/N "<<endl;
  char confirm;
  cin>>confirm;
  if(tolower(confirm)!='y') return;
  vClients[index].Balance+=depositAmount;
  saveClientsToFile(ClientFilePath,vClients);
  ReadClientsFromFile(ClientFilePath,vClients);
  
  cout<<"\n Your Balance : "<<vClients[index].Balance<<endl;
  break;
  }
  else cout<<"Client With Account Number ("<<AccountNumber<<") Does Not Exist!"<<endl;
  
  }

}

void showWithdrawScreen(vector<stClient> &vClients) {

  cout<<"--------------------------------\n";
  cout<<"         Withdraw Screen        \n";
  cout<<"--------------------------------\n";
  while(true){
  cout<<"\nPlease Enter Account Number : "<<endl;  
  string AccountNumber=ReadLine();
  stClient client;
  if(FindClientByID(vClients,AccountNumber,client)){
  int index= client.index;
  PrintClientCard(client);

  double withdrawAmount=-1;
  do{
    cout<<"Please Enter withDraw Amount : "<<endl;
    cin>>withdrawAmount;

    if(withdrawAmount<0){
      cout<<"\n\nInvalid Input !"<<endl;
    }
    else if(vClients[index].Balance-withdrawAmount<0){
      cout<<"No Enough Balance . Your Balance : "<<vClients[index].Balance<<endl;
    }
  }while(withdrawAmount<0|| vClients[index].Balance-withdrawAmount<0);
  
  cout<<"\nAre You Sure You Want To Do This Transaction ? Y/N "<<endl;
  char confirm;
  cin>>confirm;
  if(tolower(confirm)!='y') return;
  
  vClients[index].Balance-=withdrawAmount;
  saveClientsToFile(ClientFilePath,vClients);
  ReadClientsFromFile(ClientFilePath,vClients);

  cout<<"\n Your Balance : "<<vClients[index].Balance<<endl;
  break;
  }
  else cout<<"Client With Account Number ("<<AccountNumber<<") Does Not Exist!"<<endl;
  
  }

}

void showTotalBalancesScreen(vector<stClient> &vClients) {
  
  cout<<endl;
  cout<<("\t\t\t\tBalances List ("+to_string(vClients.size())+") Client(s).");
  PrintBalancesHeader();
  double TotalBalance=0;
  for(stClient &client : vClients) {
  PrintClientInBalancesTable(client);
  TotalBalance+=client.Balance;
  }
  PrintSeparator();
  cout<<"\n\t\t\t\t Total Balances : "<<TotalBalance<<endl<<endl;
}

void goBackToTransactionsScreen(vector<stClient> &vClients) {
  cout<<"Press Any Key To Go To Main Menu...\n\n";
  system("pause>0");
  showTransactionsScreen(vClients);
}

void PerformTransactionAction(vector<stClient> &vClients) {
    cout << "\nChoose What Do You Want ?  [1-4]. \n    " << endl;
    short choice;
    cin >> choice;
    enTransactionMenuOptions Option = (enTransactionMenuOptions) choice;
    switch (Option) {
    case enTransactionMenuOptions::DEPOSIT:
        system("cls");
        showDepositScreen(vClients);
        goBackToTransactionsScreen(vClients);
        break;

    case enTransactionMenuOptions::WITHDRAW:
        system("cls");
        showWithdrawScreen(vClients);
        goBackToTransactionsScreen(vClients);
        break;

    case enTransactionMenuOptions::TOTAL_BALANCES:
        system("cls");
        showTotalBalancesScreen(vClients);
        goBackToTransactionsScreen(vClients);
        break;

    default:
        system("cls");
        showMainMenuScreen(vClients);
        break;
    }
}

void Exit() {
  cout<<"====================================\n";
  cout<<"           Program End :-)          \n";
  cout<<"====================================\n";
  
}
