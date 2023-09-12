#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct square{
    double x,y,w,h;
};

square S[31];

vector<double> X;
vector<double> Y;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> S[i].x >> S[i].y >> S[i].w >> S[i].h;
        X.push_back(S[i].x);
        X.push_back(S[i].x + S[i].w);
        Y.push_back(S[i].y);
        Y.push_back(S[i].y + S[i].h);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    double Answer = 0;

    for(int i=0; i<X.size()-1; i++){
        for(int j=0; j<Y.size()-1; j++){
            for(int k=0; k<n; k++){
                if(S[k].x <= X[i] && X[i+1] <= S[k].x + S[k].w && S[k].y <= Y[j] && Y[j+1] <= S[k].y + S[k].h){ //사각형 조각이 어떤 사각형 안에 포함된다면?
                    Answer += (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
                    break;
                }
            }
        }
    }
    if(Answer == (int)Answer) cout << (int)Answer;
    else{
        cout << fixed;
        cout.precision(2);
        cout << Answer;
    }
}
