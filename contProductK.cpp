#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int result = 0;
        int start = 0;
        int mult = 1;
        for(int end = 0;end<n;end++)
        {
            mult *= arr[end];
            while(mult >= k && start<end)
            {
                mult /= arr[start++];
            
            }
            if(mult<k)
            {
                result += 1 + end - start;
            }
           
        }   
        cout<<result<<endl;
        
        
    }
    return 0;
}