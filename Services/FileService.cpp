//
// Created by patrick on 8/22/17.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "FileService.h"

std::vector<std::string> FileService::Split(std::string infoLine){
    std::vector<std::string> lineSplit = std::vector<std::string>();
    std::stringstream stream(infoLine);

    std::string current;
    while(stream >> current){
        lineSplit.push_back(current);
    }

    return lineSplit;
}

std::string FileService::BuildPath(std::string fileName){
    return "../Data/" + fileName;
}

std::string FileService::FormatInput(std::string input) {
    std::replace(input.begin(), input.end(), ' ', ',');
    return input;
}

std::string FileService::ParseInput(std::string input){
    std::replace(input.begin(), input.end(), ',', ' ');
    return input;
}

void FileService::CopyFile(std::string file1, std::string file2){
    std::ifstream sourceFile;
    std::ofstream destinationFile;

    sourceFile.open(file1, std::ifstream::in);
    destinationFile.open(file2, std::ofstream::trunc | std::ofstream::out);

    std::string current;
    while (std::getline(sourceFile, current)){
        destinationFile << current << std::endl;
    }

    sourceFile.close();
    destinationFile.close();
}