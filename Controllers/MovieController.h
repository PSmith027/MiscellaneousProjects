//
// Created by patrick on 8/23/17.
//

#ifndef DB_ASSIGNMENT1_MOVIECONTROLLER_H
#define DB_ASSIGNMENT1_MOVIECONTROLLER_H

#include <iostream>
#include "../Services/FileService.h"

class MovieController {
public:
    FileService fileService;

    MovieController();

    /**
     * Checks availability of movieName in movies.txt.
     * @param movieName movieName to find.
     * @return Bool indicating whether movieName is taken or not.
     */
    bool MovieNameAvailable(std::string movieName);

    /**
     * Attempts to add the new movie info to movies.txt.
     * @param movieName New movie name to add.
     * @param genre New genre to add.
     * @return Bool indicating whether the movie was added or not.
     */
    bool AddMovie(std::string movieName, std::string genre);

    /**
     * Displays all info for the movies contained in movies.txt.
     */
    void ListAllMovies();
};


#endif //DB_ASSIGNMENT1_MOVIECONTROLLER_H
