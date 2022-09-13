#include <bits/stdc++.h>
using namespace std;

/**
 * Insertion sort
 * 1d and 2d
 * */

void insertionSort1d(int arr[], int n){
    int i, temp, j;
    for (i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void insertionSort2d(int matrix[5][5], int rows, int cols) {
    int i, j, k;

    int min_val = matrix[0][0];
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            if(matrix[i][j] < min_val)
                min_val = matrix[i][j];

    for(k = 0; k < rows; k++){
    	for(i = 1; i < rows * cols; i++) { // rows * col = total value in 2d array
		int tmp_value = matrix[k][i];
            // limit in the loop
		    for(j = i; j >= 1 && tmp_value >= min_val && matrix[k][j-1] > tmp_value; j--)
			    matrix[k][j] = matrix[k][j-1];
		    matrix[k][j] = tmp_value;

            if(tmp_value < min_val)
                break;
        }
    }
}

int main(){
    // 1d
    int arr[] = { 12,4,3,1,15,45,33,21,10,2};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout<<"UnSorted 1d Array: ";
    for(int i = 0; i < N; i++){
        cout <<arr[i]<<", ";
    }
    cout << endl;

    insertionSort1d(arr, N);

    cout<<"Sorted 1d Array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << ", ";
    cout << endl;

    // 2d
    int matrix[5][5] = {{ 22, 23, 10, 9, 5},
                            { 15, 25, 13, 11, 21},
                            { 20, 74, 67, 9, 5},
                            { 11, 18, 14, 31, 12},
                            { 51, 1, 2, 24, 20 }};

    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    cout<<"\nUnSorted 2d Array: "<<endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // method 1
//    for (int i = 0; i < rows; i++){
//        for (int j = 0; j < cols; j++){
//            for (int inside_i = i; inside_i < rows; inside_i++){
//                for (int inside_j = j; inside_j < cols; inside_j++){
//                    if (matrix[i][j] > matrix[inside_i][inside_j]){
//                        swap(matrix[i][j], matrix[inside_i][inside_j]);
//                    }
//                }
//            }
//        }
//    }

    // method 2
    insertionSort2d(matrix, rows, cols);

    cout<<"\nSorted 2d Array: "<<endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

