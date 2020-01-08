#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void arrange(vector<int> &frames, vector<int> &output) {
	for (int i = 0; i < frames.size(); i++) {
		for (int j = 0; j < frames.size(); j++) {
			if (frames[i] > frames[j])
				swap(frames[i], frames[j]);
		}
	}
	for (int i = 0; i < frames.size(); i++) {
		output.push_back(frames[i]);
	}
}

bool check(vector<int> frames, int a) {
	bool have = false;
	for (int i = 0; i < frames.size(); i++) {
		if (a == frames[i]) {
			have = true;
		}
	}
	return have;
}

void insteadO(vector<int> &frames, vector<string> input, int currenti) {
	int firc = 0, secc = 0, thirc = 0;
	for (int i = currenti; i < input.size(); i++) {      
		if (frames[0] == stoi(input[i]) && !firc) {
			firc = i - currenti;
		}
		if (frames[1] == stoi(input[i]) && !secc) {
			secc = i - currenti;
		}
		if (frames[2] == stoi(input[i]) && !thirc) {
			thirc = i - currenti;
		}
	}
	if (firc == 0)
		firc = 99999;
	if (secc == 0)
		secc = 99999;
	if (thirc == 0)
		thirc = 99999;

	if (firc > secc &&firc > thirc) {
		frames[0] = stoi(input[currenti]);
	}
	else if (secc > thirc) {
		frames[1] = stoi(input[currenti]);
	}
	else {
		frames[2] = stoi(input[currenti]);	
	}
}

void insteadL(vector<int> &frames, vector<string> input, int currenti) {
	int firc = 0, secc = 0, thirc = 0;
	for (int i = currenti; i > 1; i--) {
		if (frames[0] == stoi(input[i]) && !firc) {
			firc = currenti - i;
		}
		if (frames[1] == stoi(input[i]) && !secc) {
			secc = currenti - i;
		}
		if (frames[2] == stoi(input[i]) && !thirc) {
			thirc = currenti - i;
		}
	}

	if (firc == 0)
		firc = 99999;
	if (secc == 0)
		secc = 99999;
	if (thirc == 0)
		thirc = 99999;

	if (firc > secc &&firc > thirc) {
		frames[0] = stoi(input[currenti]);
	}
	else if (secc > thirc) {
		frames[1] = stoi(input[currenti]);
	}
	else {
		frames[2] = stoi(input[currenti]);
	}
}

int main(int argc, char** argv) {
	fstream file;
	vector<string> input;
	int pagefault = 0;
	file.open(argv[2], ios::in);
	if (!file)
		cerr << "error" << endl;
	else {
		string temp;
		while (file.eof()==0) {
			file >> temp;
			input.push_back(temp);
		}
		for (int i = 0; i < input.size(); i++) {
			cout << input[i] << " ";
		}
		cout << endl;
		file.close();
	}
	vector<int> frames( stoi(input[1]) );
	for (int i = 0; i < frames.size(); i++) {
		frames[i] = -1;
	}

	vector<int> output;
	int num = frames.size();
	int temp = 0;
	for (int i = 0; i < frames.size(); i++) {
		if (check(frames, stoi(input[i+2+temp]))) {
			arrange(frames, output);
			i--;
			temp++;
			continue;
		}
		frames[i] = stoi(input[i+2+temp]);
		pagefault++;
		arrange(frames, output);
	}

	if (*argv[1]  == '0') {   // OPT
		for (int i = frames.size() + 2 + temp; i < stoi(input[0]) + 2; i++) {  //+2是因為 Input 前兩個 不是 值   +2 上前兩位數
			if (check(frames, stoi(input[i]))) {
				arrange(frames, output);
			}
			else {
				insteadO(frames, input, i);
				arrange(frames, output);
				pagefault++;
			}
		}
	}
	else if (*argv[1] == '1') {    // LRU
		for (int i = frames.size() + 2 + temp; i < stoi(input[0]) + 2; i++) {  //+2是因為 Input 前兩個 不是 值   +2 上前兩位數
			if (check(frames, stoi(input[i]))) {
				arrange(frames, output);
			}
			else {
				insteadL(frames, input, i);
				arrange(frames, output);
				pagefault++;
			}
		}
	}
	file.open(argv[3], ios::out);
	file << pagefault << endl;
	for (int i = 0, out=0; i < stoi(input[0]); i++) {
		for (int j = 0; j < stoi(input[1]); j++) {
			file << output[out++] << " ";
		}
		file << endl;
	}
	file.close();
}