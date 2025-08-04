#include<iostream>
using namespace std;
int fac(int n){
    int fact=1;
  for(int i=1;i<=n;i++);
     fact*=i;
  }
  return fact;
}
int main(){
    int n;
    cout<<"Enter n=";
    cin>>n;
    cout<<"Factorial="<<fac(n)<<endl;
    return 0;
}

