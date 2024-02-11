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

//Single node reduction algorithm
vector <int> index1(int n, vector <int> degree){
    vector <int> indexlist;
    for (int i = 0; i < n; ++i){
        if (degree[i] == 1){
            indexlist.push_back(i);
        }
    }
    return(indexlist);
}

void singlenodered(int n, vector <int> graph [], vector <int> degree, vector <int> vertexcover){
    vector <int> indexlist = index1(n, degree);
    for (auto u : indexlist){
        int x = graph[u][0];
        vertexcover.push_back(x);
        graph[u].clear();
        //remove(graph[].begin(),graph.end(), u);
        degree[u] = 0;
        degree[x] = degree[x] - 1;
    }
}

int maxindex(int n, vector <int> degree){
    int index;
    int x = *max_element(degree.begin(), degree.end());
    for (int i = 0; i < n; ++i){
        if (x == degree[i]){
            index = i;
            break;
        }
    }
    return(index);
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

int greedy(int n, vector <int> graph[], vector <int> degree, vector <int> vertexcover){
    int index = maxindex(n, degree);
    while ((degree[index] != 0)){
        vertexcover.push_back(index);
        for (auto u : graph[index]){
            remove(graph[u].begin(),graph[u].end(), index);
            graph[index].clear();
            degree[u] = degree[u] - 1;
            degree[index] = 0;
        }
        index = maxindex(n, degree);
    }
    return (vertexcover.size());
}

int main(){
    int n, k, cardi;
    scanf("%d %d", &n, &k); //Number of nodes and edges
    vector<int> graph[n]; //Graph of n nodes
    vector<int> degree; //List of degrees of nodes
    vector<int> vertexcover; //List of nodes in vertex cover
    definegraph(graph, n, k);
    degree = assigndegree(n, graph, degree);
    singlenodered(n, graph, degree, vertexcover);
    cardi = greedy(n, graph, degree, vertexcover);
    printf("%d", cardi);
}
