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
	int ans_K,author_K;
	assert(judge_ans >> ans_K);
	if (!(author_out >> author_K)) {
		wrong_answer("testcase %d: No output\n", run);
	}
	if(ans_K != author_K){
		wrong_answer("testcase %d: Wrong K\n", run);
	}
	double* author_arr = new double[ans_K];
	double* ans_arr = new double[ans_K];
	for(int i = 0;i<ans_K;i++){
		if(!(author_out >> author_arr[i])) wrong_answer("testcase %d: No arr input\n", run);
		assert(judge_ans >> ans_arr[i]);
	}
	for(int i = 0;i<ans_K;i++){
		if(abs(author_arr[i] - ans_arr[i]) > 1e-9) wrong_answer("testcase %d: Insufficient precision\n", run);
	}
	delete [] author_arr;
	delete [] ans_arr;
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