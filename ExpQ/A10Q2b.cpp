#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[],int disc[], int low[], 
int& time, int parent,bool isAP[]){
	int children = 0;

	visited[u] = true;
	disc[u] = low[u] = ++time;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			APUtil(adj, v, visited, disc, low, time, u, isAP);
			low[u] = min(low[u], low[v]);
			if (parent != -1 && low[v] >= disc[u])
				isAP[u] = true;
		}
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}
	if (parent == -1 && children > 1)
		isAP[u] = true;
}

void AP(vector<int> adj[], int V){
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool isAP[V] = { false };
	int time = 0, par = -1;

	for (int u = 0; u < V; u++){
		if (!visited[u]){
			APUtil(adj, u, visited, disc, low,time, par, isAP);
        }
    }
    
    bool flag=false;
	for (int u = 0; u < V; u++){
		if (isAP[u] == true){
            flag=true;
			cout << u << " ";
        }
    }cout<<endl;

    if(flag){
        cout<<"Given graph is not biconnected"<<endl;
    }else{
        cout<<"none"<<endl;
        cout<<"Given graph is biconnected"<<endl;
    }
}


void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	cout << "Articulation points in first graph : ";
	int V = 5;
	vector<int> adj1[V];
	addEdge(adj1, 1, 0);
	addEdge(adj1, 0, 2);
	addEdge(adj1, 2, 1);
	addEdge(adj1, 0, 3);
	addEdge(adj1, 3, 4);
	AP(adj1, V);

	cout << "\nArticulation points in second graph : ";
	V = 4;
	vector<int> adj2[V];
	addEdge(adj2, 0, 1);
	addEdge(adj2, 1, 2);
	addEdge(adj2, 2, 0);
	AP(adj2, V);

	return 0;
}
