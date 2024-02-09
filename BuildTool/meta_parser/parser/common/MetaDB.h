#pragma once
#include <map>
#include <iostream>
#include <filesystem>
#include <set>

struct FileData
{
	std::string FileName;
	std::size_t TimeStamp;
	std::set<std::string> ContainClass;
};

class MetaDB
{
public:
    MetaDB(){};
    MetaDB(std::string PathToDB);
    ~MetaDB();

    bool IsUpdated(std::string FilePath);
	void RegisterClass(std::string ClassName, std::string FilePath);

private:
    std::filesystem::path DBFilePath;
	std::map<std::string, FileData> DB;
    std::string GetTimestamp(std::string FilePath);
    void ReadDB();
};
