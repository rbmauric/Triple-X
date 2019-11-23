//Ryan Mauricio
//Triple X
//11/23/19

#include <iostream>
#include <ctime>

const int MAX = 9;
const int TRIES = 3;

bool checkArr(int* Arr, int N) {
	int Guess;
	int GuessNum = N + 1;
	std::cout << "\n Enter guess " << ": ";
	std::cin >> Guess;

	if (N == 2) {
		std::cout << "   Correct. Lock has been picked.\n";
		return true;
	}

	if (Guess == Arr[N]) {
		std::cout << "   Correct.";
		return checkArr(Arr, N + 1);
	}
	else {
		std::cout << "   Incorrect. \n";
		return false;
	}
}

int game(int Dif, int LockNum) {
	srand(time(NULL));

	if (LockNum == MAX)
		std::cout << "You have reached the final vault. \n";
	else
	std::cout << "\n\n\tSTARTING LOCKNUM: " << LockNum << std::endl;
	std::cout << "\tThe number pad reads from 0 to " << Dif << ".\n";

	const int Num1 = (rand() % Dif + 1);
	const int Num2 = (rand() % Dif + 1);
	const int Num3 = (rand() % Dif + 1);

	int arr[3] = { Num1, Num2, Num3 };

	for (int i = 0; i < TRIES; i++) {
		if (i == 1)
			std::cout << " Hint: the numbers add to " << (Num1 + Num2 + Num3) << "\n";
		else if (i == 2)
			std::cout << " Hint: the numbers multiply to " << (Num1 * Num2 * Num3) << "\n";
			

		if (checkArr(arr, 0) == true)
			return game(Dif + 1, LockNum + 1);
		else
			std::cout << "\n " << "Tries left: " << (TRIES - i - 1) << "\n";
	}

	std::cout << "\tOUT OF TRIES. THE POLICE ARE ON THEIR WAY. \n";
	return false;
}

int main() {
	int Difficulty = 2;
	
	std::cout << "WELCOME TO LOCKPICKER! \n   YOU'RE MISSION: BREAK ALL THE LOCKS AND GET THE MONEY AT THE FINAL VAULT. \n";
	
	if (game(Difficulty, 0) == true) 
		std::cout << "CONGRATULATIONS. YOU HAVE BROKEN THE FINAL VAULT. YOU WIN!";

	return 0;
}