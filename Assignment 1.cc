#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

void merge(long long arr[], int l, int mid, int r){
    int s1 = mid - l + 1;
    int s2 = r - mid;
    int arr1[s1], arr2[s2];

    for(int i = 0; i < s1; i++){
        arr1[i] = arr[l + i];
    }
    for(int i = 0; i < s2; i++){
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while(i < s1 && j < s2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr[k] = arr2[j];
            k++; 
            j++;
        }
    }
    while(i < s1){
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while(j < s2){
        arr[k] = arr2[j];
        k++;
        j++;
    }
}


void merge_sort(long long arr[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l,mid,r);
    }
}

void msa(long long arr[], int n){
    int l = 0, r = n - 1;
    merge_sort(arr, l, r);
    
}

void heapify(long long arr[], int n, int i){
    int maxidx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[maxidx]){
        maxidx = l;
    }                                                    

    if(r < n && arr[r] > arr[maxidx]){
        maxidx = r;
    }
    if(maxidx != i){
        swap(arr[i], arr[maxidx]);
        heapify(arr, n, maxidx);
    }
}

void heap_sort(long long arr[], int n){
    for(int i = (n / 2) - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void hsa(long long arr[], int n){
    int l = 0, r = n - 1;
    heap_sort(arr, n);
}

int partition(long long arr3[], int low, int high) {
    int pivot = arr3[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr3[j] < pivot) {
            i++;
            swap(arr3[i], arr3[j]);
        }
    }
    swap(arr3[i + 1], arr3[high]);
    return i + 1;
}


void quickSort(long long arr3[], int low, int high) {
    if (low < high) {
        int pi = partition(arr3, low, high); 
        quickSort(arr3, low, pi - 1);  
        quickSort(arr3, pi + 1, high); 
    }
}

void qsa(long long arr3[],int  n){
    quickSort(arr3, 0, n - 1);
}


int main(){
    int n = 100000;
    srand(time(0));
    long long arr[n],arr2[n],arr3[n];
    for(int i = 0; i < n; i++){
        arr[i] = arr2[i] = arr3[i] = rand() % 1000;
    }
    auto start = high_resolution_clock::now();
    msa(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Merge Sort took " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    hsa(arr2, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Heap Sort took " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    qsa(arr3, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Quick Sort took " << duration.count() << " ms\n";
    
}