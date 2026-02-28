// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  for(auto it = start; it != end; ++it)
  {
    vdata.push_back(*it);
  }

  int sizeThing = (int)vdata.size();
  int lastParent = sizeThing/2 - 1;

  int i = lastParent;
  while(i >= 0)
  {
    int index = i;
    bool keepGoing = true;

    while(keepGoing == true)
    {
      int leftIndex = 2*index + 1;
      int rightIndex = 2*index + 2;

      int smallestIndex = index;

      if(leftIndex < sizeThing)
      {
        if(vdata[leftIndex] < vdata[smallestIndex])
        {
          smallestIndex = leftIndex;
        }
      }

      if(rightIndex < sizeThing)
      {
        if(vdata[rightIndex] < vdata[smallestIndex])
        {
          smallestIndex = rightIndex;
        }
      }

      if(smallestIndex == index)
      {
        keepGoing = false;
      }
      else
      {
        int temp = vdata[index];
        vdata[index] = vdata[smallestIndex];
        vdata[smallestIndex] = temp;

        index = smallestIndex;
      }
    }

    i = i - 1;
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int curIndex = (int)vdata.size() - 1;
  while(true)
  {
    if(curIndex == 0) break;

    int parentIndex = (curIndex - 1) / 2;

    if(vdata[parentIndex] <= vdata[curIndex])
    {
      break;
    }
    else
    {
      int t = vdata[parentIndex];
      vdata[parentIndex] = vdata[curIndex];
      vdata[curIndex] = t;

      curIndex = parentIndex;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop()
{
    if(vdata.size() == 0)
    {
        return;
    }

    if(vdata.size() == 1)
    {
        vdata.pop_back();
        return;
    }

    int last = (int)vdata.size() - 1;
    int tmp = vdata[0];
    vdata[0] = vdata[last];
    vdata[last] = tmp;

    vdata.pop_back();

    int n = (int)vdata.size();
    int idx = 0;

    while(true)
    {
        int l = 2*idx + 1;
        int r = 2*idx + 2;

        int minPos = idx;
        if(l < n)
        {
            if(vdata[l] < vdata[minPos])
            {
                minPos = l;
            }
        }

        if(r < n)
        {
            if(vdata[r] < vdata[minPos])
            {
                minPos = r;
            }
        }

        if(minPos == idx)
        {
            break;
        }
        else
        {
            int tt = vdata[idx];
            vdata[idx] = vdata[minPos];
            vdata[minPos] = tt;

            idx = minPos;
        }
    }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0) return true;
  return false;
}
    