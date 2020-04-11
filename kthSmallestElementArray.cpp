#include <iostream>
using namespace std;
void Merge(int*arr ,int p,int mid,int r);
void RecursiveMergeSort(int* arr,int p,int r);

int main()
{
	int n;
	cin>>n;
	int output[n];
	int count = 0;
	for(int i = 0;i<n;i++)
	{
		int a,b;
		cin>>a;
		int arr[a];
		for(int j=0;j<a;j++)
		{
			cin>>arr[j];
		}
		cin>>b;
		RecursiveMergeSort(arr,0,a-1);
		output[count++] = arr[b-1];
		
	}
	
	for(long int l=0;l<count;l++)
	{
		cout<<output[l]<<endl;
	}
	
	return 0;
}



void Merge(int*arr ,int p,int mid,int r)
{
    
    int sizeOfLeftArray = mid-p +1;
    int sizeOfRightArray = r-mid;

    int LeftArray[sizeOfLeftArray];
    int RightArray[sizeOfRightArray];

    for(int l=0;l<sizeOfLeftArray;l++)
    {
        LeftArray[l] = arr[p+l];
    }


    for(int r=0;r<sizeOfRightArray;r++)
    {
        RightArray[r] = arr[r+mid+1];
    }
  

    //i to iterate first array, j for second array and k for main array.
    //k != 0 to avoid overwriting the sorted left array.
    
    int i=0,j=0,k=p; 
    while(i<sizeOfLeftArray && j<sizeOfRightArray)
    {
        if(LeftArray[i]<RightArray[j])
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while(i<sizeOfLeftArray)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    while(j<sizeOfRightArray)
    {
        arr[k] = RightArray[j];
        k++;
        j++;
    }


}



void RecursiveMergeSort(int* arr,int p,int r)
{
    if(p<r)
    {
        int mid = (p+r)/2;

        RecursiveMergeSort(arr,p,mid);
        RecursiveMergeSort(arr,mid+1,r);

        Merge(arr,p,mid,r);
    }
}

