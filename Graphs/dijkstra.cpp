#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <queue>
#define MAXN 100

using namespace std;

typedef struct Node{
    int dist;
    vector<int> adj;
    vector<int> weight;
}Node;

int n;
Node graph[MAXN];
bool mark[MAXN];

void dijkstra(int source){
    priority_queue<pq_entry> Q;

    for(int i = 0; i < n; i++)
        if(i == source){
            graph[i].dist = 0;
            start.node = i;
            start.dist = 0;
            Q.push(start);
        }else
            graph[i].dist = INT_MAX;


    while(!Q.empty()){
        pq_entry curr = pq.top();
        pq.pop();


    }


}
