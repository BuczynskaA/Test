#include <iostream>
#include <filesystem>
#include <thread>
#include <fstream>
using namespace std;
namespace fs = filesystem;

int numberOfFilies(fs::path path)
{
  int count = 0;
  for (const auto &file : fs::recursive_directory_iterator(path))
    count++;
  return count;
}
int numberOfLine(fs::path path)
{
  int count = 0;
  string line;
  for (const auto &file : fs::recursive_directory_iterator(path))
  {
    auto ext = file.path().extension();
    if (ext == string(".txt"))
    {
      auto name = file.path();
      ifstream file(name);
      while (getline(file, line))
        count++;
    }
  }
  return count;
}
int numberOfLetters(fs::path path)
{
  int count = 0;
  string line;
  for (const auto &file : fs::recursive_directory_iterator(path))
  {

    auto ext = file.path().extension();
    if (ext == string(".txt"))
    {
      auto name = file.path();
      ifstream file(name);
      while (getline(file, line))
        count = count + line.length();
    }
  }
  return count;
}
int numberOfWords(fs::path path)
{
  int count = 0;
  string line;
  for (const auto &file : fs::recursive_directory_iterator(path))
  {

    auto ext = file.path().extension();
    if (ext == string(".txt"))
    {
      auto name = file.path();
      ifstream file(name);
      while (getline(file, line))
      {
        stringstream lineS(line);
        while (getline(lineS, line, ' '))
        {
          count++;
        }
      }
    }
  }
  return count;
}

void informationOfFiles(fs::path path)
{
  cout << "Name: " << path.filename() << "\n"
       << "Number of files: " << numberOfFilies(path) << "\n"
       << "Total number of lines in txt files: "
       << numberOfLine(path)
       << "\nTotal number of letters: "
       << numberOfLetters(path)
       << "\nTotal number of words: "
       << numberOfWords(path);
}
int main()
{
  fs::path path("E:\\Nowy folder\\test\\example");
  thread thr(informationOfFiles, path);
  thr.join();
}