// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) {
            k = k + 1;
            }
        }
    }
    return k;
}
int countPairs2(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; i < j; j--) {
        if (arr[i] + arr[j] == value) {
            k = k + 1;
            }
        }
    }
    return k;
}
int countPairs3(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int first = i, second = len;
        while (first < second - 1) {
            int m = (first + second) / 2;
            if (arr[i] + arr[m] == value) {
                k = k + 1;
                int nm = m + 1;
                while (arr[i] + arr[nm] == value && nm < second) {
                    k = k + 1;
                    nm = nm + 1;
                }
                nm = m - 1;
                while (arr[i] + arr[nm] == value && nm > first) {
                    k = k + 1;
                    nm = nm - 1;
                }
                break;
            }
            if (arr[i] + arr[m] > value) {
                second = m;
            } else {
                first = m;
            }
        }
    }
    return k;
}
