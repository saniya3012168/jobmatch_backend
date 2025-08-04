#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class college{
    public:
    string name;
    string id;
    void accept(){
        cout<<"Enter name of student=";
        cin>>name;
        cout<<"Enter id of student=";
        cin>>id;
    }
};

int main(){
    int n;
    cout<<"Enter no of student=";
    cin>>n;
    college*student=new college[n];
    for(int i=0;i<n;i++){
    cout<<"\nEnter detail of student"<<endl;
    student[i].accept();
}
    ofstream outfile("clg.txt");
    for(int i=0;i<n;i++){
        outfile<<"Name:"<<student[i].name<<endl;
        outfile<<"Id:"<<student[i].id<<endl;
   } 
    outfile.close();
   
    string myText;
    ifstream infile("clg.txt");
    cout<<"Info of students"<<endl;
    while(getline(infile,myText)){
        cout<<myText<<endl;}
    
    infile.close();
    delete[]student;
    return 0;
   
}

