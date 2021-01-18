#include<bits/stdc++.h>
struct node
{
int a,b,w;
};

int segment(std::vector<int> &s1,int i,int j,int st,int en,int w)
{   
    if(i>en||j<st)
    {   
        return 0;
    }
    if(i==j)
    {   
        if(i!=w&&s1[i]==0)
        {   
            s1[i]=w;
            
        }
        return 0;
    }
    int mid=i + (j -i)/2;
    segment(s1,i,mid,st,en,w);
    segment(s1,mid+1,j,st,en,w);
    return 0;
}
int main()
{
int n,m;
std::cin>>n>>m;
std::vector<int> s1(n+1,0);
std::vector<node> s2(m); 
for(int i=0;i<m;i++)
{
    int x,y,s;
    std::cin>>x>>y>>s;
    s2[i].a=x;
    s2[i].b=y;
    s2[i].w=s;

}


for(int i=0;i<m;i++)
{   
    segment(s1,1,n,s2[i].a,s2[i].b,s2[i].w);
}
for(int j=1;j<=n;j++)
{
    std::cout<<s1[j]<<" ";
}

return 0;

}
