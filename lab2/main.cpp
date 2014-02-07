#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyPatratVerde.h"
#include "Enemy2Patrate.h"
#include "Enemy4Triunghiuri.h"
#include "EnemyPatratFace.h"
#include "Level.h"
#include <vector>
#include <time.h>

#define PI 3.14159265358979323846

using namespace std;

float grad = PI/360;

Visual2D *v2d_playfield;
Visual2D *v2d_scoreboard;

Player *player = new Player(350, 350);

int margini = 20;
int heightScoreBoard = 70;
int levelNo = 1;
Level level = Level();
int lives = 5;
int score = 0;
float timeout = clock();

int originePlayfieldX = margini;
int originePlayfieldY = margini;
int limitaDrSusPlayfieldX = DrawingWindow::width - margini;
int limitaDrSusPlayfieldY = DrawingWindow::height - margini - heightScoreBoard;

bool keyUpIsPressed = false;
bool keyRightIsPressed = false;
bool keyLeftIsPressed = false;

int vitezaNava = 5;
float rotatieNava = 10 * grad;

Text *textScore, *textLives, *textLevel;

Color colorText = Color(8.0f/255.0f, 243.0f/255.0f, 1);
// culoare text

//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{

	FreeConsole(); // ascunde consola
	level.newLevel(levelNo);

	v2d_playfield = new Visual2D
		(0 + margini, 0 + margini, 
		DrawingWindow::width - margini, DrawingWindow::height - margini - heightScoreBoard, 
		0 + margini, 0 + margini + heightScoreBoard,
		DrawingWindow::width - margini, DrawingWindow::height - margini);
	v2d_scoreboard = new Visual2D
		(0 + margini, 0 + DrawingWindow::height - margini - heightScoreBoard,
		DrawingWindow::width - margini, DrawingWindow::height - margini, 
		0 + margini, 0 + margini, 
		DrawingWindow::width - margini, 0 + margini + heightScoreBoard);

	v2d_playfield->cadruFereastra(Color(0, 1, 1));
	
	player->updatePlayfieldSize ((float) margini, (float) margini, 
		(float) (DrawingWindow::width - margini), 
		(float) (DrawingWindow::height - margini - heightScoreBoard), v2d_playfield);

	for (int i = 0; i < level.enemies.size(); i++) 
	{
		level.enemies[i]->updatePlayfieldSize ((float) margini, (float) margini, 
			(float) (DrawingWindow::width - margini), 
			(float) (DrawingWindow::height - margini - heightScoreBoard), v2d_playfield);
	}

	addVisual2D(v2d_playfield);
	addVisual2D(v2d_scoreboard);

	Text* text1 = new Text("Score: ", Point2D(50, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(text1, v2d_scoreboard);
	Text* text2 = new Text("Level: ", Point2D(50, 630), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(text2, v2d_scoreboard);
	Text* text3 = new Text("Lives: ", Point2D(300, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(text3, v2d_scoreboard);

	string scoreT = to_string(score);
	textScore = new Text(scoreT, Point2D(120, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textScore, v2d_scoreboard);

	string scoreL = to_string(levelNo);
	textLevel = new Text(scoreL, Point2D(120, 630), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textLevel, v2d_scoreboard);

	string scoreLiv = to_string(lives);
	textLives = new Text(scoreLiv, Point2D(370, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textLives, v2d_scoreboard);

	player->addPlayer2D(v2d_playfield);
	for (int i = 0; i < level.enemies.size(); i++) 
	{
		level.enemies[i]->addEnemy2D(v2d_playfield);
	}

}


//functia care permite animatia
void DrawingWindow::onIdle()
{

	removeText_from_Visual2D(textScore, v2d_scoreboard);
	removeText_from_Visual2D(textLevel, v2d_scoreboard);
	removeText_from_Visual2D(textLives, v2d_scoreboard);

	string scoreT = to_string(score);
	textScore = new Text(scoreT, Point2D(120, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textScore, v2d_scoreboard);

	string scoreL = to_string(levelNo);
	textLevel = new Text(scoreL, Point2D(120, 630), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textLevel, v2d_scoreboard);

	string scoreLiv = to_string(lives);
	textLives = new Text(scoreLiv, Point2D(370, 660), colorText, GLUT_BITMAP_9_BY_15);
	addText_to_Visual2D(textLives, v2d_scoreboard);

	if (levelNo > level.levelMax)
	{
		Text *text1;
		text1 = new Text("Game over. No more levels.", Point2D(300, 630), colorText, GLUT_BITMAP_9_BY_15);
		addText_to_Visual2D(text1, v2d_scoreboard);
		return;
	}
	if (lives < 0)
	{
		Text *text1;
		text1 = new Text("Game over. No more lives.", Point2D(300, 630), colorText, GLUT_BITMAP_9_BY_15);
		addText_to_Visual2D(text1, v2d_scoreboard);
		return;
	}

	if (level.enemies.size() == 0) 
	{
		levelNo++;
		level.newLevel(levelNo);
		timeout = clock();

		for (int i = 0; i < level.enemies.size(); i++) 
		{
			level.enemies[i]->updatePlayfieldSize ((float) margini, (float) margini, 
				(float) (DrawingWindow::width - margini), 
				(float) (DrawingWindow::height - margini - heightScoreBoard), v2d_playfield);
			level.enemies[i]->addEnemy2D(v2d_playfield);
		}

	}
	

	if (keyUpIsPressed)
		player->move(vitezaNava);
	if (keyLeftIsPressed)
		player->rotate(rotatieNava);
	if (keyRightIsPressed)
		player->rotate(-rotatieNava);

	for (int i = 0; i < level.enemies.size(); i++) 
	{

		level.enemies[i]->move(level.viteze[i], player);

		if (player->kills(level.enemies[i])) 
		{
			score += level.enemies[i]->score;
			level.enemies[i]->removeEnemy2D(v2d_playfield);
			level.enemies.erase(level.enemies.begin() + i);
			break;
		}

		if (player->isKilled(level.enemies[i]))
		{
			if (lives >= 0)
			{
				if ( ((clock() - timeout) / CLOCKS_PER_SEC) > 2)
				{
					lives--;
					timeout = clock();
				}
			}
			else
			{
				return;
			}
			
		}

	}

}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
		case 27 : {
			exit(0);
			break;
				  }

		case GLUT_KEY_LEFT: {
			keyLeftIsPressed = true;
			break;
							}

		case GLUT_KEY_RIGHT: {
			keyRightIsPressed = true;
			break;
							 }

		case GLUT_KEY_UP: {
			keyUpIsPressed = true;
			break;
						  }

		case 32 : {
			player->toggleWeapon();
			break;
				  }
	}

}

//functia care defineste ce se intampla cand la ridicarea unei taste
void DrawingWindow::upKey(unsigned char key)
{

	switch(key)
	{

		case GLUT_KEY_LEFT: {
			keyLeftIsPressed = false;
			break;
							}

		case GLUT_KEY_RIGHT: {
			keyRightIsPressed = false;
			break;
							 }

		case GLUT_KEY_UP: {
			keyUpIsPressed = false;
			break;
						  }
	}

}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{
}

int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 700, 700, 150, 10, "Geometry Wars");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;

}
