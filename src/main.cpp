#include "pch.h"
#include <imgui-hook.hpp>
#include <imgui.h>
#include <string>
#include "bools.h"

void RenderMain() {

    ImGui::StyleColorsCRaZy();

    if(fSpeed <= 0) {
    fSpeed = 1; }

    if (menu) {

        ImGui::Begin("CRaZy HaX V1.1:");
        ImGui::Text("Mod INFO:");
        if (ImGui::Button("Info", ImVec2(75.0f, 50.0f))) {
        gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1.1", "Close", nullptr, "Made By <cb>GMP</c>")->show();
        }
        if (ImGui::Button("Credits", ImVec2(75.0f, 50.0f))) {
            gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1.1", "Close", nullptr, "<cr>Absolllute</c>: Megahack v5 (Got Some Addresses There)\n<cd>DiOnFire</c>: GDHM Open-Source (Got Addresses There Too)")->show();
        }
        ImGui::End();

        ImGui::Begin("Global:");

        ImGui::Text("Speedhack (Beta)");
        if(ImGui::InputFloat((""), &fSpeed, 1.0f, 10.0f, "%.5f")) {
            CCDirector::sharedDirector()->getScheduler()->setTimeScale(fSpeed);
        } else {
        }

//        if (ImGui::Checkbox("No Anti-Cheat", &noAntiCheat)) {
//            if (noAntiCheat) {
//                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\xeb", 1, NULL);
//                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\xeb", 1, NULL);
//            } else {
//                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\x76", 1, NULL);
//                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\x76", 1, NULL);
//                }
//        }

        ImGui::End();

        ImGui::Begin("Bypass");

        if (ImGui::Checkbox("Unlimited Slider", &unlimitedSlider)) {
            if (unlimitedSlider) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\xeb", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\xeb", 1, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\x76", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\x76", 1, NULL);
                }
        }

        if (ImGui::Checkbox("Any Character", &anyChar)) {
            if (anyChar) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x90\x90", 3, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x76", 1, NULL);
                }
        }

        if (ImGui::Checkbox("Unlimited Text", &unlimitedText)) {
            if (unlimitedText) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\xeb\x04", 2, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\x7c\04", 2, NULL);
                }
        }

//        if (ImGui::Button("Hack Descriptions", ImVec2(150.0f, 50.0f)))
//        {
//        gd::FLAlertLayer::create(nullptr, "Hack Descriptions:", "Close", nullptr, "<cr>Unlimited Slider</c>: Removes The Limit On Sliders. <cl>Any Character</c>: Lets You Input Any Character In All Input Areas. <cg>Unlimited Text</c>: Removes The Text Limit In All Input Areas.")->show();
//        }
        

        ImGui::End();

        ImGui::Begin("Cosmetic");

        if (ImGui::Checkbox("Icon Hack", &iconHack)) {
            if (iconHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xb0\x01\x90\x90\x90", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xb0\x01\x90\x90\x90", 5, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xe8\x7a\xcd\x19\x00", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xe8\x68\xc9\x19\x00", 5, NULL);
                }

        }

        ImGui::End();


        ImGui::Begin("Level:");
        if (ImGui::Checkbox("Noclip", &noclip)) {
            if (noclip) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xEB\x37", 2, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8A\x80", 2, NULL);
            }
        }

        if (ImGui::Checkbox("Noclip Fix", &noclipFix)) {
            if (noclipFix) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xe9\x13\x02\x00\x00\x90", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xe9\x22\x01\x00\x00\x90", 6, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x0f\x84\x12\x02\x00\x00", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x0f\x8B\x21\x01\x00\x00", 6, NULL);
                }
        }
        
        if (ImGui::Checkbox("Everything Kills You", &everythingKillsYou)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                }
        }

        if (ImGui::Checkbox("ITS ALL BLOCKS", &itsAllBlocks)) {
            if (itsAllBlocks) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x31\xc0\x83\x7b\x34\x00\xba\x07\x00\x00\x00\x0f\x44\xc2\x90", 15, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x8b\x83\x00\x03\x00\x00\x83\xf8\x07\x0f\x84\x7f\x0a\x00\x00", 15, NULL);
                }
        }

        if (ImGui::Checkbox("Theres No ESCAPE", &theresNoEscape)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E644C), "\x90\x90\x90\x90\x90", 5, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E644C), "\xe8\xbf\x73\x02\x00", 5, NULL);
                }
        }

        if (ImGui::Checkbox("Accurate Percentage", &accuratePercentage)) {
            if (accuratePercentage) {
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x32\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x30\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
                }
        }

        ImGui::End();

        ImGui::Begin("Creator:");

        if (ImGui::Checkbox("No Editor Kick", &noEditorKick)) {
            if (noEditorKick) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\xeb", 1, NULL);
            } else { // noclip = False
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\x74", 1, NULL);
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
                }
        }

        if (ImGui::Checkbox("Verify Hack", &verifyHack)) {
            if (verifyHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\xeb", 1, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\x74", 1, NULL);
                }
        }

        if (ImGui::Checkbox("Every Song", &everySong)) {
            if (everySong) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x90\x90\x90", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x90\x90\x90", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x74\x2f", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x0f\x4f\xc6", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x74\x2f", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x0f\x4f\xc6", 3, NULL);
                }
        }

        if (ImGui::Checkbox("Longer Editor", &longerEditor)) {
            if (longerEditor) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\xea\x4b", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x0f\x60\xea\x4b", 4, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\x6A\x48", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x80\x67\x6a\x48", 4, NULL);
                }
        }

        if (ImGui::Checkbox("Copy Hack", &copyHack)) {
            if (copyHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x8b\xca\x90", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\xb0\x01\x90", 3, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x75\x0e", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x0f\x44\xca", 3, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\x0f\x95\xc0", 3, NULL);
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