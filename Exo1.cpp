#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string str, char splitter){
    vector<string> result;
    string current = ""; 
    for(int i = 0; i < str.size(); i++){
        if(str[i] == splitter){
            if(current != ""){
                result.push_back(current);
                current = "";
            } 
            continue;
        }
		else{
        	current += str[i];
		}
    }
    if(current.size() != 0)
        result.push_back(current);
    return result;
}

int minimum(vector<string> range){
	int actual = stoi(range[2]);
	for(int i = 3; i<range.size(); ++i){
		actual = min(actual, stoi(range[i]));
	}
	return actual;
}

int Exo2(string fileLine){
	char carac = ' ';
	int f = 0;
	vector<string> result;
	result = splitString(fileLine, carac);
	f = stoi(result[1]);
	return f + minimum(result);
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
			string fileLine = "";
			int result = 0;
			int cpt = 0;

			filename = directory + '/' + line;
			cout << "Filename = " << filename << '\n';
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open " << filename << '\n';
				return;
			}
			while (getline(myfile, fileLine)) {
				cpt ++;
				if(cpt > 2){
					result += Exo2(fileLine); 
				}
				// cout << fileLine;
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