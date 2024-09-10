#include <iostream>
#include <string>
#include <cstdlib>

void initPlayer(std::string &name, int &balance) {
    std::cout << "Enter player's name: " << std::endl;
    getline(std::cin, name);
    initAmount:
    std::cout << "Enter starting amount in EUR: " << std::endl;
    std::cin >> balance;
    if (std::cin.fail()) {
        std::cout << "Not a number. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        goto initAmount;
    }
}

void casinoRules() {
    std::cout << "==============CASINO RULES===============" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Choose a number between 1 to 10." << std::endl;
    std::cout << "Winner gets 10 times of the money bet." << std::endl;
    std::cout << "Wrong bet, and you lose the amount you bet.\n" << std::endl;

}

int main() {

    //Initialising player
    std::string name;
    int balance;
    int betAmount;
    int guess;
    int dice;
    char choise;
    srand(time(0));
    initPlayer(name, balance);
    std::cout << "Player "<< name << " starts with "<< balance << " EUR on his/her account\n\n" << std::endl;
    casinoRules();

    do {
        do {
            initBet:
            std::cout << "Enter amount of EUR to bet: " << std::endl;
            std::cin >> betAmount;
            if (std::cin.fail()) {
                std::cout << "Not a number. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                goto initBet;
            }
            if (betAmount > balance) {
                std::cout << "You entered more than you have. You have EUR " << betAmount << std::endl;
            }
        } while (betAmount > balance);

        do {
            initGuess:
            std::cout << "Choose a number between 1 to 10." << std::endl;
            std::cin >> guess;
            if (std::cin.fail()) {
                std::cout << "Not a number. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                goto initGuess;
            }
            if (guess <= 0 || guess > 10) {
                std::cout << "Number should be between 1 and 10.\n Re-enter the number" << std::endl;
            }
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10;

        if (dice == guess) {
            std::cout << "You win! You recieve " << betAmount * 10 << " EUR" << std::endl;
            balance += betAmount * 10;
        } else {
            std::cout << "You lose! You have lost" << betAmount << " EUR." << std::endl;
            balance -= betAmount;
        }
        std::cout << "The winning number was :" << dice << std::endl;
        std::cout << "Your balance is: " << balance << " EUR." << std::endl;
        if (balance == 0) {
            std::cout << "You have no money to play" << std::endl;
            return 0;
        }
        std::cout << "Would you like to play again?(y/n) "<< std::endl;
        std::cin >> choise;
    } while (choise == 'y' || choise == 'y');
    std::cout << "You have quit the casino"<< std::endl;
    std::cout << "Your balance is: " << balance << " EUR" << std::endl;

    return 0;
}