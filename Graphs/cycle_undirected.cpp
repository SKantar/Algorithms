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

bool DFS(int start){
    stack<int> S;
    stack<int> P;
    S.push(start);
    P.push(-1);
    mark[start] = true;


    while(!S.empty()){

        int tmp = S.top();
        int prev = P.top();

        S.pop();
        P.pop();

        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if(!mark[graph[tmp].adj[i]]){
                S.push(graph[tmp].adj[i]);
                P.push(tmp);
                mark[graph[tmp].adj[i]] = true;
            }else{
                if(graph[tmp].adj[i] != prev)
                    return true;

            }
        }

    }
    return false;
}


bool has_cycle(int n){
    for(int i = 0; i < n; i ++){
        if(!mark[i])
            if(DFS(i))
                return true;
    }
    return false;
}


int main(){
    int n = 6;

    graph[0].adj.push_back(1);
    graph[1].adj.push_back(0);

    graph[0].adj.push_back(2);
    graph[2].adj.push_back(0);

    graph[2].adj.push_back(1);
    graph[1].adj.push_back(2);

    graph[3].adj.push_back(5);
    graph[5].adj.push_back(3);

    printf("%d\n",has_cycle(n) ? 1 : 0);

    return 0;

}
