//
// Created by patrick on 8/22/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Services/FileService.h"
#include "Movie.h"

Movie::Movie(std::string movieName, std::string genre){
    MovieName = movieName;
    Genre = genre;
}

Movie::Movie(std::string infoLine){
    FileService fileService;
    std::vector<std::string> lineSplit = fileService.Split(infoLine);

    MovieName = lineSplit[0];
    Genre = lineSplit[1];
}

std::string Movie::GetMovieName(){
    return fileService.ParseInput(MovieName);
}

std::string Movie::GetGenre(){
    return fileService.ParseInput(Genre);
}
