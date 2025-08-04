#include<iostream>
using namespace std;
class publication{
    string title;
    float price;
    public:
    void add(){
        cout<<"\n Enter title of publication=";
        cin>>title;
        cout<<"\nEnter price of publication=";
        cin>>price;
    
    void display(){
    
        cout<<"---------------------------------------------------------"
        cout<<"\n Title="<<title;
        cout<<"\n Price="<<price;
    }
};
class book : public publication{
    private:
    int pg_count;
    public:
    void add_book(){
        try{
            add();
            cout<<"\nEnter page count=";
            cin>>pg_count;
            if(pg_count<=0){
                throw pg_count;
				}
				}
            
        
            catch(...){
                cout<<"Invalid page count";
                pg_count=0;
            }


    
    void display_book(){
        display();
        cout<<"\nPage count="<<pg_count;
        pg_count;
    }
};


class tape:public publication{
    float pl_tm;
    public:
    void add_tape(){
        try{
            add();
            cout<<"\nEnter play time=";
            cin>>pl_tm;
            if(pl_tm<=0){
                throw pl_tm;
            }
        }
        catch(...){
            cout<<"Invalid playtime";
        }
    
    void display_tape(){
        display();
        cout<<"\n PLay time=";
        pl_tm=0;
    }
};
int main(){
    int ch;
    book b1;
    tape t1;
    do{
    cout<<"\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
 cout << "\n--------------------MENU-----------------------";
 cout << "\n1. Add Information to Books";
 cout << "\n2. Add Information to Tapes";
 cout << "\n3. Display Books Information";
 cout << "\n4. Display Tapes Information";
 cout << "\n5. Exit";
 cout<<"\nEnter your choice=";
 cin>>ch;

 switch(ch){
     case 1:
     b1.add_book();
     break;
     case 2:
     t1.add_tape();
     break;
     case 3:
     b1.display_book();
    
     break;
     case 4:
     cout<<"************* tape publication database**************";
     t1.display_tape();
     break;
     case 5:
     exit(0);
 }
 }
 
 while(ch!=5)
 return 0
}

