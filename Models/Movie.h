//
// Created by patrick on 8/22/17.
//

#ifndef DB_ASSIGNMENT1_MOVIE_H
#define DB_ASSIGNMENT1_MOVIE_H

#include <iostream>

class Movie {
public:
    std::string MovieName;
    std::string Genre;

    FileService fileService;

    Movie(std::string movieName, std::string genre);

    Movie(std::string infoLine);

    std::string GetMovieName();

    std::string GetGenre();
};

#endif //DB_ASSIGNMENT1_MOVIE_H
