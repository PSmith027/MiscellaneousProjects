#include <iostream>
#include <limits>
#include "../Controllers/UserController.h"
#include "../Controllers/MovieController.h"

void Menu();

int main() {
    Menu();
    return 0;
}

void Menu(){
    UserController userController = UserController();
    MovieController movieController = MovieController();
    FileService fileService = FileService();

    char choice = 0;
    do{
        std::cout << std::endl << "1) Add new user" << std::endl
                  << "2) Add new movie" << std::endl
                  << "3) List all users" << std::endl
                  << "4) List all movies" << std::endl
                  << "5) Rent" << std::endl
                  << "6) List user's rental history" << std::endl
                  << "7) Delete user" << std::endl
                  << "8) Update user address" << std::endl
                  << "9) Exit" << std::endl
                  << ">>> Enter command number [1-9]: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case '1':{
                std::string firstName;
                std::string lastName;
                std::string username;
                std::string address;

                std::cout << "\nEnter first name: ";
                std::getline(std::cin, firstName);
                std::cout << "Enter last name: ";
                std::getline(std::cin, lastName);
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter address: ";
                std::getline(std::cin, address);

                userController.AddUser(firstName, lastName, username, address);
                break;
            }
            case '2':{
                std::string movieName;
                std::string genre;

                std::cout << "\nEnter movie name: ";
                std::getline(std::cin, movieName);
                std::cout << "\nEnter genre: ";
                std::getline(std::cin, genre);

                movieController.AddMovie(movieName, genre);
                break;
            }
            case '3':{
                userController.ListAllUsers();
                break;
            }
            case '4':{
                movieController.ListAllMovies();
                break;
            }
            case '5':{
                std::string username;
                std::string movieName;

                std::cout << "\nEnter username: ";
                std::getline(std::cin, username);
                std::cout << "\nEnter movie name: ";
                std::getline(std::cin, movieName);

                userController.Rent(fileService.FormatInput(username), fileService.FormatInput(movieName));
                break;
            }
            case '6':{
                std::string username;

                std::cout << "\nEnter username: ";
                std::getline(std::cin, username);

                userController.ListUserRentHistory(fileService.FormatInput(username));
                break;
            }
            case '7':{
                std::string username;

                std::cout << "\nEnter username: ";
                std::getline(std::cin, username);

                userController.DeleteUser(username);
                break;
            }
            case '8':{
                std::string username;
                std::string address;

                std::cout << "\nEnter username: ";
                std::getline(std::cin, username);

                std::cout << "\nEnter new address: ";
                std::getline(std::cin, address);

                userController.UpdateUserAddress(fileService.FormatInput(username), fileService.FormatInput(address));
                break;
            }
            case '9':{
                break;
            }
            default: {
                std::cout << "Incorrect input." << std::endl;
                break;
            }
        }

    } while(choice != '9');

}