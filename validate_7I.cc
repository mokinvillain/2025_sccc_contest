#include <utility>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <vector>
#include "validate.h"
#include <unordered_map>

using namespace std;


int N;
char arr[300][300],author_arr[300][300];

void rotate(int i){
    char tmp = arr[i][0];
    for(int j = 0;j<N-1;j++) arr[i][j] = arr[i][j+1];
    arr[i][N-1] = tmp;
}

bool check(int i){
	for(int j = 0;j<N;j++){
		if(arr[i][j] != author_arr[i][j]) return 0;
	}
	return 1;
}

void check_case(int run) {
	assert(judge_in >> N);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++) assert(judge_in >> arr[i][j]);
    }
    string author_string;
	cin.ignore();
	if (!(getline(author_out, author_string))) {
		wrong_answer("testcase %d: No output\n", run);
	}
    if(author_string != "Yes") wrong_answer("testcase %d: Wrong string\n", run);
    for(int i = 0;i<N;i++){
		if(!(getline(author_out,author_string))) wrong_answer("testcase %d: Wrong output format\n", run);
		if(author_string.size() != N) wrong_answer("testcase %d: Wrong string size\n", run);
		for(int j = 0;j<N;j++) author_arr[i][j] = author_string[j];
    }
	for(int i = 0;i<N;i++){
		bool c = 0;
		for(int j = 0;j<N;j++){
			if(check(i)){
				c = 1;
				break;
			}
			rotate(i);
		}
		if(!c) wrong_answer("testcase %d: Not correct with input\n", run);
	}
	unordered_map<string,bool> m;
	for(int i = 0;i<N;i++){
		string s = "";
		for(int j = 0;j<N;j++) s.push_back(author_arr[j][i]);
		if(m[s]) wrong_answer("testcase %d: Same string exist\n", run);
		m[s] = 1;
	}
}

int main(int argc, char **argv) {
	init_io(argc, argv);
	check_case(1);
	string trash;
	if (author_out >> trash){
		wrong_answer("Trailing output: '%s'\n", trash.c_str());
	}
	accept();
}