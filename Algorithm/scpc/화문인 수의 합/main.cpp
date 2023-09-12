#include <iostream>
#include <algorithm>

using namespace std;

int cnt = 0;
int mix[200];
int four_two[10001] = {0}; //���ڸ��� �ι����� ����� ����? �����ϸ� 1 / �Ұ����ϸ� 0
int P[10001][2]; //�ι����� �����Ҷ� �����Ѽ� ���� ����

void three_able(int x){ //���ڸ����� ������ �ִ� 2������ ����
    int tmp = x;
    int a = x/100; //first place
    int b = (x/10)%10; //second place
    int c = x%10; //third place
    if(a > c){
        cout << a * 101 + (b-1) * 10 << " ";
        tmp -= 101 * a + (b-1) * 10;
    }
    else{
        cout << a * 101 + b * 10 << " ";
        tmp -= 101 * a + b * 10;
    }
    cout << tmp << endl;
}

int main(int argc, char** argv)
{
	int T, test_case;

    //10000���� ���� ȸ���� ����

    for(int i=1; i<10; i++){
        mix[cnt] = i; //���ڸ����� ��� ȸ����
        cnt++;
    }
    for(int i=1; i<10; i++){
        mix[cnt] = 11 * i; //���ڸ����� 11�ǹ�� ȸ����
        cnt++;
    }
    for(int i=10; i<100; i++){
        mix[cnt] = i * 10 + i / 10; //���ڸ���
        cnt++;
    }
    for(int i=10; i<100; i++){
        mix[cnt] = i * 100 + (i % 10) * 10 + i/10; //���ڸ���
        cnt++;
    }

    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt; j++){
            int sum = mix[i] + mix[j];
            if(1000 <= sum && sum <= 10000){ //10000�� �� 4�ڸ���
                four_two[sum] = 1;
                P[sum][0] = max(mix[i],mix[j]);
                P[sum][1] = min(mix[i],mix[j]);
            }
        }
    }

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n;
        cin >> n;
        //�ϴ� n�� ȸ�������� �˻�
        bool ok = false;
        for(int i=0; i<cnt; i++){
            if(mix[i] == n){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << "Case #" << test_case+1 << endl << "1 " << n << endl;
            continue;
        }

        //������� ȸ���� �ƴ�
        if(n == 10){
            cout << "Case #" << test_case+1 << endl << "2 9 1" << endl;
            continue;
        }

        if(n < 100){ //n�� ���ڸ��� �϶�
            int a = n/10;
            int b = n%10;
            if(a < b){
                cout << "Case #" << test_case+1 << endl << "2 " << a * 11 << " " << b-a << endl;
            }
            else if(a - b > 1){
                cout << "Case #" << test_case+1 << endl << "2 " << (a-1) * 11 << " " << 11 + b - a << endl;
            }
            else{
                cout << "Case #" << test_case+1 << endl << "3 " << b * 11 << " 9 1"<< endl;
            }
            continue;
        }

        if(n == 100){
            cout << "Case #" << test_case+1 << endl << "2 99 1" << endl;
            continue;
        }

        if(n < 1000){ //n�� ���ڸ��� �϶�
            cout << "Case #" << test_case+1 << endl;
            cout << "2 ";
            three_able(n);
            continue;
        }

        //n�� ���ڸ����϶�
        if(four_two[n] == 1){
            cout << "Case #" << test_case+1 << endl << "2 " << P[n][0] << " " << P[n][1] << endl;
        }
        else{
            int a = n/1000;
            int b = (n/100) % 10;
            if(b == 0){
                cout << "Case #" << test_case+1 << endl << "3 " << a * 1001 << " ";
                three_able(n - a * 1001);
            }
            else{
                cout << "Case #" << test_case+1 << endl << "3 " << a * 1001 + (b-1) * 110 << " ";
                three_able(n - a * 1001 - (b-1) * 110);
            }
        }
	}

	return 0;
}
