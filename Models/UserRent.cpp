//
// Created by patrick on 8/22/17.
//

#include <vector>
#include "../Services/FileService.h"
#include "UserRent.h"

UserRent::UserRent(std::string username, std::string movieName){
    Username = username;
    MovieName = movieName;
}

UserRent::UserRent(std::string infoLine) {
    FileService fileService;
    std::vector<std::string> lineSplit = fileService.Split(infoLine);

    Username = lineSplit[0];
    MovieName = lineSplit[1];
}

std::string UserRent::GetUsername(){
    return fileService.ParseInput(Username);
}

std::string UserRent::GetMovieName(){
    return fileService.ParseInput(MovieName);
}