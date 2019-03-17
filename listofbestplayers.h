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



template <typename T>class ListOfBestPlayers
{
public:

    static ListOfBestPlayers &getInstance(std::string file){
        ListOfBestPlayers instance(file);
        return instance;
    }
    static void updateIfBest(int tiles, T factor){
        if(bestFactor[tiles]){
            if(bestFactor[tiles]>factor)
                bestFactor[tiles] = factor;
        }else{
            bestFactor[tiles] = factor;
        }

        typedef typename std::map<int, T>::iterator iterator;
        for (iterator it=bestFactor.begin(); it!=bestFactor.end(); ++it){
            std::cout <<"Zaczynamy"<< it->first << " => " << it->second << '\n';
        }
    }
    ~ListOfBestPlayers(){
        typedef typename std::map<int, T>::iterator iterator;
        for (iterator it=bestFactor.begin(); it!=bestFactor.end(); ++it){
            std::cout <<"Zaczynamy"<< it->first << " => " << it->second << '\n';
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

              std::cout<<results[0]<<"->"<<results[1]<<std::endl;
              //bestFactor.insert(std::stoi( results[0] ), std::stoi(results[1] ) );
                bestFactor[std::stoi( results[0])] = std::stoi(results[1]);
            }
          }
    }
    static std::map<int, T> bestFactor;
};

#endif // LISTOFBESTPLAYERS_H
