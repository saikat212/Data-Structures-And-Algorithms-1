
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string.h>
using namespace std;
int  Max(int x,int y)
{
    int m=x;
    if(m<y)
    {
        m=y;
    }
    return m;
}
void LCS(char *X,char *Y,int m,int n)
{

    int L[m+1][n+1];
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;


            }
            else if(X[i-1]==Y[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;

            }
            else

            {
                L[i][j]=Max(L[i-1][j],L[i][j-1]);

            }
        }


    }
    int id=L[m][n];
    int cheak=id;
    char Ans[id+1];
    Ans[id]='\0';
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {

            Ans[id-1]=X[i-1];
            i--;
            j--;
            id--;
        }
        else if(L[i-1][j]>L[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    if(cheak!=0)
    {
        cout<<Ans<<endl;
    }
    else
    {
        cout<<"There was no matching "<<endl;
    }

}


int main()
{
    string x,y;
    //cout<<"First input String X="<<endl;
    cin>>x;
    //cout<<"Second input String Y="<<endl;
    cin>>y;

    int m=x.size();
    int n=y.size();
    char X[m+1];
    char Y[n+1];
    for (int i=0;i<m;i++)
    {
        X[i]=x[i];

    }


    for (int i=0;i<m;i++)
    {
    Y[i]=y[i];

    }

    LCS(X,Y,m,n);
    return 0;

}
