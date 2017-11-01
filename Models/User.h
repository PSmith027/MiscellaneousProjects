//
// Created by patrick on 8/21/17.
//

#ifndef DB_ASSIGNMENT1_USER_H
#define DB_ASSIGNMENT1_USER_H

#include <iostream>
#include "../Services/FileService.h"

class User {
    std::string FirstName;
    std::string LastName;
    std::string Username;
    std::string Address;

    FileService fileService;

public:
    User(std::string firstName, std::string lastName, std::string username, std::string address);

    User(std::string infoLine);

    std::string GetUsername();

    std::string GetFirstName();

    std::string GetLastName();

    std::string GetAddress();

};


#endif //DB_ASSIGNMENT1_USER_H

