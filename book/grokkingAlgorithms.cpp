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


//////////////////
// get graph
std::map< std::string, std::vector<std::string> > getMyGraph() {
    std::map<std::string, std::vector<std::string>> myGraph;
    myGraph["CAB"] = { "CAR", "CAT" };
    myGraph["CAR"] = { "CAT", "BAR" };
    myGraph["BAR"] = { "BAT" };
    myGraph["CAT"] = { "MAT", "BAT" };
    myGraph["MAT"] = { "BAT" };
    
    return myGraph;
}

// check whether current edge is destination or not
bool isDestination(std::string curVertex) {
    if (curVertex == "BAT") {
        return true;
    }
    return false;
}

bool isChecked(vector<string> &list, string curVertex) {
    for (vector<string>::iterator iter = list.begin(); iter != list.end(); ++iter) {
        if (curVertex == *iter) {
            return true;
        }
    }
    return false;
}

void pushQueue(std::queue<std::string> &myQueue, std::vector<std::string> curVertex) {
    cout << "Push Queue: "; 
    for (int i = 0; i < curVertex.size(); i++) {
        cout << curVertex[i] << ' ';
        myQueue.push(curVertex[i]);
    }   
    cout << '\n';
}

bool searchShortestPath() {
    std::map<std::string, std::vector<std::string>> myGraph = getMyGraph();
    std::queue<std::string> myQueue;
    std::vector<std::string> checked;
    
    pushQueue(myQueue, myGraph["CAB"]);
    checked.push_back("CAB");
    // 현재 queue 에는 "CAT", "CAR" 이 들어있다. 
    while (myQueue.size() > 0) {
        std::string curVertex = myQueue.front(); myQueue.pop();
        cout << "current Vertex: " << curVertex << '\n';
        
        if (!isChecked(checked, curVertex)) {
            if (isDestination(curVertex)) {
                cout << "Destination: " << curVertex << '\n';
                return true;
            } else {
                pushQueue(myQueue, myGraph[curVertex]);
                checked.push_back(curVertex);
            }   
        }
    }
    return false;
}

TEST_CASE( "BFS", "[searchShortestPath]" ) {
    cout << endl;
    REQUIRE (searchShortestPath() == true);
}

///////// Dynamic Programming
// Knapsack problem

#define GUITAR 0    // GUITAR   weight: 1,  $: 1500
#define STEREO 1    // STEREO   weight: 4,  $: 3000
#define NOTEBOOK 2  // NOTEBOOK weight: 3,  $: 2000

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int knapsackProblem() {
    
    // create GRID for Dynamic Programming
    //      1      2      3      4
    //    --------------------------
    // G | 1500   1500   1500   1500
    // S | 1500   1500   1500   3000
    // N | 1500   1500   2000   3500
    //
    // 4g의 백팩에서 3g의 노트북을 넣을때, 1g만큼 남는데, 이미 1g의 최대값을 그 전에 구했다.
    //
    // cell[i][j]의 최대값: 1. 지금까지 구한 cell[i-1][j]의 값 중에서 가장 최대값
    //                      2. 현재 물건의 가치 + 남은 공간의 가치(cell[i-1][j-물건의 무게]
    
    std::vector<std::vector<int>> grid(100, std::vector<int>(100, 0));
    std::vector<int> weight = { 0, 1, 4, 3 };
    std::vector<int> price = { 0, 1500, 3000, 2000 };
    
    for (int i = 1; i <= 3; i++) {
       for (int w = 1; w <= 4; w++) {
           if (w < weight[i]) {
               grid[i][w] = grid[i-1][w];
           } else {
               grid[i][w] = max(grid[i-1][w], price[i] + grid[i-1][w-weight[i]]);
           }
       }
    }
    
    // print
    for (int i = 1; i < 4; i++) {
        for (int j = 1 ; j < 5; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return grid[3][4];
}

TEST_CASE( "knapsackProblem", "[knapsackProblem]" ) {
    cout << endl;
    REQUIRE (knapsackProblem() == 3500);
}