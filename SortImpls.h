/**
 * Description: header file for SortIMpls
 * Author: @Shubham Kamboj 
 * Created: November 22 2020 
 * */

#ifndef SortImpls_H
#define SortImpls_H

using namespace std;

class SortImpls{
    public: 

    //swap method that takes in two pointers and then swaps them 
    void swap1(int *one, int *two){
        int temp = *one;
        *one = *two;
        *two = temp;
    }

    //takes in two integers and returns the minimum of them 
    int min(int x, int y){
        if(x < y){
            return x;
        }
        return y;
    }

    //this method puts all the values greater than the pivot to the right of 
    //it and less than to the left
    int pivot(vector<int>& myVec, int l, int h){  
        int pivot = myVec[h];   //pivot point 
        int i = (l - 1); 
  
        for (int k = l; k <= h - 1; k++){   
            if (myVec[k] < pivot){
                i++;   
                swap1(&myVec[i], &myVec[k]);  
            }  
        }  
        swap1(&myVec[i + 1], &myVec[h]);  
        return (i + 1);  
    }

    //method for merging the two arrays in their apporpiate order      
    void merge(vector<int>& myVec, int left, int middle, int right){
        int length1 = middle - left + 1;
        int length2 = right - middle;
 
        int Left[length1], Right[length2]; //temp arrays 
 
        for (int x = 0; x < length1; x++){ //populating array1
             Left[x] = myVec[left + x];
        }
         for (int y = 0; y < length2; y++){ //populating array2
            Right[y] = myVec[middle + 1 + y];
         }
 

        int i = 0;
 
        int x = 0;
 
        int y = left;
 
        while (i < length1 && x < length2) {
            if (Left[i] <= Right[x]) {
                myVec[y] = Left[i];
                i++;
            }else{
                myVec[y] = Right[x];
                x++;
            }
            y++;
        }
 
        while (i < length1) {
            myVec[y] = Left[i];
            i++;
            y++;
        }
 
        while (x < length2) {
            myVec[y] = Right[x];
            x++;
            y++;
        }
    }
    
    //compares every value to all the other values in the array and places
    //in ascending order- bubble sort
    void BubbleSort(vector<int>& myVec, int size){
        for(int i = 0; i < size - 1; i ++){
            for(int j = 0 ; j < size - i -1; j ++){
                if(myVec[j] > myVec[j + 1]){
                    swap1(&myVec[j],&myVec[j+1]);
                }
            }
        }
    }

    //insertion sort which has a key and compares all the elements and 
    //moves accordingly - insertion sort 
    void InsertionSort(vector<int>& myVec, int size){
        int key;
        int x;
        for(int i = 1; i < size; i ++){
           key = myVec[i];
           x = i - 1;

           while(x >=0 && myVec[x] > key){
               myVec[x + 1] = myVec[x];
                x = x -1;
           }
           myVec[x + 1] = key;
        }
    }

    //splits up the array into single arrays by recursion and merges 
    //them together in the correct order - mergesort
    void MergeSort(vector<int>& myVec, int left, int right){
        if(left >= right){
            return; 
        }
        int middle = (left + right - 1)/2;
        MergeSort(myVec, left, middle);
        MergeSort(myVec, middle + 1, right);
        merge(myVec, left, middle, right);
    }

    //mergesort iteratively 
    void IterativeMergeSort(vector<int>& myVec, int size){
        int currentSize;  
                
        int leftSize;
 
        for (currentSize = 1; currentSize <= size-1; currentSize = 2*currentSize){ 
            //splitting the array 
            for (leftSize=0; leftSize< size-1; leftSize += 2*currentSize){
                int middle = min(leftSize + currentSize - 1,size -1 );
 
                int right = min(leftSize + 2*currentSize - 1, size-1);
                merge(myVec, leftSize, middle, right);
            }
        }
    }

    //uses the pivot and arranges the elements accordingly in ascending 
    //order- Quick Sort 
    void QuickSort(vector<int>& myVec, int left, int right){
        if (left < right){  

        int pi = pivot(myVec, left, right);  
  

        QuickSort(myVec, left, pi - 1);  
        QuickSort(myVec, pi + 1, right);  
        }  
    }

    //exchanges two items at any point in the array- Shell sort
    void ShellSort(vector<int>& myVec, int size){
        for (int slot = size/2; slot > 0; slot /= 2){ 
            for (int i = slot; i < size; i += 1){ 

                int temp = myVec[i]; 

                int k;             
                for (k = i; k >= slot && myVec[k - slot] > temp; k -= slot){ 
                    myVec[k] = myVec[k - slot]; 
                }
                myVec[k] = temp; 
            } 
        } 
    }
};
#endif