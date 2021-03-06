#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
 int tep=*a;
 *a=*b;
 *b=tep;
}
class MinHeap
{
 int* harr;
 int  capacity;
 int  heap_size;
public:
 MinHeap(int);
 void MinHeapify(int);

 int  parent(int i){return (i-1)/2;}
 int  left  (int i){return (2*i+1);}
 int  right (int i){return (2*i+2);}
 
 int  extractMin();
 
 void decreaseKey(int,int);
 int  getMin(){return harr[0];}
 void deleteKey(int);
 void insertKey(int);
};
MinHeap::MinHeap(int cap)
{ 
 capacity=cap;
 harr=new int[cap];
 heap_size=0;
}
void MinHeap::insertKey(int k)
{
 if(heap_size==capacity)
   {
    cout<<"heap day : khong the tren\n";
    return ;
   }
 heap_size++;
 int i=heap_size-1;
 harr[i]=k;
 while(i!=0 &&  harr[parent(i)]>harr[i])
   {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
   }
}
void MinHeap::decreaseKey(int i,int new_val)
{
 harr[i]=new_val;
 while(i!=0 && harr[parent(i)]>harr[i])
   {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
   }
}
int MinHeap::extractMin()
{
 if(heap_size<=0)
  return INT_MAX;
 if(heap_size==1)
  {
   heap_size--;
   return harr[0];
  }
 int root=harr[0];
 harr[0]=harr[heap_size-1];
 heap_size--;
 MinHeapify(0);
 return root;
}
void MinHeap::deleteKey(int i)
{
 decreaseKey(i,INT_MIN);
 extractMin();
}
void MinHeap::MinHeapify(int i)
{
 int l=left(i);
 int r=right(i);
 int smallest=i;
 if(l<heap_size && harr[l] < harr[i])
    smallest=l;
 if(r<heap_size && harr[r] < harr[smallest])
    smallest=r;
 if(smallest != i)
  {
   swap(&harr[i],&harr[smallest]);
   MinHeapify(smallest);
  }
}
int main()
{
MinHeap heap(11);
heap.insertKey(4);
heap.insertKey(-4);
heap.insertKey(43);
heap.insertKey(14);
heap.insertKey(41);
heap.insertKey(42);
heap.insertKey(44);
heap.extractMin();
cout<<heap.getMin()<<endl;
return 0; 
}
