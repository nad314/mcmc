#include <main>

void MCMC::render() {
	RenderWindow& screen = mainWindow.renderWindow;
	core::Core2D::putPixel(20, 20, vec4b(255), screen);
	screen.invalidate();
}

int MCMC::main() {
	bool done(0);
	if (!mainWindow.open())
		return 1;
	render();
	while (!done) {
		if (mainWindow.peekMessageAsync(done))
			continue;
	}
	return 0;
}
