#include <iostream>
#include <string>
#include <vector>

using namespace std;


int numCountdowns(vector<int> vect, int sizeChunk) {
    int res, c, curr;
    res = 0;


    for(int i = 0; i < vect.size(); i++) {
	c = 0;
	for(int j = i+1; j < vect.size() && c < sizeChunk; j++) {
	    curr = j-1;
	    if(vect[curr]-1 == vect[j]) {
		c++;
		if(c == sizeChunk-1) {
		    if(vect[j] == 1)
			res++;
		    break;
		}
	    } else {
		break;
	    }
	}	
    }
    return res;
}


void printVec(vector<int> vect) {
    for(int i = 0; i < vect.size(); i++) {
	cout << vect[i] << ' ';
    } cout << endl;
}


int main(void) {
    int numCases, arrLen, chunkSize, _tmp;
    vector<int> vectorIn;

    cin >> numCases;

    for(int i = 0; i < numCases; i++) {
	vectorIn.clear();
	cin >> arrLen;
	cin >> chunkSize;
	for(int j = 0; j < arrLen; j++) {
	    cin >> _tmp;
	    vectorIn.push_back(_tmp);
	}
	cout << "Case #"<< i+1 << ": " << numCountdowns(vectorIn, chunkSize) << endl;
    }

}
