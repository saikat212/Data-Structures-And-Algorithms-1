
#include<iostream>
#include<cstdlib>

using namespace std;

class C
{
    int x;
    int *Parent;
    int *Rank;
    int Size;
public:
    C(int n)
    {
        Size=n;
        Parent=new int[n+1];
        Rank=new int[n+1];
        for(int i=0;i<=Size;i++)
        {
            Parent[i]=-1;
        }

    }
    void MakeSet(int x)
    {
        Parent[x]=x;
        Rank[x]=0;
    }
    int FindSet(int x)
    {
        if(x==Parent[x] || Parent[x]==-1)
        {
            return Parent[x];
        }
        Parent[x]=FindSet(Parent[x]);

    }
    void Union(int x,int y)
    {
        int r=FindSet(x);
        int s=FindSet(y);
        if(r==s)
        {
            return;
        }
        else if(Rank[r]>Rank[s])
        {
            Parent[s]=r;

        }
        else if(Rank[r]<Rank[s])
        {
            Parent[r]=s;
        }
        else
        {
            Parent[r]=s;
            Rank[s]=Rank[s]+1;
        }


    }

    void Print(int x)
    {
        for(int i=0; i<=Size; i++)
        {
            if(FindSet(x)==FindSet(i))
            {
                cout<<i<<endl;
            }
        }
    }

};
int main()
{
    int n;
    cout<<"Enter maximum range:";
    cin>>n;
    cout<<"Select element between 0 to "<< n<<endl;
    C ob(n);
    while(1)
    {
        cout<<"Operation Mode"<<endl;
        cout<<"1. MakeSet(x) "<<endl;
        cout<<"2. FindSet(x) "<<endl;
        cout<<"3. Union(x,y)"<<endl;
        cout<<"4. Print(x) "<<endl;
        cout<<"5. Exit() "<<endl<<endl<<endl;
        cout<<"Choice a command:"<<endl;
        int s;
        cin>>s;
        if(s==1)
        {
           cout<<"Enter value for making set"<<endl;
           int z;
           cin>>z;
           if(z<=n)
           {
               ob.MakeSet(z);
           }
           else
           {
               cout<<"value is out of Range"<<endl;

           }

        }
        else if(s==2)
        {
            cout<<"Value:"<<endl;
            int z;
            cin>>z;
            if(z<=n)
            {
                int rep=ob.FindSet(z);
                if(rep==-1)
                {
                    cout<<"Set:"<<z<<"does not exist"<<endl;

                }
                else
                {
                    cout<<z <<"is element of set of representative:"<<rep<<endl;
                }


            }
            else
            {
                cout<<"Out of Range value"<<endl;
            }
        }
        else if(s==3)
        {
            cout<<"Enter sets:"<<endl;
            int x,y;
            cin>>x>>y;
            if(x<=n && y<=n)
            {
                ob.Union(x,y);
            }
            else
            {
                cout<<"Out of Range value."<<endl;

            }
        }
        else if(s==4)
        {
            cout<<"Enter the set to be Printed:"<<endl;
            int x;
            cin>>x;
            if(x<=n)
            {
                cout<<"Set:::"<<endl;
                ob.Print(x);
            }
        }
        else if(s==5)
        {
            cout<<"Exit()"<<endl;
            break;

        }
    }
}
