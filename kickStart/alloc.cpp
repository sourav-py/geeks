#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll k =0;k<t;k++)
    {
        ll n,b;
        cin>>n>>b;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll result = 0;
        ll count = 0;
        ll spent = arr[count];
        while(spent <= b)
        {
            result++;
            count++;
            spent += arr[count];
        }
        cout<<"Case #"<<k+1<<": "<<result<<endl;
    }
}