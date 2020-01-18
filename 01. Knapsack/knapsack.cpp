#include<bits/stdc++.h>
int p[100], w[100];
float x[100]={0.0};
using namespace std;
void knapsack_greedy(int, int);
int main()
{
    freopen("input.txt","r",stdin);
    int m, n;
    cin>>m>>n;
    knapsack_greedy(m,n);
    return 0;
}

void knapsack_greedy(int m, int n)
{

    cin>>p[0]>>w[0];
    for(int i=1; i<n; i++)

    {
        cin>>p[i]>>w[i];
        for(int j=0; j<i; j++)
        {
            if((p[j]/w[j])<(p[i]/w[i]))
            {
                int temp1=p[j];
                int temp2 = w[j];

                p[j] = p[i];
                w[j]=w[i];

                p[i]=temp1;
                w[i]=temp2;
            }


        }
    for(int k=0; k<i; k++)
    {
        cout<<p[k]<<" ";
    }
    cout<<endl;

       for(int k=0; k<i; k++)
    {
        cout<<w[k]<<" ";
    }
    cout<<endl<<endl;
    }



    int u, i;
    u=m;
    for( i=0; i<n; i++)
    {
        if(w[i]>u)
            break;
        x[i]=1;
        u=u-w[i];
        cout<<u<<" ";
    }
    cout<<endl;
    if(i<=n)
    {
        cout<<u<<"        "<<w[i];
        x[i]=u/(float)w[i];
        cout<<endl<<endl;
        cout<<x[i]<<endl<<endl<<endl;

    }
    for(int Q=0; Q<n; Q++)
    {
        cout<<x[Q]<<" ";
    }
cout<<endl<<endl;
    //benefit
    int sum=0;

    for(i=0; i<n; i++)
    {
        sum = sum+x[i]*p[i];
    }
    cout<<"benefit: "<<sum;
}
