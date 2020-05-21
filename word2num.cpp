#include <iostream>
#include <string>
#include <vector>

using namespace std;


void split(string str, vector<string> &vec, char splitby) {
    string thisString = "";

    for(int i = 0; i < str.size(); i++) {
	if(str[i] == splitby) {
	    vec.push_back(thisString);
	    thisString = "";
	} else {
	    thisString += str[i];
	}
    }
    vec.push_back(thisString);
    return;
}


int getInt(vector<string> words) {
    int res, toAdd, q, order;
    res = toAdd = 0;

    vector<string> nums = {"one", "two", "three", "four", "five",
                           "six", "seven", "eight", "nine"};

    vector<string> teens = {"eleven", "twelve", "thirteen", "fourteen", "fifteen",
                            "sixteen", "seventeen", "eighteen", "nineteen"};

    vector<string> tens = {"ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};


    for(int i = 0; i < words.size(); i++) {
	// get one, two ...
	for(int j = 0; j < nums.size(); j++) {
	    if(words[i] == nums[j]) {
		toAdd = j+1;
		order = 4;
		break;
	    }
	}
	// get teens ...
	for(int j = 0; j < teens.size(); j++) {
	    if(words[i] == teens[j]) {
		toAdd = 10 + (j+1);
		order = 4;
		break;
	    }
	}
	// get tens ...
	for(int j = 0; j < tens.size(); j++) {
	    if(words[i] == tens[j]) {
		toAdd = 10 * (j+1);
		order = 4;
		break;
	    }
	}
	// check for "n hundred ...
	if(i+1 < words.size()) {
	    q = i+1;
	    while(q < words.size()) {
		if(words[q] == "hundred" && order > 3) {
		    toAdd *= 100;
		    order = 3;
		}
		else if(words[q] == "thousand" && order > 2) {
		    toAdd *= 1000;
		    order = 2;
		}
		else if(words[q] == "million" && order > 1) {
		    toAdd *= 1000000;
		    order = 1;
		} 
		q++;
	    }
	}
    res += toAdd;
    toAdd = 0;
    }

    if(words[0] == "negative")
	res *= -1;

    return res;
}


int main(void) {
    string userIn;
    vector<string> vec;

    cout << "Enter a number in word form: ";
    getline(cin, userIn);

    split(userIn, vec, ' ');

    cout << getInt(vec) << endl;

    return 0;
}
