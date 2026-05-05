#include <algorithm> 
using namespace std;
template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
     while (i > 0) {
        int p = parent(i);

        if (data[i] < data[p]) {
            swap(data[i], data[p]);
            i = p;
        } else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int n = size();
    while (true) {

        int smallest = i;
        int l = left(i);
        int r = right(i);
        if (l < n && data[l] < data[smallest])
            smallest = l;

        if (r < n && data[r] < data[smallest])
            smallest = r;

        if (smallest != i) {
            swap(data[i], data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
     data.push_back(value);
     siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
     if (size() == 0)
        throw runtime_error("Heap is empty");

    T rootValue = data[0];

    data[0] = data.back();
    data.pop_back();

    if (size() > 0)
        siftDown(0);

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    if (index < size()) {
        siftUp(index);
        siftDown(index);
    }
}
