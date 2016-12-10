#include <main>

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR cmdLine, int nCmdShow) {
	return core::Init()(new MCMC());
}
