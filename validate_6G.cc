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

int arr[333][333];

void check_case(int run) {
	string str;
	int n,m,author_K,ans_K,x1,x2,y1,y2;
	assert(judge_in >> m);
    assert(judge_in >> n);
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++) assert(judge_in >> arr[i][j]);
    }
    assert(judge_ans >> ans_K);
	if (!(author_out >> author_K)) wrong_answer("testcase %d: No output\n", run);
    if(author_K != ans_K) wrong_answer("testcase %d: Wrong sum\n", run);
	if(!(author_out >> x1 >> y1 >> x2 >> y2)) wrong_answer("testcase %d: No output\n", run);
    if(x1 > m || x1 < 1) wrong_answer("testcase %d: Out of bound\n", run);
    if(x2 > m || x2 < 1) wrong_answer("testcase %d: Out of bound\n", run);
    if(y1 > n || y1 < 1) wrong_answer("testcase %d: Out of bound\n", run);
    if(y2 > n || y2 < 1) wrong_answer("testcase %d: Out of bound\n", run);
    if(x1 >= x2) wrong_answer("testcase %d: incorrect coordinate\n", run);
    if(y1 >= y2) wrong_answer("testcase %d: incorrect coordinate\n", run);
    long long sum = 0;
    for(int i = x1;i<=x2;i++) sum += arr[i][y1];
    for(int i = x1;i<=x2;i++) sum += arr[i][y2];
    for(int i = y1;i<=y2;i++) sum += arr[x1][i];
    for(int i = y1;i<=y2;i++) sum += arr[x2][i];
    sum -= arr[x1][y1];
    sum -= arr[x1][y2];
    sum -= arr[x2][y1];
    sum -= arr[x2][y2];
    if(sum != ans_K) wrong_answer("testcase %d: Not equal to real sum\n", run);
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