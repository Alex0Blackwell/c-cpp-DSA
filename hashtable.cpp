#include <iostream>
#include <string>
#include <list>

using namespace std;


class Hashtable {
    private:
	int numElements;
	list <string> *data;
    public:
	Hashtable(int numEl) {
	    numElements = numEl;
	    data = new list<string> [numEl];
	}
	int hash(string str);
	void insert(string str);
	void printList(ostream &out);
};

int Hashtable::hash(string str) {
    int hashCode = 0;
    for(int i = 0; i < str.size(); i++) {
	hashCode += str[i];
    }
    hashCode = hashCode % 10;  // because array size 10
    return hashCode;
}

void Hashtable::insert(string str) {
    int hashCode = hash(str);
    data[hashCode].push_back(str);
}

void Hashtable::printList(ostream &out = cout) {
    for(int i = 0; i < numElements; i++) {
	for(auto x : data[i]) {
	    out << " -->" << x;
	}
	out << endl;
    }
}

ostream & operator<< (ostream &out, Hashtable &hsh) {
    hsh.printList(out);
    return out;
}


int main(void) {
    Hashtable table1(5);  // let's give it 5 elements

    table1.insert("Alex");
    table1.insert("Alexandra");
    table1.insert("Alexandra");
    table1.insert("post malone");
    table1.insert("Alex");
    table1.insert("Coyote Petterson");

    cout << table1;


    

    return 0;
}
