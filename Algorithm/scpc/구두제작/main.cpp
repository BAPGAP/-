#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> gudo;
int jangin[101];


bool Compare(vector<int> x,vector<int> y){
    if(x[0] == y[0]){
        return (x[1] - x[2]) < (y[1] - y[2]);
    }
    else return x[0] < y[0];
}


int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,k;
	    cin >> n >> k;
        int a,f,p;
        int s,e;
        for(int i=0; i<101; i++){
            jangin[i] = 0;
        }

        for(int i=0; i<n; i++){
            cin >> a >> f >> p;
            gudo.push_back(vector<int> {a,f,p});
        }

        for(int i=0; i<k; i++){
            cin >> s >> e;
            for(int j=s; j<e; j++){
                jangin[j]++;
            }
        }

        sort(gudo.begin(),gudo.end(),Compare);

        bool isok = true;

        while(!gudo.empty()){
            /*cout << "����\n";
            for(int i=0; i<gudo.size(); i++){
                cout << gudo[i][0] << " " << gudo[i][1] << " " << gudo[i][2] << "\n";
            }
            cout << "����\n";
            for(int i=0; i<101; i++){
                cout << jangin[i] << " ";
            }
            cout << "\n";
            */

            if(jangin[gudo[0][0]] > 0){
                jangin[gudo[0][0]]--;
                gudo[0][0]++;
                gudo[0][2]--;
                if(gudo[0][2] == 0){
                    gudo.erase(gudo.begin());
                    continue;
                }
            }
            else{ //������ �� �ð��� �ƹ��� ������
                gudo[0][0]++;
            }

            //���� �����ٿ� �°� ���� ������ ���� �� �� ���� �˻� ���� �ٽ� sort

            if(gudo[0][0] + gudo[0][2] > gudo[0][1]){ //���θ� ���� �Ҽ� ���� ���
                isok = false;
                break;
            }
            else if(gudo[0][0] + gudo[0][2] == gudo[0][1]){ //�� ������ ���� �Ҷ�
                for(int i=gudo[0][0]; i<gudo[0][1]; i++){
                    if(jangin[i] > 0) jangin[i]--;
                    else{
                        isok = false;
                        break;
                    }
                }
                if(isok){
                    gudo.erase(gudo.begin());
                    //�̹� ���ĵ� �տ��� ����Ŷ� �� ������ �ʿ�� ����
                }
                else break;
            }
            else{ //��� ��쵵 �ƴϸ� �ٽ� sort�ؼ� ó������ �˻�
                sort(gudo.begin(),gudo.end(),Compare);
            }
        }

        if(!gudo.empty()) gudo.clear();

		cout << "Case #" << test_case+1 << endl;
		if(isok) cout << "1" << endl;
		else cout << "0" << endl;
	}

	return 0;
}
