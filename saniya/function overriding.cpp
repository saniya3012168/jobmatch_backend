#include<iostream>
using namespace std;
class base{
public:
void getdata(){
cout<<"Base";
}
};

class derived:public base{
public:
void getdata(){
cout<<"derived";
}
};
int main(){
derived obj;
obj.base::getdata();
obj.getdata();
return 0;
}

