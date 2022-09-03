#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 500), "Animation!");

	Texture Frames;
	Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
	Sprite man(Frames);

	man.setPosition(10, 50);

	int i = 0;

	int x = 10;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		i++;
		if (x > 1000)
			x = 10;

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			i++;
			switch (i)
			{
			case 1:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 2:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 3:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 4:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 5:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 6:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 7:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 8:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 9:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			case 10:
				Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
				man.setPosition(x, 50);
				x += 20;
				break;
			default:
				i = 0;
				break;
			}
		}

		switch (i)
		{
		case 1:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/1.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 2:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/2.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 3:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/3.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 4:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/4.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 5:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/5.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 6:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/6.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 7:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/7.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 8:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/8.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 9:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/9.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		case 10:
			Frames.loadFromFile("D:/BSUIR/oaip/sem2/lab8/Кадры/10.png");
			man.setPosition(x, 50);
			x += 10;
			break;
		default:
			i = 0;
			break;
		}	

		Sleep(50);

		window.clear(Color::White);
		window.draw(man);
		window.display();
	}

	return 0;
}