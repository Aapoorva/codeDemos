#include "iostream"
#include "vector"


using namespace std;

// finding vertex and returns index of vertex or -1(if not found)
int findVertex(vector<int> &graph_vertex, int vertex){
	for(int i=0 ; i<graph_vertex.size() ; i++){
		if(graph_vertex[i]==vertex)
			return i;
	}
	return -1;
}

// add vertex to graph and return their position vetor
vector<int> addVertex(vector<int> &graph_vertex,int start_vertex,int end_vertex){
	
	int start_vertex_index = findVertex(graph_vertex,start_vertex);
	int end_vertex_index = findVertex(graph_vertex,end_vertex);
	
	vector<int> v_position;

	if(start_vertex_index == -1){
		graph_vertex.push_back(start_vertex);
		start_vertex_index = graph_vertex.size() - 1;
	}
	if(end_vertex_index == -1){
		graph_vertex.push_back(end_vertex);
		end_vertex_index = graph_vertex.size() - 1;
	}

	v_position.push_back(start_vertex_index);
	v_position.push_back(end_vertex_index);

	return v_position;
}

void addEdgeToMatrix(vector<int> &graph_vertex,vector< vector<int> > &graph_edges,int start_vertex,int end_vertex){
	
	vector<int> v_position; 
	v_position = addVertex(graph_vertex,start_vertex,end_vertex);

	// adding edge to matrix
	graph_edges[v_position[0]][v_position[1]] = 1;
	graph_edges[v_position[1]][v_position[0]] = 1;
}

int main()
{
	int n_vertex;
	vector<int> graph_vertex;
	int start_vertex, end_vertex; 
	char ch = 'y';

	cout<<"Enter no. of Vertices = ";
	cin>>n_vertex;

	vector< vector<int> > graph_edges(n_vertex, vector<int>(n_vertex,0));

	while(ch == 'y'){
		cout<<"Enter Edge End Vertices - ";
		cin>>start_vertex>>end_vertex;
		addEdgeToMatrix(graph_vertex,graph_edges,start_vertex,end_vertex);

		cout<<"Do you wish to add another edge - y/n : ";
		cin>>ch;
	}

	// printing vertex
	cout<<" *** GRAPH VERTICES *** "<<endl;
	for (int i = 0; i < n_vertex; ++i){
		cout<<" "<< graph_vertex[i] << " ";
	}
	cout<<endl;
	// printing ADJENCY MATRIX
	cout<<" *** ADJENCY MATRIX *** "<<endl;
	for(int i=0 ; i < n_vertex ; i++){
		for (int j = 0; j < n_vertex ; j++){
			cout<<" "<<graph_edges[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}