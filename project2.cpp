#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <vector>

using namespace std;

struct gate{
    //0 = left, 1 = right 2 = center
    int state;
};

int main(int argc, char *argv[]){
    string starting = argv[1];
    string path = argv[2];
    string final;

    gate x1, x2, x3, x4;

    if(starting[0] == 'L')
         x1.state = 0;
    if(starting[0] == 'R')
        x1.state = 1;
    else x1.state = 2;
    if(starting[1] == 'L')
        x2.state = 0;
    else x2.state = 1;
    if(starting[2] == 'L')
        x3.state = 0;
    else x3.state = 1;
    if(starting[3] == 'L')
        x4.state = 0;
    else x4.state = 1;

    for(int i = 0; i<path.length(); i++){
        if(path[i] == '0'){
            if(x1.state == 0){
                if(x2.state == 0)
                    x2.state = 1;
                else x2.state = 0;
                x1.state = 1;
            }
            if(x1.state == 1){
                if(x3.state == 0)
                    x3.state = 1;
                else x3.state = 0;
                x1.state = 2;
            }
            if(x1.state == 2){
                if(x4.state == 0)
                    x4.state = 1;
                else x4.state = 0;
                x1.state = 0;
            }
        }
        else{
            if(x1.state == 0){
                if(x2.state == 0)
                    x2.state = 1;
                else x2.state = 0;
                x1.state = 2;
            }
            if(x1.state == 1){
                if(x3.state == 0)
                    x3.state = 1;
                else x3.state = 0;
                x1.state = 1;
            }
            if(x1.state == 2){
                if(x4.state == 0)
                    x4.state = 1;
                else x4.state = 0;
                x1.state = 0;
            }
        }
    }
    if(x1.state == 0 && x2.state == 0)
        final = "B: ACCEPT";
    else if(x1.state == 2 && x3.state == 1)
        final = "D: ACCEPT";
    else if(x1.state == 1 && x4.state == 0)
        final = "D: ACCEPT";
    else
      final = "REJECT: Either State C or E";
    cout << final << endl;
}
