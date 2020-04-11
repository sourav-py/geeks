#include <iostream>
#include <time.h>

using namespace std;

long int findMaxInInterval(int* arr,int l,int r)
{
	long int max = arr[l];
	for(long int i=l;i<=r;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

int main()
{
	
	
	long int n;
	cin>>n;
	long int output[n];
	long int count = 0;
	for(long int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		int arr[a];
		for(long int j=0;j<a;j++)
		{
			cin>>arr[j];
		}
		long int sum =0;
		for(long int c=1;c<a-1;c++)
		{
			long int max_left = findMaxInInterval(arr,0,c-1);
			long int max_right = findMaxInInterval(arr,c+1,a-1);
		
			long int minimum = (max_left>max_right)?max_right:max_left;
		
			if(minimum - arr[c] >= 0)
			{
				sum += (minimum - arr[c]);
			}
		}
		output[count++] = sum;
	}
	for(long int l = 0;l<count;l++)
	{
		cout<<output[l]<<endl;
	}
	
	return 0;
	
	
}
