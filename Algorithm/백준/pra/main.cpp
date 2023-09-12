#include <string>
#include <vector>
#include <iostream>

using namespace std;

int pan[51][51];
int jong[201] = {0};
int n,m;
int mx = 0;

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << pan[i][j] << " ";
        }
        cout << "\n";
    }
}

bool check(int x,int y,int z){
    if(z == 5) return false;
    if(z == 0){
        if(pan[x][y+1] == -1 && pan[x][y+2] == -1){
            for(int i=x; i<=x+1; i++){
                for(int j=y; j<=y+2; j++){
                    pan[i][j] = 0;
                }
            }
            return true;
        }
        else return false;
    }
    if(z == 1){
        if(pan[x][y-1] == -1 && pan[x+1][y-1] == -1){
            for(int i=x; i<=x+2; i++){
                for(int j=y-1; j<=y; j++){
                    pan[i][j] = 0;
                }
            }
            return true;
        }
        else return false;
    }
    if(z == 2){
        if(pan[x][y+1] == -1 && pan[x+1][y+1] == -1){
            for(int i=x; i<=x+2; i++){
                for(int j=y; j<=y+1; j++){
                    pan[i][j] = 0;
                }
            }
            return true;
        }
        else return false;
    }
    if(z == 3){
        if(pan[x][y-1] == -1 && pan[x][y-2] == -1){
            for(int i=x; i<=x+1; i++){
                for(int j=y-2; j<=y; j++){
                    pan[i][j] = 0;
                }
            }
            return true;
        }
        else return false;
    }
    if(z == 4){
        if(pan[x][y-1] == -1 && pan[x][y+1] == -1){
            for(int i=x; i<=x+1; i++){
                for(int j=y-1; j<=y+1; j++){
                    pan[i][j] = 0;
                }
            }
            return true;
        }
        else return false;
    }
}

void go(){
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(pan[i][j] == 0 || pan[i][j] == -1) pan[i][j] = -1;
            else break;
        }
    }
    cout << "Àü\n";
    print();
    bool ok = false;
    bool visit[201] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(pan[i][j] > 0 && !visit[pan[i][j]]){
                visit[pan[i][j]] = true;
                if(check(i,j,jong[pan[i][j]]-1)){
                    ok = true;
                }
            }
        }
    }
    cout << "ÈÄ\n";
    print();
    if(ok) go();
}

int solution(vector<vector<int>> board) {
    n = board.size();
    m = board[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pan[i][j] = board[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(pan[i][j] > 0 && jong[pan[i][j]] == 0){
                mx++;
                if(pan[i][j] == pan[i][j+1]){ //1,2,5,8,11
                    jong[pan[i][j]] = 6;
                }
                else{ //3,4,6,7,9,10,12
                    if(pan[i][j] == pan[i+2][j]){ //4,6,10,12
                        if(pan[i][j] == pan[i+2][j-1]) jong[pan[i][j]] = 2;
                        else if(pan[i][j] == pan[i+2][j+1]) jong[pan[i][j]] = 3;
                        else jong[pan[i][j]] = 6;
                    }
                    else{ //3,7,9
                        if(pan[i][j] == pan[i+1][j+2]) jong[pan[i][j]] = 1;
                        else if(pan[i][j] == pan[i+1][j-2]) jong[pan[i][j]] = 4;
                        else jong[pan[i][j]] = 5;
                    }
                }
            }
        }
    }

    for(int i=1; i<=5; i++){
        cout << i << " : " << jong[i] << "\n";
    }

    go();

    print();

    int cnt[201] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(pan[i][j] > 0 && cnt[pan[i][j]] == 0){
                cnt[pan[i][j]] = 1;
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=mx; i++){
        if(cnt[i] != 0) answer++;
    }
    return mx - answer;
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> v;
    for(int i=0; i<a; i++){
        vector<int> tmp;
        for(int j=0; j<b; j++){
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }
    cout << solution(v);
}

