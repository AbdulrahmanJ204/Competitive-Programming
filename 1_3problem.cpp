#include<iostream>
#include<iomanip>
using namespace std;
 
 int randomNumber(int from , int to){
  int number= rand()%(to-from+1) + from;
  return number;
 }
 

 int main(){
  srand((unsigned)time(NULL));
  int arr[3][3];
  for (int i = 0; i < 3; i++) 
  {
    int sum=0;
    for (int j = 0; j < 3; j++)
    {
      arr[i][j]=randomNumber(1,100);
      sum+=arr[i][j];
    }
    cout<<"sum of row "<<i+1<<" = "<<sum<<endl;
  }
  for (int i = 0; i < 3; i++){
  for (int j = 0; j < 3; j++)
    cout<<setw(3)<<arr[i][j]<<' ';
    cout<<endl;
  } 
  for (int i = 0; i < 3; i++) 
  {
    int sum=0;
    for (int j = 0; j < 3; j++)
      sum+=arr[i][j];
    
    cout<<"sum of row "<<i+1<<" = "<<sum<<endl;
  }
  return 0;
 }