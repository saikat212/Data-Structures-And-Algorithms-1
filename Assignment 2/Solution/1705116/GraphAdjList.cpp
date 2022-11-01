
#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3
#include<iostream>
using namespace std;
class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); ///insert item in the queue
    int dequeue(); ///returns the item according to FIFO
    bool empty(); ///return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; ///allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		///allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; ///copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; ///copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; ///free the memory allocated before
		data = tempData ; ///make list to point to new memory
	}

	data[front] = item ; ///store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;   /// circular queue implementation
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; ///deallocate memory
    data = 0; ///set to NULL
}

///****************Queue class ends here************************

///****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		///allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;  /// doubling memory when array is full
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; ///copy all items from list to tempList
        }
        delete[] list ; ///free the memory allocated before
        list = tempList ; ///make list to point to new memory
	};

	list[length] = newitem ; ///store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) ///do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; ///nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; ///nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

///******************ArrayList class ends here*************************

///******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	int *Parent, *Color, *Distance;
	///define other variables required for bfs such as color, parent, and dist
	///you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u, bool out);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); ///will run bfs in the graph


};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ; ///set direction of the graph
	///define other variables to be initialized
   /* Parent = new int[nVertices+1];
    Color = new int [nVertices+1];
    Distance = new int [nVertices+1];*/
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0) delete[] adjList ; ///delete previous list
	adjList = new ArrayList[nVertices] ;
	Parent = new int[nVertices];
    Color = new int [nVertices];
    Distance = new int [nVertices];
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; ///vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    ///write this function
    if (isEdge(u,v)==false)
        return;
    else if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    else{
        this->nEdges--;
        adjList[u].removeItem(v);
        if(!directed && u!=v)
            adjList[v].removeItem(u);
    }
}

bool Graph::isEdge(int u, int v)
{
    ///returns true if (u,v) is an edge, otherwise should return false
    int check1 = adjList[u].searchItem(v);
    int check2 = adjList[v].searchItem(u);

    if (check1!=NULL_VALUE || check2!=NULL_VALUE)
        return true;
    else
        return false;

}

int Graph::getDegree(int u, bool out)
{
    ///returns the degree of vertex u
    if(directed){
        if(out)
            return adjList[u].getLength();
        int degree;
        for(int i=0;i<nVertices;i++){
            if(i==u)
                continue;
            if(adjList[i].searchItem(u)!=NULL_VALUE)
                degree++;
        }
        return degree;
    }
    int degree = 0;
    for (int i=0;i<adjList[u].getLength();i++){
        if(u==adjList[u].getItem(i))
            degree = degree+2;
        else
            degree++;
    }
    return degree;
}

void Graph::printAdjVertices(int u)
{
    ///prints all adjacent vertices of a vertex u
    for (int i=0;i<adjList[u].getLength();i++)
        cout<<adjList[u].getItem(i)<<" ";
    cout<<endl;


}

bool Graph::hasCommonAdjacent(int u, int v)
{
    ///returns true if vertices u and v have common adjacent vertices
    for (int i=0;i<adjList[u].getLength();i++){
        for(int j=0;j<adjList[v].getLength();j++){
            if(adjList[u].getItem(i)==adjList[v].getItem(j))
                return true;
        }
    }
    return false;

}

void Graph::bfs(int source)
{
    ///complete this function
    ///initialize BFS variables for all n vertices first
    Queue Q;

    for (int i=0;i<nVertices;i++){
        Color[i] = WHITE;/// Set all color to white
        Parent[i] = NULL;
        Distance[i] = 0;
    }
    Q.enqueue(source); ///inserting first element to Q
    Color[source] = GREY;

    while(!Q.empty()){
        int current = Q.dequeue();
        for(int a=0;a<nVertices;a++){
            if(isEdge(current,a) && Color[a]==WHITE){
                Q.enqueue(a);
                Color[a] = GREY;
                Distance[a] = Distance[current]+1;
                Parent[a] = current;
            }
        }
        Color[current]= BLACK;
    }

}

int Graph::getDist(int u, int v)
{
    ///returns the shortest path distance from u to v
    ///must call bfs using u as the source vertex, then use distance array to find the distance
    bfs(u);
    return Distance[v];
    ///return INFINITY ;
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    ///write your destructor here
    if(adjList)
        delete[] adjList;
    adjList = 0;

    if(Parent)
        delete[] Parent;
    Parent = 0;

    if(Color)
        delete[] Color;
    Color = 0;
    if(Distance)
        delete[] Distance;
    Distance = 0;
}


///**********************Graph class ends here******************************


///******main function to test your code*************************
int main(void)
{
    int n;
    int choice;
    bool dir;
    printf("Enter your choice:\n");
    printf("1. directed graph   2. undirected graph\n");
    scanf("%d",&choice);
    if(choice == 1)dir = true;
    else if(choice == 2)dir = false;

    Graph g(dir);
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        cout<<"1. Add edge"<<endl;
        cout<<"2. Remove edge"<<endl;
        cout<<"3. Check if Edge"<<endl;
        cout<<"4. Get Degree"<<endl;
        cout<<"5. Check Adjacent Vertices"<<endl;
        cout<<"6. Print Adjacent Vertices"<<endl;
        cout<<"7. Shortest distance"<<endl;
        cout<<"8. Print Graph"<<endl;
        cout<<"9. Exit"<<endl;

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            cout<<"Add Edge"<<endl;
            cout<<"Enter the edges"<<endl;
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            cout<<"Remove Edge"<<endl;
            cout<<"Enter the edges"<<endl;
            int u, v;
            cin>>u>>v;
            g.removeEdge(u,v);


        }
        else if(ch==3)
        {
            cout<<"Check if Edge"<<endl;
            cout<<"Enter the edges"<<endl;
            int u, v;
            cin>>u>>v;
            if(g.isEdge(u,v))
                cout<<"Edge"<<endl;
            else
                cout<<"No edge"<<endl;

        }
        else if(ch==4)
        {
            cout<<"Get Degree"<<endl;
            int u;
            cin>>u;
            cout<<g.getDegree(u, true)<<endl;
        }
        else if(ch==5)
        {
            cout<<"Check Adjacent"<<endl;
            int u, v;
            cin>>u>>v;
            if(g.hasCommonAdjacent(u,v))
                cout<<"Has adjacent vertices"<<endl;
            else
                cout<<"Has no adjacent vertices"<<endl;
        }
        else if (ch==6)
        {
            cout<<"Print adjacent vertices"<<endl;
            int u;
            cin>>u;
            cout<<endl;
            g.printAdjVertices(u);
            cout<<endl;
        }
        else if (ch==7)
        {
            cout<<"Shortest distance"<<endl;
            int u,v;
            cin>>u>>v;
            cout<<g.getDist(u,v)<<endl;
        }
        else if (ch==8)
        {
            cout<<"Print Graph"<<endl;
            g.printGraph();
        }
        else if (ch==9)
        {
            break;
        }
    }

}
