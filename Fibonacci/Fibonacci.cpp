#include <iostream>



void fibonacci(int prev1, int prev2, int numberRun) {

	if (numberRun++ > 25) return;

	std::cout << prev1 << std::endl;


	fibonacci(prev2, prev1 + prev2, numberRun);

}

int main() {

	fibonacci(0, 1, 0);


	return 0;
}
