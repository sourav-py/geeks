#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[5] = {5,4,3,2,2};
    vector<int> vect(arr,arr+5);

    for(int i=0;i<5;i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    
    sort(vect.begin(),vect.end());

    for(int i=0;i<5;i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
   

    return 0;
}