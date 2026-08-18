#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 0, 3, 1, 7, 0};
    int n = 6;

    int count0 = 0, count1 = 0, count2 = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int i = 0;

    while (count0 > 0) {
        arr[i] = 0;
        i++;
        count0--;
    }


    while (count1 > 0) {
        arr[i] = 1;
        i++;
        count1--;
    }


    while (count2 > 0) {
        arr[i] = 2;
        i++;
        count2--;
    }


    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }

    return 0;
}
