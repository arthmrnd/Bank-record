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

//Ler os Dados | Read Data

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

//Mostrar os dados | Show Data

void accountQuery::showData()
{
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: R$."<<total_Balance<<endl;
    cout<<"------------------------------"<<endl;
}

//Escrever os registros | Write Record

void accountQuery::writeRec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    readData();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}

//Ler os registros | Read Records

void accountQuery::readRec()
{
    ifstream infile;
    infile.open("record.bank",ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!"<<endl;
        return;
    }
    cout<<"\n----Data from file----"<<endl;
    while (!infile.eof())
    {
        if (infile.read(reinterpret_cast<char *>(this), sizeof(*this))>0)
        {
            showData();
        }
        infile.close();
    }  
}

//Procurar os Registros | Search Records

void accountQuery::searchRec()
{
    int n;
    ifstream infile;
    infile.open("record.bank",ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!"<<endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file ";
    cout<<"\n Enter Recorde number to search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char *>(this), sizeof(*this));
    showData;
}

//Editar os Registros | Edit Records

void accountQuery::editRec()
{
    int n;
    fstream iofile;
    iofile.open("record.bank",ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"Error in Opening! File Not Found!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file ";
    cout<<"\n Enter Recorde number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    showData();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekg((n-1)*sizeof(*this));
    cout<<"\nEnter data a Modify "<<endl;
    readData();
    iofile.write(reinterpret_cast<char *>(this), sizeof(*this));
}

//Apagar os Registros | Delete Records

void accountQuery::deleteRec()
{
    int n;
    ifstream infile;
    infile.open("record.bank",ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!"<<endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file ";
    cout<<"\n Enter Recorde number to search: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for (int i = 0; i < count; i++)
    {
        infile.read(reinterpret_cast<char *>(this), sizeof(*this));
        if (i==(n-1))
        {
            continue;
        }
        tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.bank");
    rename("tmpfile.bank","record.bank");
}

//Função principal

