#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v, w(2);
	for (int i = 0; i < 7; i++){
        w.push_back(1);
	}
	w[0] = 0;
	w[1] = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	while (next_permutation(w.begin(), w.end()))
	{
		vector<int> answer;
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i] == 1){
				answer.push_back(v[i]);
                cout << i << " ";
			}
		}
		cout << "\n";
		sum++;
	}
	cout << sum << "\n";
	return 0;
}
