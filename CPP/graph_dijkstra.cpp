#include "iostream"
#include "vector"
#define INF 10000

using namespace std;

void dijkstra(vector< vector<int> > &graph, int n_vertex){

	vector<int> visited(n_vertex,0);
	vector<int> weight(n_vertex,INF);
	vector<int> parent(n_vertex,-1);
	int new_wgt,min_wgt,loc=0,curr_v = 0;

// by starting from 0 node	
	weight[0] = 0;

	while(curr_v != -1){
		visited[curr_v] = 1;
		// updating weight for curr_v not-visited neighbours
		for(int i = 0; i<graph[curr_v].size(); i++){
			if(visited[i]==0 && graph[curr_v][i] != 0){
				// As weight[i] = min(weight[i],weight[0]+graph[curr_v][i])
				new_wgt = weight[curr_v] + graph[curr_v][i];
				if (weight[i] > new_wgt){
	
					weight[i] = new_wgt;
					parent[i] = curr_v;	
				}
			}
		}

		// finding location for next min vertex location
		min_wgt = INF;
		loc = -1;
		for(int i=0; i<n_vertex; i++){
			if(visited[i] != 1 && weight[i]<min_wgt){
				min_wgt = weight[i];
				loc = i;
			}
		}
		// updating location
		curr_v = loc;
	}
	cout<<"***WEIGHTS***\n";
	for(int i = 0; i<n_vertex; i++)
		cout<<i<<" W =>"<<weight[i]<<" P => "<<parent[i]<<"\n";
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

	cout<<"***Adjacency Matrix***\n";
	for (int i = 0; i < n_vertex; ++i)
	{
		for (int j = 0; j < n_vertex; ++j)
		{

			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}

	dijkstra(graph,n_vertex);

	return 0;
}