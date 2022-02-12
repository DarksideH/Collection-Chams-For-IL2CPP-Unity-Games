#include <list>
#include <vector>
#include <string>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "Includes/Chams.h"

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

#define libName OBFUSCATE("libil2cpp.so")

bool underground, wireframe, glow, outline, chams, wchams, rainbow;

void *hack_thread(void *) {
    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap("libil2cpp.so");
        sleep(1);
    } while (!isLibraryLoaded(libName) && mlovinit());
    setShader("_BumpMap");
    LogShaders();
    Wallhack(); 
                   
    return NULL;
}

    const char *features[] = {                 
            OBFUSCATE("Toggle_Default Chams"),//0
            OBFUSCATE("Toggle_Wireframe Chams"),//1
            OBFUSCATE("Toggle_Glow Chams"),//2
            OBFUSCATE("Toggle_Outline Chams"),//3
            OBFUSCATE("Toggle_Rainbow Chams"),//4
            OBFUSCATE("SeekBar_Line Width_0_10"),//5
            OBFUSCATE("SeekBar_Color Red_0_255"),//6
            OBFUSCATE("SeekBar_Color Green_0_255"),//7
            OBFUSCATE("SeekBar_Color Blue_0_255"),//8
    };
                                            
    switch (featNum) {
        case 3:           
        chams = boolean;
        if (chams) {
        SetWallhack(true);       
        } else {
        SetWallhack(false);               
        }
        break;    
        case 4:           
        wireframe = boolean;
        if (wireframe) {
        SetWallhackW(true);
        } else {
        SetWallhackW(false);
        }
        break;    
        case 5:          
        glow = boolean;
        if (glow) {
        SetWallhackG(true);
        } else {
        SetWallhackG(false);
        }
        break;     
        case 6:          
        outline = boolean;
        if (outline) {
        SetWallhackO(true);
        } else {
        SetWallhackO(false);
        }
        break;    
        case 7:           
        rainbow = boolean;
        if (rainbow) {
        SetRainbow(true);
        } else {
        SetRainbow(false);
        }
        break;   
        case 8:                
            SetW(value);
            break;    
        case 9:            
            SetR(value);
            break;
        case 10:                      
            SetG(value);
            break;    
        case 11:           
            SetB(value);
        
