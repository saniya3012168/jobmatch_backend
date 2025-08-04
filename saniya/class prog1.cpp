#include<iostream>
#include<string>
using namespace std;
class account{
    private:
    double bal;
    public:
    string pass;
    void setbal(double b){
       bal=b;
  }
    double getbal(){
        return bal;
 }   
};


int main(){
    account a;
    a.setbal(10000);
    a.pass="saniya";
    cout<<a.getbal()<<endl;
    cout<<a.pass;
    return 0;
}

