static inline int getMax( int ar[], const int size ) {

  int max = ar[0];
  for (int i = 1; i < size; ++i) {
    if (ar[i] > max) max = ar[i];
  }

  return max;
}

static inline void countSort( int ar[], const int size, const int exp ) {

  int output[100000];
  int count[10] = { 0 };

  for (int i = 0; i < size; ++i) {
    ++count[(ar[i] / exp) % 10];
  }
  for (int i = 0; i < 10; ++i) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i > -1; --i) {
    output[--count[(ar[i] / exp) % 10]] = ar[i];
  }

  for (int i = 0; i < size; ++i) {
    ar[i] = output[i];
  }
}

static inline void radixSort( int ar[], const int size ) {

  int max = getMax( ar, size );

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSort( ar, size, exp );
  }
}



void sortF( int ar[], const int size ) {
  radixSort(ar, size);
}