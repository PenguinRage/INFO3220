#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Config
{
public:
    static Config* getInstance();
    void setAbsolutePath(string filename);
    void load();
    string getValue(string key);
    string getAbsolutePath();
    void setValue(string key, string value);
    void destroy();
    void save();
    void changeFile(string filename);
    bool validateInt(const string input);
    int getNumber(string key);
    vector<string> getCommands(string key);
    string removeSpace(string line);

private:
    Config(){}
    ~Config(){}
    void open();
    void close();
    string filename;
    fstream config_file;
    map<string, string> config_map;
    vector<string> keys;
    static Config* instance;
};

#endif // CONFIG_H
