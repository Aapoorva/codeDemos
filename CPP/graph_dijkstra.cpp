#include "iostream"
#include "vector"

using namespace std;

void dijkstra(vector<list<int> > &graph){


}

int main()
{
	int n_vertex, n_edge,edge_wgt;
	int v_start, v_end;

	cout<<"No. of vertex - ";
	cin>>n_vertex;
	cout<<"No. of edge - ";
	cin>>n_edge;

	vector< vector<int> > graph(n_vertex,vector<int>(n_vertex,0));

	cout<<"Enter edge and corresponding weight\n";
	for (int i = 0; i < n_edge; ++i)
	{
		cin>>v_start>>v_end>>edge_wgt;

		// storing data in adjacency matrix
		// adding edge
		graph[v_start][v_end] = edge_wgt;
		// as not a directed graph adding edge to v_end list too
		graph[v_end][v_start] = edge_wgt;
	}

	for (int i = 0; i < n_vertex; ++i)
	{
		for (int j = 0; j < n_edge; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}


	// dijkstra(graph);

	return 0;
}