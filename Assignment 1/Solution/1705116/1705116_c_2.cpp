#include<iostream>
#include<unordered_set>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<chrono>


using namespace std;
using namespace std::chrono;

unordered_set<string>powerSet(vector<string> const &S,int n)
{
    int N=pow(2,n);
    unordered_set<string> set;
    for(int i=0;i<N;i++)
    {
        string subset;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                subset += (S[j]) + " ";


            }


        }
        set.insert(subset);


    }
    return set;
    /*
    for(string subset:set)
        {
            cout<<subset<<endl;
        }
    */
}



int main()
{
    vector<string> S;
    unordered_set<string> set;
    int n;
    cin>>n;

    int x,c;
    char y;
    for(int i=0;i<n;i++)
    {
        c=rand()%4;
        if(c==1){
        x=rand()%26;
        y=(char)(x+97);
        }
        else if(c==2)
        {
        x=rand()%26;
        y=(char)(x+65);
        }
        else if(c==3)
        {
        x=rand()%10;
        y=(char)(x+48);
        }
        std::string st(1,y);
        S.push_back(st);


    }


    //sort(S.begin(),S.end());
    auto start=high_resolution_clock::now();
    set=powerSet(S,n);
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<"Time: "<<duration.count()<<"microseconds"<<endl;

    for(string subset:set)
        {
            cout<<subset<<endl;
        }
    return 0;
}
