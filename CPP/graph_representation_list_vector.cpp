#include "iostream"
#include "vector"


using namespace std;

// finding vertex and returns index of vertex or -1(if not found)
int findVertex(vector<vector<int> > &graph, int vertex){
	for(int i=0 ; i<graph.size() ; i++){
		if(graph[i][0]==vertex)
			return i;
	}
	return -1;
}

// add vertex to graph and return their position vetor
vector<int> addVertex(vector<vector<int> > &graph,int start_vertex,int end_vertex){
	
	vector<int> v_position;
	int start_vertex_index = findVertex(graph,start_vertex);
	int end_vertex_index = findVertex(graph,end_vertex);

	if(start_vertex_index == -1){
		graph.push_back(vector<int>(0));
		graph.back().push_back(start_vertex);
		start_vertex_index = graph.size() - 1;
	}
	if(end_vertex_index == -1){
		graph.push_back(vector<int>(0));
		graph.back().push_back(end_vertex);
		end_vertex_index = graph.size() - 1;
	}

	v_position.push_back(start_vertex_index);
	v_position.push_back(end_vertex_index);

	return v_position;
}

void addEdge(vector< vector<int> > &graph, int start_vertex, int end_vertex){
	
	vector<int> v_position; 
	v_position = addVertex(graph,start_vertex,end_vertex);

	// adding edge to list
	graph[v_position[0]].push_back(end_vertex);
	graph[v_position[1]].push_back(start_vertex);
}

int main()
{
	int n_vertex;
	vector< vector<int> > graph;
	int start_vertex, end_vertex;
	char ch = 'y';

	while(ch == 'y'){

		cout<<"Enter Edge Start Vertices - ";
		cin>>start_vertex;
		cout<<"Enter Edge End Vertices - ";
		cin>>end_vertex;

		addEdge(graph,start_vertex,end_vertex);

		cout<<"Do you wish to add another edge - y/n : ";
		cin>>ch;
	}

	// printing ADJENCY LIST
	cout<<" *** ADJENCY LIST *** "<<endl;
	for(int i=0 ; i < graph.size() ; i++){
		for (int j = 0; j < graph[i].size() ; j++){
			cout<<" "<<graph[i][j];
			if( j < graph[i].size() - 1)
				cout<<" -> ";
		}
		cout<<endl;
	}
	return 0;
}