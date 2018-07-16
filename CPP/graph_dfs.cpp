#include "iostream"
#include "vector"
#include "stack"
#include "list"

using namespace std;

int findVertex(vector< list<int> > graph, int vertex){

	int currIndx = 0;
	for (vector<list <int> >::iterator i = graph.begin(); i != graph.end(); ++i, currIndx++)
	{
		if((*i).front() == vertex){
			return currIndx;
		}
	}
	return -1;
}

int addVertex(vector< list<int> > &graph, int vertex){

	int vertexIndex = findVertex(graph, vertex);

	if (vertexIndex == -1)
	{
		graph.push_back(list<int>());
		graph.back().push_back(vertex);
		vertexIndex = graph.size() - 1; 
	}

	return vertexIndex;
}

void addEdge(vector< list<int> > &graph, int startVertex, int endVertex, int isDirected){

	// adding vertex to graph
	int startVertexIndx = addVertex(graph, startVertex);
	int endVertexIndx = addVertex(graph, endVertex);

	// adding edge to list
	graph[startVertexIndx].push_back(endVertex);
	if (isDirected == 0)
	{
		graph[endVertexIndx].push_back(startVertex);
	}
}

void showDfsTraversal(vector< list<int> > &graph){

	int startVertex, currVertex, v_pos,curr_v_pos;
	int *visitedVertx = new int[graph.size()];
	stack<int> waitingVertex;

	cout<<"Enter start node : ";
	cin>>startVertex;
	
	curr_v_pos = findVertex(graph,startVertex);

	if (curr_v_pos == -1){
		
		cout<<"Vertex does not exists";	
	}	
	else{
		// pushing starting vertex to stack
		waitingVertex.push(startVertex);
		visitedVertx[curr_v_pos] = 1;

		cout<<"***DFS TRAVERSAL***\n";
		while(!waitingVertex.empty()){

			currVertex = waitingVertex.top();
			waitingVertex.pop();
			cout<<currVertex<<" ";
			curr_v_pos = findVertex(graph, currVertex);

			// pushing current vertex's unvisited vertex to stack
			for (std::list<int>::iterator i = graph[curr_v_pos].begin(); i != graph[curr_v_pos].end(); ++i)
			{
				v_pos = findVertex(graph,(*i));
				// checking vertex visited or not
				if (visitedVertx[v_pos] != 1){
					// pushing to stack
					waitingVertex.push(*i);
					// marking vertex as visited
					visitedVertx[v_pos] = 1;
				}
			}
		}
	}
}

int main()
{
	vector< list<int> > graph;
	int n_edge, isDirected;
	int startVertex, endVertex;

	cout<<"Is your graph directed? yes = 1, no = 0 - ";
	cin>>isDirected;

	cout<<"Enter no. of edges - ";
	cin>>n_edge;

	cout<<"Enter edge list\n";
	for (int i = 0; i < n_edge; ++i)
	{
		cin>>startVertex>>endVertex;
		addEdge(graph,startVertex,endVertex,isDirected);
	}

	showDfsTraversal(graph);

	cout<<"\n***ADJENCY LIST***\n";
	for (std::vector< list<int> >::iterator i = graph.begin(); i != graph.end(); ++i)
	{
		for (list<int>::iterator i_list = (*i).begin(); i_list != (*i).end(); ++i_list)
		{
			cout<<*i_list<<" ";
		}
		cout<<"\n";
	}

	return 0;
}