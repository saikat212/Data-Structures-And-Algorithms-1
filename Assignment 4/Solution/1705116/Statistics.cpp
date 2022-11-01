#include <cstdio>
#include<iostream>
#include<stdlib.h>
#include<chrono>
#include<time.h>
#define Max 99
#define Mutiple_senario_num 1
#define Operation_average_case 1
#define Operation_best_case 2
#define Operation_worst_case 3
using namespace std;
using namespace std::chrono;

class MergeQuick
{


public:

    int *array_Merge;
    int *array_Quick;
    int *array_average_value;
    bool issorted;
    int which_case;
    long num;
    MergeQuick()
    {
        array_Merge=new int[Max];
        array_Quick=new int[Max];
        array_average_value=new int[Max];

        issorted=false;
    }
///Case generation
///###################################################################################

    void Worst_case(long n)
    {
        delete array_Merge;
        delete array_Quick;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];

        for (long j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;

        }

        B_sort(array_Merge,n,2);
        B_sort(array_Quick,n,2);



    }


    void Best_case(long n)
    {
        delete array_Merge;
        delete array_Quick;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];

        for (long j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;

        }

        B_sort(array_Merge,n,1);
        B_sort(array_Quick,n,1);


    }



    void Average_case(long n)
    {
        delete array_Merge;
        delete array_Quick;
        delete array_average_value;
        num=n;
        array_Merge=new int[n];
        array_Quick=new int[n];
        array_average_value=new int[n];

        for (long j=0; j<n; j++)
        {

            int x=rand()%100;

            array_Merge[j]=x;
            array_Quick[j]=x;
            array_average_value[j]=x;

        }

    }

    void Assign_average_array(int a[],int n)

    {
        delete a;
        a=new int[n];
        for (long i=0; i<n; i++)
        {
            a[i]=array_average_value[i];
        }
    }


    void B_sort(int a[],long n,int c)
    {
        for(long i=0; i<n; i++)
        {
            for(long j=0; j<n-i-1; j++)
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



    ///##################$$....Merge_Sort....##########################

    void Merge(int a[],long l,long m,long h)
    {
        long i,j,k;
        long n1=m-l+1;
        long n2=h-m;
        long L[n1];
        long R[n2];


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


    void Merge_Sort(int a[],long l,long h)
    {
        if(l<h)
        {
            long m=l+(h-l)/2;
            Merge_Sort(a,l,m);
            Merge_Sort(a,m+1,h);
            Merge(a,l,m,h);

        }
    }

    ///#####################....Quick_sort....##################

    void Quick_Sort(int a[],long l,long h)
    {
        if(l<h)
        {
            long m=Partition(a,l,h);
            Quick_Sort(a,l,m-1);
            Quick_Sort(a,m+1,h);

        }
    }

    int  Partition(int a[],long l,long h)
    {

        long pivot=a[h];
        long i=l-1;
        for (long j=l; j<=h-1; j++)
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




    ///##############################################################################


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
            for (long i=0; i<num; i++)
            {
                cout<< a[i] <<" < ";
            }
            cout<<endl;
            cout<<"Quick sorted Array: "<<endl;
            for (long i=0; i<num; i++)
            {
                cout<<a1[i]<<" < ";
            }

        }
        else
        {
            cout<<"wothout applying merge or quick sort array: "<<endl;
            for (long i=0; i<num; i++)
            {
                cout<< a[i] <<" < ";
            }
        }

    }

};



int main()
{


    int choice;
    int  n;
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
            mq.which_case=1;
            break;


        case 2:
            printf("Number of elements: ");
            scanf("%d", &n);
            mq.Best_case(n);
            mq.issorted=false;
            mq.which_case=2;

            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &n);
            mq.Worst_case(n);
            mq.issorted=false;
            mq.which_case=3;

            break;

        case 4:
        {
            {

                printf("Applying merge sort\n");
                mq.issorted=true;
                float sum=0;

                for (int i=0; i<Mutiple_senario_num; i++)
                {
                    auto start2 = high_resolution_clock::now();
                    mq.Merge_Sort(mq.array_Merge,0,n-1);

                    auto stop2 = high_resolution_clock::now();
                    auto duration2 = duration_cast<microseconds>(stop2 - start2);
                    sum+=duration2.count();
                    cout<<"\n"<<i+1<<" th running time = "<<duration2.count()<<endl;

                    if(mq.which_case==3)
                    {

                        mq.B_sort(mq.array_Merge,n,2);

                    }
                    else if(mq.which_case==2)
                    {

                        mq.B_sort(mq.array_Merge,n,1);
                    }
                    else if(mq.which_case==1)
                    {
                        mq.Assign_average_array(mq.array_Merge,n);

                    }




                }
                float duration3=(sum/Mutiple_senario_num);

                cout << "\nAverage Time for MergeSort: " << duration3 << " microseconds" << endl;


                break;
            }
        }

        case 5:
        {


            printf("Applying quicksort\n");

            mq.issorted=true;
            float sum=0;

            for (int i=0; i<Mutiple_senario_num; i++)
            {
                auto start2 = high_resolution_clock::now();
                mq.Quick_Sort(mq.array_Quick,0,n-1);

                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                sum+=duration2.count();
                cout<<i+1<<" th running time = "<<duration2.count()<<endl;
                if(mq.which_case==3)
                {

                    mq.B_sort(mq.array_Quick,n,2);
                }
                else if(mq.which_case==2)
                {
                    mq.B_sort(mq.array_Quick,n,1);
                }
                else if(mq.which_case==1)
                {
                    mq.Assign_average_array(mq.array_Quick,n);
                }




            }
            float duration3=(sum/Mutiple_senario_num);

            cout << "\n Average time for quickSort: " << duration3 << " microseconds" << endl;


            break;
        }

        case 6:
            printf("Array\n");

            mq.PrintArray(mq.array_Merge,mq.array_Quick);

            break;
        }
    }
}




