#include <iostream>
#include <vector>

using namespace std;

class DynamicArrayList {
private:
    vector<int> arr;

public:
    DynamicArrayList(int size) {
        arr.resize(size);
    }

    void SetValue(int index, int value) {
        if (index >= 0 && index < arr.size()) {
            arr[index] = value;
        }
        else {
            cout << "Index out of range!" << endl;
        }
    }

    int GetValue(int index) {
        if (index >= 0 && index < arr.size()) {
            return arr[index];
        }
        else {
            cout << "Index out of range!" << endl;
            return -1; // Return -1 as an error indicator
        }
    }

    void DisplayArray() {
        cout << "Array: ";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Merge(int low, int mid, int high) 
    {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                cout << "\a"; // Play beep sound for each swap
                DisplayArray(); // Display array after each swap
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= high) {
            temp[k++] = arr[j++];
        }
        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    void MergeSort(int low, int high) 
    {
        if (low < high) {
            int mid = (low + high) / 2;
            MergeSort(low, mid);
            MergeSort(mid + 1, high);
            Merge(low, mid, high);
        }
    }
};

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    DynamicArrayList sortArray(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        sortArray.SetValue(i, value);
    }

    sortArray.MergeSort(0, n - 1);

    cout << "Sorted ";
    sortArray.DisplayArray();

    return 0;
}