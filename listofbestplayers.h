#ifndef LISTOFBESTPLAYERS_H
#define LISTOFBESTPLAYERS_H
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

/*! /brief struktura użytkownika
*
*Struktura, która zawiera podstawowe dane użytkownika, nazwę użytkownika oraz czynnik, wg którego jest oceniany na Tablicy Wyników.
*
*/
template<typename N> struct User{
    N factor;/*! czynnik z tablicy wyników - czas[minuty] gdy N jest doublem, liczba ruchów gdy N jest intem */
    std::string username; /*! nazwa użytkownika */
    /**
     * @brief Konstruktor parametrowy
     * @param factor czynnik z tablicy wyników - czas[minuty] gdy N jest doublem, liczba ruchów gdy N jest intem
     * @param username nazwa użytkownika
     */
    User(N factor, std::string username){
        this->factor = factor;
        this->username = username;
    }
    /**
     * @brief Konstruktor bezparametrowy
     */
    User(){}
};
/**
 *Klasa odpowiedzialna za przechowywanie listy najlepszych gracy wg czynnika - czasu lub liczby ruchów w zależności od parametru T
 */
template <typename T>class ListOfBestPlayers {

public:
    /**
     * @brief Funkcja statyczna odpowiedzialna za utworzenie co najwyżej jednego obiektu tej klasy.
     * @param file nazwa pliku, w którym będą przechowywane dane o graczach
     * @return instancja obiektu
     */
    static ListOfBestPlayers &getInstance(std::string file){
        ListOfBestPlayers instance(file);
        return instance;
    }
    /**
     * @brief Funkcja statyczna odpowiedzialna za uaktualnianie listy gdy nowy gracz zakończy swoją rozgrywkę.
     * @param tiles liczba płytek, które miała układanka (rozmiar kwadratu)
     * @param factor czas dla T =double lub liczba ruchów dla T = int
     * @param username nazwa użytkownika
     */
    static void updateIfBest(int tiles, T factor, std::string username){
        if(userNumberOfTilesMap.count(tiles)){
            if(userNumberOfTilesMap[tiles].factor > factor)
                userNumberOfTilesMap[tiles] = User<T>(factor, username);
        }else{
            userNumberOfTilesMap[tiles] = User<T>(factor, username);
        }
    }
    ~ListOfBestPlayers(){}
    /**
     * @brief Funkcja statyczna zapisująca aktualną zawartość mapy do pliku.
     */
    static void saveToFile(){
        file.open(fileName, std::ofstream::out | std::ofstream::trunc);
        typedef typename std::map<int, User<T>>::iterator iterator;
        if (file.is_open())
          {
           for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            file<<it->first<<" "<<it->second.factor<<" "<<it->second.username;
            if(it!=userNumberOfTilesMap.end())
             file<< "\n";
        }}
        file.close();
    }
    /**
     * @brief Funkcja zamieniająca aktualną zawartość mapy na napis (string)
     * @return zawartość mapy jako napuis
     */
    static std::string stringFromMap(){
        std::stringstream text;
        typedef typename std::map<int, User<T>>::iterator iterator;
        for (iterator it=userNumberOfTilesMap.begin(); it!=userNumberOfTilesMap.end(); ++it){
            text << it->first << " " << it->second.factor << " " << it->second.username;
            if(it!=userNumberOfTilesMap.end())
             text<< "\n";
        }
        return text.str();
    }

private:
    static std::fstream file;
    static std::string fileName;
    static std::map<int, User<T>> userNumberOfTilesMap;
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
              std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
               userNumberOfTilesMap[std::stoi( results[0])] = User<T>(std::stod(results[1]), results[2]);
            }
          }
        file.close();
    }
};


#endif // LISTOFBESTPLAYERS_H
