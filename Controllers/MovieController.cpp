//
// Created by patrick on 8/23/17.
//

#include <iostream>
#include <fstream>
#include "MovieController.h"
#include "../Models/Movie.h"

MovieController::MovieController(){ }

bool MovieController::MovieNameAvailable(std::string movieName){
    std::ifstream movieFile;
    try{
        movieFile.open(fileService.BuildPath("movies.txt"), std::fstream::in);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string tempLine;
    while (std::getline(movieFile, tempLine)){
        std::string tempMovieName = tempLine.substr(0, tempLine.find(' '));
        if (tempMovieName == movieName){
            movieFile.close();
            return false;
        }
    }

    movieFile.close();
    return true;
}

bool MovieController::AddMovie(std::string movieName, std::string genre){
    if ( !(MovieNameAvailable(movieName)) ){
        std::cout << "ERROR: Movie Name already taken, please choose different name." << std::endl;
        return false;
    }

    std::fstream movieFile;

    try{
        movieFile.open(fileService.BuildPath("movies.txt"), std::fstream::in | std::fstream::out | std::fstream::app);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string completeLine = fileService.FormatInput(movieName) + " " + fileService.FormatInput(genre) + "\n";
    movieFile << completeLine;
    movieFile.close();
}

void MovieController::ListAllMovies(){
    std::ifstream movieFile;

    try{
        movieFile.open(fileService.BuildPath("movies.txt"), std::fstream::in);
    }
    catch(std::exception &e){
        std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    }

    std::string current;
    while (std::getline(movieFile, current)){
        Movie newMovie = Movie(current);
        std::cout << "\nMovie Name: " << newMovie.GetMovieName() << std::endl
                  << "Genre: " << newMovie.GetGenre() << std::endl;
    }

    movieFile.close();
}
