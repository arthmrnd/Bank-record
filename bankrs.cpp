#include<iostream>
#include<fstream>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

class accountQuery
{
private:
    char accountNumber[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;
public:
    void readData();
    void showData();
    void writeRec();
    void readRec();
    void searchRec();
    void editRec();
    void deleteRec();
};

void accountQuery::readData()
{
    cout<<"\nEnter Account Number:  ";
    cin>>accountNumber;
    cout<<"\nEnter First Name:  ";
    cin>>firstName;
    cout<<"\nEnter Last Name:  ";
    cin>>lastName;
    cout<<"\nEnter Balance:  ";
    cin>>total_Balance;
    cout<<endl;
}

void accountQuery::showData()
{
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: R$."<<total_Balance<<endl;
    cout<<"------------------------------"<<endl;
}
void accountQuery::writeRec()
{
    ofstream outfile;
    
}


