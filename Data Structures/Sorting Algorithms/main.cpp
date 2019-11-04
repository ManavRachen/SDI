#include "stdAfx.h"
#include <vector>
using namespace std;

void main() {
	vector<int> c;
}

void MergeSort(vector<int> array_) {

}

vector<vector<int>> split(vector<int> array_) {
	int mid = array_.size / 2;

	vector<vector<int>> retArray;
	for (int i = 0; i < mid; i++) {
		retArray[0][i] = array_[i];
	}
	for (int i = mid; i < array_.size; i++) {
		retArray[1][i] = array_[i];
	}

	return retArray;
}

vector<int> merge(vector<vector<int>> array_) {
	vector<int> retArray;

	for (int i = 0; i < array_[0].size; i++) {
		for (int j = 0; j < array_[1].size; j++) {

		}
	}
}