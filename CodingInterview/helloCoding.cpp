#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

template<typename T>
void pop_front(std::vector<T>& vec)
{
   vec.front() = vec.back();
   vec.pop_back();
}


// recursive
void countDown(int i) {
    cout << i << ' ';
    if (i <= 1) {
        cout << '\n';
        return;
    } else {
        countDown(i-1);
    }
}

int factorial(int x) {
    if (x == 1) {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

int findSmallestIdx(vector<int> &arr) {
    int idx = 0;
    int small = arr[idx];
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < small) {
            small = arr[i];
            idx = i;
        }
    }
    
    return idx;
}

vector<int> selectionSort(vector<int> arr) {
    vector<int> sortArr;
    int smallIdx = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        smallIdx = findSmallestIdx(arr);
        sortArr.push_back(arr[smallIdx]);
        arr.erase(arr.begin() + smallIdx);
    }
    
    return sortArr;
}
/*
TEST_CASE( "Simple Selection Sort", "[selectionSort]" ) {
    vector<int> test = { 5, 1, 2, 4, 3 };
    vector<int> expected = { 1, 2, 3, 4, 5 };
    vector<int> result = selectionSort(test);
    
    for (int i = 0; i < result.size(); i++) {
        REQUIRE( expected[i] == result[i] );
    }
}
*/



int binarySearch(vector<int> list, int value) {
    int low = 0;
    int high = list.size()-1;
    int mid, guess = 0;
    
    while (low <= high) {
        mid = (low + high) / 2;
        guess = list[mid];
        
        if (guess > value)
            high = mid - 1;
        if (guess < value)
            low = mid + 1;
        
        if (guess == value) 
            return mid;
    }
    
    return -1;
}

/*
TEST_CASE( "Simple Binary Search", "[binary_search]" ) {
    vector<int> test = { 1, 3, 5, 7, 9 };
    
    int value = 3;
    REQUIRE( binarySearch(test, value) == 1 );
    
    value = 1;
    REQUIRE( binarySearch(test, value) == 0 );
    
    value = 9;
    REQUIRE( binarySearch(test, value) == 4 );
    
    value = -3;
    REQUIRE( binarySearch(test, value) == -1 );
}
*/

int basicSum(vector<int>& arr) {
    int total = 0;
    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
        total += (*iter);
    }
    return total;
}

int recursiveSum(vector<int>& arr) {
    int total = 0;
    
    if (arr.size() == 0) {
        return 0;
    } else {
        total += arr[0];
        pop_front(arr);
    }
    
    return total + recursiveSum(arr);
}

TEST_CASE( "Basic Sum", "[basic_sum]" ) {
    vector<int> testArr = { 1, 3, 5, 7, 9 };
    REQUIRE (basicSum(testArr) == 25);
    REQUIRE (recursiveSum(testArr) == 25);
}

// graph
map<string, vector<string>> getGraph() {
    map<string, vector<string>> graph;
    graph["you"] = { "alice", "bob", "claire" };
    graph["bob"] = { "anju", "peggy" };
    graph["alice"] = { "peggy" };
    graph["claire"] = { "thom", "jonny" };
    graph["anju"] = { };
    graph["peggy"] = { };
    graph["thom"] = { };
    graph["jonny"] = { };
    
    return graph;
}

bool isMangoSeller(string name) {
    if (name == "thom")
        return true;
        
    return false;
}

bool isSearched(vector<string> &list, string name) {
    for (vector<string>::iterator iter = list.begin(); iter != list.end(); ++iter) {
        if (name == *iter) {
            return true;
        }
    }
    return false;
}

void pushStrVector(queue<string> &searchQueue, vector<string> list) {
    for (int i = 0; i < list.size(); i++) {
        searchQueue.push(list[i]);
    }
}

bool searchMangoSeller(string name) {
    cout << "start searchMangoSeller" << endl;
    
    map<string, vector<string>> graph = getGraph();
    queue<string> searchQueue;
    vector<string> searched;
    string person;
    
    // insert "YOU"
    pushStrVector(searchQueue, graph[name]);
    
    while (searchQueue.size() > 0) {
        person = searchQueue.front();
        searchQueue.pop();
        
        if (!isSearched(searched, person)) {
            if (isMangoSeller(person)) {
                cout << "We found Mango Seller: " << person << endl;
                return true;
            } else {
                pushStrVector(searchQueue, graph[person]);
                // insert searched
                searched.push_back(person);
            }
        }
    }
    return false;
}

TEST_CASE( "Graph", "[searchMangoSeller]" ) {
    REQUIRE (searchMangoSeller("you") == true);
}
