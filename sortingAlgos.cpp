//#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) (x).begin(),(x).end()
#define forn(i, n) for (int i=0; i<n;++ i)
#define forlr(i, l, r) for (int i=l; i<=r; ++i)
#define forrl(i, r, l) for (int i=r; i>=l; --i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


bool checkSortedOrder(vi& vec);
ll selectionSort(vi& vec);
ll insertionSort(vi& vec);
ll shellSort(vi& vec);
ll mergeSort(vi& vec);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    auto start = high_resolution_clock::now(), stop = high_resolution_clock::now();
    vi arr, arrBase;
    ll time;
    ll comparisons;
    int minNum = 1<<7, maxNum = 1<<17;

//    cout << "Test 1 (random array)" << endl;
    freopen("randomArrays.csv", "w", stdout);
    cout << "numElements,selectionSortTime,selectionSortComperes,insertionSortTime,insertionSortComperes,shellSortTime,shellSortComperes,mergeSortTime,mergeSortComperes\n";
    for (int num = minNum; num<=maxNum; num<<=1) {
//        cout << "\nNum of elements : " << num << endl;
        cout << num;
        arrBase.resize(num);
        forn(i, num) {
            arrBase[i] = i;
        }
        auto rng = default_random_engine {};
        const int numExp = 5;
        vvi arraysBase(numExp);
        forn(i, numExp) {
            shuffle(all(arrBase), rng);
            arraysBase[i] = arrBase;
        }

//        cout << "Selection Sort  : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += selectionSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Insertion Sort  : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += insertionSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;
        cout << "," << (double)time/1000000 << "," <<  comparisons;

//        cout << "Shell Sort      : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += shellSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;
        cout << "," << (double)time/1000000 << "," <<  comparisons;

//        cout << "Merge Sort      : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += mergeSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;
        cout << "," << (double)time/1000000 << "," <<  comparisons;

        cout << endl;
    }
//    cout << "======================================\n\n";

//    cout << "Test 2 (sorted array)" << endl;
    freopen("sortedArrays.csv", "w", stdout);
    cout << "numElements,selectionSortTime,selectionSortComperes,insertionSortTime,insertionSortComperes,shellSortTime,shellSortComperes,mergeSortTime,mergeSortComperes\n";
    for (int num = minNum; num<=maxNum; num<<=1) {
//        cout << "\nNum of elements : " << num << endl;
        cout << num;
        arrBase.resize(num);
        forn(i, num) {
            arrBase[i] = i;
        }

//        cout << "Selection Sort  : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = selectionSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Insertion Sort  : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = insertionSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Shell Sort      : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = shellSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Merge Sort      : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = mergeSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

        cout << endl;
    }
//    cout << "======================================\n\n";

//    cout << "Test 3 (reversed array)" << endl;
    freopen("reversedArrays.csv", "w", stdout);
    cout << "numElements,selectionSortTime,selectionSortComperes,insertionSortTime,insertionSortComperes,shellSortTime,shellSortComperes,mergeSortTime,mergeSortComperes\n";
    for (int num = minNum; num<=maxNum; num<<=1) {
//        cout << "\nNum of elements  : " << num << endl;
        cout << num;
        arrBase.resize(num);
        forn(i, num) {
            arrBase[i] = i;
        }
        reverse(all(arrBase));

//        cout << "Selection Sort  : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = selectionSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Insertion Sort  : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = insertionSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Shell Sort      : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = shellSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Merge Sort      : ";
        arr = arrBase;
        start = high_resolution_clock::now();
        comparisons = mergeSort(arr);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start).count();
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

        cout << endl;
    }
//    cout << "======================================\n\n";

//    cout << "Test 4 (random array of 1,2 and 3)" << endl;
    freopen("randomArrays123.csv", "w", stdout);
    cout << "numElements,selectionSortTime,selectionSortComperes,insertionSortTime,insertionSortComperes,shellSortTime,shellSortComperes,mergeSortTime,mergeSortComperes\n";
    for (int num = minNum; num<=maxNum; num<<=1) {
//        cout << "\nNum of elements : " << num << endl;
        cout << num;
        const int numExp = 3;
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> uni(1,3);
        vvi arraysBase(numExp, vi(num));
        forn(i, numExp) {
            forn(j, num) {
                arraysBase[i][j] = uni(rng);
            }
        }

//        cout << "Selection Sort  : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += selectionSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Insertion Sort  : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += insertionSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Shell Sort      : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += shellSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

//        cout << "Merge Sort      : ";
        comparisons = 0ll;
        time = 0;
        forn(i, numExp) {
            arr = arraysBase[i];
            start = high_resolution_clock::now();
            comparisons += mergeSort(arr);
            stop = high_resolution_clock::now();
            time += duration_cast<microseconds>(stop - start).count();
        }
        time /= numExp;
        comparisons /= numExp;
        cout << "," << (double)time/1000000 << "," <<  comparisons;
//        cout << (double)time/1000000 << "s\t" <<  comparisons << "comp" << endl;

        cout << endl;
    }
//    cout << "======================================\n";

    return 0;
}


bool checkSortedOrder(vi& vec) {
    const int nMax = vec.size()-1;
    forn(i, nMax) {
        if (vec[i] > vec[i+1])
            return false;
    }
    return true;
}

ll selectionSort(vi& vec) {
    ll comparisons = 0ll;
    const int n = vec.size();
    vec.push_back(INT_MAX);
    forrl(i, n-2, 0) {
        int pos = i;
        while (vec[pos] > vec[pos+1]) {
            ++comparisons;
            swap(vec[pos], vec[pos+1]);
            ++pos;
        }
        ++comparisons;
    }
    vec.pop_back();
    return comparisons;
}

ll insertionSort(vi& vec) {
    ll comparisons = 0ll;
    const int nMax = vec.size()-1;
    forlr(i, 0, nMax) {
        int pos = i;
        forlr(j, i+1, nMax) {
            if (vec[pos] > vec[j]) {
                pos = j;
            }
            ++comparisons;
        }
        swap(vec[pos], vec[i]);
    }
    return comparisons;
}

ll shellSort(vi& vec) {
    ll comparisons = 0ll;
    const int n = vec.size();
    int gep = n >> 1;
    while (gep) {
        int i=0, j = gep;
        while (j<n) {
            int x = i, y = j;
            while (x>=0 && vec[x] > vec[y]) {
                swap(vec[x], vec[y]);
                y = x;
                x -= gep;
                ++comparisons;
            }
            ++comparisons;
            ++i;
            ++j;
        }
        gep >>= 1;
    }
    return comparisons;
}

ll mergeSort(vi& vec) {
    ll comparisons = 0ll;
    const int n = vec.size();
    int mergeSize = 1;
    vi left((n>>1) + 1), right((n>>1) + 1);
    while (mergeSize < n) {
        int l = 0;
        while (l < n) {
            int r = min(n-1, l + (mergeSize<<1)-1);
            int m = l + mergeSize-1;
            int i;

            // start merging
            for (i=l; i<=m; ++i) {
                left[i-l] = vec[i];
            }
            left[i-l] = INT_MAX;
            for (i=m+1; i<=r; ++i) {
                right[i-(m+1)] = vec[i];
            }
            right[i-(m+1)] = INT_MAX;
            i=l;
            int iL=0, iR=0;
            while (i<=r) {
                ++comparisons;
                if (left[iL] < right[iR]) {
                    vec[i++] = left[iL++];
                } else {
                    vec[i++] = right[iR++];
                }
            }
            // end merging

            l += mergeSize<<1;
        }

        mergeSize <<= 1;
    }
    return comparisons;
}
