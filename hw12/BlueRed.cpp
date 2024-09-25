#include <iostream>
using namespace std;

const int base = 10;

int find_max(int *arr, int n)
{

    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            arr2[i] = -1 * arr[i];
        else
            arr2[i] = arr[i];
    }
    int maxx = arr2[0];
    for (int i = 1; i < n; i++)
    {
        if (arr2[i] > maxx)
            maxx = arr2[i];
    }
    return maxx;
}

int find_min(int *arr, int n)
{
    int minn = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minn)
            minn = arr[i];
    }
    return minn;
}

void make_zero(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    return;
}

int count_neg(int *arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            res++;
    }
    return res;
}

void counting_sort(int *arr, int n, int exp)
{

    int final[n];
    int count[base];

    make_zero(count, base);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            count[(arr[i] / exp) % base]++;
        }
        else
        {
            count[(-1 * arr[i] / exp) % base]++;
        }
    }
    for (int i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            final[count[(arr[i] / exp) % base] - 1] = arr[i];
            count[(arr[i] / exp) % base]--;
        }
        else
        {
            final[count[(-1 * arr[i] / exp) % base] - 1] = arr[i];
            count[(-1 * arr[i] / exp) % base]--;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = final[i];
    return;
}

void radix_sort(int *arr, int n)
{

    int max_num = find_max(arr, n);

    for (int i = 1; max_num / i > 0; i *= 10)
    {
        counting_sort(arr, n, i);
    }
    int negatives = count_neg(arr, n);
    int arr2[n];
    int ind1 = negatives - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr2[ind1--] = arr[i];
        }
    }
    int ind2 = negatives;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            arr2[ind2++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = arr2[i];
    return;
}

void find()
{
    int n, R = 0, B = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            B++;
        else
            R++;
    }

    int red[R];
    int blue[B];

    int R_ind = 0, B_ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            blue[B_ind++] = arr[i];
        else
            red[R_ind++] = arr[i];
    }

    radix_sort(red, R);
    radix_sort(blue, B);

    for (int i = 0; i < B; i++)
    {
        if (blue[i] < i + 1)
        {
            cout << "NO" << "\n";
            return;
        }
    }
    for (int i = 0; i < R; i++)
    {
        if (red[R - i - 1] > n - i)
        {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        find();
    }
    return 0;
}