#include<bits/stdc++.h>
using namespace std;

class heap
{
    public:
      int arr[100];
      int size;
      
      heap()
      {
          size = 0;
          arr[0]=-1;
      }
      
      void insert(int val)
      {
          size++;
          arr[size]=val;
          int index = size;
          while(index>1){
              int parent = index/2;
              if(arr[index]>arr[parent]){
                  swap(arr[index],arr[parent]);
                  index=parent;
              }
              else{
                  return;
              }
          }
      }
      void print()
      {
          for(int i=1;i<=size;i++){
              cout<<arr[i]<<" ";
          }
          cout<<endl;
      }
      
      void deletefromheap()
      {    if(size==0){
          cout<<"NO pos"<<endl;
          return;
      }
          
          arr[1]=arr[size];
          size--;
          int i= 1;
          
          while(i<size){
           int leftInd=2*i;
      int rightInd=2*i+1;
     /* Modification - 1 */
      if(leftInd<=size && arr[i]<arr[leftInd] && arr[leftInd]>arr[rightInd]){
        swap(arr[i], arr[leftInd]);
        i=leftInd;
      }
      /* Modification - 2 */
      else if(rightInd<=size && arr[i]<arr[rightInd] && arr[rightInd]>arr[leftInd]){
        swap(arr[i], arr[rightInd]);
        i=rightInd;
      }else{
        return;
      }
          }
      }
};
//max heap
void heapify(int arr[],int n,int i)
{   
  
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
//min heap
/*#include <bits/stdc++.h> 
void heapify(vector<int>& arr,int n,int i){
       int small = i;
       int left = 2*i+1;
       int right = 2*i+2;
       if(left<n && arr[small]>arr[left]){
           small = left;
       }
       if(right<n && arr[small]>arr[right]){
           small = right;
       }
       if(small!=i){
           swap(arr[i],arr[small]);
           heapify(arr,n,small);
       }
       return;
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2;i>=0;i--){
         heapify(arr,n,i);
    }
    // Write your code here
    return arr;
}
*/
void heapsort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
    return;
}
int main()
{   heap h;
    h.insert(34);
    h.insert(873);
    h.insert(21);
    h.insert(34);
    h.insert(1);
    h.insert(7342);
    h.insert(5);
  //  h.print();
    h.deletefromheap();
  //  h.print();
    h.deletefromheap();
   // h.print();
   int arr[8]={-1,4,3,1,7,10,6,2};
   int n=7;
   for(int i=n/2;i>0;i--){
       heapify(arr,n,i);
   }
  for(int i=1;i<=n;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   heapsort(arr,7);
   for(int i=1;i<=n;i++){
       cout<<arr[i]<<" ";
   }
   
}