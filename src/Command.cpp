#include "Command.h"
#include <conio.h>

namespace util {
    // Constructor
    Command::Command(){
        this->prefix = -1;
        this->postfix = -1;
        this->keyType = Null;
    }
    
    // Get Input key
    void Command::getInput(){
        this->prefix = getch();
        if( this->prefix == 0xe0 || this->prefix == 0x00 ) this->postfix = getch();
    }

    // Check input key (ANSI)
    int Command::getKeyType() const{
        
        if( this->prefix == 0xe0 || this->prefix == 0x00 ){
            switch (this->postfix){
                case 0x48: return UpArrow; break;
                case 0x50: return DownArrow; break;
                case 0x4b: return LeftArrow; break;
                case 0x4d: return RightArrow; break;
                default: return Null; break;
            }
        }

        else{
            switch (this->prefix){
                case 0x1b: return ESC; break;
                case 0x20: return Space; break;
                default: return Null; break;
            }
        }
        
    }

    // Reset
    void Command::reset(){
        this->prefix = -1;
        this->postfix = -1;
        this->keyType = Null;
    }
}