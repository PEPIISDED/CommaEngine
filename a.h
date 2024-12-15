#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#ifndef MY_COMMA_HEADER_
#define MY_COMMA_HEADER_
    inline int color;
    std::vector<std::vector<std::string>> td = {};
    std::vector<std::vector<std::string>> obj = {};
    inline void wait(int mi){
        std::this_thread::sleep_for(std::chrono::milliseconds(mi));
    }
    inline void cls(){	
        COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    }
    inline void makesp(int x, int y, std::string sy, int col){
        std::vector<std::string> let = {};
        for (int i=0;i<x;i++){
            let.push_back(sy);
        }
        for (int i=0;i<y;i++){
            td.push_back(let);
        }
        color = col;
    }
    inline void render(){
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int flag = 0;
        int flagg = 0;
        int j = 0;
        std::vector<std::vector<int>> fornow = {};
        std::vector<int> fornoww = {};
        for (int i = 0; i < td.size(); i++) {
            j=0;
            for ( auto it = td[i].begin(); it != td[i].end(); it++){
                j++;
                flag = 0;
                for (int m = 0; m < obj.size(); m++){
                    
                    if (obj[m][2] == std::to_string(i)){
                        if (obj[m][1] == std::to_string(j)){
                            SetConsoleTextAttribute(hConsole, std::stoi(obj[m][3]));
                            /*for(int n = 0; n < fornow.size(); n++){
                                if(i == fornow[n][1]){
                                    if(j == fornow[n][0]){
                                        flagg = 1;
                                        std::cout << flagg;
                                    }
                                }
                            }
                            fornoww.push_back(j);
                            fornoww.push_back(i);
                            fornow.push_back(fornoww);
                            fornoww = {};*/

                            
                            for (int n = 0; n < obj.size(); n++){
                                if(obj[m][1] == obj[n][1] && n < m){
                                    if(obj[m][2] == obj[n][2] && n < m){
                                        flagg = 1;
                                    }
                                }
                            }


                            if (flagg == 0){
                                std::cout << obj[m][4];
                            }
                            flagg = 0;
                            flag = 1;
                        }
                    }
                }
               if (flag == 0){
                    SetConsoleTextAttribute(hConsole, color);
                    std::cout << *it;
               }
            }
            std::cout << "\n"; 
        }
        SetConsoleTextAttribute(hConsole, 7);
    }
    inline void changeOG(int x, int y, std::string z){
        td[y][x] = z;
    }



    inline void chmk(std::string name, int x, int y, int color, std::string sy){
        std::vector<std::string> let = {};
        let.push_back(name);
        let.push_back(std::to_string(x+1));
        let.push_back(std::to_string(y));
        let.push_back(std::to_string(color));
        let.push_back(sy);
        obj.push_back(let);
    }

    inline void change(std::string name, int x, int y, int color, std::string sy){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][1] = std::to_string(x);
                obj[i][2] = std::to_string(y);
                obj[i][3] = std::to_string(color);
                obj[i][4] = sy;
            }
        }
        
    }



    inline void changex(std::string name, int x){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][1] = std::to_string(x);
            }
        }
    }

    inline void changey(std::string name, int y){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][2] = std::to_string(y);
            }
        }
    }

    inline void changecl(std::string name, int cl){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][3] = std::to_string(cl);
            }
        }
    }

    inline void changesy(std::string name, std::string sy){
        int nq;
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][4] = sy;
            }
        }
    }



    inline int getx(std::string name){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                return std::stoi(obj[i][1]);
            }
        }
        return 0;
    }
    inline int gety(std::string name){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                return std::stoi(obj[i][2]);
            }
        }
        return 0;
    }


    inline int coll(std::string name, std::string name2){
        int nmx;
        int nmy;
        int nmx2;
        int nmy2;
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                nmx = std::stoi(obj[i][1]);
                nmy = std::stoi(obj[i][2]);
            }
            if (obj[i][0] == name2){
                nmx2 = std::stoi(obj[i][1]);
                nmy2 = std::stoi(obj[i][2]);
            }
        }
        if (nmy == nmy2){
            if (nmx == nmx2){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
        return 0;

    }


    inline int collb(std::string name, std::string name2){
        int nmx;
        int nmy;
        std::vector<std::vector<int>> nm2 = {};
        std::vector<int> nm2n = {};
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                nmx = std::stoi(obj[i][1]);
                nmy = std::stoi(obj[i][2]);
            }
            if (obj[i][0] == name2){
                nm2n.push_back(std::stoi(obj[i][1])-1);
                nm2n.push_back(std::stoi(obj[i][2])-1);
                nm2.push_back(nm2n);
                nm2n = {};

                nm2n.push_back(std::stoi(obj[i][1]));
                nm2n.push_back(std::stoi(obj[i][2])-1);
                nm2.push_back(nm2n);
                nm2n = {};

                nm2n.push_back(std::stoi(obj[i][1])+1);
                nm2n.push_back(std::stoi(obj[i][2])-1);
                nm2.push_back(nm2n);
                nm2n = {};
                


                nm2n.push_back(std::stoi(obj[i][1])-1);
                nm2n.push_back(std::stoi(obj[i][2]));
                nm2.push_back(nm2n);
                nm2n = {};
                
                nm2n.push_back(std::stoi(obj[i][1]));
                nm2n.push_back(std::stoi(obj[i][2]));
                nm2.push_back(nm2n);
                nm2n = {};
                
                nm2n.push_back(std::stoi(obj[i][1])+1);
                nm2n.push_back(std::stoi(obj[i][2]));
                nm2.push_back(nm2n);
                nm2n = {};
                



                nm2n.push_back(std::stoi(obj[i][1])-1);
                nm2n.push_back(std::stoi(obj[i][2])+1);
                nm2.push_back(nm2n);
                nm2n = {};
                
                nm2n.push_back(std::stoi(obj[i][1]));
                nm2n.push_back(std::stoi(obj[i][2])+1);
                nm2.push_back(nm2n);
                nm2n = {};
                
                nm2n.push_back(std::stoi(obj[i][1])+1);
                nm2n.push_back(std::stoi(obj[i][2])+1);
                nm2.push_back(nm2n);
                nm2n = {};
            }
        }
        

        for(int i = 0; i < nm2.size(); i++){
            if (nm2[i][1] == nmy){
                if (nm2[i][0] == nmx){
                    return 1;
                }
            }
        }


        return 0;

    }
    

    inline int colld(std::string name, std::string name2, std::string dir){
        int nmx;
        int nmy;
        int nmx2;
        int nmy2;
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                nmx = std::stoi(obj[i][1]);
                nmy = std::stoi(obj[i][2]);
            }
            if (obj[i][0] == name2){
                if (dir == "d"){
                    nmx2 = std::stoi(obj[i][1])-1;
                    nmy2 = std::stoi(obj[i][2]);
                }
                if (dir == "a"){
                    nmx2 = std::stoi(obj[i][1])+1;
                    nmy2 = std::stoi(obj[i][2]);
                }
                if (dir == "w"){
                    nmx2 = std::stoi(obj[i][1]);
                    nmy2 = std::stoi(obj[i][2])+1;
                }
                if (dir == "s"){
                    nmx2 = std::stoi(obj[i][1]);
                    nmy2 = std::stoi(obj[i][2])-1;
                }
                
            }
        }
        if (nmy == nmy2){
            if (nmx == nmx2){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
        return 0;

    }



#endif