#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#include<iostream>
#define WHITE 1
#define GREY 2
#define BLACK 3

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
	rear = (rear + 1) % queueMaxSize ;  /// circular queue implementation
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; ///deallocate memory
    data = 0; ///set to NULL
}

///****************Queue class ends here************************


///******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; ///adjacency matrix to store the graph
	///define other variables required for bfs such as color, parent, and dist
	///you must use pointers and dynamic allocation
	int *parent, *color, *Distance;

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
	matrix = 0 ;
	directed = dir ; ///set direction of the graph
	///define other variables to be initialized

}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	///allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; ///initialize the matrix cells to 0
    }
    parent = new int[nVertices];
	color = new int[nVertices];
    Distance = new int[nVertices];

}

void Graph::addEdge(int u, int v)
{
    ///write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 1;
    if(!directed) matrix[v][u] = 1;

}

void Graph::removeEdge(int u, int v)
{
    ///write this function
    if(isEdge(u,v)==false)
        return;
    else{
        this->nEdges--;
        matrix[u][v] = 0;
        if(!directed){
            matrix[v][u] = 0;
        }
    }
}

bool Graph::isEdge(int u, int v)
{
    ///returns true if (u,v) is an edge, otherwise should return false
    if(matrix[u][v]==1)
        return true;
    else if (matrix[v][u]==1)
        return true;
    else
        return false;
}

int Graph::getDegree(int u, bool out)
{
    ///returns the degree of vertex u
    int count = 0;
    if (out==true){
        for(int i=0;i<nVertices;i++){
            if(matrix[u][i]==1)
                count++;
        }
    }
    else{
        for(int i=0;i<nVertices;i++){
            if(matrix[i][u]==1)
                count++;
        }
    }
    return count;

}

void Graph::printAdjVertices(int u)
{
    ///prints all adjacent vertices of a vertex u
    for(int i=0;i<nVertices;i++){
        if(matrix[u][i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    ///returns true if vertices u and v have common adjacent vertices
    for(int i=0;i<nVertices;i++){
        for(int j=0;j<nVertices;j++){
            if(matrix[u][i]==matrix[v][i])
                return true;
        }
    }
    return false;

}

void Graph::bfs(int source)
{
    ///write this function
    Queue Q;

    for(int i=0;i<nVertices;i++){
        color[i] = WHITE;
        parent[i] = NULL;
        Distance[i] = 0;
    }
    Q.enqueue(source);
    color[source] = GREY;
    while(!Q.empty()){
        int current = Q.dequeue();
        for(int a =0;a<nVertices;a++){
                if(isEdge(current,a) && color[a]==WHITE){
                    Q.enqueue(a);
                    color[a] = Distance[current]+1;
                    parent[a] =current;
                }
        }
        color[current] = BLACK;
    }


}

int Graph::getDist(int u, int v)
{
    ///returns the shortest path distance from u to v
    ///must call bfs using u as the source vertex, then use distance array to find the distance
    bfs(u);
    return Distance[v];
    //return INFINITY ;
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    ///write your destructor here
    for(int i=0;i<nVertices;i++){
        delete[]matrix[i];
    }
    delete[]matrix;
      if(parent) delete []parent;
    parent=0;
    if(color) delete []color;
    color=0;
    if(Distance) delete []Distance;
    Distance=0;

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

