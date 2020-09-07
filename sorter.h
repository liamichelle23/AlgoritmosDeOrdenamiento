#ifndef sorter_h
#define sorter_h
#include <stdlib.h>
#include <vector>

using namespace std;

template<typename T>
class Sorter{
    public:
    Sorter(){};
    ~Sorter(){};
    void swap(int i,int j,vector<T>&a){
        T aux=a[i];
        a[i]=a[j];
        a[j]=aux;
    };
    virtual void sort(vector<T> &a) {};
};

template<typename T>
class SelectionSort:public Sorter<T>{
    public:
    SelectionSort(){};
    ~SelectionSort(){};
    void sort(vector<T> &a){
        for (size_t i = 0; i < a.size()-1; i++){
            size_t min=i;
            for (size_t j = i+1; j < a.size(); j++){
                if(a[j] < a[min]){
                    min=j;
                }
            }
            Sorter<T>::swap(i,min,a);
        }
    };
};

template<typename T>
class BubbleSort:public Sorter<T>{
    public:
    BubbleSort() {};
    ~BubbleSort() {};
    void sort(vector<T> &a){
        for (size_t i = 0; i < a.size(); i++){
            bool noSwap= true;
            for (size_t j = 0 ; j < a.size()-i-1; j++){
                if(a[j]>a[j+1]){
                    Sorter<T>::swap(j,j+1,a);
                    noSwap=false;
                }
            }
            if (noSwap){
                break;
            }
        }
    };
};

template<typename T>
class InsertionSort:public Sorter<T>{
    public:
    InsertionSort(){};
    ~InsertionSort(){};
    void sort(vector<T> &a){
        T key;
        for (size_t i = 0; i < a.size(); i++){
            key= a[i];
            int j=i-1;
            while (j>=0 && a[j]>key){
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
        } 
    };
};

template <typename T>
class MergeSort : public Sorter<T>{
    public:
    MergeSort() {};
    ~MergeSort() {};
    void sort(vector<T> &a){
        mergesort(a, 0, a.size()-1);
    };

    void mergesort(vector<T> &a, int left, int right){
        int middle;
        if (left < right){
            middle = left + (right-left) / 2;
            mergesort(a, left, middle);
            mergesort(a, middle+1, right);
            merge(a, left, middle, right);
        }
    };

    void merge(vector<T> &a, int left, int middle, int right){
        int i, j, k; 
        int n1 = middle - left + 1; 
        int n2 = right - middle;
        int I[n1], D[n2]; 

        for (i = 0; i < n1; i++){
            I[i] = a[left + i]; 
            for (j = 0; j < n2; j++){
                D[j] = a[middle + 1 + j]; 
            }
        } 
        i = 0; 
        j = 0; 
        k = left; 
        while (i < n1 && j < n2){  
            if (I[i] <= D[j]){ 
                a[k] = I[i]; 
                i++; 
            } 
            else{ 
                a[k] = D[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < n1){ 
            a[k] = I[i]; 
            i++; 
            k++; 
        } 
        while (j < n2){ 
            a[k] = D[j]; 
            j++; 
            k++;
        } 
    };
};

#endif