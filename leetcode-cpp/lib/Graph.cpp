#include "Graph.h"

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}
 
Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int u, int v) {
    return (A[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 1;
}

void Graph::BFS(int s) {
    Queue2 Q;
 
    /** Keeps track of explored vertices */
    bool *explored = new bool[n+1];
 
    /** Initailized all vertices as unexplored */
    for (int i = 1; i <= n; ++i)
    explored[i] = false;
 
    /** Push initial vertex to the queue */
    Q.enqueue(s);
    explored[s] = true; /** mark it as explored */
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
 
    /** Unless the queue is empty */
    while (!Q.isEmpty()) {
        /** Pop the vertex from the queue */
        int v = Q.dequeue();
 
        /** display the explored vertices */
        cout << v << " ";
 
        /** From the explored vertex v try to explore all the
        connected vertices */
        for (int w = 1; w <= n; ++w)
 
            /** Explores the vertex w if it is connected to v
            and and if it is unexplored */
            if (isConnected(v, w) && !explored[w]) {
                /** adds the vertex w to the queue */
                Q.enqueue(w);
                /** marks the vertex w as visited */
                explored[w] = true;
            }
    }
    cout << endl;
    delete [] explored;
}

int Graph::MainEntry() {
    Graph g(12);
 
    /** Adds edges to the graph */
    g.addEdge(1, 2); g.addEdge(1, 3);
    g.addEdge(2, 4); g.addEdge(3, 4);
    g.addEdge(3, 6); g.addEdge(4 ,7);
    g.addEdge(5, 6); g.addEdge(5, 7);
    clock_t t1;
    t1 = clock();
 
    /** Explores all vertices findable from vertex 1 */
    g.BFS(1);
    float diff = (double)(clock() - t1)/CLOCKS_PER_SEC ;
    cout <<endl<< "The time taken for Breadth first search: "<< diff << endl;
    return 0;
}