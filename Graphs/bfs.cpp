#include <cstdio>
#include <vector>
#include <queue>

#define MAXN 100

using namespace std;

typedef struct Node{

    vector<int> adj;

}Node;

Node graph[MAXN];
bool mark[MAXN];

void BFS(int start){
    queue<int> Q;
    Q.push(start);
    mark[start] = true;


    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();

        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if(!mark[graph[tmp].adj[i]]){
                Q.push(graph[tmp].adj[i]);
                mark[graph[tmp].adj[i]] = true;
            }
        }

        printf("Traversing Node ID %d\n", tmp);

    }
}


int main(){
    graph[0].adj.push_back(1);
    graph[0].adj.push_back(2);
    graph[2].adj.push_back(3);
    graph[3].adj.push_back(4);
    BFS(0);
    return 0;

}
