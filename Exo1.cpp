#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read(string directory){
	string dir = "./BildeKrarup/" + directory + "/files.lst";

	ifstream mydir;
	mydir.open(dir);
	if (!mydir.is_open()) cerr << "Can't open " << dir << '\n';
	else {
		ifstream myfile;
		string line = "", filename = "";

		while (getline(mydir, line)) {
			string fileLine = "";
			filename = "./BildeKrarup/" + directory + '/' + line;
			cout << "Filename = " << filename << '\n';
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open " << filename << '\n';
				return;
			}

			while (getline(myfile, fileLine)) {
				//cout << fileLine;
			}
			myfile.close();
		}
		mydir.close();
	}
	return;
}

void Exercice1(){
	//B, C, Dq, Eq
	vector<string> vDir(4);
	vDir[0] = "B";
	vDir[1] = "C";
	vDir[2] = "Dq";
	vDir[3] = "Eq";

	for (int i = 0; i < vDir.size(); ++i) {
		if (i == 3 || i == 4) {
			for (int j(1); j <= 10; ++j) {
				string str = vDir[i] + "/" + to_string(j);
				read(str);
			}
		}
		else{
			read(vDir[i]);
		}
	}
}