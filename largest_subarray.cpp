#include<iostream>
#include<vector>
using namespace std;


bool isconsec(int arr[], int j, int k, int min, int max )
{
        if(max-min!=k-j)
        {
                return false;
        }
        vector<bool> visited(k-j+1);
        for(int l=j;l<=k;l++)
        {
                if(visited[arr[l]-min])
                {
                        return false;
                }
                visited[arr[l]-min]=true;
        }
        return true;
}

void lar_sub(int arr[],int n)
{
        int len=1;
        int start=0;
        int end=0;

        for(int j=0;j<n-1;j++)
        {
                int minimum_value=arr[j],maximum_value=arr[j];
                for(int k=j+1;k<n;k++)
                {
                        minimum_value= min(minimum_value,arr[k]);
                        maximum_value= max(maximum_value,arr[k]);
                        if(isconsec(arr,j,k,minimum_value,maximum_value))
                        {
                                if(len < maximum_value-minimum_value+1)
                                {
                                 len=maximum_value-minimum_value+1;
                                 start=j;
                                 end=k;
                                }
                        }

                }
        }

cout<<"The lagrest subarray is [";

for(int m=start;m<=end;m++)
{
        cout<<arr[m]<<",";
}
cout<<"]";
}



int main()
{
int n,i;
cout<<"Enter the size of array: ";
cin>>n;
int arr[n];
cout<<"\nEnter array:\n";
for(i=0;i<n;i++)
{
cin>>arr[i];
}

//cout<<"hi";
lar_sub(arr,n);
return 0;

}
