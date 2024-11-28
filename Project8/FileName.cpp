#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int n = 7;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 21 - 10;
    }

    cout << "Масив: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto min_abs_iter = min_element(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });
    int min_abs_idx = distance(arr.begin(), min_abs_iter);
    cout << "Номер мінімального за модулем елемента: " << min_abs_idx << endl;

    int sum_after_negative = 0;
    bool found_negative = false;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < 0 && !found_negative)
        {
            found_negative = true;
        }
        if (found_negative)
        {
            sum_after_negative += abs(arr[i]);
        }
    }
    cout << "Сума модулів елементів після першого від’ємного: " << sum_after_negative << endl;

    arr.erase(remove_if(arr.begin(), arr.end(), [](int x) { return abs(x) <= 1; }), arr.end());

  
    size_t original_size = n; 
    arr.resize(original_size, 0); 

    // Виведення стиснутого масиву
    cout << "Масив після стискання: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

