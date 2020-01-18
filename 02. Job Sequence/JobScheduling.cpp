#include<bits/stdc++.h>
using namespace std;
int Jobsequence(int d[],int j[],int n)
{
    int q,i,r,k;
    d[0]=0;j[0]=0;
    j[1]=1;k=1;

    for(i=2;i<=n;i++)
    {
        r=k;
        while((d[j[r]]>d[i])&&(d[j[r]]!=r))
            r = r-1;
        if((d[j[r]]<=d[i])&&(d[i]>r))
        {
            for(q=k;q>=r;q--)
            {
                j[q+1]=j[q];
            }
            j[r+1]=i;
            k=k+1;

        }
    }
return k;
}

int main()
{
    int d[100],j[100],p[100],n;
    cout<<"Enter the value of job Number"<<endl;
    cin>>n;
    cout<<"Enter the values of profits"<<endl;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>d[i];


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
   for(int i =1;i<=n;i++)
        cout<<p[i]<<" "<<d[i]<<endl<<endl;

    int k = Jobsequence(d,j,n);
    int prof=0;
    for(int i=1;i<=k;i++)
        prof+=p[j[i]];
    cout<<"Total profits is = "<<prof<<endl;

return 0;
}
