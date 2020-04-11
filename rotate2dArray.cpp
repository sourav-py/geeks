#include <iostream>
using namespace std;


void swap(int* x,int* y)
{
    *y += *x;
    *x = *y - *x;
    *y = *y - *x;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    
	    for(int i=0;i<n/2;i++)
	    {
	        for(int j=i;j<n-i-1;j++)
	        {
	            int a = j;
	            int b = (n-1-i)>=0?(n-1-i):(i+1-n);
                swap(&arr[i][j],&arr[a][b]);
	            
	            swap(&a,&b);
                b = (n-1-b)>=0?(n-1-b):(b+1-n);
                swap(&arr[i][j],&arr[a][b]);
	            
                swap(&a,&b);
	            b = (n-1-b)>=0?(n-1-b):(b+1-n);
                swap(&arr[i][j],&arr[a][b]);

	        }
            
	    }

        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                cout<<arr[x][y]<<" ";
            }
            
        }
        cout<<endl;
        

	    
	    
	    
	    
	}
	return 0;
}