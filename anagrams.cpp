#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    vector<string> list;
	    vector<int> countList;
	    
	    
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        string el;
	        cin>>el;
	        list.push_back(el);
	    }
	    
	    int check[n];
	    for(int i=0;i<n;i++)
	    {
	        check[i] = 0;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(check[i])
	        {
	            continue;
                cout<<"Index : "<<i<<" skipped"<<endl;
	        }
            if(i==n-1)
            {
                countList.push_back(1);
                break;
            }
	        int count = 0;
	        string hold = list[i];
            cout<<"Holding : "<<list[i]<<endl;
	        for(int j=i;j<n;j++)
	        {
	            bool isAnagram = true;
                cout<<"\tChecking with : "<<list[j]<<endl;
	            if(list[i].length()==list[j].length())
	            {
                    cout<<"\t\tSize is same"<<endl;
	                int tempLen = hold.length();
                    cout<<"\t\tSize : "<<tempLen<<endl;
	                for(int k=0;k<tempLen;k++)
	                {
                        cout<<"\t\t\tInside for"<<endl;
	                    size_t itr = hold.find(list[j][k]);
	                    if(itr==string::npos)
	                    {
                            cout<<"\t\t\tInside if"<<endl;
	                        isAnagram = false;
	                        break;
	                    }
	                }
                    cout<<"\t\tSet 2"<<endl;
                    for(int k=0;k<tempLen;k++)
	                {
                        cout<<"\t\t\tInside for"<<endl;
	                    size_t itr = list[j].find(hold[k]);
	                    if(itr==string::npos)
	                    {
                            cout<<"\t\t\tInside if"<<endl;
	                        isAnagram = false;
	                        break;
	                    }
	                }
	            }
	            if(isAnagram)
	            {
	                count++;
	                check[j] = 1;
	            }
	        }
	        countList.push_back(count);
	    }
        sort(countList.begin(),countList.end());
        for(int i=0;i<countList.size();i++)
	    {
	        cout<<countList[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}