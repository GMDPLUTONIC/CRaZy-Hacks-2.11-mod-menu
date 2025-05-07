/*#include "api.hpp"
#include "pch.h"

int shortcutIndexKey;


void CHP::Begin(const char* name, bool* open)
{
	ImGui::Begin(name, open, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar);
}

void CHP::End()
{
	ImGui::End();
}

void CHP::Text(const char* text)
{
	ImGui::Text(text);
}

bool CHP::Checkbox(const char* label, bool* v, bool canMakeShortcut)
{
	bool checkbox = false;

	checkbox = ImGui::Checkbox(label, v);

    return checkbox;
}

bool CHP::Button(const char* label, bool canMakeShortcut)
{
    bool button = false;

	button = ImGui::Button(label);

    return button;
}

bool CHP::InputFloat(const char* label, float* v)
{
    bool inputFloat = false;

	inputFloat = ImGui::InputFloat(label, v);

    return inputFloat;
}

bool CHP::InputText(const char* label, char* buf, size_t buf_size)
{
    bool inputText = false;

	ImGui::InputText(label, buf, buf_size);

    return inputText;
}*/