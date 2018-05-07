#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

//this function performs a 3 way partition of the input vector a as follows 
//partition A : contains all elements less than the pivot element
//partition B : contains all elements equal to the pivot element
//partition C : contains all elements more than the pivot element
vector<int> partition3(std::vector<int> &a, int l, int r) { 

//mid and l start from the the leftmost element
int mid = l;
//_result vector stores the starting and ending position of the repeating pivot element a[l]
vector<int> _result(2);
while(mid <= r) {
  if(a[mid] < a[l])  {
    swap(a[mid], a[l]);
    ++l;
    ++mid;
  }else if(a[mid] == a[l]) {
    ++mid;
  }else { 
    swap(a[r], a[mid]);
    --r;
  }
}

_result[0] = l;
_result[1] = mid;

return _result;
}

//this function is a recursive implementation of the randomised quick sort algorithm
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  //select a random pivot
  int k = l + rand() % (r - l + 1);
  //place the pivot in the first index
  swap(a[l], a[k]);
  //p[0] and p[1] contain the first and last indices of the repeating element in its final position
  vector<int> p = partition3(a, l, r);
  //recursive call to sort the first half of the remaining array
  randomized_quick_sort(a, l, p[0]);
  //recursive call to sort second half of the remaining array
  randomized_quick_sort(a, p[1], r);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  //input n integer elements
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //call the randomized_quick_sort function
  randomized_quick_sort(a, 0, a.size() - 1);
  //display the sorted result
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
