#include "pch.h"
#include "include.h"

std::string hii() //dll
{
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    if (GetOpenFileName(&ofn))
        return fileName;
}

void RenderMain() {

    ImGui::StyleColorsCRaZy();

    if(fSpeed <= 0) {
    fSpeed = 1; }

    if (menu) {

        ImGui::SetNextWindowPos(ImVec2(60, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(150, 200));
        ImGui::Begin("CRaZy HaX V1.2.0:", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        ImGui::Text("Mod INFO:");
        if (ImGui::Button("Info", ImVec2(75.0f, 50.0f))) {
/*            auto scene = CCScene::create();
            auto layer = InfoLayer::create();
            scene->addChild(layer);
            CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));*/
            gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1.2.0", "Close", nullptr, "Made By <cb>GMP</c>")->show();
        }
        if (ImGui::Button("Credits", ImVec2(75.0f, 50.0f))) {
            gd::FLAlertLayer::create(nullptr, "CRaZy HaX V1.2.0", "Close", nullptr, "<cr>Absolllute</c>: Megahack v5 (Got Some Addresses There)\n<cd>DiOnFire</c>: GDHM Open-Source (Got Addresses There Too)")->show();
        }
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(210, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(150, 125));
        ImGui::Begin("Global:", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Speedhack (Beta)");
        if(ImGui::InputFloat((""), &fSpeed, 1.0f, 10.0f, "%.5f")) {
            CCDirector::sharedDirector()->getScheduler()->setTimeScale(fSpeed);
        }
        
	    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Changes the game speed."); }

        if (ImGui::Checkbox("Safe Mode", &safeMode))
            if (safeMode) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\xE9\x9A\x01\x00\x00\x90\x90", 7, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\xE9\x13\x06\x00\x00\x90\x90", 7, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\x80\xBB\x94\x04\x00\x00\x00", 7, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\x83\xB9\x64\x03\x00\x00\x01", 7, NULL);
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Disables progress on levels if your are using hacks."); }

        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(360, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(190, 150));
        ImGui::Begin("Bypass", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        if (ImGui::Checkbox("Unlimited Slider", &unlimitedSlider)) {
            if (unlimitedSlider) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\xeb", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\xeb", 1, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\x76", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\x76", 1, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Removes the limit on the slider."); }

        if (ImGui::Checkbox("Any Character", &anyChar)) {
            if (anyChar) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x90\x90", 3, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21A99), "\x76", 1, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Allows you to type any character in text fields."); }

        if (ImGui::Checkbox("Unlimited Text", &unlimitedText)) {
            if (unlimitedText) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\xeb\x04", 2, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\x7c\04", 2, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Removes the text limit in text fields."); }

        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(550, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(200, 150));
        ImGui::Begin("Cosmetic", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        if (ImGui::Checkbox("Icon Hack", &iconHack)) {
            if (iconHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xb0\x01\x90\x90\x90", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xb0\x01\x90\x90\x90", 5, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xe8\x7a\xcd\x19\x00", 5, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xe8\x68\xc9\x19\x00", 5, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Gives you every icon in the game."); }

        if (ImGui::Checkbox("Solid Trail", &solidTrail)) {
            if (solidTrail) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xAEB0C), "\x90\x90\x90", 3, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xAEB0C), "\x89\x41\x10", 3, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Removes the blending on the wave trail."); }

        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(750, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(225, 250));
        ImGui::Begin("Level:", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        if (ImGui::Checkbox("Noclip", &noclip)) {
            if (noclip) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20a1dd), "\xeb\x37", 2, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20a1dd), "\x8a\x80", 5, NULL);
            }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Makes the player invincible."); }

        if (ImGui::Checkbox("Noclip Fix", &noclipFix)) {
            if (noclipFix) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xe9\x13\x02\x00\x00\x90", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xe9\x22\x01\x00\x00\x90", 6, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x0f\x84\x12\x02\x00\x00", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x0f\x8B\x21\x01\x00\x00", 6, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Fixes bugs with noclip."); }
        
        if (ImGui::Checkbox("Everything Kills You", &everythingKillsYou)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Makes the player die to everything."); }

        if (ImGui::Checkbox("ITS ALL BLOCKS", &itsAllBlocks)) {
            if (itsAllBlocks) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x31\xc0\x83\x7b\x34\x00\xba\x07\x00\x00\x00\x0f\x44\xc2\x90", 15, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20456D), "\x8b\x83\x00\x03\x00\x00\x83\xf8\x07\x0f\x84\x7f\x0a\x00\x00", 15, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Makes every object function like a block."); }

        if (ImGui::Checkbox("Theres No ESCAPE", &theresNoEscape)) {
            if (everythingKillsYou) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E660C), "\xEB\x0B", 2, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E660C), "\x6a\x00", 2, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Doesn't let the player esc a level."); }

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

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Adds decimals to the percentage count."); }

        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(975, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(200, 250));
        ImGui::Begin("Creator:", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        if (ImGui::Checkbox("No Editor Kick", &noEditorKick)) {
            if (noEditorKick) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\xeb", 1, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\x74", 1, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Doesn't kick you from a high object level."); }

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

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Lets you place an unlimited amount of objects in the editor."); }

        if (ImGui::Checkbox("Verify Hack", &verifyHack)) {
            if (verifyHack) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\xeb", 1, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\x74", 1, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Automatically verifies your levels for you."); }

        if (ImGui::Checkbox("Longer Editor", &longerEditor)) {
            if (longerEditor) {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\xea\x4b", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x0f\x60\xea\x4b", 4, NULL);
            } else {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E67A4), "\x00\x60\x6A\x48", 4, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8FA4D), "\x80\x67\x6a\x48", 4, NULL);
                }
        }

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Increases the editor size by a factor of 128."); }

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

        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
            ImGui::SetTooltip("Lets you copy any level in the game."); }
        
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(1175, 55), ImGuiCond_Appearing);
        ImGui::SetNextWindowSize(ImVec2(200, 150));
        ImGui::Begin("Shortcuts:", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        if (ImGui::Button("Inject Dll (Beta)")) {
            std::string stringpath = hii();
            const char* DllPath = stringpath.c_str();
            
            // Open a handle to target process
            HWND hWnd = FindWindow(0, "2.1 GDPS");
                DWORD proccess_ID;
                GetWindowThreadProcessId(hWnd, &proccess_ID);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
                LPVOID pDllPath = VirtualAllocEx(hProcess, 0, strlen(DllPath) + 1,
                MEM_COMMIT, PAGE_READWRITE);
                WriteProcessMemory(hProcess, pDllPath, (LPVOID)DllPath,
                strlen(DllPath) + 1, 0);
                HANDLE hLoadThread = CreateRemoteThread(hProcess, 0, 0,
                (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"), "LoadLibraryA"), pDllPath, 0, 0);
                WaitForSingleObject(hLoadThread, INFINITE);
                VirtualFreeEx(hProcess, pDllPath, strlen(DllPath) + 1, MEM_RELEASE);
            
        }

        ImGui::End();
        }
    }

DWORD WINAPI my_thread(void* hModule) {

    ImGuiHook::setRenderFunction(RenderMain);
    ImGuiHook::setToggleCallback([]() {
        menu = !menu;
    });
    if (MH_Initialize() == MH_OK) {
        ImGuiHook::setupHooks([](void* target, void* hook, void** trampoline) {
            MH_CreateHook(target, hook, trampoline);
        });
        MH_EnableHook(MH_ALL_HOOKS);
    } else {
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