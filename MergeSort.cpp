#include<iostream>
using namespace std;

void Merge(int arr[6],int si,int ei)
{
	int mid=(si+ei)/2;
	int size=ei-si+1;
	int *temp=new int[size];
    int k=0,i=si,j=mid+1;
    while(i<=mid&& j<=ei)
    {
    	if(arr[i]<arr[j])
    	{
    		temp[k]=arr[i];
    		i++;
    		k++;
		}
		else
		{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	
	while(i<=mid)
	{
		temp[k]=arr[i];
		k++;
		i++;
	}
	while(j<=ei)
	{
		temp[k]=arr[j];
		k++;
		j++;
	}

int m=0;
for(int i=si;i<=ei;i++)
{
	arr[i]=temp[m];
	m++;
}

}


void MergeSort(int arr[6],int si,int ei)
{
	if(si>=ei)
	{
	 return;	
	}
	
    int mid=(si+ei)/2;
	MergeSort(arr,si,mid);
	MergeSort(arr,mid+1,ei);
	Merge(arr,si,ei);
}


int main()
{
	
	int arr[6]={20,10,40,50,60,30};
	MergeSort(arr,0,5);
	for(int i=0;i<6;i++)
	{
		cout<<endl<<arr[i];
	}
	return 0;
}
