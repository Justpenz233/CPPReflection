#pragma once
#include <map>
#include <iostream>
#include <filesystem>

class FileTimestamp
{
public:
    FileTimestamp(){};
    FileTimestamp(std::string PathToDB);
    ~FileTimestamp();

    bool IsUpdated(std::string FilePath);

private:
    std::filesystem::path DBFilePath;
    std::map<std::string, std::size_t> DB;
    std::string GetTimestamp(std::string FilePath);
    void ReadDB();
};
