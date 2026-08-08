#include <iostream>
#include<vector>
#include<fstream>
#pragma warning(disable : 4996)
#include<ctime>
using namespace std;

struct stEmployee{
  string FirstName;
  string LastName;
  float Salary;
};

stEmployee ReadEmployee(){
  cout<<"Please Enter Employee First Name : \n";
  stEmployee employee;
  cin>>employee.FirstName;
  cout<<"Please Enter Employee Last Name : \n";
  cin>>employee.LastName;
  cout<<"Please Enter Employee Salary : \n";
  cin>>employee.Salary;
  return employee ;
}

void ReadEmployees(vector<stEmployee> &v)
{
  char y='y';
  while('y'==tolower(y))
  {
    stEmployee employee=ReadEmployee();
    v.push_back(employee);
    cout<<"Do You Want to Add More? Y/N\n";
    cin>>y;
  }
}

void PrintEmployees(vector<stEmployee> &vEmployees)
{
  for(stEmployee &Employee:vEmployees )
  {
    cout<<"First Name : "<<Employee.FirstName<<endl;
    cout<<"Last Name : "<<Employee.LastName<<endl;
    cout<<"Salary : "<<Employee.Salary<<endl;
    cout<<endl;
  }
}
  
void swap(int *a , int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}  

void SaveVectorToFile(string fileName , vector<string> &vFileContent)
{
  fstream myFile;
  myFile.open(fileName,ios::out);
  if (myFile.is_open()) {
      for (string &Line : vFileContent)
      if(Line!="") myFile << Line << endl;
      myFile.close();
  }
}

void LoadDataFromFileToVector(string fileName , vector<string> &vFileContent)
{
  fstream myFile;
  myFile.open(fileName,ios::in);
  if(myFile.is_open()){

  string line;
  while(getline(myFile,line)){
    vFileContent.push_back(line);
  }
  myFile.close();
  }
}

void PrintFileContent(string fileName){
  fstream myFile;
  myFile.open(fileName,ios::in);
  if(myFile.is_open()){

  string line;
  while(getline(myFile,line)){
    cout<<line<<endl;
  }
  myFile.close();
  }
}

void WriteToFile(string fileName){

  fstream newFile;
  newFile.open(fileName,ios::out | ios::app);
  if(newFile.is_open()){
    string s;
    newFile<< "HI NOOBIE";
    newFile.close();  

  }
}

void deleteRecordFromFile(string fileName,string Record){
   vector<string> vFileContent;
  LoadDataFromFileToVector(fileName,vFileContent);
  cout<<"Before Delete : \n";
  PrintFileContent(fileName);
  for(string &line : vFileContent){
    if(line==Record) line="";
  }
  SaveVectorToFile(fileName,vFileContent);
  cout<<"\n\nAfter Delete : \n";
  PrintFileContent(fileName);
}
void UpdateRecordInFile(string fileName,string Record,string newRecord){
   vector<string> vFileContent;
  LoadDataFromFileToVector(fileName,vFileContent);
  cout<<"Before Update : \n";
  PrintFileContent(fileName);
  for(string &line : vFileContent){
    if(line==Record) line=newRecord;
  }
  SaveVectorToFile(fileName,vFileContent);
  cout<<"\n\nAfter Update : \n";
  PrintFileContent(fileName);
}

int main() {
  // InTheNameOfAllah

  // PrintFileContent("FIRST.txt");  
  // vector<string> vFileContent;
  // deleteRecordFromFile("FIRST.txt","HI NOOBIEaa");
  // UpdateRecordInFile("FIRST.txt","HI NOOBIEaa","NO MORE NOOBIEaa");
  // LoadDataFromFileToVector("FIRST.txt",vFileContent);
  // for(string &line : vFileContent){
  //   cout<<line<<endl;
  // }
  // SaveVectorToFile("FIRST.txt",vFileContent);

  // time_t cur_time= time(0);
  // char *cur_timeString= ctime(&cur_time);
  // cout<<cur_timeString<<endl;
  // tm* stCurTime=localtime(&cur_time);
  // cout<<"Year : "<<stCurTime->tm_year+1900<<endl;
  // cout<<"Month : "<<stCurTime->tm_mon+1<<endl;
  // cout<<"Year day : "<<stCurTime->tm_yday<<endl;
  // cout<<"Month day : "<<stCurTime->tm_mday<<endl;
  // cout<<"week day : "<<stCurTime->tm_wday<<endl;
  // cout<<"Hours : "<<stCurTime->tm_hour<<endl;
  // cout<<"Minutes : "<<stCurTime->tm_min<<endl;
  // cout<<"seconds : "<<stCurTime->tm_sec<<endl;
  // cout<<"isDst? : "<<stCurTime->tm_isdst<<endl;
  // cout<<endl;
  // cout<<endl;

  // tm *griTime=gmtime(&cur_time);

  // cur_timeString=asctime(griTime);
  // cout<<cur_timeString<<endl;


}