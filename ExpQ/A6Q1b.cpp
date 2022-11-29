#include<bits/stdc++.h>
using namespace std;

struct Job{
	char id;
	int deadLine, profit;
};

struct DisjointSet{
	int *parent;

	DisjointSet(int n){
		parent = new int[n+1];

		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int s){
		if (s == parent[s])
			return s;
		return parent[s] = find(parent[s]);
	}

	void merge(int u, int v){
		parent[v] = u;
	}
};

bool cmp(Job a, Job b){
	return (a.profit > b.profit);
}

int main()
{
	Job arr[] = { { 'a', 2, 100 }, { 'b', 1, 19 },{ 'c', 2, 27 }, { 'd', 1, 25 },{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	
    sort(arr, arr + n, cmp);

    int maxDeadline = INT_MIN;
	for (int i = 0; i < n; i++){
		maxDeadline = max(maxDeadline, arr[i].deadLine);
    }

	DisjointSet ds(maxDeadline);

    cout<<"The jobs that can be performed within deadline to maximize the profit :"<<endl;
    for (int i = 0; i < n; i++){
		int availableSlot = ds.find(arr[i].deadLine);

		if (availableSlot > 0){
			ds.merge(ds.find(availableSlot - 1),availableSlot);
			cout << arr[i].id << " ";
		}
	}
	return 0;
}
