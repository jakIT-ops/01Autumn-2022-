#include <iostream>
#include <algorithm>

using namespace std;

//// ============== Utility functions ======================
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

void resetArr(int array[], int len){
    for(int r= 0; r<len; r++)
        array[r]=rand()%10;
}

//// ====================== Sorting algorithms ===========================
void bubbleSort(int array[], int size) {
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
       while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// RADIX SORT
void countingSort(int array[], int size, int place) {
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i) count[i] = 0;
    for (int i = 0; i < size; i++)count[(array[i] / place) % 10]++;
    for (int i = 1; i < max; i++) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++) array[i] = output[i];
}
void radixsort(int array[], int size) {
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10) countingSort(array, size, place);
}

// QUICK SORT
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
// MERGE SORT
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]){
    int i = 0, j = 0, k = 0;
    while(i < n1) arr3[k++] = arr1[i++];
    while(j < n2) arr3[k++] = arr2[j++];
    sort(arr3, arr3+n1+n2);
}

// Heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

///// ================= Searching algorithms ============================

int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) return mid;
        if (array[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (array[i] == x) return i;
    return -1;
}

// Tree
// Binary heap
class MinHeap {
    int *harr;
    int capacity; // maximum possible size of min heap
    int heap_size; // current number of elements in min heap
public:
    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return harr[0]; }
    void deleteKey(int i);
    void insertKey(int k);
};

MinHeap::MinHeap(int capacity) {
    heap_size = 0;
    capacity = capacity;
    harr = new int[capacity];
}

void MinHeap::insertKey(int k){
    if (heap_size == capacity){
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// binary heap impl
void binHeapImpl(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
}

int main() {
    int arr[] = { 12,4,3,1,15,45,33,21,10,2};
    int arr1[] = {};
    int resArr[] = {};
    int searchElement, option, res, len, len1;
    bool isNotFinished = true;

    do {
        cout << "================================SORTING AND SEARCHING ALGORITHMS ======================="<<endl;
        cout << " Massiv- iin urtiig oruulna uu: ";
        cin >> len;
        resetArr(arr, len);
        len = sizeof(arr) / sizeof(arr[0]);
        cout << "Elementvvd :"<<endl;
        printArray(arr, len);
        cout<<"------------------------"<<endl;
        cout<<"Sorting algorithms"<<endl;
        cout<<"1 - bubbleSort: "<<endl;
        cout<<"2 - selectionSort: "<<endl;
        cout<<"3 - insertionSort: "<<endl;
        cout<<"4 - radixSort: "<<endl;
        cout<<"5 - quickSort: "<<endl;
        cout<<"6 - mergeSort: "<<endl;
        cout<<"Searching algorithms: "<<endl;
        cout<<"7 - linear search: "<<endl;
        cout<<"8 - binary search: "<<endl;
        cout<<"Namelt algorithmuud: "<<endl;
        cout<<"9 - heap sort "<<endl;
        cout<<"Songoltoo oruulna uu: "<<endl;
        cin>>option;
        switch(option){
            case 1:
                bubbleSort(arr, len);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(arr, len);
                break;
            case 2:
                selectionSort(arr, len);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(arr, len);
                break;
            case 3:
                insertionSort(arr, len);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(arr, len);
                break;
            case 4:
                radixsort(arr, len);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(arr, len);
                break;
            case 5:
                quickSort(arr,0, len-1);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(arr, len);
                break;
            case 6:
                cout << "Hoyr dohi massiviin urtiig oruulna uu: "<<endl;
                cin>>len1;
                resetArr(arr1, len1);
                resArr[len + len1];
                mergeArrays(arr, arr1, len, len1, resArr);
                cout<<"Erembalsanii daraah"<<endl;
                printArray(resArr, len + len1);
                break;
            case 7:
                cout<<"Haih elmentee oruulna uu"<<endl;
                cin>>searchElement;
                res = linearSearch(arr, len, searchElement);
                res == -1 ? cout<<"Element oldsongvi!" : cout<<"Amjilttai oldlooo: "<<res;
                break;
            case 8:
                cout<<"Haig elementee oruulna uu: "<<endl;
                cin>>searchElement;
                res = linearSearch(arr, len, searchElement);
                binarySearch(arr, len/2, 0, len - 1);
                res == -1 ? cout<<"Element oldsongvi!" : cout<<"Amjilttai oldloo: "<<res;
                break;
            case 9:
                heapSort(arr, len);
                cout<<"Erembelsenii daraah"<<endl;
                printArray(arr, len);
                break;
            default:
                isNotFinished = false;
        }
    }while(isNotFinished);
}



