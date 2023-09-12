#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> vs;
int cnt[10] = {0};
int main()
{
    string line;
	ifstream file("길이32,1이8개,서로60도인 set.txt");
	if(file.is_open()){
		while(getline(file, line)) {
            vs.push_back(line);
		}
		file.close();
	}
	for(int i=0; i<vs.size(); i++){
        for(int j=i+1; j<vs.size(); j++){
            string x = vs[i];
            string y = vs[j];
            int sum = 0;
            for(int k=0; k<32; k++){
                sum += (x[k] == y[k]) ? stoi(x.substr(k,1)) : 0;
            }
            cnt[sum]++;
        }
	}
	for(int i=0; i<10; i++){
        cout << "cnt " << i << " is " << cnt[i] << "\n";
	}
}
