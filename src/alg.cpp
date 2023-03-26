// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; i++) {
      if (arr[i] + arr[j] == value) {
        k += 1;
      }
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
        }
    }
    return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
        int left = i;
        int right = len;
        while (left < right - 1) {
            int middle = (left + right) / 2;
            if (arr[i] + arr[middle] == value) {
                k += 1;
                int newmiddle = middle + 1;
                while (arr[i] + arr[newmiddle] == value && newmiddle < right) {
                    k += 1;
                    newmiddle += 1;
                }
                newmiddle = middle - 1;
                while (arr[i] + arr[newmiddle] == value && newmiddle > left) {
                    k += 1;
                    newmiddle -= 1;
                }
                break;
            }
            if (arr[i] + arr[middle] > value) {
                right = middle;
            } else {
                left = middle;
            }
        }
    }
    return k;
}
