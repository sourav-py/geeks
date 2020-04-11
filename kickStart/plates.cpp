#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    for(ll u=0;u<t;u++)
    {
        ll n,k,p;
        cin>>n>>k>>p;
        vector<vector<ll>> v;
        for(ll i=0;i<n;i++)
        {
            vector<ll> temp;
            for(ll j=0;j<k;j++)
            {
                ll el;
                cin>>el;
                temp.push_back(el);
            }
            v.push_back(temp);
        }

        ll selected = 0;
        ll profit = 0;
        while(selected < p && v.size() > 0)
        {
            //cout<<"Selected : "<<selected<<endl;
            //cout<<"Profit : "<<profit<<endl;
            ll max[n];
            ll curr_max = *max_element(v[0].begin(),v[0].end());
            if(k-selected < v[0].size())
            {
                curr_max = *max_element(v[0].begin(),v[0].begin() + (k-selected));
            }
            cout<<v[0][0]<<endl;
            //cout<<"Curr max : "<<curr_max<<endl;
            ll curr_max_index = 0;

            for(int m=1;m<v.size();m++)
            {
                ll check_max = *max_element(v[m].begin(),v[m].end());
                cout<<k-selected<<endl;
                if(k-selected < v[m].size())
                {
                    check_max = *max_element(v[m].begin(),v[m].begin() + (k-selected));
                }
                //cout<<"Check max : "<<check_max<<endl;
                if(check_max > curr_max)
                {
                    curr_max = check_max;
                    curr_max_index = m;
                }
            }
            
            //popping from mth index stack
            //cout<<"final max : "<<curr_max<<endl;
            ll justPopped = v[curr_max_index][0];
            v[curr_max_index].erase(v[curr_max_index].begin());
            profit += justPopped;
            selected += 1;
            //cout<<"Popped  : "<<justPopped<<endl;
            //eliminate condition stack
            if(v[curr_max_index].size() == 0)
            {
                v.erase(v.begin()+curr_max_index);
            }

            while(justPopped != curr_max)
            {
                selected += 1;
                justPopped = v[curr_max_index][0];
                profit += justPopped;
                //cout<<"Popped : "<<justPopped<<endl;
                v[curr_max_index].erase(v[curr_max_index].begin());
                if(v[curr_max_index].size() == 0)
                {
                    v.erase(v.begin()+curr_max_index);
                }
            }
        }
        //cout<<"Selected : "<<selected<<endl;
        //cout<<"Profit : "<<profit<<endl;
        cout<<"Case #"<<u+1<<": "<<profit<<endl;

    }
    return 0;
}
