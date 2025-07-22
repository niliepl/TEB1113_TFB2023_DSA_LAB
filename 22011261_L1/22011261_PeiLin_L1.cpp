/*
ID :22011261
Name :Lee Pei Lin 
*/

#include <iostream>
#include <string>

using namespace std;
struct Student{
    int id;
    string name;
    string contact;
    string email;
  };

int main() 
{
  Student students[5];
  for (int i = 0; i < 5; i++) {
    cout<<"Enter your id: ";
    cin >> students[i].id;

    
    cout<<"Enter your name: ";
    cin >> students[i].name;

    
    cout<<"Enter your contact: ";
    cin >> students[i].contact;

    
    cout<<"Enter your email: ";
    cin >> students[i].email;

    cout << endl;
  }
  for (int i = 0; i < 5; i++) {
    cout<<"********************"<<endl;
    cout<<"Student "<<i+1<<endl;
    cout<<students[i].id<<endl;
    cout<<students[i].name<<endl;
    cout<<students[i].contact<<endl;
    cout<<students[i].email<<endl;
  }
  
}