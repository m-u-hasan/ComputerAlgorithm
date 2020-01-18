#include<bits/stdc++.h>
using namespace std;

    int p[100], w[100];
    float arr[100]={0.0};

void knapsack(int, int);



int main()
{
    freopen("kinput.txt", "w", stdin);
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
        for(int j=i+1; i<n; i++)
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

    for(i=0; i<n; i++)
    {
        if(m<w[i])
        {
            break;
        }
        m=m-w[i];
        arr[i]=1;
    }
    if(i<=n)
    {
        arr[i]=m/(float)w[i];
    }

    cout<<endl<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    int sum=0;

for(i=0; i<n; i++)
{
    sum= sum+p[i]*arr[i];
}
cout<<sum;
}


