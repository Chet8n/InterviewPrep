/*
Next Greater Element
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider next greater element as -1. 

Examples: 

For an array, the rightmost element always has the next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.
For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.  

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1


*/


vector<int> Solution::nextGreater(vector<int> &a) {
   
   /**

    - getting the next greater element from thr array
    - [1 3 5 2 6 8 3 9]
    - [3 5 6 6 8 9 9 -1] --> ans for the above
    - Algorithm
    - keep adding elements to the stack and when you find an
      element greater than the s.top(), remove all elements from s
      untill s.top() > cur_element
    - for the all the elements removed cur_element is the next greater element

    **/
    
    int n = a.size();
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() and a[s.top()] < a[i]) {
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }
    
    return ans;
}
