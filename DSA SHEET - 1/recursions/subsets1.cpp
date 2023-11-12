#include<iostream>
#include<vector>
using namespace std;

void findCombination(int index, vector<int>& num, vector<vector<int>>& ans, vector<int> ds) {
	if(index == num.size()) {
		ans.push_back(ds);
		return;
	}
	ds.push_back(num[index]);
	findCombination(index + 1, num, ans, ds);
	ds.pop_back();
	findCombination(index + 1, num, ans, ds);
}

vector<int> subsetSum(vector<int> &num){
	vector<vector<int>> ans;
	vector<int> ds, count;
	findCombination(0, num, ans, ds);
	for(auto s: ans) {
		int sum = 0;
		for (auto& val : s) {
            sum += val;
        }
		count.push_back(sum);
	}
	return count;
}