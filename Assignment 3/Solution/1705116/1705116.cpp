
#include<iostream>
using namespace std;

#define Heapcapacity 50

class PriorityQueue
{
    int*a;
    int capacity;
    int heap_size;
public:
    PriorityQueue(int cap);

    void MaxHeapify(int i);
    void Insert(int k);
    int FindMax()
    {
        return a[0];
    }
    int ExtractMax();
    void IncreaseKey(int i,int newKey);
    void DecreaseKey(int i,int newKey);

    void Print();

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void Swap(int *x,int*y)
    {
        int temp=*x;
        *x=*y;
        *y=temp;
    }




};

void PriorityQueue::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && a[l] > a[i])
        largest =l;
    if (r < heap_size && a[r] >a[largest])
        largest= r;
    if (largest!= i)
    {
        Swap(&a[i], &a[largest]);
        MaxHeapify(largest);
    }
}



void PriorityQueue:: Insert(int k)
{
    heap_size++;
    int i=heap_size-1;
    a[i]=k;
    while(i!=0 && a[parent(i)]<a[i])
    {
        Swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}


int PriorityQueue::ExtractMax()
{
    if(heap_size<=0)
    {
        return -1;
    }
    if(heap_size==1)
    {
        heap_size--;
        return a[0];
    }
    int maxvalue=a[0];
    a[0]=a[heap_size-1];
    heap_size--;
    MaxHeapify(0);
    return maxvalue;



}


void PriorityQueue::IncreaseKey(int x,int newKey)
{
    if(heap_size>0)
    {
        int i=x-1;
        if(newKey<a[i])
        {
            cout<<"Eror:New Key is smaller than current key"<<endl;

        }
        else
        {
            a[i]=newKey;


            while(i!=0 && a[parent(i)]<a[i])
            {
                Swap(&a[i],&a[parent(i)]);
                i=parent(i);
            }
        }
    }
    else
    {
        cout<<"Eror: heap is empty."<<endl;
    }

}
void PriorityQueue::DecreaseKey(int x,int newKey)
{
    if(heap_size>0)
    {
        int i=x-1;
        if(a[i]<newKey)
        {
            cout<<"Eror:"<<endl;
        }
        else
        {
            a[i]=newKey;
            MaxHeapify(i);
        }
    }
    else
    {
        cout<<"Error: Empty heap."<<endl;
    }
}

void PriorityQueue::Print()
{
    for(int i=0; i<heap_size; i++)
    {
        cout<<a[i]<<"->";
    }
    cout<<endl;

}


PriorityQueue::PriorityQueue(int cap)
{

    a=new int[cap];
    capacity=cap;
    heap_size=0;
}



int main()
{
    PriorityQueue pq(Heapcapacity);
    while(1)
    {

        cout<<"Select option"<<endl<<endl;
        cout<<"Press: 1 --->Insert(int x)"<<endl;
        cout<<"Press: 2 --->FindMax()"<<endl;
        cout<<"Press: 3 --->ExtractMax()"<<endl;
        cout<<"Press: 4 --->IncreaseKey(int i,int value)"<<endl;
        cout<<"Press: 5 --->DecreaseKey(int i,int value)"<<endl;
        cout<<"Press: 6 --->Print()"<<endl;
        cout<<"Press: 7 --->Quit()"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter a new element to make max heap: "<<endl;
            int value;
            cin>>value;
            pq.Insert(value);
            cout<<"Value insert sucessfully completed"<<endl;

        }
        else if(choice==2)
        {
            cout<<"Maximum value of this heap is="<<pq.FindMax()<<endl;

        }
        else if(choice==3)
        {
            int x=pq.ExtractMax();
            if(x==-1)
            {
                cout<<"Empty heap"<<endl;
            }
            else
            {
                cout<<"Extracting maximum value= "<<x<<endl;
            }


        }
        else if(choice==4)
        {
            cout<<"Increasing Index"<<endl;
            int i;
            cin>>i;
            cout<<"Increasing value:"<<endl;
            int newKey;
            cin>>newKey;
            pq.IncreaseKey(i,newKey);

        }


        else if(choice==5)
        {
            cout<<"Decreasing Index"<<endl;
            int i;
            cin>>i;
            cout<<"Decreasing value:"<<endl;
            int newKey;
            cin>>newKey;
            pq.DecreaseKey(i,newKey);


        }
        else if(choice==6)
        {
            cout<<"Final Heap after operation"<<endl;
            pq.Print();

        }
        else if(choice==7)
        {
            cout<<"Program terminated"<<endl;
            return 0;
        }

        cout<<"\n##############################\n"<<endl;

    }

    return 0;


}
