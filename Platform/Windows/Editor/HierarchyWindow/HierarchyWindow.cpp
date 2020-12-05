#include "HierarchyWindow.h"
#include "Platform/Windows/Common/WinEnviroment.h"
#include "Platform/Windows/Common/ViewWindow.h"
#include "Platform/Windows/Common/Control/Button/TabButton.h"
#include "Platform/Windows/Editor/Menu/MenuItemDefine.h"
#include "Runtime/Debugger/Logger.h"
#include "Runtime/String/StringUtils.h"
#include "Runtime/IO/FileSystem.h"
namespace Editor {
	HierarchyWindow*HierarchyWindow::mSingleton = nullptr;
	void HierarchyWindow::Init(BaseWindow*parent) {
		ViewWindow*view_window = new ViewWindow;
		view_window->SetWindowName("HierarchyWindow");
		view_window->SetNCSize(0, 3, 0, 0);
		view_window->SetMinRect(0, 0, 200, 200);
		view_window->Init(parent);
		//view_window->SetBkgColor(Gdiplus::Color(200, 255, 200));
		view_window->MoveWindow(0, 70, 300, 400);
		view_window->Show();
		mViewWindow = view_window;
		TabButton *tab_button = new TabButton;
		tab_button->Init(WinResources::Singleton()->GetImageData("AliceTab.png"), WinResources::Singleton()->GetImageData("HierarchyWindowIcon.png"),"Hierarchy");
		tab_button->SetRect(view_window->GetUILocationL(96,0)-48, view_window->GetUILocationT(20,0)-10, 96, 20);
		view_window->AppendUI(tab_button);
	}
	ViewWindow*HierarchyWindow::GetViewWindow() {
		return mViewWindow;
	}
	HierarchyWindow*HierarchyWindow::Singleton() {
		if (mSingleton == nullptr) {
			mSingleton = new HierarchyWindow;
		}
		return mSingleton;
	}
}