#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H
#include <cmath>
#include <fstream>

using namespace std;

namespace MyLibrary
{
    // Linear Search
    void linearsearch(int arr[], int n, int key)
    {
        bool found = false;
        int index = 0;
        for (int i = 0; i < n; ++i)
        {

            if (arr[i] == key)
            {
                found = true;
                index = i;
            }
            else
            {
                found = false;
            }
        }
        if (found)
        {
            cout << "Found at index : " << index << endl;
        }
        else
        {
            cout << "value not found" << endl;
        }
    }
    // binary search
    void binarysearch(int arr[], int size, int key)
    {
        int high = size - 1;
        int low = 0;
        bool found = false;
        int index = -1; 

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                found = true;
                index = mid;
                break;
            }

            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (found)
        {
            cout << "Key found at index: " << index << endl;
        }
        else
        {
            cout << "Value not found" << endl;
        }
    }
    
    //Jump Search
    int JumpSearch(int array[], int n, int key){
    	int start=0;
		int end=sqrt(n);
	
		while(array[end]<key&&start<n){
			start=end;
			end=end+sqrt(n);
			if(end>n-1){
				end=n;
			}
		}
		
		int index=0;
		for(int i=start; i<end; i++){
			if(array[i]==key){
				index=i;
				cout<<"Key found at index: "<<index<<endl;
				return i;
			}
		
		}
            cout<<"Value not found";
			return -1;
	}
	
	//Shell Sort
	void ShellSort(int array[], int n){
		cout<<"Shell Sort: ";
		for(int gap=n/2; gap>0; gap/=2){
			for(int i=gap; i<n; i++){
				int temp=array[i];
				int j;
				for(j=i; j>=gap && array[j-gap]>temp; j-=gap){
					array[j]=array[j-gap];
				}
				array[j]=temp;
			}
		}
	}
	
	//Bubble Sort
	void Bubble_sort(int array[], int size){
	cout<<endl<<"Bubble Sort: ";	
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    }
    
    //Selection Sort
    void Selection_sort(int array[], int size){
    cout<<endl<<"Selection Sort: ";	
    for(int i=0; i<size-1; i++){
        int min=i;
        for(int j=i+1; j<size; j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=array[min];
            array[min]=array[i];
            array[i]=temp;
        }
    }
    }
    
    //Insertion Sort
    void insertion_sort(int array[], int size){
    cout<<endl<<"Insertion Sort: ";	
    for(int i=1; i<size-1; i++){
        int key=array[i];
        int j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
            
        }
        array[j+1]=key;
    }
    }
    
    //Quick Sort
    int Quick(int array[], int low, int high){
    	
    int pivot=array[high];
    int i=low-1;
    for(int j=low; j<=high; j++){
        if(array[j]<pivot){
            i++;
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    int temp2=array[i+1];
    array[i+1]=array[high];
    array[high]=temp2;
    return(i+1);
 
   }

    void QuickSort(int array[], int low, int high){
    	
    if(low<high){
        int pi=Quick(array, low, high);
        QuickSort(array, low, pi-1);
        QuickSort(array, pi+1, high);
    }
    
   }
   
   //Merge Sort
   void merge(int array[], int begin, int mid, int end){
   
    int i=begin;   //starting index for left subarray
    int j=mid+1;   //starting index for right subarray
    int k=begin;   //starting index for temp array
    
    int size=(end-begin)+1;
    int temp[size];
    
    while(i<=mid && j<=end){
        if(array[i]<=array[j]){
            temp[k]=array[i];  //array[i] is smaller than array[j]
            i++;
            k++;
        } 
        else{
            temp[k]=array[j];  //array[j] is smaller than array[i]
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=array[i];  //copying all elements from left subarray to temp as it is 
        i++;
        k++;
    }
    while(j<=end){
        temp[k]=array[j];  //copying all elements from right subarray to temp as it is
        j++;
        k++;
    }
    
    for(int n=begin; n<=end; n++){
        array[n]=temp[n];
    }
    	
   }
    void mergeSort(int array[], int begin, int end){
  	
    if(begin<end){
        int mid=(begin+end)/2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid+1, end);
        merge(array, begin, mid, end);
    }
   }
   
   //Heapify
   void heapify(int array[], int size, int i){
     int root=i;
	 int left=2*i+1;
	 int right=2*i+2;
	 
	 if(left<size&&array[left]>array[root]){
	 	root=left;
	 }
	 if(right<size&&array[right]>array[root]){
	 	root=right;
	 }
	 if(root!=i){
	 	int temp=array[i];
	 	array[i]=array[root];
	 	array[root]=temp;
	 	heapify(array,size,root);
	 } 	
}

   //Heap Sort
   void heapsort(int array[], int size){
   	cout<<endl<<"Heap Sort: ";
	for(int i=size/2-1; i>=0; i--){
		heapify(array, size, i);
	}
	for(int i=size-1; i>=0; i--){
		int temp=array[0];
		array[0]=array[i];
		array[i]=temp;
		heapify(array, i, 0);
	}
    
}

    //Print Array
    void PrintArray(int array[], int size){
    	for(int i=0; i<size; i++){
    		cout<<array[i]<<" ";
		}
	}

    //LinkList
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val)  {
         data = val ;
         next = NULL;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = NULL;
    }


    void insertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtPosition(T data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            throw out_of_range("Position out of range");
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

   void writeToFile(const string& filename) const {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        throw ios_base::failure("Failed to open file for writing");
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        outFile << temp->data << " ";
        temp = temp->next;
    }
    outFile << endl; 
    outFile.close();
}


    void readFromFile(const string& filename) {
     ifstream inFile(filename);
    if (!inFile) {
        throw ios_base::failure("Failed to open file for reading");
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
}

#endif
