#include "FileTimestamp.h"
#include <fstream>
#include <format>


FileTimestamp::FileTimestamp(std::string PathToDB)
{
    DBFilePath = PathToDB;
    DBFilePath = DBFilePath / "_generated" / "DB";
    std::ifstream DBFile(DBFilePath);
    std::cout << "Reading CODE database : " << DBFilePath << std::endl;
    if(DBFile.is_open())
    {
        std::string FilePath;
        std::size_t FileTime;
        while(!DBFile.eof()) {
            DBFile >> FilePath >> FileTime;
            DB[FilePath] = FileTime;
        }
        DBFile.close();
    }
}

FileTimestamp::~FileTimestamp()
{
    std::ofstream DBFile(DBFilePath);

    if(DBFile.is_open())
    {
        for(auto p : DB)
        {
            DBFile << p.first << " " << p.second << std::endl;
        }
    }
    std::cout << "Updating CODE database : " << DBFilePath << std::endl;

    DBFile.close();
}
template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}
bool FileTimestamp::IsUpdated(std::string FilePath)
{
    std::filesystem::file_time_type ftime = std::filesystem::last_write_time(FilePath);
    std::time_t t = to_time_t(ftime);

    // 将 std::time_t 转换为字符串
    std::string timeString = std::ctime(&t);
    std::size_t str_hash = std::hash<std::string>{}(timeString);
    if(DB.count(FilePath) == 0 || DB[FilePath] != str_hash) {
        DB[FilePath] = str_hash;
        return true;
    }
    else
        return false;
}
