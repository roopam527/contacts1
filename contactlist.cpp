#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
class Contacts
{
        long long int ph_no;
       string name;
public:
        void setcontact()
        {
                ofstream fout;
                fout.open("Contact.txt",ios::app);
                cout<<"ENTER THE NAME : ";
                cin.ignore();
                getline(cin,name);
                fout<<name<<"\t\t";
                cout<<"\nENTER THE PHONE NUMBER : ";
                cin>>ph_no;
                fout<<ph_no<<"\n";
                fout.close();
        }
        void showcontact()
        {
                ifstream fin;
               char ch;
                fin.open("Contact.txt");
                ch=fin.get();
                while(!fin.eof())
                {
                        cout<<ch;
                        ch=fin.get();
                }
                fin.close();
                    getchar();
        }
       void searchcontact()
        {
                ifstream fin;
                string ch,sname;
                char ch1;
                fin.open("Contact.txt",ios::binary);
                cout<<"ENTER THE NAME TO BE SEARCH";
                cin.ignore();
                getline(cin,sname);
                ch=fin.get();
                while(!fin.eof())
                {
                        ch1=fin.get();
                        ch=ch+ch1;
                        if(ch==sname)
                        {
                                cout<<ch;
                                while(ch1!='\t')
                                {
                                ch1=fin.get();
                                cout<<ch1;
                                }
                               //cout<<"\t";
                                fin.get();
                                int i;
                                while(ch1!='\n'){
                                     ch1=fin.get();
                                       cout<<ch1;
                                       }
                                       cout<<"\n";
                        }
                        if(ch1=='\t'||ch1=='\n')
                        {
                                ch="";
                        }
                }
                fin.close();
                    getchar();
        }
};
int main()
{
        Contacts number;
        int choice;
        while(1)
        {

        system("cls");
        cout<<"1. ADD CONTACT\n";
        cout<<"2. SHOW LIST\n3.SEARCH CONTACT \n4.EXIT\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
                system("cls");
                number.setcontact();
                break;
        case 2:
                system("cls");
                number.showcontact();
                getchar();
                break;
        case 3:
                system("cls");
                number.searchcontact();
              //  getchar();
                break;
        case 4:
                exit(0);
        default:
                cout<<"\nINVALID ENTRY";
                break;
        }
        }
}
