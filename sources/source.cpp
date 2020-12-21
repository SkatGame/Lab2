// Copyright 2020 Your Name <your_email>
//
//#include "header.hpp"

// 128Kb<1Mb<2Mb<4Mb<8Mb<9Mb cache1 = 256Kb; cache2 = 1Mb; cache3 = 6Mb
//vector<double> cache {0.125,1,2,4,8,9};
// 1 = 128Kb
//vector<int[]> Arrs (int arr1[], int arr2[], int arr3[], int arr4[], int arr5[], int arr6[]);
//
//void First() {
//  vector<double> cache;
//  vector<double> sizeCashe{256, 6144};
//  double sizeCacheMinMb = (sizeCashe[0] / 2048);
//  double sizeCacheMaxMb = (sizeCashe[1] / 1024) * 1.5;
//  cache.push_back(sizeCacheMinMb);
//  int j = 0;
//  int k = 0;
//  while(k < 8){
//    k = pow(2,j);
//    cache.push_back(k);
//    j++;
//  }
//  cache.push_back(sizeCacheMaxMb);
//
//  for( int i = 0; i < 6; ++i){
//    cout << cache[i] << " ";
//  }
//
//  vector<double> size = cache;
//
//  vector<vector<int>> arrBig;
//
//  for(int i = 0; i < 6; i++)
//    size[i] *= 262144;
//
//
//  for (int i = 0; i < 6; ++i){
//    int * arr = new int [size[i]];
//  }
//
//}
//
//vector<vector<int>> arr;
//
//






//
//void Second(int k) {
//  int* arr1 = new int[32];
//  for (int i = 0; i < 32; i += 16)  // прогрев
//    k = arr1[i];
//
//  int t = clock();
//  for (int i = 0; i < 32; i += 16)  // чтение
//    k = arr1[i];
//
//  cout << clock() - t << endl;
//}

//vector<int> cacheMinMax {2};
//vector<int> sizeCashe {256, 6144};
//
//void Size(){
//  int j = 0;
//  while (sizeCashe[1] % 2 == 0) {
//    sizeCashe[1] /= 2;
//    j++;
//  }
//  cacheMinMax.emplace_back(1);
//  cacheMinMax.emplace_back();
//}
//
//void Cache() {
//
//}
//void Arr() {
//  for (size_t i = 0; i < cache.size(); ++i) {
//    int* Arrs[] = new int[cache[i] * 128 * 1024 / 4];
//  }
//}
//int * arr1 = new int [32768];
//int * arr2 = new int[262144];
//int * arr3 = new int[524288];
//int * arr4 = new int[1048576];
//int * arr5 = new int[2097152];
//int * arr6 = new int[2359296];

//int * arr1 = new int [size[0]];