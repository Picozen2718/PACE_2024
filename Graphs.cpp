#include <iostream>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

//Adjacency vector list is choosen over edge lists as it is more convenient for this problem.
void definegraph(vector<int> graph[], int n, int k){
    int x, y;
    for (int i = 0; i < k; ++i){
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

//Greedy implementation

//Single node reduction algorithm

int greedy(int n, vector <int> graph[], vector <int> degree){
    
}

vector <int> assigndegree(int n, vector<int> graph[], vector<int> degree){
    int len;
    for (int i = 0; i < n; ++i){
        len = 0;
        for (auto u : graph[i]){
            len = len + 1;
        }
        degree.push_back(len);
    }
    return (degree);
}

int main(){
    int n, k, cardi;
    scanf("%d %d", &n, &k); //Number of nodes and edges
    vector<int> graph[n]; //Graph of n nodes
    vector<int> degree; //List of degrees of nodes
    definegraph(graph, n, k);
    degree = assigndegree(n, graph, degree);
    cardi = greedy(graph, degree);
    //for (auto i = degree.begin(); i != degree.end(); ++i) cout << *i << " ";
}