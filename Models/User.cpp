//
// Created by patrick on 8/21/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "User.h"
#include "../Services/FileService.h"

User::User(std::string firstName, std::string lastName, std::string username, std::string address){
    FirstName = firstName;
    LastName = lastName;
    Username = username;
    Address = address;
}

User::User(std::string infoLine){
    FileService fileService;
    std::vector<std::string> lineSplit = fileService.Split(infoLine);

    Username = lineSplit[0];
    FirstName = lineSplit[1];
    LastName = lineSplit[2];
    Address = lineSplit[3];
}

std::string User::GetUsername(){
    return fileService.ParseInput(Username);
}

std::string User::GetFirstName(){
    return fileService.ParseInput(FirstName);
}

std::string User::GetLastName(){
    return fileService.ParseInput(LastName);
}

std::string User::GetAddress(){
    return fileService.ParseInput(Address);
}