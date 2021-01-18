// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


 // } Driver Code Ends


int findPlatform(int arr[], int dep[], int n)
{
	int tot[2*n];
    int type[2*n];
    map<int,int> s1;
    int j=0;
    for(int i=0;i<2*n;i++)
    {   if(i==n)
        {
            j=0;
        }
        if(i>=n)
        {
            tot[i]=dep[j];
            type[i]=1;

            j++;
        }
        if(i<n)
        {
        tot[i]=arr[j];
        type[i]=0;
        j++;
        }

    }
    for(int i=0;i<2*n;i++)
    {   
        s1[tot[i]]=i;
    }
    sort(tot,tot+2*n);

    int max=0;
    int curr=0;
    for(int i=0;i<2*n;i++)
    {   if(s1[tot[i]]<n)
        type[i]=0;
        else
        {
            type[i]=1;
        }
        
    }
   
    for(int i=0;i<2*n;i++)
    {
        if(type[i]==0)
        {
            curr=curr+1;
            if(max<curr)
            {
                max=curr;
            }
        }
        else
        {
            curr=curr-1;

        }
        
    }
    return(max);
	
}


// { Driver Code Starts.
// Driver code
int main()
{

   
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
       
        
    cout <<findPlatform(arr, dep, n)<<endl;

   return 0;
}  // } Driver Code Ends