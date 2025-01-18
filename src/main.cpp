#include "pch.h"
#include <imgui-hook.hpp>
#include <imgui.h>
#include <string>
#include "bools.h"

void RenderMain() {

    if(fSpeed <= 0) {
    fSpeed = 1; }

    if (menu) {

        if (!std::filesystem::is_directory("CRaZyHaX") || !std::filesystem::exists("CRaZyHaX"))
	    {
		std::filesystem::create_directory("CRaZyHaX");
	    }
	    if (!std::filesystem::is_directory("CRaZyHaX/dll") || !std::filesystem::exists("CRaZyHaX/dll"))
	    {
		std::filesystem::create_directory("CRaZyHaX/dll");
	    }

        ImGui::Begin("CRaZy HaX V1:");
        ImGui::Text("Mod INFO:");
        if (ImGui::Button("Info", ImVec2(75.0f, 50.0f))) {
        gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "Made By <cb>GMP</c>\n")->show();
        }
        if (ImGui::Button("Credits", ImVec2(75.0f, 50.0f))) {
            gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "<cr>Absolllute</c>: Megahack 5 (Got Some Addresses There)\n<cd>DiOnFire</c>: GDHM Open-Source (Got Addresses There Too)")->show();
        }
        ImGui::End();

        ImGui::Begin("Global:");

//        if(ImGui::Checkbox("Speedhack (Beta)", &speedhack)) {
//        if(ImGui::InputFloat((""), &fSpeed, 1.0f, 2.0f, "%.5f")) {
//            CCDirector::sharedDirector()->getScheduler()->setTimeScale(fSpeed);
//        gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "<cr>WARNING!!!</c><cb>Speedhack</c> Doesn't change <cr>Levels</c> or <cg>Audio</c>!")->show();
//        } else {
//        }
//    }

        if (ImGui::Checkbox("Unlimited Slider", &unlimitedSlider)) {
            if (unlimitedSlider) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\xeb", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\xeb", 1, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Unlimited Slider!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\x76", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\x76", 1, NULL);                
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Unlimited Slider!")->show();
                }
        }

        if (ImGui::Checkbox("Any Character", &anyChar)) {
            if (anyChar) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x90\x90", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Any Character!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x76", 1, NULL);               
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Any Character!")->show();
                }
        }

        if (ImGui::Checkbox("Unlimited Text", &unlimitedText)) {
            if (unlimitedText) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\xeb\x04", 2, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Unlimited Text!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\x7c\04", 2, NULL);             
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Unlimited Text!")->show();
                }
        }

        if (ImGui::Checkbox("Copy Hack", &copyHack)) {
            if (copyHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x8b\xca\x90", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\xb0\x01\x90", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Copy Hack!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x75\x0e", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x0f\x44\xca", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\x0f\x95\xc0", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Copy Hack!")->show();
                }
        }

        if (ImGui::Checkbox("Icon Hack", &iconHack)) {
            if (iconHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xb0\x01\x90\x90\x90", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xb0\x01\x90\x90\x90", 5, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Icon Hack!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xe8\x7A\xcd\x19\x00", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xe8\x68\xc9\x19\x00", 5, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Icon Hack!")->show();
                }

        }

        ImGui::End();

        ImGui::Begin("Level:");
        if (ImGui::Checkbox("Noclip", &noclip)) {
            if (noclip) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xeb\x37", 2, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Noclip!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8a\x80", 2, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Noclip!")->show();
                }
        }
        
        if (ImGui::Checkbox("Everything Kills You", &everythingKillsYou)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Everything Kills You!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Everything Kills You!")->show();
                }
        }

        if (ImGui::Checkbox("ITS ALL BLOCKS", &itsAllBlocks)) {
            if (itsAllBlocks) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x31\xc0\x83\x7b\x34\x00\xba\x07\x00\x00\x00\x0f\x44\xc2\x90", 15, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED ITS ALL BLOCKS!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x8b\x83\x00\x03\x00\x00\x83\xf8\x07\x0f\x84\x7f\x0a\x00\x00", 15, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED ITS ALL BLOCKS!")->show();
                }
        }

        if (ImGui::Checkbox("Theres No ESCAPE", &theresNoEscape)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E644C), "\x90\x90\x90\x90\x90", 5, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Theres No ESCAPE")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E644C), "\xe8\xbf\x73\x02\x00", 5, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Theres No ESCAPE!")->show();
                }
        }

        if (ImGui::Checkbox("Accurate Percentage", &accuratePercentage)) {
            if (accuratePercentage) {
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x32\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Accurate Percentage")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x30\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Accurate Percentage!")->show();
                }
        }

        ImGui::End();

        ImGui::Begin("Creator:");

        if (ImGui::Checkbox("No Editor Kick", &noEditorKick)) { // Toggles noEditorKick
            if (noEditorKick) { // noclip = True
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\xeb", 1, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED No Editor Kick!")->show();
            } else { // noclip = False
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\x74", 1, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED No Editor Kick!")->show();
                }
        }

        if (ImGui::Checkbox("Unlimited Objects", &unlimitedObj)) {
            if (unlimitedObj) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x73169), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x856A4), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87B17), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87BC7), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87D95), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x880F4), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160B06), "\xff\xff\xff\x7f", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x73169), "\xeb", 1, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A022), "\xeb", 1, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A100), "\x90\x90", 2, NULL); 
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Unlimited Objects!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x73169), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x856A4), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87B17), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87BC7), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87D95), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x880F4), "\x80\x38\x01\x00", 4, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160B06), "\x80\x38\x01\x00", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A100), "\x72", 1, NULL);   
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A022), "\x76", 1, NULL); 
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A203), "\x77\x3a", 2, NULL); 
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Unlimited Objects!")->show();
                }
        }

        if (ImGui::Checkbox("Verify Hack", &verifyHack)) {
            if (verifyHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\xeb", 1, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Verify Hack!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\x74", 1, NULL);              
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Verify Hack!")->show();
                }
        }

        if (ImGui::Checkbox("Every Song", &everySong)) {
            if (everySong) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x90\x90\x90", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x90\x90\x90", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Every Song!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x74\x2f", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x0f\x4f\xc6", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x74\x2f", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x0f\x4f\xc6", 3, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Every Song!")->show();
                }
        }

        if (ImGui::Checkbox("Longer Editor", &longerEditor)) {
            if (longerEditor) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\xea\x4b", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x0f\x60\xea\x4b", 4, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have ENABLED Longer Editor!")->show();
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\x6A\x48", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x80\x67\x6a\x48", 4, NULL);
                gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1", "Close", nullptr, "You Have DISABLED Longer Editor!")->show();
                }
        }
        
        ImGui::End();

        }
    }

DWORD WINAPI my_thread(void* hModule) {
    ImGuiHook::setRenderFunction(RenderMain);
    ImGuiHook::setToggleCallback([]() {
        menu = !menu; // Toggles imgui from showing (Press K to toggle)
    });
    if (MH_Initialize() == MH_OK) {
        ImGuiHook::setupHooks([](void* target, void* hook, void** trampoline) {
            MH_CreateHook(target, hook, trampoline); // Sets up hook for imgui
        });
        MH_EnableHook(MH_ALL_HOOKS);
    } else {
        // Comment this if this causes crashes.
        std::cout << "MinHook failed to load! Unloading..." << std::endl;
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
    }
    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, my_thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}