#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXE 10000
#define MAXN 100
using namespace std;


typedef struct Edge{
    int begining;
    int ending;
    int weight;

    bool operator <(const Edge &e) const
    {
        return (weight < e.weight);
    }

}Edge;

typedef struct Set{
    int parent;
    int quantity;
}Set;

int n, m;
Edge E[MAXE];
Set S[MAXN];


void make_set(int i){
    S[i].parent = i;
    S[i].quantity = 0;
}

int find_set(int x){
    if(S[x].parent == x) return x;
    S[x].parent = find_set(S[x].parent);
    return S[x].parent;
}

void union_set(int a, int b){
    int set_a = find_set(a);
    int set_b = find_set(b);

    if(S[set_a].quantity < S[set_b].quantity)
        S[set_a].parent = set_b;
    else if(S[set_a].quantity > S[set_b].quantity)
        S[set_b].parent = set_a;
    else{
        S[set_b].parent = set_a;
        S[set_a].quantity += 1;
    }
}

int kruskal(){
    int min_weight = 0;
    int components = n - 1;
    for(int i = 0; i < n; i++)
        make_set(i);
    sort(E, E+m);

    for(int i = 0; i < m && components; i++){
        if(find_set(E[i].begining) != find_set(E[i].ending)){
            union_set(E[i].begining, E[i].ending);
            components--;
            min_weight += E[i].weight;
        }
    }

    return min_weight;
}

int main(){

    n = 7, m = 11;

    E[0].begining = 0, E[0].ending = 1, E[0].weight = 7;
    E[1].begining = 0, E[1].ending = 3, E[1].weight = 5;
    E[2].begining = 1, E[2].ending = 2, E[2].weight = 8;
    E[3].begining = 1, E[3].ending = 3, E[3].weight = 9;
    E[4].begining = 1, E[4].ending = 4, E[4].weight = 7;
    E[5].begining = 2, E[5].ending = 4, E[5].weight = 5;
    E[6].begining = 3, E[6].ending = 4, E[6].weight = 15;
    E[7].begining = 3, E[7].ending = 5, E[7].weight = 6;
    E[8].begining = 4, E[8].ending = 5, E[8].weight = 8;
    E[9].begining = 4, E[9].ending = 6, E[9].weight = 9;
    E[10].begining = 5, E[10].ending = 6, E[10].weight = 11;

    printf("%d\n",kruskal());


    return 0;
}


