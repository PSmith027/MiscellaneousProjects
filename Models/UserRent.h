//
// Created by patrick on 8/22/17.
//

#ifndef DB_ASSIGNMENT1_USERRENT_H
#define DB_ASSIGNMENT1_USERRENT_H

#include <iostream>

class UserRent {
public:
    std::string Username;
    std::string MovieName;

    FileService fileService;

    UserRent(std::string username, std::string movieName);

    UserRent(std::string infoLine);

    std::string GetUsername();

    std::string GetMovieName();
};


#endif //DB_ASSIGNMENT1_USERRENT_H
