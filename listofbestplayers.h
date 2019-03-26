#ifndef LISTOFBESTPLAYERS_H
#define LISTOFBESTPLAYERS_H
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <iterator>

template<typename N> struct User{
    N factor;
    std::string username;
    User(N factor, std::string username){
        this->factor = factor;
        this->username = username;
    }
    User(){}
};

template <typename T>class ListOfBestPlayers
{

public:

    static ListOfBestPlayers &getInstance(std::string file){
        ListOfBestPlayers instance(file);
        return instance;
    }
    static void updateIfBest(int tiles, T factor, std::string username){
        if(userNumberOfTilesMap.count(tiles)){
            if(userNumberOfTilesMap[tiles].factor > factor)
                userNumberOfTilesMap[tiles] = User<T>(factor, username);
        }else{
            userNumberOfTilesMap[tiles] = User<T>(factor, username);
        }


    }
    ~ListOfBestPlayers(){}

    static void saveToFile(){
        file.open(fileName, std::ofstream::out | std::ofstream::trunc);
        typedef typename std::map<int, User<T>>::iterator iterator;
        if (file.is_open())
          {
           for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            std::cout <<"Zapisujemy ;/"<< it->first << " => " <<it->second.factor<<" ->>" << it->second.username << '\n';
            file<<it->first<<" "<<it->second.factor<<" "<<it->second.username;
            if(it!=userNumberOfTilesMap.end())
             file<< "\n";
        }}
        file.close();
    }
    static std::string stringFromMap(){
        std::stringstream text;
        //std::string text ="";
        typedef typename std::map<int, User<T>>::iterator iterator;
        for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            std::cout<<"Przy przerobianiu mapy na stringi "<<it->first<<"->"<<it->second.factor<<"->"<<it->second.username<<std::endl;
            text << it->first << " " << it->second.factor << " " << it->second.username;
            if(it!=userNumberOfTilesMap.end())
             text<< "\n";
        }
        return text.str();
    }
private:
    static std::fstream file;
    static std::string fileName;
    ListOfBestPlayers(const ListOfBestPlayers &);
    ListOfBestPlayers(std::string fileName){
        this->fileName = fileName;
        file.open(fileName);
        std::string line;
        if (file.is_open())
          {
            while ( getline (file,line) )
            {
                std::istringstream iss(line);
                if(line == "")
                    break;
              std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                               std::istream_iterator<std::string>());

              std::cout<<results[0]<<"->"<<results[1]<<"->"<<results[2]<<std::endl;
              //userNumberOfTilesMap.insert(std::stoi( results[0] ), std::stoi(results[1] ) );
               userNumberOfTilesMap[std::stoi( results[0])] = User<T>(std::stod(results[1]), results[2]);
            }
          }
        file.close();
    }
    static std::map<int, User<T>> userNumberOfTilesMap;
};


#endif // LISTOFBESTPLAYERS_H
