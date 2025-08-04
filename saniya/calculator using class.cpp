#include<iostream>
using namespace std;
class cal{
    public:
    float add(float a,float b){
    return a+b;   
    }
     float sub(float a,float b){
    return a-b;   
    }
     float mul(float a,float b){
    return a*b;   
    }
     float div(float a,float b){
    return a/b;   
    }
   
};
int main(){
    float x,y,z,w;
    cal m;
    x=m.add(10,2);
    cout<<"addition="<<x<<endl;
     y=m.sub(10,2);
    cout<<"Subtraction="<<y<<endl;
     z=m.add(10,2);
    cout<<"multiplication="<<z<<endl;
     w=m.div(10,2);
    cout<<"division="<<w;
    return 0;
}

