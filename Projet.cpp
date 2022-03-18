#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> splitLine(string str){
    vector<int> result;
	string current = "";
	for (int i = 0; i < str.size(); i++) {
		if (isblank(str[i])) {
			if (current != "") {
				result.push_back(stoi(current));
				current = "";
			}
			continue;
		}
		else {
			current += str[i];
		}
	}
	if (current.size() != 0)
		result.push_back(stoi(current));
	return result;
}

int minimum(vector<int> column){
	int actualMin = column[0];
	for(int i = 1; i<column.size(); ++i){
		actualMin = min(actualMin, column[i]);
	}
	return actualMin;
}

int Exo2(vector<string> file, int NbCol, int NbLine) {
	vector< vector<int> > result;
	vector<int> Vcol;
	int sum = 0;
	for (int i = 0; i < file.size(); ++i) {
		result.push_back(splitLine(file[i]));
	}
	for (int j = 0; j < NbLine; ++j) { 
		sum += result[j][1];
	}
	for (int i = 2; i < NbCol; ++i) {
		Vcol.clear();
		for (int j = 0; j < NbLine; ++j) { 
			Vcol.push_back(result[j][i]);
		}
		sum += minimum(Vcol);
	}
	return 1;
}

void read(string directory){
	string dir = directory + "/files.lst";
	
	ifstream mydir;
	mydir.open(dir);
	if (!mydir.is_open()) cerr << "Can't open " << dir << '\n';
	else {
		ifstream myfile;
		string line = "", filename = "";

		while (getline(mydir, line)) {
			vector<string> strFile;
			string fileLine = "";
			int result = 0;
			int nbLin = 0;
			int nbCol = 0;

			filename = directory + '/' + line;
			cout << "Filename = " << filename << endl;
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open " << filename << endl;
				return;
			}
			for (int i(0); i < 2; ++i) getline(myfile, fileLine);
			nbLin = splitLine(fileLine)[0];
			nbCol = splitLine(fileLine)[1];
			// cout << nbCol << " " << nbLin << endl;
			while (getline(myfile, fileLine)) {
				strFile.push_back(fileLine);
			}
			Exo2(strFile, nbCol, nbLin);
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

int main(){
	Exercice1();
}