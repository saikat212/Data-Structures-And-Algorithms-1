#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
using namespace std::chrono;
void insertionSort(int a[],int n){

         for(int i=1;i<n;i++)
         {
             int key=a[i];
             int j=i-1;
             while (j>=0 && a[j]>key)
             {
                 a[j+1]=a[j];
                 j--;
             }
             a[j+1]=key;
         }



    }

void selectionSort(int a[],int n)
{
    int min_id,j,i;
    int temp;
    for (i=0;i<n;i++)
    {
        min_id=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_id])
            {
                min_id=j;
            }
        }


        temp=a[i];
        a[i]=a[min_id];
        a[min_id]=temp;

    }
}


void B_sort(int a[],int n)
{
for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}

void B1_sort(int a[],int n)
{
for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}




int main()
{
    int n;
    cout<<"Enter Array size: "<<endl;
    cin>>n;
    int *a=new int[n];
    int *a2=new int[n];
    for(int i=0;i<n;i++)
    {
        int x=rand()%10;
        a[i]=x;
        a2[i]=x;

    }


    cout<<"\nunsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a2[i]<<" ";
    }

     B_sort(a,n);
     B_sort(a2,n);
      cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a2[i]<<" ";
    }


    cout<<"Selection Sort  result"<<endl;
    auto start2 = high_resolution_clock::now();
    selectionSort(a2,n);

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "\nTime for selection: " << duration2.count() << " microseconds" << endl;


    cout<<"Insertion Sort  result"<<endl;
    auto start1 = high_resolution_clock::now();
    insertionSort(a,n);

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\nTime for insertionSort: " << duration1.count() << " microseconds" << endl;

   cout<<"\ns_sorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a2[i]<<" ";
    }

     cout<<"\ni_sorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }




}
