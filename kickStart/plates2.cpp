#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class pStack
{
    public:
    int* arr;
    int size;
    int counter;
    public:
    pStack(int* plates,int size)
    {
        arr = plates;
        size = size;
        counter = 0;
    }
    int findMaxIndex(int k)
    {
        cout<<"inside max function "<<endl;
        if(counter<=size-1)
        {
            int last = k<size?k:size;
            int max_index = counter;
            for(int i=counter+1;i<last;i++)
            {
                if(arr[i]>arr[max_index])
                {
                    max_index = i;
                }
            }
            return max_index;
        }
        return -1;
    }
    int popx(int x)
    {
        int toReturn = 0;
        for(int i=0;i<x;i++)
        {
            toReturn += arr[counter++];
            size--;
        }
        return toReturn;
    }
};


int findMaxIndexFromMaxArr(int* arr,int size)
{
    int max_index = 0;
    for(int i=1;i<size;i++)
    {
        if(arr[i]>arr[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}


int main()
{
    int t;
    cin>>t;
    for(int u=0;u<t;u++)
    {
        int n,k,p;
        cin>>n>>k>>p;
        vector<pStack> v;
        for(int i=0;i<n;i++)
        {
           
            int arr[k];
            for(int j=0;j<k;j++)
            {
                cin>>arr[j];
            }
            pStack temp(arr,k);
            v.push_back(temp);
        }
        int selected = 0;
        int profit = 0;
        int max[n];
        while(selected<p)
        {
            cout<<"Selected : "<<selected<<endl;
            cout<<"Profit : "<<profit<<endl;

            for(int i=0;i<n;i++)
            {
                max[i] = v[i].findMaxIndex(k-selected);
            }
            int maxIndexFromMaxArray = findMaxIndexFromMaxArr(max,n);
            int maxIndexFromStack = findMaxIndexFromMaxArr(v[maxIndexFromMaxArray].arr,v[maxIndexFromMaxArray].size);
            int count = maxIndexFromStack+1;
            profit+= v[maxIndexFromMaxArray].popx(count);

        }
        cout<<"Selected : "<<selected<<endl;
        cout<<"Profit : "<<profit<<endl;
    
    return 0;
    }
}