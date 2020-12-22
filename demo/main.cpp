#include <header.hpp>
#include <random>
//128Kb<1Mb<2Mb<4Mb<8Mb<9Mb

inline void Heating (int* arr, int& h,const double& buffer) {
  for (unsigned int i = 1; i < buffer + 1; i += st)  // прогрев
    h = arr[i];
}

int main() {
  vector<double> cache;
  vector<unsigned int> buffer = GeneratorVector(cache);
  Print(buffer);
}

vector<unsigned int> GeneratorVector(vector<double>& cache){
  double sizeCacheMinMb = 0.125;
  double sizeCacheMaxMb = 9;
  cache.push_back(sizeCacheMinMb);
  int j = 0;
  int k = 0;
  while (k < sizeCacheMaxMb) {
    k = pow(2, j);
    cache.push_back(k);
    j++;
  }
  cache.pop_back();
  cache.push_back(sizeCacheMaxMb);
  cout << "Vector experimentSizes: {";
  for (int i = 0; i < 6; ++i) {
    cout << cache[i] << " ";
  }
  cout << "}" << endl;
  vector<unsigned int> buffer(cache.size());
  for (double i = 0; i < cache.size(); ++i)
    buffer[i] = cache[i] * 262144;
  return  buffer;
}

  void StraightExperiment(const vector<unsigned int>& buffer, ostream& ss) {
    for (double z = 0; z < buffer.size(); ++z) {
      auto* arr = new int[buffer[z]];

      [[maybe_unused]] int h = 0;

      Heating(arr,h,buffer[z]);

      auto start = std::chrono::high_resolution_clock::now();

      for (int hi = 0; hi < th; ++hi) {
        for (unsigned int i = 0; i < buffer[z]; i += st)  // чтение
          h = arr[i];
      }
      auto end = std::chrono::high_resolution_clock::now();
      ss << static_cast<int>(
          std::chrono::nanoseconds((end - start) / th).count())
         << " ns ";
    }
  }

  void BackExperiment(const vector<unsigned int>& buffer, ostream& ss) {
    for (double z = 0; z < buffer.size(); ++z) {
      auto* arr = new int[buffer[z] + 1];

      [[maybe_unused]] int h = 0;

      Heating(arr,h,buffer[z]);

      auto start = std::chrono::high_resolution_clock::now();

      for (int hi = 0; hi < th; ++hi) {
        for (unsigned int i = buffer[z]; i >= 1; i -= st)  // чтение
          h = arr[i];
      }

      auto end = std::chrono::high_resolution_clock::now();
      ss << static_cast<int>(
          std::chrono::nanoseconds((end - start) / th).count())
         << " ns ";
    }
  }

  void RandomExperiment(const vector<unsigned int>& buffer, ostream& ss) {
    for (double z = 0; z < buffer.size(); ++z) {
      auto* arr = new int[buffer[z]];
      vector<int> size;
      vector<int>::iterator start, end;

      for (unsigned int i = 0; i < buffer[z]; i += st) size.emplace_back(i);
      start = size.begin();
      end = size.end();
      shuffle(start, end, std::mt19937(std::random_device()()));

      [[maybe_unused]] int h = 0;

      Heating(arr,h,buffer[z]);

      auto startTime = std::chrono::high_resolution_clock::now();

      for (int hi = 0; hi < th; ++hi) {
        for (unsigned int i = 0; i < (buffer[z] / st); ++i)  // чтение
          h = arr[size[i]];
      }

      auto endTime = std::chrono::high_resolution_clock::now();
      string print;
      ss << static_cast<int>(
                 std::chrono::nanoseconds((endTime - startTime) / th).count())
          << " ns ";
    }
  }

  void Print(const vector<unsigned int>& buffer) {
    cout << R"(investigation:
    travel_variant: StraightExperiment
    experiments:
    number: 1
    input_data:
    buffer_size: 0.125Mb, 1Mb, 2Mb, 4Mb, 8Mb, 9Mb
    results:
    duration: )";
    StraightExperiment(buffer, cout);
    cout << endl
         << R"(investigation:
    travel_variant: BackExperiment
    experiments:
    number: 2
    input_data:
    buffer_size: 0.125Mb, 1Mb, 2Mb, 4Mb, 8Mb, 9Mb
    results:
    duration: )";
    BackExperiment(buffer, cout);
    cout << endl
         << R"(investigation:
    travel_variant: RandomExperiment
    experiments:
    number: 3
    input_data:
    buffer_size: 0.125Mb, 1Mb, 2Mb, 4Mb, 8Mb, 9Mb
    results:
    duration: )";
    RandomExperiment(buffer, cout);
  }
