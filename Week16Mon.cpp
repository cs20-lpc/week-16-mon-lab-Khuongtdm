#include <iostream>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr) {
    MinHeap<T> h;

    // TODO: Insert all elements into heap using sift-down insert from lecture

    // TODO: Repeatedly remove root and store back into array
    for (const T& element : arr) {
        h.insert(element);
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = h.removeRoot();
    }
    
}
template <typename T>
void printHeap(const MinHeap<T>& heap) {
    const auto& arr = heap.getArray();
    cout << "Heap Array: [ ";
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    try {
        MinHeap<int> mh;

        cout << "--- Testing Insertion ---" << endl;
        vector<int> values = { 10, 5, 20, 2, 15, 30 };
        for (int v : values) {
            cout << "Inserting: " << v << endl;
            mh.insert(v);
        }
        printHeap(mh); // Root should be 2

        cout << "\nTesting removeRoot" << endl;
        while (!mh.empty()) {
            cout << "Removed Root: " << mh.removeRoot() << " | ";
            printHeap(mh);
        }

        cout << "\n Testing removeAt" << endl;
        mh.insert(40);
        mh.insert(10);
        mh.insert(30);
        mh.insert(5);
        printHeap(mh);

        cout << "\nRemoving element at index 1" << endl;
        mh.removeAt(1);
        printHeap(mh);

        cout << "\nTesting Exception Handling" << endl;
        mh.removeRoot(); // Clear heap
        mh.removeRoot();
        mh.removeRoot();
        mh.removeRoot(); // This should trigger error

    }
    catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    cout << "Sorting section to test\n";
    vector<int> arr = { 5, 1, 9, 3, 7, 4 };
    cout << "Before sort\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    heapsort(arr);
    cout << "after sort\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
