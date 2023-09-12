#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int arr[10][10];

int main()
{
    int cnt1 = 0;
    int cnt2;

    ifstream readFile;
    readFile.open("lineq1.dat");
    if(readFile.is_open()){
        while(!readFile.eof()){
            string s;
            getline(readFile,s);
            cout << s << "\n";
            stringstream ss(s);
            string s1;
            cnt2 = 0;
            while(ss >> s1){
                arr[cnt1][cnt2] = stoi(s1);
                cnt2++;
            }
            cnt1++;
        }
    }
    readFile.close();
    cout << "\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
