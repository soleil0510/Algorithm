//#include<iostream>
//#include<cstring>
//#define N 10000001
//using namespace std;
//
//int Tree[N];
//int sum[N];
//
//int findRoot(int x){
//	if(Tree[x]==-1)
//		return x;
//	else{
//		int temp=findRoot(Tree[x]);
//		Tree[x]=temp;
//		return temp;
//	}
//}
//
//int main(){
//	int n;
//	while(cin>>n){
//		if(n==0){
//			cout<<1<<endl;
//			continue;
//		}
//		
//		memset(Tree,-1,sizeof(Tree));
//		
//		for(int i=1;i<=N;i++){
//
//			sum[i]=1;
//		}
//		
//		int a,b;
//		while(n--){
//			cin>>a>>b;
//			a=findRoot(a);
//			b=findRoot(b);
//			if(a!=b){
//				Tree[a]=b;
//				sum[b]+=sum[a];
//			}
//		}
//		
//		int max=1;
//		for(int i=1;i<=N;i++){
//			if(Tree[i]==-1){
//				if(sum[i]>max)
//					max=sum[i];
//			}
//		}
//		
//		cout<<max<<endl;
//		
//	}
//	
//	
//	return 0;
//}


#include <iostream>
#include <cstring>

using namespace std;
#define N 10000005
int p[N];
int sum[N];
int Find_set(int x)
{
    return p[x]==-1?x:p[x]=Find_set(p[x]);
}

int main()
{
    int n;
    while(cin>>n)
    {
        memset(p,-1,sizeof(p));
        for(int i=1;i<=N;i++)
        sum[i]=1;//每个集合元素都是1；
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            a=Find_set(a);
            b=Find_set(b);
            if(a!=b)
            {
                p[a]=b;
                sum[b]+=sum[a];//将合并后元素的个数保存到新树根中；
            }
        }
        int ans=1;
        for(int i=1;i<=N;i++)
        {
            if(p[i]==-1&&sum[i]>ans)
                ans=sum[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
