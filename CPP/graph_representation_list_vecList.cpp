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

void addEdge(vector< list<int> > &graph, int startVertex, int endVertex){

	// adding vertex to graph
	int startVertexIndx = addVertex(graph, startVertex);
	int endVertexIndx = addVertex(graph, endVertex);

	graph[startVertexIndx].push_back(endVertex);
	graph[endVertexIndx].push_back(startVertex);
}

int main()
{
	vector< list<int> > graph;
	int n_edge;
	int startVertex, endVertex;

	cout<<"Enter no. of edges - ";
	cin>>n_edge;

	cout<<"Enter edge list\n";
	for (int i = 0; i < n_edge; ++i)
	{
		cin>>startVertex>>endVertex;
		addEdge(graph,startVertex,endVertex);
	}

	cout<<"***ADJENCY LIST***\n";
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