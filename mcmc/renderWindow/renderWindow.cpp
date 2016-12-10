#include <main>

void RenderWindow::onOpening() {
	Form::onOpening();
	setStyle(WS_CHILD);
}

int RenderWindow::onPaint(const core::eventInfo& e) {
	imageToScreen();
	return e;
}
