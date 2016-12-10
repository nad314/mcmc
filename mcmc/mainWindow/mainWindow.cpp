#include <main>

void MainWindow::onOpening() {
	setTitle("Markov Chain Monte Carlo Test");
	allowResize(0);
}

void MainWindow::onOpened() {
	WindowForm::onOpened();
	renderWindow.setParent(this);
	renderWindow.open();
	reshape();
}

void MainWindow::onClosing() {
	renderWindow.close();
	WindowForm::onClosing();
}

void MainWindow::reshape() {
	renderWindow.move(vec4i(10, 40, width - 10, height - 10));
}

void MainWindow::onEndPaint(const core::eventInfo& e) {
	WindowForm::onEndPaint(e);
	core::Core2D::drawRect(renderWindow.getChildRect().expand(1), core::Color(31, 31, 31, 255), *this);
}

