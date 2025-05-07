#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <functional>
#include <string>
#include <vector>

namespace CHP {
    void addImGuiFunc(std::function<void()> func);

    void Begin(const char* name, bool *open = (bool*)false);
    void End();
    void Text(const char* text);

    void Marker(const char* marker, const char* desc);
    bool Hotkey(const char* label, int* k);
    bool Checkbox(const char* label, bool* v, bool canMakeShortcut = true);
    bool Button(const char* label, bool canMakeShortcut = true);
    bool InputFloat(const char* label, float* v);
    bool InputInt(const char* label, int* v, int step = 1);
    bool InputInt2(const char* label, int* v);
    bool InputText(const char* label, char* buf, size_t buf_size);

    template <class T> void WriteRef(uint32_t vaddress, const T& value);
    template <class T> bool Write(uint32_t vaddress, const T& value);
    std::vector<uint8_t> ReadBytes(uint32_t vaddress, size_t size);
    template <class T> T Read(uint32_t vaddress);
    void writeOutput(std::string out);
    void writeOutput(int out);
    void writeOutput(float out);
    void writeOutput(double out);

    void SaveInt(const char* filename, const char* key, int value);
    void SaveBool(const char* filename, const char* key, bool value);
    void SaveFloat(const char* filename, const char* key, float value);
    void SaveDouble(const char* filename, const char* key, double value);
    void SaveString(const char* filename, const char* key, const char* value);
    void ReadInt(const char* filename, const char* key, int* value);
    void ReadBool(const char* filename, const char* key, bool* value);
    void ReadFloat(const char* filename, const char* key, float* value);
    void ReadDouble(const char* filename, const char* key, double* value);
    void ReadString(const char* filename, const char* key, std::string* value);

    void Init(std::string name, std::function<void()> openCallback, std::function<void()> closeCallback);

    static bool IsLoaded() {
        return GetModuleHandleA("CRaZyHaXPRO.dll");
    }
}