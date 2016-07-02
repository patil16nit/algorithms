#include<iostream>


using namespace std;

class MaxPQ {
  int capacity;
  int heap_size;
  int *harray;
  public:
    MaxPQ(int cap);
    void insertKey(int k);
    int parent(int pos) { return (pos-1)/2; }
    int left(int pos) { return  2*pos+1;}
    int right(int pos) { return 2*pos+2;}
    void maxHeapify(int pos);
    void buildMaxHeap(int pos);
    void printHeap() {
      cout<<"Heap-> ";
      for(int i=0;i<heap_size;i++) {
        cout<<harray[i]<<" ";
      }
      cout<<endl;
    }
};


MaxPQ::MaxPQ(int cap) {
  capacity = cap;
  heap_size = 0;
  harray = new int[cap];
}

void MaxPQ::insertKey(int k) {
  if (capacity == heap_size) {
    cout<<"Overflow"<<endl;
    return;
  }
  heap_size++;
  int i = heap_size-1;
  harray[i] = k;
}


void MaxPQ::maxHeapify(int pos) {
  int large;
  int l = left(pos);
  int r = right(pos);
  if (l<heap_size && harray[l]> harray[pos]) {
    large = l;
  } else { large = pos;}
  if (r< heap_size && harray[r] > harray[large]) {
    large = r;
  }

  if (large != pos) {
    swap(harray[large],harray[pos]);
    this->maxHeapify(large);
  }
}


void MaxPQ::buildMaxHeap(int pos) {
  for (int i=heap_size/2-1; i>=0;i--) {
    maxHeapify(i);
    printHeap();
  }
}


int main() {
  MaxPQ maxpq(10); 
  maxpq.insertKey(4);
  maxpq.insertKey(1);
  maxpq.insertKey(3);
  maxpq.insertKey(2);
  maxpq.insertKey(16);
  maxpq.insertKey(9);
  maxpq.insertKey(10);
  maxpq.insertKey(14);
  maxpq.insertKey(8);
  maxpq.insertKey(7);
  maxpq.printHeap();
  maxpq.buildMaxHeap(0);
  maxpq.printHeap();
  return 0;
}
