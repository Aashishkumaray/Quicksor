#include<iostream>
using namespace std;

int partion(int arr[],int si,int ei){
     int pivotElement=arr[si];//taking pivot eelement
     int count=0;
     //find index of pivt element
     for(int i=si+1;i<=ei;i++){
        if(arr[i]<=pivotElement) count++;
     }
     int pivotidx=count+si;
     swap(arr[si],arr[pivotidx]);//postioning pivot at his rihgt ;positiion
    int i=si;
    int j=ei;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}

void QuickSort(int arr[] ,int si,int ei){
    if(si>=ei) return;
    //5,1,8,2,7,6,3,4,-8
    int pivot=partion(arr,si,ei);
    //4 1 3 2 5 7 8 6
    QuickSort(arr,si,pivot-1);
    QuickSort(arr,pivot+1,ei);
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr,0+1,n-2);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}