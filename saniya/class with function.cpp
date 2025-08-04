#include<iostream>
using namespace std;
class employee{
    private:
    int a,b,c;
	
    public:
    int d,e;
    void setdata(int a,int b,int c);  //Declaretion
    void getdata(){       //To get output
    cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;

};
void employee::setdata(int a1,int b1,int c1){   //"::"=for scope
    a=a1;
    b=b1;
    c=c1;
}
int main(){
    employee emp;
    emp.setdata(1,2,3);
    emp.getdata();
    emp.d=4;
    emp.e=5;
    cout<<"d="<<emp.d<<endl;
     cout<<"e="<<emp.e;
    return 0;
}

