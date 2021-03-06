/*
Kth Smallest Element
Problem Description

Find the Bth smallest element in given array A .

NOTE: Users should try to solve it in <= B swaps.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= min(|A|, 500)

1 <= A[i] <= 109



Input Format
First argument is vector A.

Second argument is integer B.



Output Format
Return the Bth smallest element in given array.



Example Input
Input 1:

A = [2, 1, 4, 3, 2]
B = 3
Input 2:

A = [1, 2]
B = 2


Example Output
Output 1:

 2
Output 2:

 2


Example Explanation
Explanation 1:

 3rd element after sorting is 2.
Explanation 2:

 2nd element after sorting is 2.


*/

int Solution::kthsmallest(const vector<int> &A, int B) {

    // vector<int> c;
    // for(auto x : A){
    //     c.push_back(x);
    // }

    // sort(c.begin(), c.end());

    // return c[B - 1];

    // The expected 0(n^2) solution :

    vector<int> a;
    a = A;
    int n = (int)a.size();

    for (int i = 0; i < B; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[minIndex] > a[j]) {
                minIndex = j;
            }
        }

        swap(a[minIndex], a[i]);
    }


    return a[B - 1];

}



