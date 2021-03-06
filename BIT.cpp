#include<bits/stdc++.h>
#define maxn 500023
using namespace std;
inline int lowbit(int x){return x&-x;}
int n,m;
int c[maxn],c2[maxn],a[maxn];
inline void add(int pos,int val)
{
    for(;pos<=n;pos+=lowbit(pos)) c[pos]+=val,c2[pos]+=val*pos;
}
inline void add_range(int l,int r,int val)
{
    add(l,val);
    add(r+1,-val);
}
inline long long ask(int pos)
{
    long long ans=0;
    for(;pos>0;pos-=lowbit(pos)) ans+=(pos+1)*c[pos]-c2[pos];
    return ans;
}
inline long long ask_range(int l,int r)
{
    return ask(r)-ask(l-1);
}
int main()
{
    memset(c,0,sizeof(c));
    memset(c2,0,sizeof(c2));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]),add(i,a[i]-a[i-1]);
    for(int i=1;i<=m;++i)
    {
        int p,x,y,z;
        scanf("%d",&p);
        if(p==1)
        {
            scanf("%d%d%d",&x,&y,&z);
            add_range(x,y,z);
        }
        else scanf("%d",&x),printf("%lld\n",ask(x));
    }
    return 0;
}