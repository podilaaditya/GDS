#include "../inc/GdsNodes.h"


template <typename nodeDataClass> NodeOfTree<nodeDataClass>::NodeOfTree(nodeDataClass arr[], int s)
{
    //ptr = new T[s];
    mSize = s;
    for (int i = 0; i < mSize; i++){
        ptrNodeArray[i] = new NodeOfTree();
        ptrNodeArray[i]->mData = arr[i];
    }
}

template <typename nodeDataClass> NodeOfTree<nodeDataClass>::NodeOfTree(nodeDataClass aValue){
    mSize = 2; // default size is 2 , 
    mData = aValue;
}


template <typename nodeDataClass> NodeOfTree<nodeDataClass>::NodeOfTree(int aSize){
       mSize = aSize; // we make the default tree as Binary Search Tree; 
       ptrNodeArray = std::make_unique<int[]>(aSize);
}


template <typename nodeDataClass>  void NodeOfTree<nodeDataClass>::getData(nodeDataClass *ptr) {
    ptr = &mData;
}
