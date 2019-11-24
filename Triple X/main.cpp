//Ryan Mauricio
//Triple X
//11/23/19

#include <iostream>
#include <ctime>

const int MAX = 9;
const int TRIES = 3;

bool CheckArr(int* Arr, int N) {
	int Guess;
	int GuessNum = N + 1;
	std::cout << "\n Enter guess " << ": ";
	std::cin >> Guess;

	if (N == 2) {
		std::cout << "   Correct. Lock has been picked.\n";
		std::cin.clear();
		std::cin.ignore();
		return true;
	}

	if (Guess == Arr[N]) {
		std::cout << "   Correct.";
		std::cin.clear();
		std::cin.ignore();
		return CheckArr(Arr, N + 1);
	}
	else {
		std::cout << "   Incorrect. \n";
		std::cin.clear();
		std::cin.ignore();
		return false;
	}
}

int Game(int Dif, int LockNum) {
	srand(time(NULL));

	if (LockNum == MAX)
		std::cout << "You have reached the final vault. \n";
	else
		std::cout << "\n\n\tSTARTING LOCKNUM: " << LockNum + 1 << std::endl;

	const int Num1 = (rand() % Dif + Dif);
	const int Num2 = (rand() % Dif + Dif);
	const int Num3 = (rand() % Dif + Dif);

	int arr[3] = { Num1, Num2, Num3 };

	std::cout << " \tHint: the numbers add to " << (Num1 + Num2 + Num3) << "\n";
	std::cout << " \tHint: the numbers multiply to " << (Num1 * Num2 * Num3) << "\n";

	for (int i = 0; i < TRIES; i++) {
		if (CheckArr(arr, 0) == true)
			return Game(Dif + 1, LockNum + 1);
		else
			std::cout << "\n " << "Tries left: " << (TRIES - i - 1) << "\n";
	}

	std::cout << "\tOUT OF TRIES. THE POLICE ARE ON THEIR WAY. \n";
	return false;
}

int main() {
	int Difficulty = 2;
	
	std::cout << "WELCOME TO LOCKPICKER! \n   YOU'RE MISSION: BREAK ALL THE LOCKS AND GET THE MONEY AT THE FINAL VAULT. \n";
	std::cout << "   Each lock has 3 possible numbers. You only have three tries before the police are alerted!\n";
	
	if (Game(Difficulty, 0) == true) 
		std::cout << "CONGRATULATIONS. YOU HAVE BROKEN THE FINAL VAULT. YOU WIN!";

	return 0;
}