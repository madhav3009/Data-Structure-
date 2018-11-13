#include<iostream>
using namespace std;

int partition(int arr[6],int si,int ei)
{
	
	
	int pivot=arr[si];
	int countSmaller=0;
	for(int i=si+1;i<=ei;i++)
	{
		if(arr[i]<=pivot)
		{
			countSmaller++;
	    }
	}
	int pivotIndex=si+countSmaller;
	
	arr[si]=arr[pivotIndex];
	arr[pivotIndex]=pivot;
	
	int i=si,j=ei;
	while(i<=pivotIndex && j>pivotIndex)
	{
		if(arr[i]<=pivot)
		{
			i++;
		}
		else if(arr[j]>pivot)
		{
			j--;
		}
		else
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		
	}
	return pivotIndex;
}

void QuickSort(int arr[6],int si,int ei)
{
if(si>=ei)
	return ;
   int p=partition(arr,si,ei);
   QuickSort(arr,si,p-1);
   QuickSort(arr,p+1,ei);  	
}

int main()
{
	int arr[6]={20,40,10,50,60,30};
	QuickSort(arr,0,5);
	for(int i=0;i<6;i++)
	{
	cout<<endl<<arr[i];
	}
return 0;
}
