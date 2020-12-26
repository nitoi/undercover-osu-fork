#include "../Overlay.h"
#include "../../Config/Config.h"

static int currentTab = 0;

void Overlay::Toggle() {

	Menu::isOpen = !Menu::isOpen;

	if (!Menu::isOpen) {
		ImGui::GetIO().MouseDrawCursor = false;
		Input::RestoreRaw();
	}
	else {
		ImGui::GetIO().MouseDrawCursor = true;
		Input::DisableRaw();
	}
}

void Overlay::Render(HDC hDc) {
	if (!Menu::isOpen)
		return;

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("undercover", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar); {
		ImGui::SetWindowSize(ImVec2(512, 512));

		ImGui::PushFont(Overlay::logoFont); { //meth
			ImGui::SetCursorPos(ImVec2((512 / 2 - 55), 482));
			ImGui::Text("under");
			ImGui::SetCursorPos(ImVec2((512 / 2 - 55) + 64, 482));
			ImGui::TextColored(ImVec4(0.78, 0.074, 0.15, 1), "cover");
		}ImGui::PopFont();

		ImGui::PushFont(Overlay::menuIconFont); {
			ImGui::SetCursorPos(ImVec2(0, 0));
			if (ImGui::Button("H", ImVec2(75, 75)))
				currentTab = 0;

			ImGui::SetCursorPos(ImVec2(0, 75));
			if (ImGui::Button("C", ImVec2(75, 75)))
				currentTab = 1;

			ImGui::SetCursorPos(ImVec2(0, 150));
			if (ImGui::Button("I", ImVec2(75, 75)))
				currentTab = 2;

			ImGui::SetCursorPos(ImVec2(0, 225));
			if (ImGui::Button("D", ImVec2(75, 75)))
				currentTab = 3;

			ImGui::SetCursorPos(ImVec2(0, 300));
			if (ImGui::Button("G", ImVec2(75, 75)))
				currentTab = 4;
		}ImGui::PopFont();


		ImGui::PushFont(Overlay::menuMainFont); {
			switch (currentTab) {
			case 0:
				ImGui::SetCursorPos(ImVec2(80, 10));
				ImGui::Text("Relax");
				ImGui::SetCursorPos(ImVec2(80, 40));
				ImGui::Checkbox("Enable", &Config::Relax::isEnabled);

				if (Config::Relax::isEnabled) {
					ImGui::SetCursorPos(ImVec2(80, 70));
					ImGui::Text("Style");
					ImGui::SetCursorPos(ImVec2(80, 90));
					ImGui::Combo("1.", &Config::Relax::tappingStyle, "TapX\0Alternate\0SingleTap");
					ImGui::SetCursorPos(ImVec2(80, 120));
					ImGui::Text("Max BPM");
					ImGui::SetCursorPos(ImVec2(80, 140));
					ImGui::SliderInt("2.", &Config::Relax::maxBpm, 10, 300);
					ImGui::SetCursorPos(ImVec2(80, 170));
					ImGui::Text("Max SingleTap BPM");
					ImGui::SetCursorPos(ImVec2(80, 190));
					ImGui::SliderInt("3.", &Config::Relax::singleTapBpm, 10, 300);
					ImGui::SetCursorPos(ImVec2(80, 220));
					ImGui::Text("Alternation BPM");
					ImGui::SetCursorPos(ImVec2(80, 240));
					ImGui::SliderInt("4.", &Config::Relax::alternationBpm, 10, 300);
					ImGui::SetCursorPos(ImVec2(80, 270));
					ImGui::Checkbox("Manual Spinners", &Config::Relax::manualSpinners);
					ImGui::SetCursorPos(ImVec2(80, 300));
					ImGui::Checkbox("Wait Late", &Config::Relax::waitLate);
				}
				break;
			case 1:
				ImGui::SetCursorPos(ImVec2(80, 10));
				ImGui::Text("Timewarp");
				ImGui::SetCursorPos(ImVec2(80, 40));
				ImGui::Checkbox("Enable", &Config::Timewarp::isEnabled);

				if (Config::Timewarp::isEnabled) {
					ImGui::SetCursorPos(ImVec2(80, 70));
					ImGui::Text("Multiplier");
					ImGui::SetCursorPos(ImVec2(80, 90));
					ImGui::SliderFloat("1.", &Config::Timewarp::multiplier, 0.1f, 1.0f, "%.2f", 1);
				}
				break;
			case 2:
				ImGui::SetCursorPos(ImVec2(80, 10));
				ImGui::Text("Aim Assist");
				ImGui::SetCursorPos(ImVec2(80, 40));
				ImGui::Checkbox("Enable", &Config::AimAssist::isEnabled);

				if (Config::AimAssist::isEnabled) {
					ImGui::SetCursorPos(ImVec2(80, 70));
					ImGui::Text("Fov");
					ImGui::SetCursorPos(ImVec2(80, 90));
					ImGui::SliderFloat("1.", &Config::AimAssist::fov, 0.1f, 1.0f, "%.2f", 1);
				}
				break;
			case 3:
				ImGui::SetCursorPos(ImVec2(80, 10));
				ImGui::Text("Visuals");
				ImGui::SetCursorPos(ImVec2(80, 40));
				ImGui::Checkbox("Enable", &Config::Visuals::isEnabled);

				if (Config::Visuals::isEnabled) {
					ImGui::SetCursorPos(ImVec2(80, 70));
					ImGui::Checkbox("Disable Flashlight", &Config::Visuals::flashlight);
					ImGui::SetCursorPos(ImVec2(80, 95));
					ImGui::Checkbox("Disable Hidden", &Config::Visuals::hidden);
				}
				break;
			case 4:
				ImGui::SetCursorPos(ImVec2(80, 10));
				ImGui::Text("Misc");
				break;
			default: break;
			}
		}ImGui::PopFont();

	}ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}