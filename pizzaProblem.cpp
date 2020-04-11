#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    
    int toOrder = 0;
    int pizzaCount = 0;

    vector<int> slices(arr,arr+n);
    vector<int> pickedSlices;
    while(toOrder < m && slices.size() > 0)
    {
        int maxElement = *max_element(slices.begin(),slices.end());
        if(toOrder + maxElement <= m)
        {
            toOrder += maxElement;
            pizzaCount++;
            pickedSlices.push_back(maxElement);
        }
        auto itr = find(slices.begin(),slices.end(),maxElement);
        slices.erase(itr);
    }

    cout<<toOrder<<endl;
    cout<<pizzaCount<<endl;
    reverse(pickedSlices.begin(),pickedSlices.end());
    for(int i=0;i<pickedSlices.size();i++)
    {
        cout<<pickedSlices[i]<<" ";
    }
    cout<<endl;
    
    return 0;

}