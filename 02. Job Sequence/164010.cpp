
#include<bits/stdc++.h>
using namespace std;
int Jobsequence(int d[],int j[],int n)
{
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
    int d[100],j[100],p[100],n;
    cin>>n;
    for(int i =1;i<=n;i++)
        cin>>p[i]>>d[i];

         cout<<endl<<endl;
    cout<<p[1]<<" "<<d[1];
    cout<<endl<<endl;
    cout<<endl<<endl;
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


    cout<<endl<<endl;
    cout<<p[1]<<" "<<d[1];
    cout<<endl<<endl;

    for(int i=1;i<=n;i++)
        cout<<p[i]<<" "<<d[i]<<endl<<endl;
    int k, prof=0;
    k = Jobsequence(d, j, n);
    for(int i =1;i<=k;i++)
    {
        prof+=p[j[i]];
        cout<<j[i]<<" ";
    }
    cout<<endl<<endl<<prof;
}
