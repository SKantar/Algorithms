#include <cstdio>
#include <cstdlib>
#define MAXN 100
using namespace std;

int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

int populate(int matrix[][MAXN], int n){
    int tmp = 0;
    int curr = 0;
    int layer = 0;
    int px = 0;
    int py = 0;



    while(tmp < n * n){
        matrix[px][py] = ++tmp;

        py += y[curr];
        px += x[curr];

        if((px == layer && py == n - 1 - layer)
        || (px == n - 1 - layer && py == n - 1 - layer)
        || (px == n - 1 - layer && py == layer))
            curr++;
        else
        if(px == py){
            layer ++;
            px ++;
            py ++;
            curr = 0;
            continue;
        }

    }
}

int main(){
    int matrix[MAXN][MAXN];
    int n = 7;
    populate(matrix, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}
