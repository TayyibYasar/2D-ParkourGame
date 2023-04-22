#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include<time.h>
#include<math.h>
#include<windows.h>
using namespace std;
sf::RenderWindow window(sf::VideoMode(1080, 720), "Oyun");


int main(){
	srand(time(NULL));
	sf::Texture diken ;
	diken.loadFromFile("images/custom/diken.png");
	sf::Texture kayak;
	kayak.loadFromFile("images/custom/kayak.png");
	sf::Texture portal1;
	portal1.loadFromFile("images/custom/portal1.png");
	sf::Texture texture;
	sf::Texture ground;
	sf::Texture akim;
	sf::Texture gameover ;
	gameover.loadFromFile("images/custom/gameover.png");
	sf::Texture salincak;
	salincak.loadFromFile("images/custom/salýncak.png");
	ground.loadFromFile("images/custom/ground.png");
	if (!texture.loadFromFile("images/custom/basket-ball-10.png")){
		cout << "Could not find the image file!" << endl;
	}
	akim.loadFromFile("images/custom/akým.png");
	sf::Sprite sprite;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite Kayak;
	sf::Sprite Akim;
	sf::Sprite Portal1;
	sf::Sprite Salincak;
	sf::Sprite Gameover;
	Gameover.setTexture(gameover);
	Salincak.setTexture(salincak);
	Portal1.setTexture(portal1);
	sprite.setTexture(texture);
	sprite3.setTexture(ground);
	sprite4.setTexture(diken);
	Kayak.setTexture(kayak);
	Akim.setTexture(akim);
	float x = 300;
	float y = 500;
	int mousex = x;
	int mousey = y;
	int locationx = 0;
	int locationy = 0;
	float incrementx = 0;
	float incrementy = 0;
	float releasedx = 0;
	float releasedy = 0;
	float yercekimi = 0.1;
	float upper = 50;
	int below = 500;
	bool click = 0;
	bool rightclick = false;
	bool down = false;
	bool finish = false;
	float abc=0.0;
	int donme= 0;
	float surtunme = 0.05;
	bool pause = false;
	int countred = 0;
	bool ret = false;
	float level = 0.3;
	int salincaky = 480;
	
	sf::FloatRect boundingBox = sprite.getGlobalBounds();
	sprite.setOrigin(sf::Vector2f(boundingBox.width / 2, boundingBox.height / 2));  
	while(window.isOpen()){
		if(salincaky < upper+30){
			down = true;
		}
		if(salincaky > 480){
			down = false;
		}
		if(down){
			salincaky++;
		}
		else{
			salincaky--;
		}
		
		upper += level;
		sf::Event event;
		int mousex_ = mousex;
		int mousey_  = mousey;
		mousex = event.mouseMove.x;
		mousey = event.mouseMove.y;;
		if (mousex == 0){
			mousex = mousex_;
		}
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::MouseButtonPressed ){						
				switch(event.key.code){
					case sf::Mouse::Left:		
						if(abs(mousex-x)<35 && abs(mousey-y)<20)
							click = true;
						mousey = mousey_;
						locationx=mousex;
						locationy=mousey;
						yercekimi=0.1;
						break;
					case sf::Mouse::Right:
						if(abs(mousex-x)<35 && abs(mousey-y)<20)
							click = true;
						locationx=mousex;
						locationy=mousey;
						yercekimi=0.1;
						rightclick = true;
						break;
				}
			}
			if(event.type == sf::Event::MouseButtonReleased && click ==true ){
				releasedx=mousex;	
				releasedy=mousey;
				incrementx=(locationx-releasedx)/30;
				incrementy=((releasedy-locationy)/30)*1.3;
				click=false;	
				rightclick = false;
			}
	
				if(event.type == sf::Event::MouseWheelMoved){
					
					donme+=30;
				}
				if(event.type == sf::Event::MouseEntered){
					
					pause = false;
				}
				if(event.type == sf::Event::MouseLeft){
					
					pause = true;
				}
			
		}
		if(!pause && !finish){
			window.clear(sf::Color(255, 255, 255));
			if(click){
				donme = 0;
				incrementx=0;
				incrementy=0;
				abc = abs(sqrt((locationy-mousey) * (locationy-mousey) + (locationx-mousex) * (locationx-mousex))) / 2;
				window.clear(sf::Color(255, 255-abc/2, 255-abc/2));
			}
			else if(rightclick)
			{
				x=event.mouseMove.x;
				y=event.mouseMove.y;
				incrementx=0;
				incrementy=0;
			}
			x+=incrementx;
			y-=incrementy;
			if(y>below){
				y=below;
				if(-incrementy > 2){
					incrementy = -incrementy / 1.4;
				}
				else{
					incrementy = 0;
				}
				if(incrementx>0){
					incrementx -= surtunme;
					if(incrementx < 0.1)
						incrementx = 0;
				}
				else if(incrementx<0){	
					incrementx += surtunme;
				}
				donme = incrementx;						
			}
			else if(x < 110 && y > 430 && y < 532 && (y-x) > 380 && (y-x) < 420 ){ // kaykaya geldiyse
				if(incrementy != 0 && incrementx != 0 && incrementy != -incrementx){ // kaykaya dümdüz gelmediyse
					float temp = incrementy;
					incrementy = -incrementx;
					incrementx = abs(temp);
				}
				else{ // kaykaya düz geldiyse
					donme = incrementx*2;  // topun kaykayýn üzerinde hareket ederken dönme iþlemi
					incrementx +=surtunme*1.5;
					incrementy = -incrementx;
				}
			}
			else if(x < 150 && y < upper +100){ // hava akýmýna girerse
				incrementx ++;
				donme += 1.5;
			}
			else if(x > 980  && x < 1045 && y > 420 && y < 490){ // portalýn ucuna çarparsa
				
				incrementx = -incrementx;
				incrementy = - incrementy;
			}
			else if(x > 1010 && y < 435 && y > 340){ // portala girerse
				x = 100;
				y = upper + 20;
			}
			else if(x > 486 &&  x < 590 && y>=salincaky+10 && y < salincaky+15){ // salincagýn içi
				y = salincaky+10 ;
				if(-incrementy > 2){
					incrementy = -incrementy / 1.4;
				}
				else{
					incrementy = 0;
				}
				if(incrementx>0){
					incrementx -= surtunme;
					if(incrementx < 0.1)
						incrementx = 0;
				}
				else if(incrementx<0){	
					incrementx += surtunme;
				}	
			}
			else if((x > 465 && x < 486) || (x > 590 && x < 620)){
				incrementy -= yercekimi;
			}
			else if(x > 465 &&  x < 620 && y>=salincaky+25 && y <= salincaky + 80 ){// salincaga çarparsa
				incrementx = -incrementx;
				incrementy = -incrementy;
			}
			else if(x > 475 && x < 600 && y>=salincaky+80 && y <= salincaky + 85){
				incrementy = -incrementy;
			}
			else{
				incrementy-=yercekimi;

			}
			sprite.setRotation(sprite.getRotation()+donme);
			if(x>=1045 || x<=35){
				ret = true;
				if(x <= 35)
				{
					x = 35;	
				}	
				else{
					x = 1045;
					
				}
				incrementx=-(incrementx)*0.9;
			}
			if (ret){
				window.clear(sf::Color(255, 50 + countred * 10, 50 + countred * 10));
				countred++ ;
				if(countred > 20){
					ret = false;
					countred = 0;
				}
			}
			if(y <= upper){
				y = upper ;
				incrementy = -(incrementy);
			}
			if(upper > 500){
				level = 1.5;
			}
			if(upper >= 1000){
				finish = true;
			}
			sprite4.setPosition(0,upper-750);
			sprite.setPosition(x,y);
			sprite3.setPosition(0, 530);
			Kayak.setPosition(-4,430);
			Akim.setPosition(0,upper-40);
			Portal1.setPosition(1000,370);
			Salincak.setPosition(500,salincaky);
			Gameover.setPosition(450,upper-975);
			window.draw(sprite);
			window.draw(Kayak);
			window.draw(Akim);
			window.draw(sprite3);
			window.draw(Portal1);
			window.draw(Salincak);
			window.draw(sprite4);
			window.draw(Gameover);
			window.display();
			sf::sleep(sf::seconds(0.01f));
		}
		else if (pause){
			sf::Texture texture2;
			if (!texture2.loadFromFile("images/custom/pause.jpg")){
				cout << "Could not find the image file!" << endl;
			}
			sf::Sprite sprite2;
			sprite2.setTexture(texture2);
			sprite2.setPosition(250,100);
			window.draw(sprite2);
			window.display();
		}
		else if(finish){
			Sleep(1);
			break;
		}									
	}
	return 0;
}
