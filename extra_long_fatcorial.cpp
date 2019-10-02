#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1000]={0};
    arr[0]=1;
    int len=1;
    for(int i=2;i<=n;i++)
    {   
        int carry=0;
        for(int j=0;j<len;j++)
        {
            int mul=arr[j]*i+carry;
            int val=mul%10;
            carry=mul/10;
            arr[j]=val;
        }

        while(carry)
        {
            len++;
            int val=carry%10;
            arr[len-1]=val;
            carry/=10;
        }

    }

    for(int i=len-1;i>=0;i--)
    {
        cout<<arr[i];
    }

    return 0;

}
    
