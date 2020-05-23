#include<iostream>

int main()
//sumata na chisla pod dvata diagonala koito sa prosti

{
  const int n = 100;
  unsigned int matrix[n][n];
  int size = 0;
  //  std::cout << "size : " ;
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      // std::cout << "matrix["<<i<<"]["<<j<<"]= ";
      std::cin >> matrix[i][j];
    }
  }


  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (i + j >= size) {
        unsigned int number = matrix[i][j];
        int counter = 0;

        if (number != 1) {
          for (int k = 1; k <= number; k++) {
            counter += (number % k == 0) ? 1 : 0;
          }
          if (counter == 2) {
            sum += number;
          }

        } else {
          sum++;
        }
      }
    }
  }

  std::cout << sum << std::endl;


  return 0;
}
