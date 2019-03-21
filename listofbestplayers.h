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

        typedef typename std::map<int, User<T>>::iterator iterator;
        for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            std::cout <<"Zaczynamy"<< it->first << " => " << it->second.factor << '\n';
        }
    }
    ~ListOfBestPlayers(){
        file.close();
        file.open("moves.txt");
        typedef typename std::map<int, User<T>>::iterator iterator;
        for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            std::cout <<"Konczymy;/"<< it->first << " => " << it->second.username << '\n';
            file<<it->first<<" "<<it->second.factor<<" "<<it->second.username<<"\n";
        }
        file.close();
    }
private:
    std::fstream file;
    ListOfBestPlayers(const ListOfBestPlayers &);
    ListOfBestPlayers(std::string fileName){
        file.open(fileName);
        std::string line;
        if (file.is_open())
          {
            while ( getline (file,line) )
            {
                std::istringstream iss(line);
              std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                               std::istream_iterator<std::string>());

              std::cout<<results[0]<<"->"<<results[1]<<"->"<<results[2]<<std::endl;
              //userNumberOfTilesMap.insert(std::stoi( results[0] ), std::stoi(results[1] ) );
               userNumberOfTilesMap[std::stoi( results[0])] = User<T>(std::stoi(results[1]), results[2]);
            }
          }
    }
    static std::map<int, User<T>> userNumberOfTilesMap;
};


#endif // LISTOFBESTPLAYERS_H
