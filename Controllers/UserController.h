//
// Created by patrick on 8/21/17.
//

#ifndef DB_ASSIGNMENT1_USERCONTROLLER_H
#define DB_ASSIGNMENT1_USERCONTROLLER_H

#include <iostream>
#include <string>
#include "../Models/User.h"
#include "../Services/FileService.h"

class UserController {
public:
    FileService fileService;

    /**
     * Adds a user to the text file containing all users in our system.
     * @param firstName First name of user to be entered.
     * @param lastName Last name of user to be entered.
     * @param username Username of user to be entered.
     * @param address Address of user to be entered.
     * @return Bool indicating success or failure.
     */
    bool AddUser(std::string firstName, std::string lastName, std::string username, std::string address);

    /**
     * Determines availability of the username parameter.
     * @param username Username to check availability.
     * @return Bool indicating availability.
     */
    bool UsernameAvailable(std::string username);

    /**
     * Lists all information for all users.
     */
    void ListAllUsers();

    /**
     * Lists a movie as rented by the username given, in userRent.txt
     * @param username Username to find.
     * @param movieName Movie name to find.
     * @return Bool indiciating whether both username and movie name were found.
     */
    bool Rent(std::string username, std::string movieName);

    /**
     * Display the rental history pertaining to the username given.
     * @param username Unique username of user.
     */
    void ListUserRentHistory(std::string username);

    /**
     * Finds the line in users.txt that contains username, then deletes that line.
     * @param username Username to find.
     * @return Bool which indicates if the user was deleted or not.
     */
    bool DeleteUser(std::string username);

    /**
     * Changes the address of the indicated user.
     * @param username Username of user for address change.
     * @param newAddress Address to replace current user address with.
     * @return Bool indicating success or failure of address update.
     */
    bool UpdateUserAddress(const std::string username, std::string newAddress);
};


#endif //DB_ASSIGNMENT1_USERCONTROLLER_H
