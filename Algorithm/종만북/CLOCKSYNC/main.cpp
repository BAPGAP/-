#include <iostream>
#include <vector>

using namespace std;

vector<int> swich[10] ={{0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};

int clock_now[16];

void swich_on(int x,int num){ //x번 스위치 num번 만큼 누름
    for(int i=0; i<swich[x].size(); i++){
        clock_now[swich[x][i]] = (clock_now[swich[x][i]] - num + 4) % 4;
    }
}

void print(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << clock_now[i*4+j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int Answer = 0;
        for(int i=0; i<16; i++){
            cin >> clock_now[i];
            clock_now[i] = (clock_now[i]/3) % 4;
        }
        if(clock_now[8] != clock_now[12]){
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<4; i++){
            if(clock_now[11] == i){
                swich_on(1,i);
                Answer += 4-i;
            }
            if(clock_now[8] == i){
                swich_on(4,i);
                Answer += 4-i;
            }
            if(clock_now[13] == i){
                swich_on(9,i);
                Answer += 4-i;
            }
        }
        if(clock_now[9] > 0){
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<4; i++){
            if(clock_now[6] == i){
                swich_on(3,i);
                Answer += 4-i;
            }
            if(clock_now[10] == i){
                swich_on(2,i);
                Answer += 4-i;
            }
        }

        for(int i=1; i<4; i++){
            if(clock_now[7] == i){
                swich_on(7,i);
                Answer += 4-i;
            }
        }
        if(clock_now[4] != clock_now[5]){
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<4; i++){
            if(clock_now[4] == i){
                swich_on(8,i);
                Answer += 4-i;
            }
        }

        for(int i=1; i<4; i++){
            if(clock_now[1] == i){
                swich_on(0,i);
                Answer += 4-i;
            }
        }

        if(clock_now[0] != clock_now[2]){
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<4; i++){
            if(clock_now[0] == i){
                swich_on(5,i);
                Answer += 4-i;
            }
        }

        if(clock_now[3] != clock_now[14]){
            cout << "-1\n";
            continue;
        }
        if(clock_now[14] != clock_now[15]){
            cout << "-1\n";
            continue;
        }
        if(clock_now[3] != clock_now[15]){
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<4; i++){
            if(clock_now[3] == i){
                swich_on(6,i);
                Answer += 4-i;
            }
        }

        cout << Answer  << "\n";
    }
}
