#include <cstdio>
#include<iostream>
#include<stdlib.h>
#include<chrono>
#include<time.h>
#define Max 99

using namespace std;
using namespace std::chrono;

class MergeQuick
{
public:

    int *array_Merge;
    int *array_Quick;
    bool issorted;
    MergeQuick()
    {
        array_Merge=new int[Max];
        array_Quick=new int[Max];
        issorted=false;
    }

    int num;


                                       ///Case Generation
///#########################################################################################################
    void Worst_case(int n)
    {
        delete array_Merge;
        delete array_Quick;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];

        for (int j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;

        }

        B_sort(array_Merge,n,2);
        B_sort(array_Quick,n,2);



    }


    void Best_case(int n)
    {
        delete array_Merge;
        delete array_Quick;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];

        for (int j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;

        }

        B_sort(array_Merge,n,1);
        B_sort(array_Quick,n,1);


    }

    void Average_case(int n)
    {
        delete array_Merge;
        delete array_Quick;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];

        for (int j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;

        }

    }


    void B_sort(int a[],int n,int c)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(c==1)
                {
                    if(a[j]>a[j+1])
                    {
                        int temp;
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
                if(c==2)
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

    }



    ///Merge sort
    ///#####################################################################################################

    void Merge(int a[],int l,int m,int h)
    {
        int i,j,k;
        int n1=m-l+1;
        int n2=h-m;
        int L[n1];
        int R[n2];


        for(i=0; i<n1; i++)
        {
            L[i]=a[l+i];

        }
        for (j=0; j<n2; j++)
        {
            R[j]=a[m+j+1];
        }

        i=0;
        j=0;
        k=l;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i++;
            }
            else
            {
                a[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            a[k]=L[i];
            i++;
            k++;
        }

    }


    void Merge_Sort(int a[],int l,int h)
    {
        if(l<h)
        {
            int m=l+(h-l)/2;
            Merge_Sort(a,l,m);
            Merge_Sort(a,m+1,h);
            Merge(a,l,m,h);

        }
    }




    ///Quick sort
    ///####################$$$$$$$$$$$$$$$$$$#################################################################


    void Quick_Sort(int a[],int l,int h)
    {
        if(l<h)
        {
            int m=Partition(a,l,h);
            Quick_Sort(a,l,m-1);
            Quick_Sort(a,m+1,h);

        }
    }

    int  Partition(int a[],int l,int h)
    {

        int pivot=a[h];
        int i=l-1;
        for (int j=l; j<=h-1; j++)
        {
            if(a[j]<=pivot)
            {
                i++;
                Swap(&a[i],&a[j]);

            }
        }
        Swap(&a[i+1],&a[h]);
        return i+1;
    }
///############################$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#################################################

    void Swap(int *x,int *y)
    {
        int temp=*x;
        *x=*y;
        *y=temp;
    }

    void PrintArray(int a[],int a1[])
    {
        if(issorted==true)
        {
            cout<<"Merge sorted Array: "<<endl;
            for (int i=0; i<num; i++)
            {
                cout<< a[i] <<" < ";
            }
            cout<<endl;
            cout<<"Quick sorted Array: "<<endl;
            for (int i=0; i<num; i++)
            {
                cout<<a1[i]<<" < ";
            }

        }
        else
        {
            cout<<" array-- not using merge or quick"<<endl;
            for (int i=0; i<num; i++)
            {
                cout<< a[i] <<" < ";
            }
        }

    }

};



int main()
{
    clock_t ts,tf,total_time;

    int choice, n;
    MergeQuick mq;



    while(1)
    {
        printf("\n1. Generate average case\n");
        printf("2. Generate best case\n");
        printf("3. Generate worst case\n");
        printf("4. Apply Merge sort\n");
        printf("5. Apply Quicksort\n");
        printf("6. Print array\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Number of elements: ");
            scanf("%d", &n);
            mq.Average_case(n);
            mq.issorted=false;
            break;

        case 2:
            printf("Number of elements: ");
            scanf("%d", &n);
            mq.Best_case(n);
            mq.issorted=false;

            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &n);
            mq.Worst_case(n);
            mq.issorted=false;

            break;

        case 4:
        {
            {

                printf("Applying merge sort\n");
                    mq.issorted=true;
                    auto start2 = high_resolution_clock::now();
                    mq.Merge_Sort(mq.array_Merge,0,n-1);

                    auto stop2 = high_resolution_clock::now();
                    auto duration2 = duration_cast<microseconds>(stop2 - start2);
                    cout << "\nTime for MergeSort: " << duration2.count()<< " microseconds" << endl;

                    break;
            }
        }

        case 5:
        {


            printf("Applying quicksort\n");
            auto start1 = high_resolution_clock::now();

            mq.Quick_Sort(mq.array_Quick,0,n-1);

            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            cout << "\nTime for QuickSort: " << duration1.count() << " microseconds" << endl;
            break;
        }

        case 6:
            printf("Array\n");
            mq.PrintArray(mq.array_Merge,mq.array_Quick);
            break;
        }
    }
}

