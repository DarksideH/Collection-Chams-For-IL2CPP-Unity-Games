#include <pthread.h>
#include <jni.h>
#include <Includes/Utils.h>
#include <Substrate/SubstrateHook.h>
#include "KittyMemory/MemoryPatch.h"
#include <Icon.h>
#include <Includes/Chams.h>

    bool chams, shading, wireframe, glow, outline, rainbow = false;
	const char *libName = "libil2cpp.so";
 
    const char *features[] = {
		    "Text_Chams Menu︎", //1
            "Button_Default Chams",//2
            "Button_Shading Chams", //3
            "Button_Wireframe Chams",//4
            "Button_Glow Chams",//5
            "Button_Outline Chams", //6
            "Button_Rainbow Chams", //7
            "Button_Bypass Chams", //8
            "Seek_Line Width_0_12",//9
            "Seek_Color R_0_255",//10
            "Seek_Color G_0_255",//11
            "Seek_Color B_0_255",//12
    
    switch (feature) {
        case 2:
        chams = !chams;
        if (chams) {
        SetWallhack(true);
        } else {
        SetWallhack(false);
        }
        break;      
        case 3:
        shading = !shading;
        if (shading) {
        SetWallhackS(true);
        } else {
        SetWallhackS(false);
        }
        break;
        case 4:
        wireframe = !wireframe;
        if (wireframe) {
        SetWallhackW(true);  
        } else {
        SetWallhackW(false);  
        }
        break;      
        case 5:
        glow = !glow;
        if (glow) {
        SetWallhackG(true);
        } else {
        SetWallhackG(false);
        }
        break;      
        case 6:
        outline = !outline;
        if (outline) {
        SetWallhackO(true); 
        } else {
        SetWallhackO(false);
        }
        break;     
        case 7:
        rainbow = !rainbow;
        if (rainbow) {
        SetRainbow(true);
        } else {
        SetRainbow(false);
        }
        break;		
        case 8:
            bypass = !bypass;
            if (bypass) {
                hexPatches.Bypass.Modify();   
            } else {
                hexPatches.Bypass.Restore();   
            }
            break;  
        case 9:
        SetW(value);
        break;     
        case 10:
        SetR(value);
        break;
        case 11:
        SetG(value);
        break;
        case 12:
        SetB(value);
        break; 

void *hack_thread(void *) {
    
    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(1);
    } while (!il2cppMap.isValid() && mlovinit());
    setShader("_BumpMap");
    LogShaders();
    Wallhack();
    
    hexPatches.Bypass = MemoryPatch::createWithHex("libil2cpp.so", 0xB3FE74,"1E FF 2F E1");
	
    return NULL;
}
