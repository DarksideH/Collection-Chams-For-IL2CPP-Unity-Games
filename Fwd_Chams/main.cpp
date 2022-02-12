#include <vector>
#include <list>
#include <string>
#include <locale>
#include <sstream>
#include <string>
#include <stdint.h>
#include <cstring>
#include <string.h>
#include <wchar.h>
#include <endian.h>
#include <pthread.h>
#include <jni.h>
#include <vector>
#include <GLES2/gl2.h>
#include <dlfcn.h>
#include "Chams.h"
#include <iostream>
#include <string>

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

const char *features[] = {
            "Text_Chams Menu",
            "Button_Wireframe Red",
            "Button_Wireframe Green",
            "Button_Wireframe Blue",
            "Button_Wireframe Yellow",
            "Button_Wireframe Pink",
            "Button_Wireframe White",
            "Button_Chams Red",
            "Button_Chams Green",
            "Button_Chams Blue",
            "Button_Chams Yellow",
            "Button_Chams Pink",
            "Button_Chams White",
            "Button_Outline Red",
            "Button_Outline Green",
            "Button_Outline Blue",
            "Button_Outline Yellow",
            "Button_Outline Pink",
            "Button_Outline White",
          "};

bool chr, chgr, chblu, chyelo, chpin, chwhit;
bool chrr, chgrr, chblur, chyelor, chpinr, chwhitr;
bool chro, chgro, chbluo, chyeloo, chpino, chwhito;

    switch (feature) {
        case 1:
        chr = !chr;
        if (chr) {
        SetWireframe(true);
        SetR(255);
        SetG(0);
        SetB(0);
        } else {
        SetWireframe(false);
		}
        break;
        case 2:
        chgr = !chgr;
        if (chgr) {
        SetWireframe(true);
        SetR(0);
        SetG(255);
        SetB(0);
        } else {
        SetWireframe(false);
		}
        break;
        case 3:
        chblu = !chblu;
        if (chblu) {
        SetWireframe(true);
        SetR(0);
        SetG(0);
        SetB(255);
        } else {
        SetWireframe(false);
		}
        break;
        case 4:
        chyelo = !chyelo;
        if (chyelo) {
        SetWireframe(true);
        SetR(255);
        SetG(255);
        SetB(0);
        } else {
        SetWireframe(false);
		}
        break;
        case 5:
        chpin = !chpin;
        if (chpin) {
        SetWireframe(true);
        SetR(255);
        SetG(0);
        SetB(255);
        } else {
        SetWireframe(false);
		}
        break;
        case 6:
        chwhit = !chwhit;
        if (chwhit) {
        SetWireframe(true);
        SetR(255);
        SetG(255);
        SetB(255);
        } else {
        SetWireframe(false);
		}
        break;
        case 7:
        chrr = !chrr;
        if (chrr) {
        SetChams(true);
        SetRR(255);
        SetGG(0);
        SetBB(0);
        } else {
        SetChams(false);
		}
        break;
        case 8:
        chgrr = !chgrr;
        if (chgrr) {
        SetChams(true);
        SetRR(0);
        SetGG(255);
        SetBB(0);
        } else {
        SetChams(false);
		}
        break;
        case 9:
        chblur = !chblur;
        if (chblur) {
        SetChams(true);
        SetRR(0);
        SetGG(0);
        SetBB(255);
        } else {
        SetChams(false);
		}
        break;
        case 10:
        chyelor = !chyelor;
        if (chyelor) {
        SetChams(true);
        SetRR(255);
        SetGG(255);
        SetBB(0);
        } else {
        SetChams(false);
		}
        break;
        case 11:
        chpinr = !chpinr;
        if (chpinr) {
        SetChams(true);
        SetRR(255);
        SetGG(0);
        SetBB(255);
        } else {
        SetChams(false);
		}
        break;
        case 12:
        chwhitr = !chwhitr;
        if (chwhitr) {
        SetChams(true);
        SetRR(255);
        SetGG(255);
        SetBB(255);
        } else {
        SetChams(false);
		}
        break;
        case 13:
        chro = !chro;
        if (chro) {
        SetOutline(true);
        SetRO(255);
        SetGO(0);
        SetBO(0);
        } else {
        SetOutline(false);
		}
        break;
        case 14:
        chgro = !chgro;
        if (chgro) {
        SetOutline(true);
        SetRO(0);
        SetGO(255);
        SetBO(0);
        } else {
        SetOutline(false);
		}
        break;
        case 15:
        chbluo = !chbluo;
        if (chbluo) {
        SetOutline(true);
        SetRO(0);
        SetGO(0);
        SetBO(255);
        } else {
        SetOutline(false);
		}
        break;
        case 16:
        chyeloo = !chyeloo;
        if (chyeloo) {
        SetOutline(true);
        SetRO(255);
        SetGO(255);
        SetBO(0);
        } else {
        SetOutline(false);
		}
        break;
        case 17:
        chpino = !chpino;
        if (chpino) {
        SetOutline(true);
        SetRO(255);
        SetGO(0);
        SetBO(255);
        } else {
        SetOutline(false);
		}
        break;
        case 18:
        chwhito = !chwhito;
        if (chwhito) {
        SetOutline(true);
        SetRO(255);
        SetGO(255);
        SetBO(255);
        } else {
        SetOutline(false);
		}
        break;
        case 19:
        jump = !jump;
        if (jump) {
        hexPatches.Airjump.Modify();
        } else {
        hexPatches.Airjump.Restore();
        }
        break;
    }
}

const char *libName = "libil2cpp.so";

void *hack_thread(void *) {

    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(1);
    } while (!il2cppMap.isValid() && mlovinit());
    setShader("_BumpMap");
    LogShaders();
    Wallhack();

}
