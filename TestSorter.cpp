#include <iostream>
#include <vector>
#include <stdlib.h>  
#include <algorithm>
#include "sorter.h"
#include "myTimer.h"
using namespace std;


//En el main, comenté esta función para que se puedan ver los resultados de una vez sin tener que ver 10000 números repetidos
template<typename T>
void PrintVector(vector<T> a, int n){
    for (size_t i = 0; i < a.size() && i<n; i++){
        cout<<a[i]<<",";
    }
    cout<< endl;
}

template <typename T>
void CompareVectors(vector<T> a, vector<T> b, string message = ""){
    cout << message << " ";
    // check if equal
    if (a == b)
        cout << "La implementación es correcta!!" << endl;
    else
        cout << "Hay algún error por aquí :/" << endl;
}


int main(){
    int count=10000;
    vector<int> arr1;
    for (size_t i = 0; i < count; i++){
        arr1.push_back((int)rand()%10000+1);    
    }
    cout<<"Vector desordenado"<<endl;
    //PrintVector(arr1,10000);
    DECLARE_TIMING(t);
    START_TIMING(t);
    sort(arr1.begin(), arr1.end());
    STOP_TIMING(t);
    SHOW_TIMING(t, "sort");
    cout<<"__________________"<<endl;


    vector<int> arr2(arr1);
    vector<int> arr3(arr1);
    vector<int> arr4(arr1);
    vector<int> arr5(arr1);

    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort<int> selsort;
    selsort.sort(arr2);
    //PrintVector(arr2,10000);
    STOP_TIMING(t1);
    CompareVectors(arr1, arr2, "Selection Sort:");
    SHOW_TIMING(t1, "SelectionSort: ");
    cout<<"__________________"<<endl;

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<int> bubble;
    bubble.sort(arr3);
    //PrintVector(arr3,10000);
    STOP_TIMING(t2);
    CompareVectors(arr1, arr3, "Bubble Sort:");
    SHOW_TIMING(t2, "BubbleSort");
 
    cout<<"__________________"<<endl;

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertionSort<int> insetion;
    insetion.sort(arr4);
    //PrintVector(arr4,10000);
    STOP_TIMING(t3);
    CompareVectors(arr1, arr4, "Insertion Sort:");
    SHOW_TIMING(t3, "InsertionSort");

    cout<<"__________________"<<endl;

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<int> merge;
    int arr_size = sizeof(arr5) / sizeof(arr5[0]);
    merge.mergesort(arr5, 0, arr_size - 1);
    //PrintVector(arr5,10000);
    STOP_TIMING(t4);
    CompareVectors(arr1, arr5, "Merge Sort:");
    SHOW_TIMING(t4, "MergeSort");

    cout<<"__________________"<<endl;

    return 0;
}

