# C and C++ Data Structures and Algorithms

[![Image](./.pictures/intro-card.png)](https://github.com/Alex0Blackwell/c-cpp-DSA)

## Table of contents
* [Overview](#overview)
* [Algorithms](#algorithms)
* [Data Structures](#data-structures)
* [Sorting-Searching](#sorting-searching)

## Overview
This repository is for small C and C++ programs I do outside of my school work. The repository includes data structures and algorithms that I have done for practice.


## Algorithms

#### C programs
<details>
  <summary>Expand C Programs</summary>

  - addingFormattedNums.c
    - print two rows one increasing one decreasing
  - compareArr.c
    - Return -1 if an element of array1 is less than array2, return 1 if an element of array1 is greater than array2, return 0 otherwise
  - factorial.c
    - recursive factorial in c, bad use of recursion but still fun
  - loopPointers
  - randNum.c
    - seeding random numbers
  - reverse.c
    - reverse an array in place
  - reverseStr.c
    - reverse string
  - squareCalc.c
    - return the square of a number with just addition
    - inductive assert
  - textAnim.c
    - terminal text animation

</details>

#### C++ Programs

<details>
  <summary>Expand C++ Programs</summary>

  - **macm-formulas**
    - forumlas used in MACM *including:*
      - combinations
      - permutations
      - combinations with repetition
      - dearangements
  - anagramCheck.cpp
    - determine two words are anagrams for eachother
    - Leetcode problem [here](https://leetcode.com/problems/valid-anagram/)
  - GKSRoundAq1.cpp
    - my solution for Google Kick Start round A, question 1
  - GKSRoundAq2.cpp
    - my solution for Google Kick Start round A, question 2
  - GKSRoundCq1.cpp
    - my solution for Google Kick Start round C, question 1
  - barPblm.cpp
    - algorithm practice
  - barPblm2.cpp
    - more direct solution
  - binaryLLtoInt.cpp
    - Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
    - Leetcode problem [here](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
  - bracketCheck.cpp
    - check for valid brackets using a stack
  - calcE.cpp
    - calculate Eulers number using a taylor series
  - employee.cpp
    - class practice
  - definedAsBad.cpp
    - a program rewritten with #Define
  - destinationCity.cpp
    - You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
    - Leetcode problem [here](https://leetcode.com/problems/destination-city/)
  - fibonacci.cpp
    - four ways of making the fibonacci sequence
    - naive recursive, memoized recursive, sequenctial and sequential
  - getMinimum.cpp
    - recursively return the minimum element of a vector
    - generic programming using templates
  - kWeakestRows.cpp
    - Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.
  - macmFindNum.cpp
    - find a number such that abc = a! + b! + c!
  - maxProductInArr.cpp
    - Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)\*(nums[j]-1).
    - Leetcode problem found [here](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)
  - multiplyWithAdd.cpp
    - multiplication using only addition
  - numOfBSTs.cpp
    - number of BST's that can be made with a given number
  - proveEvenNums.cpp
    - induction proof for printing even numbers
  - removeAdjacentDups.cpp
    - Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them. We repeatedly make duplicate removals on S until we no longer can.
    - Leetcode problem found [here](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
  - reverseCharOnly.cpp
    - reverse only the characters in the string
    - Leetcode problem found [here](https://leetcode.com/problems/reverse-only-letters/)
  - reverseStr.cpp
  - romanToDecimal.cpp
    - given roman numerals, return a decimal number
  - strReverseInP.cpp
    - reverse string in place
  - toLowerCase.cpp
    - Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
  - word2num.cpp
    - given a word (two thousand five hundred and one) a number is returned (2501)

</details>

## Data Structures

#### C Programs
<details>
  <summary>Expand C Data Structures</summary>

  - linkedList.c
    - first implementation of linked list

</details>

#### C++ Programs
<details>
  <summary>Expand C++ Data Structures</summary>

  - **Binary Search Tree**
  	- ***Methods include***
  		- insert
  		- delete
  		- get the minimum value
  		- print inorder
  		- print preorder
  		- print postorder
  		- print in descending order
  		- return the kth smallest number in the tree
  		- return the kth largest number in the tree
  		- search
  		- return BST of lowest common ancestor
  		- return the least depth from the root
  		- print the tree level by level
  - **Singly Linked List**
  	- ***Methods include***
  		- get value at front
  		- get value at back
  		- get the size
  		- get value at index *([])*
  		- append
  		- pop
  		- insert at an index
  		- clear
  		- assign lists *(=)*
  		- concatinate lists *(+)*
  - **Queue**
  	- ***Methods include***
  		- check if empty
  		- get the size of the Queue
  		- get the value at the front
  		- get the value at the back
  		- clear the Queue
  		- push to the back *O(1)*
  		- pop from the front *O(1)*
  		- assign Queue *(=)*
  		- print the Queue
  - **Red Black Binary Tree Hash Table**
    - ***Methods include***
      - assign one tree to another with the overloaded assignment operator *O(n)*
      - insertion *O(log(n))*
      - removal *O(log(n))*
      - search *O(log(n))*
      - search and return a vector of all the values of the keys within two given key values *O(log(n))*
      - return a vector of all the values in ascending order *O(n)*
      - return a vector of all the keys in ascending order *O(n)*
      - return the number of nodes in the tree *O(1)*
      - print the keys and values in ascending order for debugging *O(n)*
  - **Stack**
  	- ***Methods include***
  		- check if empty
  		- get the size of the Stack
  		- get the value at the top
  		- clear the Stack
  		- push to the Stack *O(1)*
  		- pop from the Stack *O(1)*
  		- assign Stack *(=)*
  		- print the Stack
  - **Double Ended Queue**
  	- ***Methods include***
  		- insert at the front
  		- insert at the back
  		- remove from the front
  		- remove from the back
  		- peek at the front
  		- peek at the back
  		- check if it's empty
  		- get the size
  		- copy one Deque into another
  		- deallocate all the Nodes
  		- print the Deque
  		- *Note that this program uses templates so it works for all types :)*
  - **Binary Heap**
    - ***Methods Include***
      - check if empty *O(1)*
      - get the minimum element *O(1)*
      - insert *O(log(n))*
      - delete the minimum element *O(log(n))*
      - make the heap empty *O(1)*
      - *Note that this program uses templates so it works for all types :)*

</details>

## Sorting-Searching

#### C Programs

<details>
  <summary>Expand C Sorting-Searching</summary>

  - binarySearch.c
    - first implementation of a binary search (those were the days)
  - binarySearch2.c
    - second implementation of a binary search
  - binarySearchCP.cpp
    - HackerEarth problem found [here](https://www.hackerearth.com/practice/algorithms/searching/binary-search/tutorial/)
  - bubbleSort.c
    - everyone loves bubbles
  - insertionSort.c
    - linearSearch.c
  - mergesort.c
    - first implementation of merge sort
  - quicksort.c
    - first implementaion of quick sort
  - selectionSort.c

</details>

#### C++ Programs

<details>
  <summary>Expand C++ Sorting-Searching</summary>

  - mergeSort.cpp
  - reverseMerge.cpp
    - sort in descending order  
  - *binSearch-mergeSort*
    - **Binary Search and Merge Sort**
      - Binary and Merge sort with generics programming
  - *quicksort*
    - **Quicksort with median-of-three pivot**
      - This Quicksort uses a median-of-three pivot. This means that the pivot is chosen by sorting the first element, the last and the middle element, and taking the median. This method ensures that the worst case O(n^2) becomes exponentially unlikely.
      - An insertion sort is used for subarrays of size 10 or less. This is because the insertion sort is more optimal for very small arrays.

</details>

## License
Licensed under the [MIT License](LICENSE).
