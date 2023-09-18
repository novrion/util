static inline void swap( int& a, int& b ) {
  const int temp = a;
  a = b;
  b = temp;
}

static inline int partition( int ar[], const int lo, const int hi ) {

  const int p = ar[hi];
  int pi = lo - 1;

  for (int i = lo; i < hi; ++i) {
    if (ar[i] <= p) swap( ar[++pi], ar[i] );
  }
  swap( ar[++pi], ar[hi] );


  return pi;
}

static inline void quickSort( int ar[], const int lo, const int hi ) {

  if (lo >= hi) return;

  const int pi = partition( ar, lo, hi );

  quickSort( ar, lo, pi - 1 );
  quickSort( ar, pi + 1, hi );
}



void sortF( int ar[], const int size ) {
  quickSort(ar, 0, size - 1);
}