#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read(string directory){
	string dir = directory + "/files.lst";

	ifstream mydir;
	mydir.open(dir);
	if (!mydir.is_open()) cerr << "Can't open " << dir << '\n';
	else {
		ifstream myfile;
		string line = "", filename = "";

		while (getline(mydir, line)) {
			string fileLine = "";
			filename = directory + '/' + line;
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

void BildeKrarup(){
	//B, C, Dq, Eq
	vector<string> vDir(4);
	vDir[0] = "B";
	vDir[1] = "C";
	vDir[2] = "Dq";
	vDir[3] = "Eq";

	for (int i = 0; i < vDir.size(); ++i) {
		if (i == 2 || i == 3) {
			for (int j = 1; j <= 10; ++j) {
				string str = "./BildeKrarup/" + vDir[i] + "/" + to_string(j);
				read(str);
			}
		}
		else{
			read("./BildeKrarup/" + vDir[i]);
		}
	}
}

void KoerkelGhosh(){
	//B, C, Dq, Eq
	vector<string> vDir(3);
	vDir[0] = "250";
	vDir[1] = "500";
	vDir[2] = "750";

	vector<string> vSubDir(3);
	vSubDir[0] = "a";
	vSubDir[1] = "b";
	vSubDir[2] = "c";

	for (int i = 0; i < vDir.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			string str = "./KoerkelGhosh/" + vDir[i] + "/" + vSubDir[j];
			read(str);
		}
	}
}

void Exercice1(){
	BildeKrarup();
	KoerkelGhosh();
}