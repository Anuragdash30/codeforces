#include<set>
#include<vector>
#include<iostream>
struct node
{
long a,b,w;
};
void deletee(long a,long b, long w, std::set<long> &s1,std::vector<long> &s3)
{
   
    auto it =s1.lower_bound(a);
    while(it!=s1.upper_bound(b)&& it!=s1.end())
    {  
        if(*it != w)
        {   s3[*it]=w;
            s1.erase(*it);
      
            it = s1.lower_bound(*it);
            
        }
        else
        {
        s1.erase(it);
        it=s1.lower_bound(*it);
        }
    }
    return;
}

int main()
{
long n,m;
std::cin>>n>>m;
std::set<long> s1;
std::vector<node> s2(m); 
std::vector<long> s3(n,-1);
long x,y,s;
for(long i=0;i<m;i++)
{
    
    std::cin>>x>>y>>s;
    s2[i].a=x-1;
    s2[i].b=y-1;
    s2[i].w=s-1;

}


for(long i=0;i<n;i++)
{   
    s1.insert(i);
}
for(long i=0;i<m;i++)
{
    deletee(s2[i].a,s2[i].b,s2[i].w,s1,s3);
    s1.insert(s2[i].w);
}
for(long j=0;j<n;j++)
{   
    std::cout<<(s3[j]==-1?0:s3[j]+1)<<" ";
}
return 0;

}
