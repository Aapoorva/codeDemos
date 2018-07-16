#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
#include "iterator"

using namespace std;

int findVertex(vector< vector<int> > &graph, int vertex){
	for (int i = 0; i < graph.size(); ++i){
		if (graph[i][0] == vertex){
			return i;
		}
	}
	return -1;
}

vector<int> addVertex(vector< vector<int> > &graph, int start_vertex, int end_vertex){

	vector<int> v_position;
	int start_vertex_index = findVertex(graph,start_vertex);
	int end_vertex_index = findVertex(graph,end_vertex);
	
	// checking vertex exists or not
	if(start_vertex_index == -1){
		// addding a new row
		graph.push_back(vector<int>(0));
		// adding vertex
		graph.back().push_back(start_vertex);
		// storing vertex index
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
void addEdge(vector< vector<int> > &graph, int start_vertex, int end_vertex, int isDirected){

	vector<int> v_position = addVertex(graph, start_vertex, end_vertex);

	// adding edge
	graph[v_position[0]].push_back(end_vertex);
	if (isDirected == 0){
		graph[v_position[1]].push_back(start_vertex);
	}
}

void createGraph(vector< vector<int> > &graph, int n_egdes,int isDirected){

	int start_vertex, end_vertex;

	for (int i = 0; i < n_egdes; ++i){

		cout<<"Enter edge end vertex - ";
		cin>>start_vertex>>end_vertex;

		addEdge(graph, start_vertex, end_vertex, isDirected);
	}
}

// bfs traversal
void showBfsTraversal(vector< vector<int> > &graph){
	vector<int> visited_vertex(graph.size(),0);
	queue<int> vertex_queue;
	int starting_vertex;
	int curr_vertex;
	int vertex;

	cout<<"Enter starting vertex - ";
	cin>>starting_vertex;

	int starting_vertex_index = findVertex(graph,starting_vertex);

	// checking vertex exists or not
	if (starting_vertex_index == -1){
		cout<<"Vertex not found";
	}
	else{
		cout<<" *** BFS TRAVERSAL *** "<<endl;
		vertex_queue.push(starting_vertex);
		visited_vertex[starting_vertex_index] = 1;
		while(vertex_queue.size() != 0){
			curr_vertex = vertex_queue.front();
			vertex_queue.pop();
			cout<<curr_vertex<<" ";
			// adding curr vertex neighbours to queue
			int curr_vertex_index = findVertex(graph,curr_vertex);
			for (int i = 1; i < graph[curr_vertex_index].size(); ++i){
				vertex = graph[curr_vertex_index][i];
				int v_pos = findVertex(graph,vertex);
				if (visited_vertex[v_pos] == 0){
					vertex_queue.push(vertex);
					visited_vertex[v_pos] = 1;
				}
				

			}
		}
		cout<<endl;
	}
}

int main()
{
	int n_vertex, n_egdes, isDirected;
	cout<<"Enter no. of vertex - ";
	cin>>n_vertex;

	cout<<"Enter no. of edges - ";
	cin>>n_egdes;

	cout<<"Is your graph directed ? yes = 1 / no = 0 - ";
	cin>>isDirected;
	
	vector< vector<int> > graph;

	createGraph(graph,n_egdes,isDirected);
	cout<<"graph created successfully"<<endl;
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

	showBfsTraversal(graph);

	return 0;
}