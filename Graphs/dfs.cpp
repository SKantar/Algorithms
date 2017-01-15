#include <cstdio>
#include <vector>
#include <stack>

#define MAXN 100

using namespace std;

typedef struct Node{

    vector<int> adj;

}Node;

Node graph[MAXN];
bool mark[MAXN];

void BFS(int start){
    stack<int> S;
    S.push(start);
    mark[start] = true;


    while(!S.empty()){
        int tmp = S.top();
        S.pop();

        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if(!mark[graph[tmp].adj[i]]){
                S.push(graph[tmp].adj[i]);
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
