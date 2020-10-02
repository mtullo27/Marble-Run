#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <vector>

using namespace std;

struct gate{
    //L = left, R = right C = center
    string state;
};

int main(int argc, char *argv[]){
    string starting = argv[1];
    string path = argv[2];
    string final;

    gate x1, x2, x3, x4;

    x1.state = starting[0];
    x2.state = starting[1];
    x3.state = starting[2];
    x4.state = starting[3];
    
    cout << starting << "->";
    
    for(int i = 0; i<path.length()-1; i++){
        if(path[i] == '0'){
            if(x1.state == "L"){
                if(x2.state == "L")
                    x2.state = "R";
                else x2.state = "L";
                x1.state = "R";
            }
            else if(x1.state == "R"){
                if(x3.state == "L")
                    x3.state = "R";
                else x3.state = "L";
                x1.state = "C";
            }
            else if(x1.state == "C"){
                if(x4.state == "L")
                    x4.state = "R";
                else x4.state = "L";
                x1.state = "L";
            }
        }
        else{
            if(x1.state == "L"){
                if(x2.state == "L")
                    x2.state = "R";
                else x2.state = "L";
                x1.state = "C";
            }
            else if(x1.state == "R"){
                if(x3.state == "L")
                    x3.state = "R";
                else x3.state = "L";
                x1.state = "R";
            }
            else if(x1.state == "C"){
                if(x4.state == "L")
                    x4.state = "R";
                else x4.state = "L";
                x1.state = "L";
            }
        }
        cout << x1.state << x2.state << x3.state << x4.state << "->";
    }
    cout << x1.state << x2.state << x3.state << x4.state <<endl;
    if(x1.state == "L" && x2.state == "L")
        final = "B: ACCEPT";
    else if(x1.state == "C" && x3.state == "R")
        final = "D: ACCEPT";
    else if(x1.state == "R" && x4.state == "L")
        final = "D: ACCEPT";
    else if(x1.state == "L" && x2.state == "R")
      final = "C: Reject";
    else if(x1.state == "R" && x2.state == "R")
      final = "E: Reject";
    else if(x1.state == "C" && x2.state == "R")
      final = "C: Reject";
    cout << final << endl;
}
