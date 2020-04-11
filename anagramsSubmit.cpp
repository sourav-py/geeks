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
    
	        }
            if(i==n-1)
            {
                countList.push_back(1);
                break;
            }
	        int count = 0;
	        string hold = list[i];
            
	        for(int j=i;j<n;j++)
	        {
	            bool isAnagram = true;
               
	            if(list[i].length()==list[j].length())
	            {
                   
	                int tempLen = hold.length();
                    
	                for(int k=0;k<tempLen;k++)
	                {
                        
	                    size_t itr = hold.find(list[j][k]);
	                    if(itr==string::npos)
	                    {
                            
	                        isAnagram = false;
	                        break;
	                    }
	                }
                   
                    for(int k=0;k<tempLen;k++)
	                {
                       
	                    size_t itr = list[j].find(hold[k]);
	                    if(itr==string::npos)
	                    {
                    
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