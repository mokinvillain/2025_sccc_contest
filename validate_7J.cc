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

void check_case(int run){
    int N,M;
    assert(judge_in >> N);
    int *town = new int[N],*author_town = new int[N],*ans_town = new int[N];
    for(int i = 0;i<N;i++) assert(judge_in >> town[i]);
    for(int i = 0;i<N;i++) assert(judge_ans >> ans_town[i]);
    assert(judge_in >> M);
    int *shelter = new int[M];
    for(int i = 0;i<M;i++) assert(judge_in >> shelter[i]);
    for(int i = 0;i<N;i++){
        if(!(author_out >> author_town[i])) wrong_answer("testcase %d: No input\n", run);
        if(author_town[i] > M || author_town[i] < 1) wrong_answer("testcase %d: Out of bound\n", run);
    }
    for(int i = 0;i<N;i++){
        if(abs(town[i] - shelter[ans_town[i]-1]) < abs(town[i] - shelter[author_town[i]-1])) wrong_answer("testcase %d: Not nearest shelter\n", run);
    }
    delete [] town;
    delete [] author_town;
    delete [] ans_town;
    delete [] shelter;
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