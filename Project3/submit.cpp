#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

bool addOvf(int a, int b)
{
   
   if( a > INT_MAX - b)
     return false;
   else
   {
      return true;
   }
}



class Graphs_P3
{
    private:
      // Graph data structure here 
        const static int vertexAmount = 50;
    
    public:
      class Vertex {
        public:
            int name;
            //the value stored in the vector is the weight of the edge, the index of the vector is the vertex connecting it    
            vector<int> vertexList;

        
            Vertex(int from): name(from), vertexList(vector<int>(vertexAmount)){ 
                for(int i = 0; i < vertexAmount; i++)
                {
                    this->vertexList[i] = -1;
                }
            };
            bool operator < (const Vertex& str) const
            {           
                return (name < str.name);         
            } 
};

      vector<Vertex*> adjList;
      void printPath(vector<int> parent, int j, bool firstRun);
      int printSolution(vector<int> distance, int size, vector<int> parent, int source);
      void insertVertex(int vertex); //inserts new vertex in graph
      void insertEdge(int from, int to, int weight);  //inserts new edge in graph
      bool isEdge(int from, int to);  //returns true if there is an edge between the vertices from and to
      int getWeight(int from, int to);  //returns the weight of the edge between the vertices from and to
      vector<int> getAdjacent(int vertex);  //return an array of integers representing vertices adjacent to vertex
      void printDijkstra(int source);  //prints result of running Dijkstra algorithm with source vertex
      void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
      Graphs_P3();
};

//constructor for graphs
Graphs_P3::Graphs_P3() {
    this->adjList = vector<Vertex*>(vertexAmount);
};

void Graphs_P3::insertEdge(int from, int to, int weight)
{   
    
    if(from > vertexAmount || from < 0 || to > vertexAmount || to < 0 )
    {
        cout << "A vertex is not in the graph" << endl;
        return;
    }
    else if(weight <= 0)
    {
        cout << "Entered an invalid weight" << endl;
        return;
    }
    Vertex* current = this->adjList[from];
    Vertex* destination = this->adjList[to];

    if(current == NULL || destination == NULL)
    {
        cout << "Current Vertex is null, this shouldn't go here" << endl;
        return;
    }
    else if(this->adjList[from]->vertexList[to] != -INT_MAX)
    {    
        
        this->adjList[from]->vertexList[to] = weight;
    }
    
}
   
void Graphs_P3::insertVertex(int vertex)
{
    
   Vertex* current = this->adjList[vertex];
   if(current == NULL)
   {
       Vertex* newVertex = new Vertex(vertex);
       this->adjList[vertex] = newVertex;
   }
    else
    {
        cout << "There is already this vertex in the graph" << endl;
        return;
    }
    
}

void Graphs_P3::printGraph()
{
    //Print out all lists for each vertex
    for (int i = 0; i < vertexAmount; i++)
    {
        if(this->adjList[i] != NULL)
        {
           
            cout<<this->adjList[i]->name;
            vector<int> adjVerticies = this->getAdjacent(i);
            for(int j = 0; j < adjVerticies.size(); j++)
            {
                   cout << " " << adjVerticies[j];       
            }
            cout << endl;
        }
    }
}

//returns true if there is an edge between the vertices from and to
bool Graphs_P3::isEdge(int from, int to) {
    /**the way its saved is that the adj list has a reference to a vertex who has a vector of ints whose index represent
    the vertex connected and the value at that index is the weight of the edge. THUS if the weight is 0 (default) then 
    there is no edge. */
    if(this->adjList[from]->vertexList[to] > -1 && from >= 0 && to >= 0 && from < vertexAmount && to < vertexAmount && this->adjList[from] != NULL && this->adjList[to] != NULL)
    {
         return true;   
    }
    return false;
}  

 //returns the weight of the edge between the vertices from and to
int Graphs_P3::getWeight(int from, int to) {
    /**the way its saved is that the adj list has a reference to a vertex who has a vector of ints whose index represent                             
    the vertex connected and the value at that index is the weight of the edge */
    if(this->adjList[from]->vertexList[to] > -1 && from >= 0 && to >= 0 && from < vertexAmount && to < vertexAmount && this->adjList[from] != NULL && this->adjList[to] != NULL)
    {
        return this->adjList[from]->vertexList[to];
    }
    return -1;
   
    
} 

//return an array of integers representing vertices adjacent to vertex
vector<int> Graphs_P3::getAdjacent(int vertex) {
    vector<int> adjVerticies;
    
    //Print out all lists for each vertex
    for (int i = 0; i < vertexAmount; i++)
    {
        if(this->adjList[vertex]->vertexList[i] != -1)
        {
           adjVerticies.push_back(i);
        }
    }

    sort(adjVerticies.begin(), adjVerticies.end());
    
    return adjVerticies;
}  

//prints result of running Dijkstra algorithm with source vertex
void Graphs_P3::printDijkstra(int source) {

    //have a valid vertex
    if(source < 0 || source > vertexAmount)
    {
        return;
    }

    //Create the distance array for the source and all other verticies
    vector<int> distance(vertexAmount);
    vector<int> parent(vertexAmount);

    distance[source] = 0; //It's literally on top of itself



    //create a priority queue of all the distances from the source vertex to the other vertex
    priority_queue <int, vector<int>, greater<int>> Q;
    
    //Establish the infitite initial distances from the source & add the verticies to the priority queue for min. distance
    for(int i = 0; i < this->adjList[source]->vertexList.size(); i++)
    {
        if(i != source )
        {    
            distance[i] = INT_MAX;
        }
        parent[0] = -1;

        //i is the vertex (its not actually a Vertex, but the index that represents a vertex on the vertexList)
        Q.push(i);
        
    }
    
       
    //While there exists an edge, get smallest one
    while(!Q.empty())
    {     
        int v = Q.top(); //The closest vertex to the source is v
        
        Q.pop();
    
        //For each neightbor u of v (the closest vertex)
        if(v >= 0 && v < vertexAmount && this->adjList[v] != NULL)
           {

                for(int u = 0; u < this->adjList[v]->vertexList.size(); u++)
                {

                    //idea: new distance = distance -> v + distance (weight) from v->u
                    //If the vertex is in the graph and is not itself (we don't list itself on the adjacency list)
                    if(this->adjList[v]->vertexList[u] != -1 && u != source)
                    {

                        
                        //Used abs to avoid overflow into negatives (also we shouldnt have negatives anyway
                        int alt = INT_MAX;
                        
                        //Check for overflow, if none, then add the correct new distance into alt
                        if(addOvf(distance[v], this->getWeight(v,u)))
                        {
                               alt = distance[v] + this->getWeight(v,u);
                        }                      
                        
                        //if the new distance < distance -> u
                        if(alt < distance[u])
                        {
                            distance[u] = alt;
                            parent[u] = v;
                            
                        }
                        

                    }
                    
                }
                
           }
        
    }
    
    //Correct formatting
    this->printSolution(distance, vertexAmount, parent, source);
    
    
}
void Graphs_P3::printPath(vector<int> parent, int j, bool firstRun)
{
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    
    printPath(parent, parent[j], false);
    cout << j;
    if(!firstRun)
       cout << "-"; 
   
}

int Graphs_P3::printSolution(vector<int> distance, int size, vector<int> parent, int source)
{
    
    cout << "V D P";
    for (int i = 1; i < size; i++)
    {
        if(distance[i] != INT_MAX && distance[i] > 0 && i != source)
        {
            cout << "\n" << i << " "<< distance[i] << " ";
            printPath(parent, i, true);
        }
        
        
    }
}

int main()
{
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
    int noOfLines, operation, vertex, to, fro, weight,source,j;
    vector<int> arr;
    int arrSize;
    Graphs_P3 g;
    cin>>noOfLines;
    for(int i=0;i<noOfLines;i++)
    {
        cin>>operation;
        switch(operation)
        {
            case 1: 
                cin>>vertex;
                g.insertVertex(vertex);
                break;
            case 2: 
                cin>>fro;
                cin>>to;
                cin>>weight;
                g.insertEdge(fro,to,weight);
                break;
            case 3: 
                cin>>fro;
                cin>>to;
                cout<<g.isEdge(fro,to)<<"\n";
                break;
            case 4: 
                cin>>fro;
                cin>>to;
                cout<<g.getWeight(fro,to)<<"\n";
                break;
            case 5: 
                cin>>vertex;
                arr=g.getAdjacent(vertex);
                arrSize = arr.size();
                j=0;
                while(j<arrSize)
                {
                    cout<<arr[j]<<" ";
                    j++;
                }
                cout<<"\n";
                break;
            case 6: 
                cin>>source;
                g.printDijkstra(source);
                cout<<"\n";
                break;
            case 7: 
                g.printGraph();
                cout<<"\n";
                break;
        }
    }
}