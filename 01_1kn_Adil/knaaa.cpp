#include<bits/stdc++.h>
using namespace std;

    int p[100], w[100];
    float arr[100]={0.0};

void knapsack(int, int);

int main()
{
   freopen("kinput.txt", "r", stdin);
    int m, n;

    cin>>m>>n;
    knapsack(m,n);

}
void knapsack(int m, int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        cin>>w[i];
    }

    int i, j, temp, temp1;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((p[i]/w[i])<(p[j]/w[j]))
            {
                temp= p[i];
                temp1= w[i];


                p[i]=p[j];
                w[i]=w[j];


                p[j]=temp;
                w[j]=temp1;
            }
        }
    }



    int u=m;

    for(i=0; i<n; i++)
    {
        if(u<w[i])
        {
            break;
        }
        u=u-w[i];
        arr[i]=1;
    }
    if(i<=n)
    {
        arr[i]=u/(float)w[i];
    }


    int sum=0;

for(i=0; i<n; i++)
{
    sum= sum+p[i]*arr[i];
}
cout<<"Total Profit: "<<sum;
}


