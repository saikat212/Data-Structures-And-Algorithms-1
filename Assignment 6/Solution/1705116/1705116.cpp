#include <bits/stdc++.h>
using namespace std;

class activity
{
public:

    string name;
    int s;
    int f;
    activity()
    {

    }

    void FindActivities(activity a[],int n)
    {


        int j=0,i;
        cout<<"Set={ ";
        cout<<a[j].name<<",";

        for (i=0; i<n; i++)
        {

            if(a[i].s>=a[j].f)
            {
                cout<<a[i].name<<",";
                j=i;
            }
        }
        cout<<"}";
    }

    void Mysort(activity a[],int n);

};
void activity::Mysort(activity a[],int n)
{
    int min_index=0,i,j;
    for (i=0; i<n-1; i++)
    {
        min_index=i;
        for (j=i+1; j<n; j++)
        {

            if(a[j].f<a[min_index].f)
            {
                min_index=j;

            }
        }
        activity temp;
        temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;

    }

}
int main()
{
    int n;
    cout<<"Activities number: ";
    cin>>n;
    int y=100;
    activity a[n];
    activity ob;
    for (int i=0; i<n; i++)
    {
        string s=to_string(i+1);
        a[i].name="a"+s;
        a[i].s=rand()%10;
        int x=rand()%3;

        if(x!=0)
        {
            a[i].f=a[i].s+x;

        }
        else
        {
            a[i].f=a[i].s+x+1;
        }

    }
    cout<<"Unsorted activies: "<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i].name<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<a[i].s<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<a[i].f<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {

    }
    cout<<endl;

    ob.Mysort(a,n);

    cout<<"Sorted activies: "<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i].name<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<a[i].s<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<a[i].f<<"\t\t\t";
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {

    }
    cout<<endl;
    cout<<"Optimal solution set:"<<endl;

    ob.FindActivities(a,n);

}
