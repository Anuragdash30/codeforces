#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void create(int *seg,int *a,int in,int st,int en,int height)
{   
    
    if(st>en)
    {
        return;
    }
    if(st==en)
    {   seg[in]=a[st];
        return;
    }
    int mid=st+(en-st)/2;
    
  
    create(seg,a,2*in,st,mid,height);
    create(seg,a,2*in+1,mid+1,en,height);
    int curr=log2(in);
    int left=seg[2*in];
    int right = seg[2*in+1];
    if(height==1)
    {
    if(curr%2==0)
    {
    seg[in]=left | right;
    }
    else
    seg[in]=left^right;
    }
    else
    {
    if(curr%2==1)
    {
    seg[in]=left | right;
    }
    else
    seg[in]=left^right;
    }

}
void update(int *seg,int ind,int in,int val,int st,int en,int height)
{
    if(in<st||in>en)
    {
        return;
    }
    if(st==en)
    {
        seg[ind]=val;
        return;
    }
    int mid=st+(en-st)/2;
  
    update(seg,2*ind,in,val,st,mid,height);
    update(seg,2*ind+1,in,val,mid+1,en,height);
    int curr=log2(ind);
    int left=seg[2*ind];
    int right = seg[2*ind+1];
    if(height==1)
    {
    if(curr%2==0)
    {
    seg[ind]=left | right;
    }
    else
    seg[ind]=left^right;
    }
    else
    {
    if(curr%2==1)
    {
    seg[ind]=left | right;
    }
    else
    seg[ind]=left^right;
    }

}
int main()
{
fio;
int n,m;
cin>>n>>m;
int c=n;
n=pow(2,n);

int *seg=new int[4*n+1];
int *a=new int[n];
queue<int> s1;
if(c%2==0)
{
    c=0;
}
else
{
    c=1;
}

for(int i=0;i<n;i++)
{
    
    cin>>a[i];
   
}

create(seg,a,1,0,n-1,c);
for(int i=0;i<m;i++)
{

    int p,q;
    cin>>p>>q;
    update(seg,1,p-1,q,0,n-1,c);
    s1.push(seg[1]);

}
for(int i=0;i<m;i++)
{
    cout<<s1.front()<<endl;
    s1.pop();
}



    



return 0;
}

