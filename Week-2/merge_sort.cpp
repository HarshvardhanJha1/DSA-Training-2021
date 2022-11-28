#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int low, int high) {
    if(low>=high)
        return;
    int mid = low + (high-low)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], M[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[i+low];
    
    for(int i=0;i<n2;i++)
        M[i]=arr[i+mid+1];

    int i=0,j=0,k=low;

    while(i < n1 and j < n2) {
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k]=M[j];
        j++;
        k++;
    }


}



int main(int argc, char const *argv[])
{
    int arr[5] = {2,3,4,5,1};
    for(auto it: arr)
        cout<<it<<" ";
    cout<<endl;
    merge_sort(arr, 0, 4);
    for(auto it: arr)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}
