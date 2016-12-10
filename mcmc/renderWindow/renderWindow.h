#pragma once
class RenderWindow : public core::Form {
public:
	void onOpening() override;
	int onPaint(const core::eventInfo& e) override;
};
