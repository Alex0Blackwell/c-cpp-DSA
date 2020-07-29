/**
 * Simple implementation of a hashmap taking a pair of a string as the key
 * and an integer as the value.
 * This hashmap suffers from primary clustering.
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>


class Hashtable {
private:
  typedef std::pair<std::string, int> pair;
	int size;
	std::vector<std::vector<pair>> matrix;

	int hash(const std::string & str);
public:
  explicit Hashtable(void);

	void insert(pair p);
  /**
   * Get the value of the associated key.
   * Returns -1 if key not found.
   */
  int get(const std::string & key);
};


Hashtable::Hashtable(void) :
  size{0}, matrix(11)
{  }


int Hashtable::hash(const std::string & str) {
  int hashCode = 0;
  for(size_t i = 0; i < str.size(); ++i)
  	hashCode += str[i];

  hashCode = hashCode % 11;  // because matrix size 11

  return hashCode;
}


void Hashtable::insert(pair p) {
    int hashCode = hash(p.first);

    // check if it is already in the list and replace it
    for(size_t i = 0; i < matrix[hashCode].size(); ++i) {
      if(matrix[hashCode][i].first == p.first) {
        matrix[hashCode][i] = p;
        return;
      }
    }
    matrix[hashCode].push_back(p);
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


#endif /* end of include guard: HASHTABLE_H */
