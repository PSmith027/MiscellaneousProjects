//
// Created by patrick on 8/22/17.
//

#ifndef DB_ASSIGNMENT1_FILESERVICE_H
#define DB_ASSIGNMENT1_FILESERVICE_H

#include <iostream>
#include <vector>

class FileService {
public:
    /**
     * Splits infoLine by spaces. Return all split strings in vector.
     * @param infoLine String
     * @return Vector containing each word of sentence.
     */
    std::vector<std::string> Split(std::string infoLine);

    /**
     * Build the file path of the text files.
     * @param fileName Name of the file.
     * @return String containing full file path.
     */
    std::string BuildPath(std::string fileName);

    /**
     * Formats the readable input to a format appropriate for storage.
     * @param input Readable input.
     * @return String appropriate for storing in txt file.
     */
    std::string FormatInput(std::string input);

    /**
     * Parses the address into a readable format.
     * @param address Address to be parsed.
     * @return Readable string.
     */
    std::string ParseInput(std::string input);

    /**
     * Copies the content of file1 into file2.
     * @param file1 Source file.
     * @param file2 Destionation file.
     */
    void CopyFile(std::string file1, std::string file2);
};


#endif //DB_ASSIGNMENT1_FILESERVICE_H
