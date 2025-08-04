#include<iostream>
using namespace std;
class test{
int data=5;
friend int fun(int x);
public:
test(){
data=5;
}
};
int fun(int x){
test obj;
return obj.data+x;
}
int main(){
cout<<"Answer="<<fun(4)<<endl;
return 0;
}

