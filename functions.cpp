
#include <vector>
#include <iostream>

using std::vector;

vector<double> moranTest(vector<double> x, double **matrix) {
  // double N = weight.n_rows;

  // // first moment
  // double ei = -1/(N - 1);

  // // unitization
  // weight = unitize_C(weight);

  // // Moran's I
  // double W = sum(sum(weight));
  // arma::vec z = x - mean(x);
  // double cv = sum(sum(weight % (z * z.t()))); // weight * (z %o% z)
  // NumericVector zbar = wrap(z); // convert to numeric vector to use power
  // double v = sum(pow(zbar, 2));
  // double obs = (N/W) * (cv/v);

  // // second moment
  // double Wsq = pow(W, 2);
  // double Nsq = pow(N, 2);
  // NumericMatrix wbar = wrap(weight + weight.t());
  // arma::mat wbarbar = pow(wbar, 2);
  // double S1 = 0.5 * sum(sum(wbarbar));
  // arma::vec rs = conv_to<arma::vec>::from(sum(weight, 1));
  // arma::vec cs = conv_to<arma::vec>::from(sum(weight, 0));
  // arma::vec sg =  rs + cs;
  // NumericVector sgbar = wrap(sg);
  // arma::vec sbarbar = pow(sgbar, 2);
  // double S2 = sum(sbarbar); //sg^2
  // arma::vec zbarbar = pow(zbar, 4);
  // double S3 = (sum(zbarbar)/N)/pow(v/N, 2);
  // double S4 = (Nsq - 3*N + 3)*S1 - N*S2 + 3*Wsq;
  // double S5 = (Nsq - N)*S1 - 2*N*S2 + 6*Wsq;
  // double ei2 = (N*S4 - S3*S5)/((N - 1)*(N - 2)*(N - 3) * Wsq);

  // // standard deviation
  // double sdi = sqrt(ei2 - pow(ei, 2));

  // // return results as vector
  // arma::vec results;
  // results.set_size(3);
  // results.at(0) = obs; // Moran's I
  // results.at(1) = ei; // Expected
  // results.at(2) = sdi; // SD

  vector<double> results;
  results.push_back(1);
  return results;
}

int main() {
  std::cout << "Hello World" << std::endl;
  vector<double> input;
  input.push_back(1.0);
  double **matrix;
  matrix = new double*[10];
  for (int i = 0; i < 5; i++) {
    matrix[i] = new double[10];
  }
  vector<double> results = moranTest(input, matrix);
  std::cout << results.front() << std::endl;
  return 0;
}