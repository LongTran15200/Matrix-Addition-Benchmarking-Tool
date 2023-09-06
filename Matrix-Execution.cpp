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
