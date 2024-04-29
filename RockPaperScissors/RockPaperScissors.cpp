#include <iostream>
#include <random>
#include <string> 

class RockPaperScissors {
private: 
	int scorePlayer = 0, scoreComputer = 0;
	std::string moves[3] = { "Rock", "Paper", "Scissors" }; // Use this to output which sign is generated to check for bugs...
public:

	~RockPaperScissors() {
		std::cout << "Bye, Bye! Come back if you ever have a need for me!" << std::endl;
	}

	void Round() {
		int input = 0;
		std::cout << "Please, make a move." << std::endl;
		std::cout << "Rock - 1" << std::endl;
		std::cout << "Paper - 2" << std::endl;
		std::cout << "Scissors - 3" << std::endl;
		while (input != 1 && input != 2 && input != 3) { 
			std::cout << "Your move please: ";  
			std::cin >> input;     
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		int aiMove = computerMove();
		bool won = true, draw = false;
		std::cout << "Computer's move is: " << moves[aiMove-1] << std::endl;
		if (input == 1 && aiMove == 3) std::cout << "You won this round!" << std::endl; 
		else if (input == 2 && aiMove == 1)  std::cout << "You won this round!" << std::endl; 
		else if (input == 3 && aiMove == 2)  std::cout << "You won this round!" << std::endl; 
		else if (input == aiMove) { std::cout << "It's a draw. You both will get a point!" << std::endl; won = 0; draw = 1; }
		else { std::cout << "You have lost the round... Good luck next time!" << std::endl; won = false; }
		if (won) scorePlayer++;
		else if (draw) { scorePlayer++; scoreComputer++; }
		else scoreComputer++;

		std::cin.get();

	}

	int computerMove() {
		 return rand() % 3 + 1;
	}

	int getPlayerScore() {
		return scorePlayer;
	}

	int getComputerScore() {
		return scoreComputer;
	}
};

int main()
{
	srand(time(0));
	int rounds;
	RockPaperScissors* rps = new RockPaperScissors;
	std::cout << "How many roudns of Rock, Paper, Scissors do you want: ";
	std::cin >> rounds;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < rounds; i++) {
		rps->Round();
	}
	if (rps->getPlayerScore() > rps->getComputerScore()) std::cout << "You have won the game." << std::endl;
	else if (rps->getPlayerScore() == rps->getComputerScore()) std::cout << "It's a draw! Better than losing right?" << std::endl;
	else std::cout << "You lost the game! Good luck next time!" << std::endl;
	
	delete rps;

}
