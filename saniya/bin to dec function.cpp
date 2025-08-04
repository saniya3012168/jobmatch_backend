//Binary--->Decimal


#include<iostream>
using namespace std;
int bintodec(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans+=x*y;
        x*=2;  //for octal ---> decimal x*=8
        n/=10;
    }
    return ans;
	}

int main(){
    int n;
    cout<<"Enter n=";
    cin>>n;
    cout<<bintodec(n)<<endl;
}

