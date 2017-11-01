//
// Created by patrick on 8/21/17.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "UserController.h"
#include "MovieController.h"
#include "../Models/UserRent.h"

bool UserController::UsernameAvailable(std::string username){
    std::ifstream userFile;
    try{
        userFile.open(fileService.BuildPath("users.txt"), std::fstream::in);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string tempLine;
    while (std::getline(userFile, tempLine)){
        std::string tempUsername = tempLine.substr(0, tempLine.find(' '));
        if (tempUsername == username){
            userFile.close();
            return false;
        }
    }

    userFile.close();
    return true;
}

bool UserController::AddUser(std::string firstName, std::string lastName, std::string username, std::string address){
    if ( !(UsernameAvailable(username)) ){
        std::cout << "ERROR: Username already taken, please choose different username." << std::endl;
        return false;
    }

    std::fstream userFile;

    try{
        userFile.open(fileService.BuildPath("users.txt"), std::fstream::in | std::fstream::out | std::fstream::app);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string completeLine = fileService.FormatInput(username) + " " + fileService.FormatInput(firstName) + " " + fileService.FormatInput(lastName) + " " + fileService.FormatInput(address) + "\n";
    userFile << completeLine;
    userFile.close();
}

void UserController::ListAllUsers(){
    std::fstream userFile;

    try{
        userFile.open(fileService.BuildPath("users.txt"), std::fstream::in);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string current;
    while (std::getline(userFile, current)){
        User newUser = User(current);
        std::cout << "\nUsername: " << newUser.GetUsername() << std::endl
                  << "Name: " << newUser.GetFirstName() + " " + newUser.GetLastName() << std::endl
                  << "Address: " << newUser.GetAddress() << std::endl;
    }

    userFile.close();
}

bool UserController::Rent(std::string username, std::string movieName){
    MovieController movieController = MovieController();

    if ( UsernameAvailable(username) || movieController.MovieNameAvailable(movieName) ){
        std::cout << "ERROR: Username and/or Movie name; does not exist." << std::endl;
        return false;
    }

    std::ofstream userRentFile;
    userRentFile.open(fileService.BuildPath("userRent.txt"), std::fstream::out | std::fstream::app);

    std::string completeLine = fileService.FormatInput(username) + " " + fileService.FormatInput(movieName);
    userRentFile << completeLine << std::endl;

    return true;
}

void UserController::ListUserRentHistory(std::string username){
    if (UsernameAvailable(username)){
        std::cout << "ERROR: Username does not exist." << std::endl;
        return;
    }

    std::ifstream userRentFile;
    userRentFile.open(fileService.BuildPath("userRent.txt"), std::fstream::in);

    std::string current;
    while (std::getline(userRentFile, current)){
        std::string currentUser = current.substr(0, current.find(' '));
        if (username == currentUser){
            UserRent newRent = UserRent(current);
            std::cout << "Username: " << newRent.GetUsername() << " - " << newRent.GetMovieName() << std::endl;
        }
    }
}

bool UserController::DeleteUser(std::string username){
    if (UsernameAvailable(username)){
        std::cout << std::endl << "Username not found!" << std::endl;
        return false;
    }

    std::ofstream tempFile;
    tempFile.open(fileService.BuildPath("temp.txt"), std::ofstream::trunc | std::ofstream::out);

    std::ifstream userFile;
    userFile.open(fileService.BuildPath("users.txt"), std::ifstream::in);

    std::string current;
    while (std::getline(userFile, current)){
        if (current.substr(0, current.find(' ')) != username){
            tempFile << current;
        }
    }
    tempFile.close();
    userFile.close();

    fileService.CopyFile(fileService.BuildPath("temp.txt"), fileService.BuildPath("users.txt"));
    return true;
}

bool UserController::UpdateUserAddress(const std::string username, std::string newAddress){
    if (UsernameAvailable(username)){
        std::cout << std::endl << "Username not found!" << std::endl;
        return false;
    }

    std::ofstream tempFile;
    tempFile.open(fileService.BuildPath("temp.txt"), std::ofstream::trunc | std::ofstream::out);

    std::ifstream userFile;
    userFile.open(fileService.BuildPath("users.txt"), std::ifstream::in);

    std::string current;
    while (std::getline(userFile, current)){
        if (current.substr(0, current.find(' ')) != username){
            tempFile << current;
        }
        else{
            std::string correctInfo = "";
            for (int i = 0; i < 3; i++) {
                correctInfo += current.substr(0, current.find(' ') + 1);
                current = current.substr(current.find(' ') + 1);
            }
            correctInfo += newAddress;
            tempFile << correctInfo << std::endl;
        }
    }
    tempFile.close();
    userFile.close();

    fileService.CopyFile(fileService.BuildPath("temp.txt"), fileService.BuildPath("users.txt"));

    return true;
}
