#include<iostream>


using namespace std;
int linearsch(int arr[],int n,int key){
    for(int i=0;i<=n;i++){
        if(arr[i]==key){
            return i;
        }
    }
  
    return -1
  } 

int main()
{
    int n,i ,key;
    cout<<"Enter lenght of array=";
    cin>>n;
    int arr[n]
    for(i=0;i<n;i++){
        cout<<"Enter elements=";
        cin>>arr[i];
		}
    
    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
   
    cout<<"Enter no. to be search=";
    cin>>key;
     cout<<linearsch(arr,n,key);
     return 0;
	 }




