#include <iostream>
#include <set>

using namespace std;

string solve()
{
	string n;
	int k;
	cin >> n >> k;

	while(1){
		set<char> s;
		for (auto c : n) s.insert(c);
		if (s.size() <= k) return n;

		s.clear();
		for(int ptr = 0; ; ptr++){
			s.insert(n[ptr]);
			if (s.size() > k){

                //n[ptr]++ �Ұ����� ���
				while (n[ptr] == '9'){
                    ptr--;
				}

				n[ptr]++;

				//���� ģ������ ��� 0���� ���� �ּҰ��� ã�´�
				for (int i = ptr + 1; i < n.size(); i++){
                    n[i] = '0';
				}

				break;
			}
		}
	}
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--){
        cout << solve() << '\n';
	}
	return 0;
}
