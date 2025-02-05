all: compile link

compile:
	g++ -c main.cpp TApplication.cpp TMapWidget.cpp TMainHero.cpp TMap.cpp TView.cpp -I"/home/jeexike/Документы/SFML-2.6.2-linux-gcc-64-bit/SFML-2.6.2/include" -DSFML_STATIC

link:
	g++ main.o TApplication.o TMapWidget.o TMainHero.o TMap.o TView.o -o sfml-app -L"/home/jeexike/Документы/SFML-2.6.2-linux-gcc-64-bit/SFML-2.6.2/lib" -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main *.o
