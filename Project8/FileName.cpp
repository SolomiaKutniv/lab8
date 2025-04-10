#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    srand(time(0));
    int n = 7;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 100-50;
    }

    cout << "Масив: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> abs_arr(n);
    for (int i = 0; i < n; ++i)
    {
        abs_arr[i] = abs(arr[i]);
    }

    auto miniter = min_element(abs_arr.begin(), abs_arr.end());
    int minidx = distance(abs_arr.begin(), miniter);
    cout << "Мінімальний по модулю елемент: " << arr[minidx] << endl;


    int sum = 0;
    bool found_negative = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0 && !found_negative)
        {
            found_negative = true;
        }
        else if (found_negative)
        {
            sum += abs(arr[i]);
        }
    }
    cout << "Сума модулів елементів після першого від’ємного: " << sum << endl;

    int a = 2, b = 15;

    auto it = partition(arr.begin(), arr.end(), [a, b](int x) 
        {
        return x < a || x > b;  
        });

    fill(it, arr.end(), 0);

    cout << "Масив після стискання: ";
    for (size_t i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
