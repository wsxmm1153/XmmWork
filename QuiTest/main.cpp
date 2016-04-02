#include "quitest.h"
#include <QtWidgets/QApplication>
#include <QtCore/QThread>
#include <thread>
#include <iostream>
#include <chrono>
void showOtherWindow(QuiTest& w, QuiTest& w0){
	//std::this_thread::sleep_for(std::chrono::seconds(20));
	w.setFixedSize(w0.size());
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QuiTest w;
	w.setFixedSize(5, 5);
	QuiTest w0;

	std::thread other_thread(&showOtherWindow, std::ref(w), std::ref(w0));
	other_thread.detach();
	w.show();
	//std::this_thread::sleep_for(std::chrono::seconds(0));
	//std::thread other_thread(&showOtherWindow, std::ref(w), std::ref(w0));

	//other_thread.detach();


	return a.exec();
}
