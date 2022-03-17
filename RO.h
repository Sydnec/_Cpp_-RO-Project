#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int DqEq(){
    vector<string> vDir(2);
	vDir[0] = "Dq";
	vDir[1] = "Eq";

	for (int i = 0; i < vDir.size(); ++i) {
        for(int j = 0; j < 10; ++j){
            char buffer[4];
            sprintf(buffer, "%d", j);
            string dirname = "./BildeKrarup/" + vDir[i] + "/" + buffer + "/files.lst";
            cout << dirname;
        }
    }
}
int BC(){
	//B, C
	vector<string> vDir(4);
	vDir[0] = "B";
	vDir[1] = "C";

	for (int i = 0; i < vDir.size(); ++i) {
		string dirname = "./BildeKrarup/" + vDir[i] + "/files.lst";
		
		ifstream mydir;
		mydir.open(dirname);
		if (!mydir.is_open()) cerr << "Can't open file " << dirname << '\n';
		else {
			ifstream myfile;
			string line = "", filename ="";

			while (getline(mydir, line)) {
				string fileLine = "";
				filename = "./BildeKrarup/" + vDir[i] + '/' + line;
				cout << "Filename = " << filename << '\n';
				myfile.open(filename);
				if (!myfile.is_open()) cerr << "Can't open file " << filename << '\n';
				
				while (getline(myfile, fileLine)) {
					cout << fileLine;
				}
				cout << '\n';
				myfile.close();
			}
			mydir.close();
		}
	}
	return 0;
}