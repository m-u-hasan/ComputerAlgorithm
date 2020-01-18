#include<bits/stdc++.h>
using namespace std;
int p[100];

int js(int d[],int j[],int n)
{
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            if(p[j]<p[j+1])
            {
                swap(p[j],p[j+1]);
                swap(d[j],d[j+1]);
            }
        }

    }

    d[0] = j[0] = 0;
    j[1]  = 1;
    int k = 1;
    for(int i = 2;i<=n;i++)
    {
        int r = k;
        while(d[j[r]]>d[i] && d[j[r]]!=r)
        {
            r = r-1;
        }
        if(d[j[r]]<=d[i] && d[i]>r)
        {
            for(int q = k;q>=r+1;q--)
                j[q+1] = j[q];
            j[r+1] = i;
            k = k+1;
        }
    }
    return k;
}

int main()
{
    int n,d[100],j[100];
    cin>>n;
    for(int i =1;i<=n;i++)
        cin>>p[i]>>d[i];
    cout<<endl;
    int k = js(d,j,n);
    cout<<"After Sorting: "<<endl;
    for(int i =1;i<=n;i++)
        cout<<p[i]<<" "<<d[i]<<endl;
    cout<<"job Added after sorting : "<<endl;
    for(int i =1;i<=k;i++)
        cout<<j[i]<<" ";
}
