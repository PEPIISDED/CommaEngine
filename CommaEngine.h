#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include <chrono>
#ifndef MY_COMMA_HEADER_
#define MY_COMMA_HEADER_

    inline int color;
    inline bool removewithe = true;
    std::vector<std::vector<std::string>> td = {};
    std::vector<std::vector<std::string>> obj = {};
    std::vector<std::vector<std::string>> fatobj = {{"name", "1", "4"}};

    inline void removethycursor(bool a){
        if (a == true){
            removewithe = false;
        }
        if (a == false){
            removewithe = true;
        }
        
    }
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
    inline void draw(){
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
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = removewithe; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }
    inline void change(int x, int y, std::string z){
        td[y][x] = z;
    }



    















/*    inline int collb(std::string name, std::string name2){
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
*/


/*
y 1
x 1
xs 2
xy 2
6
6
5
1 1 3
2 1
1 2
2 2 6
6
*/
    inline void chmk(std::string name, int x, int y, int colorr, std::string sy, int xs, int ys){
        std::vector<std::string> tempobj = {};
        int count = 0;
        int ogsize = obj.size();
        for (int i = 0; i < ys; i++){
            for (int j = 0; j < xs; j++){
                tempobj.push_back(name);
                tempobj.push_back(std::to_string(j+x+1));
                tempobj.push_back(std::to_string(i+y));
                tempobj.push_back(std::to_string(colorr));
                tempobj.push_back(sy);
                obj.push_back(tempobj);
                tempobj = {};
                count++;
            }
        }
        std::vector<std::string> fatobjtemp = {};
        fatobjtemp.push_back(name);
        fatobjtemp.push_back(std::to_string(ogsize));
        fatobjtemp.push_back(std::to_string(ogsize-1+count));
        fatobjtemp.push_back(std::to_string(xs));
        fatobjtemp.push_back(std::to_string(ys));
        fatobj.push_back(fatobjtemp);
    }





    




    inline int colld(std::string name, std::string name2, std::string dir, int dir2){
        int nmx;
        int nmy;
        int nmx2;
        int nmy2;
        int first;
        int last;
        int first2;
        int last2;

        int howmany;
        int howmany2;
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                howmany = std::stoi(fatobj[i][3]) * std::stoi(fatobj[i][4]);
            }
        }
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name2){
                howmany2 = std::stoi(fatobj[i][3]) * std::stoi(fatobj[i][4]);
            }
        }

        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                first = std::stoi(fatobj[i][1]);
                last = std::stoi(fatobj[i][2]);
            }
        }


        for (int j = 0; j < howmany; j++){
            for (int m = first; m < last+1; m++){{
                if (obj[m][0] == name){
                    nmx = std::stoi(obj[m][1]);
                    nmy = std::stoi(obj[m][2]);
                }


                for (int i = 0; i < fatobj.size(); i++){
                    if (fatobj[i][0] == name2){
                        first2 = std::stoi(fatobj[i][1]);
                        last2 = std::stoi(fatobj[i][2]);
                    }
                }

                for (int i = first2; i < last2+1; i++){
                    if (dir == "x"){
                        if (nmy == std::stoi(obj[i][2])){
                            if (nmx == std::stoi(obj[i][1])+dir2){
                                return 1;
                            }
                        }
                    }
                    if (dir == "y"){
                        if (nmy == std::stoi(obj[i][2])+dir2){
                            if (nmx == std::stoi(obj[i][1])){
                                return 1;
                            }
                        }
                    }
                }
            }
        
            }

            
        }
                
        return 0;

    }






    
    
    inline int coll(std::string name, std::string name2){
        int nmx;
        int nmy;
        int nmx2;
        int nmy2;
        int first;
        int last;
        int first2;
        int last2;

        int howmany;
        int howmany2;
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                howmany = std::stoi(fatobj[i][3]) * std::stoi(fatobj[i][4]);
            }
        }
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name2){
                howmany2 = std::stoi(fatobj[i][3]) * std::stoi(fatobj[i][4]);
            }
        }

        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                first = std::stoi(fatobj[i][1]);
                last = std::stoi(fatobj[i][2]);
            }
        }


        for (int j = 0; j < howmany; j++){
            for (int m = first; m < last+1; m++){{
                if (obj[m][0] == name){
                    nmx = std::stoi(obj[m][1]);
                    nmy = std::stoi(obj[m][2]);
                }


                for (int i = 0; i < fatobj.size(); i++){
                    if (fatobj[i][0] == name2){
                        first2 = std::stoi(fatobj[i][1]);
                        last2 = std::stoi(fatobj[i][2]);
                    }
                }

                for (int i = first2; i < last2+1; i++){
                    if (nmy == std::stoi(obj[i][2])){
                        if (nmx == std::stoi(obj[i][1])){
                            return 1;
                        }
                    }
                }
            }
        
            }

            
        }
                
        return 0;

    }






    /*inline void chmk(std::string name, int x, int y, int color, std::string sy){
        std::vector<std::string> let = {};
        let.push_back(name);
        let.push_back(std::to_string(x+1));
        let.push_back(std::to_string(y));
        let.push_back(std::to_string(color));
        let.push_back(sy);
        obj.push_back(let);
    }*/

    inline int getx(std::string name){
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                return std::stoi(obj[std::stoi(fatobj[i][1])][1])-1;
            }
        }
        return 0;
    }
    inline int gety(std::string name){
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                return std::stoi(obj[std::stoi(fatobj[i][1])][2]);
            }
        }
        return 0;
    }

    inline std::string getpos(std::string name){
        return std::to_string(getx(name)) + " " + std::to_string(gety(name));
    }

    inline void setx(std::string name, int x){
        int first;
        int last;
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                first = std::stoi(fatobj[i][1]);
                last = std::stoi(fatobj[i][2]);
            }
        }

        /*for (int i = 0; i < obj.size(); i++) { 
            for (int j = 0; j < obj[i].size(); j++) 
                std::cout << obj[i][j] << " "; 
            std::cout << std::endl; 
        } */
        std::vector<std::string> ii = {};

        //std::stoi(obj[i][2]) - 5
        //y - 4
        //std::stoi(obj[i][2])3d -- 6

        int iifor = std::stoi(obj[first][1]) - x - 1;

        for (int i = first; i < last+1; i++){
            ii.push_back(obj[i][0]);
            ii.push_back(std::to_string(std::stoi(obj[i][1])-iifor));
            ii.push_back(obj[i][2]);
            obj[i] = ii;
            ii = {};
        }
    }

    inline void sety(std::string name, int y){
        int first;
        int last;
        for (int i = 0; i < fatobj.size(); i++){
            if (fatobj[i][0] == name){
                first = std::stoi(fatobj[i][1]);
                last = std::stoi(fatobj[i][2]);
            }
        }

        /*for (int i = 0; i < obj.size(); i++) { 
            for (int j = 0; j < obj[i].size(); j++) 
                std::cout << obj[i][j] << " "; 
            std::cout << std::endl; 
        } */
        //std::cout << first << "\n";
        //std::cout << last;
        std::vector<std::string> ii = {};

        //std::stoi(obj[i][2]) - 5
        //y - 4
        //std::stoi(obj[i][2])3d -- 6

        int iifor = std::stoi(obj[first][2]) - y;

        for (int i = first; i < last+1; i++){
            /*if (i == 2 || i == 4 ||i == 6 || i == 8){
                iio++;
            }*/
            //std::cout << "\n"<< i << "\n";
            //std::cout << std::stoi(fatobj[i][4]);
            //std::cout << obj[i][1] << "  ";
            //std::cout << obj[i][2] << "\n";
            ii.push_back(obj[i][0]);
            ii.push_back(obj[i][1]);
            ii.push_back(std::to_string(std::stoi(obj[i][2])-iifor));
            obj[i] = ii;
            ii = {};
        }
    }

    inline void setpos(std::string name, int x, int y){
        setx(name, x);
        sety(name, y);
    }

    inline void setall(std::string name, int x, int y, int colorr, std::string sy){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                setx(name, x);
                sety(name, y);
                obj[i][3] = std::to_string(colorr);
                obj[i][4] = sy;
            }
        }
        
    }




    inline void setcl(std::string name, int cl){
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][3] = std::to_string(cl);
            }
        }
    }

    inline void setsy(std::string name, std::string sy){
        int nq;
        for (int i = 0; i < obj.size(); i++){
            if (obj[i][0] == name){
                obj[i][4] = sy;
            }
        }
    }
/*0 5
0 6

0 3
*/
#endif