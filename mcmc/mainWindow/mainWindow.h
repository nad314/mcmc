#pragma once
class MainWindow : public core::WindowForm {
public:
	RenderWindow renderWindow;
	void onOpening() override;
	void onOpened() override;
	void onClosing() override;
	void onEndPaint(const core::eventInfo& e) override;

	void reshape();
};