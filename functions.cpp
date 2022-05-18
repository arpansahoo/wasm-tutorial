
#include <emscripten.h>
#include <numeric>

double* mean_centered(double x[], int n) {
  double mean = std::accumulate(x, x + n, 0);
  mean /= n;

  double *z = new double[n];
  for (int i = 0; i < n; i++) {
    z[i] = x[i] - mean;
  }
  return z;
}

EMSCRIPTEN_KEEPALIVE
int arpan_fib(int x) {
  if (x < 1)
    return 0;
  if (x == 1)
    return 1;
  return arpan_fib(x-1)+arpan_fib(x-2);
}

EMSCRIPTEN_KEEPALIVE
double* moranTest(double x[5], double weight[25]) {
  // double N = weight.n_rows;
  double N = 5;

  // Moran's I
  double W = std::accumulate(weight, weight + 25, 0);
  double *z = mean_centered(x, 5);

  double cv = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cv += weight[i * 5 + j] * z[i] * z[j];
    }
  }

  double v = 0;
  for (int i = 0; i < 5; i++) {
    v += z[i] * z[i];
  }

  double obs = (N / W) * (cv / v);

  // return results as vector
  double *results = new double[10];
  results[0] = obs; // Moran's I
  return results;
}

int main() {
  return 0;
}


// 1,1,1,0,0
// 1,1,1,0,0
// 1,1,1,0,0
// 0,0,0,0,0
// 0,0,0,0,0

// 50,50,50,5,5,5 (high Moran's I)
// 50,5,5,50,5,50 (lower Moran's I)