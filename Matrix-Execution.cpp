#include <iostream>
#include <vector>
#include <chrono>




using namespace std;

// Function to perform matrix addition - Version 1
void matrixVersion1(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to perform matrix addition - Version 2
void matrixVersion2(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    //larger the n_values, the larger memory will take to execute
    vector<int> n_values = { 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200 };

    for (int n : n_values) {
        //initialize integer of matrices A,B, and C
        vector<vector<int>> A(n, vector<int>(n, 1));
        vector<vector<int>> B(n, vector<int>(n, 2));
        vector<vector<int>> C(n, vector<int>(n, 0));

        //calculating the execution time for version 1
        auto start = chrono::high_resolution_clock::now();
        matrixVersion1(A, B, C, n);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "n: " << n << endl;
        cout << "Version 1, Time: " << elapsed.count() << " seconds" << endl;

        // Reset matrix C
        for (int i = 0; i < n; i++) {
            fill(C[i].begin(), C[i].end(), 0);
        }

        //calculating the execution time for version 2
        start = chrono::high_resolution_clock::now();
        matrixVersion2(A, B, C, n);
        finish = chrono::high_resolution_clock::now();
        elapsed = finish - start;
        cout << "Version 2, Time: " << elapsed.count() << " seconds" << endl;
        cout << endl;
    }

    return 0;
}


/*
Output:
n: 100
Version 1, Time: 0.0002708 seconds
Version 2, Time: 0.0002693 seconds

n: 200
Version 1, Time: 0.0010501 seconds
Version 2, Time: 0.0009323 seconds

n: 400
Version 1, Time: 0.0037964 seconds
Version 2, Time: 0.0057719 seconds

n: 800
Version 1, Time: 0.0176688 seconds
Version 2, Time: 0.0227962 seconds

n: 1600
Version 1, Time: 0.0685992 seconds
Version 2, Time: 0.121038 seconds

n: 3200
Version 1, Time: 0.278761 seconds
Version 2, Time: 0.504388 seconds

n: 6400
Version 1, Time: 0.962318 seconds
Version 2, Time: 1.60325 seconds

n: 12800
Version 1, Time: 3.85232 seconds
Version 2, Time: 22.5756 seconds

n: 25600
Version 1, Time: 16.0659 seconds
Version 2, Time: 148.363 seconds

n: 51200
Version 1, Time: 106.973 seconds
Version 2, Time: 709.328 seconds
*/
