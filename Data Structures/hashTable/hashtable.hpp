/**
 * Alex Blackwell
 * July 29, 2020
 *
 * Simple implementation of a hashmap taking a pair of a string as the key
 * and an integer as the value.
 * LIMITATIONS:
 *     -> Vector does not use prime numbers
 *     -> Elementary hashing function
 *     -> Hashing function only supports strings as keys
 *
 * ... but hey it's 150 lines...
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>


class Hashtable {
private:
  typedef std::pair<std::string, int> pair;
	int numCols, currMaxRow;
  int allowedMaxRow = 10;
	std::vector<std::vector<pair>> matrix;

	int hash(const std::string & str);
  void rehash(void);
public:
  explicit Hashtable(void);

	void insert(pair p);
  /**
   * Get the value of the associated key.
   * Returns -1 if key not found.
   */
  int get(const std::string & key);

  void remove(const std::string & key);

  void print(void) const;
};


Hashtable::Hashtable(void) :
  numCols{10}, currMaxRow{0}, matrix(10, std::vector<pair>(0))
{  }


int Hashtable::hash(const std::string & str) {
  int hashCode = 0;
  for(size_t i = 0; i < str.size(); ++i)
  	hashCode += str[i];

  hashCode = hashCode % numCols;

  return hashCode;
}


void Hashtable::rehash(void) {
  std::vector<pair> matrixData;

  // deep copy
  for(size_t i = 0; i < matrix.size(); ++i) {
    for(size_t j = 0; j < matrix[i].size(); ++j) {
      matrixData.push_back(matrix[i][j]);
    }
    matrix[i].clear();
  }

  numCols *= 2;
  matrix.resize(numCols);
  currMaxRow = 0;

  for(auto el : matrixData)
    insert(el);

  return;
}


void Hashtable::insert(pair p) {
    int hashCode = hash(p.first);

    // check if it is already in the list and replace it
    size_t i;
    for(i = 0; i < matrix[hashCode].size(); ++i) {
      if(matrix[hashCode][i].first == p.first) {
        matrix[hashCode][i] = p;
        return;
      }
    }
    currMaxRow = std::max(currMaxRow, (int)i);

    matrix[hashCode].push_back(p);

    if(currMaxRow >= allowedMaxRow)
      rehash();  // O(n) but call it exponentially less
}


int Hashtable::get(const std::string & key) {
  int hashCode = hash(key);

  int res = -1;

  for(auto el : matrix[hashCode]) {
    if(el.first == key) {
      res = el.second;
      break;
    }
  }

  return res;
}


void Hashtable::remove(const std::string & key) {
  // dirty remove, does not preserve order
  int hashCode = hash(key);

  for(size_t i = 0; i < matrix[hashCode].size(); ++i) {
    if(matrix[hashCode][i].first == key) {
      int len = matrix[hashCode].size();
      matrix[hashCode][i] = matrix[hashCode][len-1];
      matrix[hashCode].pop_back();
    }
  }

}


void Hashtable::print(void) const {
  using std::cout;
  using std::endl;

  for(auto row : matrix) {
    for(auto col : row) {
      cout << "(" << col.first << ", " << col.second << "), ";
    }
    cout << endl;
  }
}

#endif /* end of include guard: HASHTABLE_H */
