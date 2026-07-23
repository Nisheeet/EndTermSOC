#include<bits/stdc++.h>
using namespace std;

int tot=0;
int lm=48;

int templ[48]; // -1 is ?
bool board[9][9]; //0 means empty //-1 means dont touch

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char d[4] = {'L','R','U','D'};

void move(int cy=1, int cx=1, int left=lm){

    if((board[cy-1][cx] != 0 and board[cy+1][cx] != 0 and board[cy][cx-1]==0 and board[cy][cx+1]==0)
    or (board[cy][cx-1] != 0 and board[cy][cx+1] != 0 and board[cy-1][cx]==0 and board[cy+1][cx]==0)){
        return;
    }
    
    if(cy==7 and cx==1){
        if(left==0) tot++;
        return;
    }

    for(int i=0; i<4; i++){
        if(templ[lm-left] != -1 and templ[lm-left] != i) continue;
        int ny = cy+dy[i];
        int nx = cx+dx[i];
        if(board[ny][nx]==0){
            board[ny][nx] = 1;
            move(ny,nx,left-1);
            board[ny][nx] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for(int i=0; i<48; i++) templ[i] = -1;
    for(int i=0; i<9; i++){
        board[0][i] = -1;
        board[8][i] = -1;
    }
    for(int i=1; i<8; i++){
        board[i][0] = -1;
        board[i][8] = -1;
    }
    
    board[1][1] = 1;
    string s; cin >> s;
    for(int i=0; i<48; i++){
        if(s[i] == 'L') templ[i] = 0;
        else if(s[i] == 'R') templ[i] = 1;
        else if(s[i] == 'U') templ[i] = 2;
        else if(s[i] == 'D') templ[i] = 3;
    }
    
    move();
    cout << tot << "\n";
}