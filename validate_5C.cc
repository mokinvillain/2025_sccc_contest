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

int N;
void check_case(int run){
	assert(judge_in >> N);
	bool *machine = new bool[N+1](), *check = new bool[N+1]();
	int *author_arr = new int[N+1]();
	vector<int> G[N+1];
	int K,author_K;
	for(int i = 1;i<=N;i++){
		assert(judge_in >> machine[i]);
		assert(judge_in >> K);
		G[i].resize(K);
		for(int j = 0;j<K;j++) assert(judge_in >> G[i][j]);
	}
	assert(judge_ans >> K);
	if(!(author_out >> author_K)) wrong_answer("testcase %d: No input\n", run);
	if(K != author_K) wrong_answer("testcase %d: Not equal\n", run);
	author_K = 0;
	bool cur;
	if(!(author_out >> author_arr[0])) wrong_answer("testcase %d: No input\n", run);
	if(author_arr[0] <= 0 || author_arr[0] > N) wrong_answer("testcase %d: Out of bound\n", run);
	cur = machine[author_arr[0]];
	check[author_arr[0]] = 1;
	for(int i = 1;i<N;i++){
		if(!(author_out >> author_arr[i])) wrong_answer("testcase %d: No input\n", run);
		if(author_arr[i] <= 0 || author_arr[i] > N) wrong_answer("testcase %d: Out of bound\n", run);
		if(cur != machine[author_arr[i]]){
			author_K++;
			cur = machine[author_arr[i]];
		}
		for(int j : G[author_arr[i]]){
			if(!check[j]) wrong_answer("testcase %d: Not satisfied conditions\n", run);
		}
		check[machine[i]] = 1;
	}
	if(author_K != K) wrong_answer("testcase %d: Wrong changing number\n", run);
	delete [] machine;
	delete [] check;
	delete [] author_arr;
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