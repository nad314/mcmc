#include <main>

int MCMC::main() {
	bool done(0);
	if (mainWindow.open())
		while (!done) {
			if (mainWindow.peekMessageAsync(done))
				continue;
		}
	return 0;
}
