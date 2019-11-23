//Ryan Mauricio
//Triple X
//11/23/19

#include <iostream>
#include <ctime>

const int MAX = 9;
const int TRIES = 3;

bool checkArr(int* arr, int n) {
	int guess;
	int guessNum = n + 1;
	std::cout << "\n Enter guess " << ": ";
	std::cin >> guess;

	if (n == 2) {
		std::cout << "   Correct. Lock has been picked.\n";
		return true;
	}

	if (guess == arr[n]) {
		std::cout << "   Correct.";
		return checkArr(arr, n + 1);
	}
	else {
		std::cout << "   Incorrect. \n";
		return false;
	}
}

int game(int dif, int locknum) {
	srand(time(NULL));

	if (locknum == MAX)
		std::cout << "You have reached the final vault. \n";
	else
	std::cout << "\n\n\tSTARTING LOCKNUM: " << locknum << std::endl;
	std::cout << "\tThe number pad reads from 0 to " << dif << ".\n";

	const int a = (rand() % dif + 1);
	const int b = (rand() % dif + 1);
	const int c = (rand() % dif + 1);

	int arr[3] = { a, b, c };

	for (int i = 0; i < TRIES; i++) {
		if (i == 1)
			std::cout << " Hint: the numbers add to " << (a + b + c) << "\n";
		if (i == 2)
			std::cout << " Hint: the numbers multiply to " << (a * b * c) << "\n";
			

		if (checkArr(arr, 0) == true)
			return game(dif + 1, locknum + 1);
		else
			std::cout << "\n " << "Tries left: " << (TRIES - i - 1) << "\n";
	}

	std::cout << "\tOUT OF TRIES. THE POLICE ARE ON THEIR WAY. \n";
	return false;
}

int main() {
	int difficulty = 2;
	
	std::cout << "WELCOME TO LOCKPICKER! \n   YOU'RE MISSION: BREAK ALL THE LOCKS AND GET THE MONEY AT THE FINAL VAULT. \n";
	
	if (game(difficulty, 0) == true) 
		std::cout << "CONGRATULATIONS. YOU HAVE BROKEN THE FINAL VAULT. YOU WIN!";

	return 0;
}