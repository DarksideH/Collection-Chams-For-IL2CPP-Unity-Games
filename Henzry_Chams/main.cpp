#include <pthread.h>
#include <jni.h>
#include <Substrate/SubstrateHook.h>
#include <Includes/Chams.h>

    bool chams, shading, wireframe, glow, outline, rainbow = false;
	
    const char *features[] = {
		    "Text_Chams Menu︎", //0
            "Button_Default Chams",//1
            "Button_Shading Chams", //2
            "Button_Wireframe Chams",//3
            "Button_Glow Chams",//4
            "Button_Outline Chams", //5
            "Button_Rainbow Chams", //6
            "Seek_Line Width_0_12",//7
            "Seek_Color R_0_255",//8
            "Seek_Color G_0_255",//9
            "Seek_Color B_0_255",//10   
            };

    switch (feature) {
        case 1:
        chams = !chams;
        if (chams) {
        SetWallhack(true);
        } else {
        SetWallhack(false);
        }
        break;
        case 2:
        shading = !shading;
        if (shading) {
        SetWallhackS(true);
        } else {
        SetWallhackS(false);
        }
        break;
        case 3:
        wireframe = !wireframe;
        if (wireframe) {
        SetWallhackW(true);  
        } else {
        SetWallhackW(false);  
        }
        break;       
        case 4:
        glow = !glow;
        if (glow) {
        SetWallhackG(true);
        } else {
        SetWallhackG(false);
        }
        break;        
        case 5:
        outline = !outline;
        if (outline) {
        SetWallhackO(true); 
        } else {
        SetWallhackO(false);
        }
        break;        
        case 6:
        rainbow = !rainbow;
        if (rainbow) {
        SetRainbow(true);
        } else {
        SetRainbow(false);
        }
        break;      
        case 7:
        SetW(value);
        break;         
        case 8:
        SetR(value);
        break;
        case 9:
        SetG(value);
        break;
        case 10:
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
   
   return NULL;
}
