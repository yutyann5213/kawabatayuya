#include 
#define ROW 6
#define COL 3
int pathList[ROW][COL] = {
    {0},
    {2, 3, 0},
    {4, 0},
    {6, 0},
    {5, 0},
    {0}
};
int route[ROW];
void initRoute(){
    int i;
    for(i = 0; i < ROW; i++){
        route[i] = 0;
    }
    
    return;
}
void dfs(int start, int target){
    int i;
    
    route[start] = 1;
    printf("%d→", start);
    if(start == target){
        printf("Found target");
        return;
    }
    for(i = 0; pathList[start][i] != 0; i++){
        if(route[pathList[start][i]] == 0){
            dfs(pathList[start][i], target);
        }
    }
}
int main(){
    initRoute();
    dfs(1, 6);
        
    return 0;
}

