#include <pthread.h>
#include <jni.h>
#include <Includes/Utils.h>
#include <Substrate/SubstrateHook.h>
#include <Icon.h>
#include <jnimethods.h>
#include "Includes/Chams.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <dlfcn.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

    bool chams, wireframe, glow, outline, rainbow = false;
    
    const char *features[] = {
            OBFUSCATE("Text_Visuals"),
            OBFUSCATE("ButtonOnOff_Color Chams"),
			OBFUSCATE("ButtonOnOff_Wireframe Chams"),
			OBFUSCATE("ButtonOnOff_Glow Chams"),
			OBFUSCATE("ButtonOnOff_Outline Chams"),
			OBFUSCATE("ButtonOnOff_Rainbow Mode"),
			OBFUSCATE("Text_Chams Settings"),//6
			OBFUSCATE("SeekBar_Color Red_0_255"),
			OBFUSCATE("SeekBar_Color Green_0_255"),
			OBFUSCATE("SeekBar_Color Blue_0_255"),
			OBFUSCATE("SeekBar_Wireframe Width_0_15"),
			OBFUSCATE("SeekBar_Glow Width_0_15"),
			OBFUSCATE("SeekBar_Outline Width_0_15"),
		
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
            wireframe = !wireframe;
			if (wireframe) {
                SetWireframe(true);
            } else {
                SetWireframe(false);
            }
            break;
        case 3:
            glow = !glow;
			if (glow) {
                SetGlow(true);
            } else {
                SetGlow(false);
            }
            break;
		case 4:
            outline = !outline;
			if (outline) {
                SetOutline(true);
            } else {
                SetOutline(false);
            }
            break;
        case 5:
            rainbow = !rainbow;
			if (rainbow) {
                SetRainbow(true);
            } else {
                SetRainbow(false);
            }
            break;
        case 7:
            SetR(value);
            break;
	    case 8:
            SetG(value);
            break;
		case 9:
            SetB(value);
            break;
		case 10:
            SetWireframeWidth(value);
            break;
		case 11:
            SetGlowWidth(value);
            break;
		case 12:
            SetOutlineWidth(value);
            break;

void *cheat(void *) {
    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(10);
    } while (!isLibraryLoaded(libName) && mlovinit());
	setShader("_BumpMap");
    LogShaders();
    Wallhack();

    return NULL;
}