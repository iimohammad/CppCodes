#include<iostream>
#include<vector>
#include <iterator>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

set<int> convertToSet(vector<int> v){
    set<int> s;
    for (int x : v) 
        s.insert(x);
    return s;
}
void printSet(set<int> s)
{
    cout << "Set: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
}
void remove(std::vector<int> &v)
{
    std::unordered_set<int> s;
    auto end = std::copy_if(v.begin(), v.end(), v.begin(),
                            [&s](int const &i) {
                                return s.insert(i).second;
                            });
 
    v.erase(end, v.end());
}
std::vector<int> mySort(const std::vector<int> unsorted) {
    vector<int> sorted = unsorted; 
    sort(sorted.begin(), sorted.end()); 
    return sorted;
}

int main(){
	vector<int> v = { 10, 62, 11, 10 , 32, 0 , 5 ,62, 65, 0, 1, 0, 10};
    //First Solution --> time-->O(nlogn) ---> O(n)
    set<int> s = convertToSet(v);
    printSet(s);


    //Second Solution---time--> O(nlog(n)) --- memory---> constant space O(1)
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
 
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << ' ';
    }
    cout <<endl;
        remove(v);
 
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << ' ';
    }



    /*
        if we don't want to use vector and algorithms libraries we have to sort them by quick sort with time O(logn)
        after that remove duplicates by traverse through the array__> total time  -> O(n+nlogn) = O(nlogn) -> O(n)

    */
    
    cout<<endl;
	return 0;
}
