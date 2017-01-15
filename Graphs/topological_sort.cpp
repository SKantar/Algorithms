#include <cstdio>
#include <cstdlib>
#include <queue>

#define MAXN 500
using namespace std;

typedef struct Node{

    vector<int> adj;

}Node;

int n;
Node graph[MAXN];
int indegree[MAXN];
int topoorder[MAXN];

int topo_sort(){
    queue<int> Q;
    int idx = 0;

    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            Q.push(i);

    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        topoorder[idx++] = tmp;
        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if( !--indegree[graph[tmp].adj[i]] )
                Q.push(graph[tmp].adj[i]);
        }
    }

    if(idx < n)
        return -1;
    else
        return 1;
}



int main(){

    n = 8;

    graph[7].adj.push_back(0);
    graph[7].adj.push_back(5);
    graph[7].adj.push_back(6);
    graph[4].adj.push_back(5);
    graph[3].adj.push_back(7);
    graph[3].adj.push_back(4);
    graph[2].adj.push_back(7);
    graph[1].adj.push_back(4);
    graph[1].adj.push_back(6);

    indegree[0] = 1;
    indegree[1] = 0;
    indegree[2] = 0;
    indegree[3] = 0;
    indegree[4] = 2;
    indegree[5] = 2;
    indegree[6] = 2;
    indegree[7] = 2;

    topo_sort();

    for (int i = 0; i < n; i++)
        printf("%d ", topoorder[i]);


    return 0;
}
