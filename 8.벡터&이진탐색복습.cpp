#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>&N,int M)
{
    int L=0;
    int R=N.size();
    
    while(L<=R)
    {
        int point=(L+R)/2;
        if(N[point]==M)
            return true;
            
        if(point>M)
            R=point-1;
        else
            L=point+1;
    }
    return false;
}

int main()
{
    int n,m,M;
    
    
    scanf("%d",&n);
    vector<int>N(n);
    for(int i=0;i<n;i++)
        scanf("%d",&N[i]);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(N[j]>N[j+1])
            {
                int im=N[j];
                N[j]=N[j+1];
                N[j+1]=im;
            }
        }
    
    scanf("%d",&m);
    for(int j=0;j<m;j++)
    {
        scanf("%d",&M); 
        printf("%s ",search(N,M) ? "Yes" : "No");
    }
        
    return 0;
}