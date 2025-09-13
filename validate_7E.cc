#include <utility>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <vector>
#include "validate.h"

using namespace std;

void check_case(int run) {
	string str;
	int ans_idx,author_idx;
	assert(judge_in >> str);
	assert(judge_ans >> ans_idx);
	if (!(author_out >> author_idx)) {
		wrong_answer("testcase %d: No index\n", run);
	}
	if (ans_idx == 0){
		if(author_idx != 0) wrong_answer("testcase %d: 0 case\n", run);
		else return;
	}
	if(author_idx < 1 || author_idx > str.size()) wrong_answer("testcase %d: Out of bound\n", run);
	string author_str = "";
	for(int i = 0;i<str.size();i++){
		if(i+1 != author_idx) author_str.push_back(str[i]);
	}
	int *check = new int[2]();
	for(int i = 0;i<author_str.size();i++){
		if(author_str[i] == '1') check[(i+1)%2]++;
	}
	if(check[0] != check[1]) wrong_answer("testcase %d: Not equal\n", run);
    delete [] check;
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