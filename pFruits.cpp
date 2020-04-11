#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int fruits[n];
        int cost[n];
        int count[m];

        for(int i=0;i<n;i++)
        {
            cin>>fruits[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>cost[i];
        }

        for(int i=0;i<m;i++)
        {
            count[i] = 0;
        }

        for(int i=0;i<n;i++)
        {
            count[fruits[i]-1] += cost[i];
        }

        
        int max = *max_element(count,count+m);
        int min = max;
        for(int i=0;i<m;i++)
        {
            if(count[i] != 0 && count[i]<min)
            {
                min = count[i];
            }
        }
        cout<<min<<endl;

    }
}