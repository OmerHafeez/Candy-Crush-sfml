#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
using namespace sf;
using namespace std;

// IF YOU ADD MORE SPRITES, MODIFY GRAVITY CHECK

// Function declarations
int matchx(int x, int y);
int matchy(int x, int y);
void bearmatch(int k, int l);
void bunnymatch(int k, int l);
void koalamatch(int k, int l);
void catmatch(int k, int l);
void raccoonmatch(int k, int l);
void dogmatch(int k, int l);
void foxmatch(int k, int l);

// Global declaration
int Animal_Species[8][8], x_axis[8][8], y_axis[8][8];
int bear = 0, bunny = 0, koala = 0, cat = 0, raccoon = 0, dog = 0, fox = 0;
int score = 0;



int main() {
  int ts = 54; // tile size
  Vector2i offset(10, 20);//to position the tiles on the screen
  srand(time(0));//To generate new random values
  
  Music ingame;//music declaration
  ingame.openFromFile("sprites/InGameSong.wav");//loading ingame music
  ingame.play(); // Playing music
  ingame.setLoop(true);//setting a loop for the music
  
  //variable declarations
  Vector2i pos(0, 0), pos_copy(8, 8), pos_copy1(8, 8);//for mouse clicks
  int click = 0, Animal_Species_copy, a, b, pos_x1;
  //int gravitycheck(int x, int y);
  // Flags used to verify explosion
  bool Flag_xMatch;
  bool Flag_yMatch;
  int timer, moves = 30;

  RenderWindow app1(VideoMode(740, 480), "Menagerie");//window size
  Texture title;
  title.loadFromFile("sprites/Title.png");//loading Title screen image
  Sprite title_background(title);//loading background


  while (app1.isOpen()) // Title window
  {
    app1.draw(title_background);//drawing background on title window
    app1.display();
    Event f;
    while (app1.pollEvent(f)) {
      if (f.type == Event::Closed)//window will close when the user presses on the 'x' button
        app1.close();
      if (f.type == Event::KeyPressed) {
       
       
        if (f.key.code == Keyboard::Enter) // Title page will be redirected to the menu page on the key press 'Enter'
        {
          app1.close();//title window will be closed

          RenderWindow app4(VideoMode(740, 480), "Menagerie");//window size
          Texture Menu;
          Menu.loadFromFile("sprites/Menu.png");//loading background for menu window
          Sprite Menu1(Menu);
          
	  while (app4.isOpen()) // menu window
          {
            Event i;
            app4.draw(Menu1);//drawing menu background
            app4.display();//displaying menu background
            while (app4.pollEvent(i)) {
              if (i.type == Event::Closed)//window will close when the user presses on the 'x' button
                app4.close();
              if (i.type == Event::KeyPressed) {
                app4.close();//menu window will be closed
                
                
                
                
                if (i.key.code == Keyboard::Num3) // Menu Page will be redirected to help page on the 'Num3' button
                {
                  RenderWindow app5(VideoMode(740, 480), "Menagerie");//window size
                  Texture Help;
                  Menu.loadFromFile("sprites/Help.png");//loading background for the help window
                  Sprite Help1(Help);

                  while (app5.isOpen()) // Help window
                  {
                    Event j;
                    app5.draw(Menu1);//drawing background for help window
                    app5.display();
                    while (app5.pollEvent(j)) {
                      if (j.type == Event::Closed)//window will close when the user presses on the 'x' button
                        app5.close();
                      if (j.type == Event::KeyPressed) {
                        if (j.key.code == Keyboard::Escape)//window will close when the user presses on the 'Escape' button
                          app5.close();
                      }
                    }
                  }
                }
                
                
                
                
                if (i.key.code ==
                    Keyboard::Num4) // Menu Page will be redirected to
                                    // Highscores page on the 'Num4' button
                {
                }
                
                
                
                
                
                if (i.key.code ==
                    Keyboard::Num2) // Menu Page will be redirected to Level 2
                                    // ingame window on the 'Num2' button
                {
                  app4.close();
                  RenderWindow app6(VideoMode(740, 480), "Level 2");//window size
                  app6.setFramerateLimit(60);
                  Texture t1, t2;
                  t1.loadFromFile("sprites/Background.png");//loading background for level 2 window
                  t2.loadFromFile("sprites/animals.png");//loading animal images
                  Sprite background(t1), gems(t2);
                  Event k;
                  
                  Clock clock;//declaration for timer
                  
                  for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                      // 0)Bear  1)Bunny  2)Koala  3)Cat  4)Raccoon  5)Dog 6)Fox
                      Animal_Species[i][j] = rand() % 7; // Saving random numbers that represents
                                      // the number of animal species
                      x_axis[i][j] = j * ts; // Grid x-axis
                      y_axis[i][j] = i * ts; // Grid y-axis
                    }
                  }
                  
                  while (app6.isOpen()) // level 2 Ingame window
                  {
                    Time elapsed=clock.getElapsedTime();//storing time as the window runs on loop
                    timer=elapsed.asSeconds();//time will be displayed as seconds
		   
                    while (app6.pollEvent(k)) {
                      if (k.type == Event::Closed) {
                        app6.close();//window will be closed if the user presses 'x' button
                      }
                      if (k.type == Event::MouseButtonPressed)
                        if (k.key.code == Mouse::Left) // Sprites will move with
                                                       // left mouse click
                        {
                          click++;
                          pos = Mouse::getPosition(app6) -
                                offset; // offsetting the mouse position

                          // code of action to be performed on mouse click
                        }
                    }
                    if (timer >= 120) // You lose window
                    {
                      app6.close();//level 2 window will be closed
                      RenderWindow app2(VideoMode(740, 480), "Menagerie");//window size
                      Texture YouLose;
                      YouLose.loadFromFile("sprites/YouLoseLVL2.png");//loading background for You Lose window
                      Sprite You_Lose(YouLose);
                      Event g;
                      while (app2.isOpen()) {

                        while (app2.pollEvent(g)) {
                          if (g.type == Event::Closed)//window will be closed if the user presses 'x' button
                            app2.close();
                          if (g.type == Event::KeyPressed) {
                            if (g.key.code ==
                                Keyboard::Escape) // Window will close with
                                                  // Keyboard press "Escape"
                            {
                              app2.close();
                            }
                          }
                        }
                        app2.draw(You_Lose);//drawing background for you lose window
                        app2.display();
                      }
                    }
                    if (score >= 250) // You win window
                    {
                      app6.close();//level 2 window will be closed
                      RenderWindow app3(VideoMode(740, 480), "Menagerie");//window size
                      Texture YouWin;
                      YouWin.loadFromFile("sprites/YouWin.png");//loading background for You Win window
                      Sprite You_Win(YouWin);
                      Event h;
                      while (app3.isOpen()) {

                        while (app3.pollEvent(h)) {
                          if (h.type == Event::Closed)//window will be closed if the user presses 'x' button
                            app3.close();
                          if (h.type == Event::KeyPressed) {
                            if (h.key.code ==
                                Keyboard::Escape) // Window will close with
                                                  // Keyboard press "Escape"
                            {
                              app3.close();
                            }
                          }
                        }
                        app3.draw(You_Win);//loading background for You Win window
                        app3.display();
                      }
                    }
                    if (click == 1) {
                      pos_copy.x = pos.x / ts; // Copying the x coordinate of
                                               // the first mouse click
                      pos_copy.y = pos.y / ts; // Copying the y coordinate of
                                               // the first mouse click
                    }
                    if (click == 2) {
                      pos_copy1.x = pos.x / ts; // Copying the x coordinate of
                                                // the second mouse click
                      pos_copy1.y = pos.y / ts; // Copying the y coordinate of
                                                // the second mouse click
                      click = 0; // Refreshing the mouseclick counter after 2 clicks
                    }
                    app6.draw(background);//drawing background for level 2 window

                    for (int i = 0; i < 8; i++) {
                      for (int j = 0; j < 8; j++) {

                        if (pos_copy.x == x_axis[i][j] / ts &&
                            pos_copy.y == y_axis[i][j] / ts) {
                          a = i;
                          b = j; // Storing the positions of the array from the
                                 // first click to be used for swapping
                          Animal_Species_copy =
                              Animal_Species[i][j]; // Storing the tile of the
                                                    // first mouse click into a
                                                    // temp int
                        }
                           //condition to swap the tile with its adjacent tile
                        if ((pos_copy1.x - pos_copy.x == 1 &&
                             pos_copy1.y - pos_copy.y == 0) ||
                            (pos_copy.x - pos_copy1.x == 1 &&
                             pos_copy.y - pos_copy1.y == 0) ||
                            (pos_copy1.x - pos_copy.x == 0 &&
                             pos_copy1.y - pos_copy.y == 1) ||
                            (pos_copy.x - pos_copy1.x == 0 &&
                             pos_copy.y - pos_copy1.y == 1)) {

                          if (pos_copy1.x == x_axis[i][j] / ts &&
                              pos_copy1.y == y_axis[i][j] / ts) {
                            // Swapping the tiles from the first click with the
                            // tiles from the second click
                            Animal_Species[a][b] = Animal_Species[i][j];
                            Animal_Species[i][j] = Animal_Species_copy;
                            pos_copy.x = 8;  // to refresh the temp vector
                            pos_copy.y = 8;  // to refresh the temp vector
                            pos_copy1.x = 8; // to refresh the temp vector
                            pos_copy1.y = 8; // to refresh the temp vector
                          }
                        }

                        gems.setTextureRect(
                            IntRect(Animal_Species[i][j] * 49, 0, 49,
                                    49)); // Breaking animals img into 7 pieces
                        gems.setPosition(x_axis[i][j],y_axis[i][j]); 
                        		   // Sets the position where we want to
                                           // print the animal specie
                        gems.move(offset.x, offset.y); // moves the object to
                                                       // the specified position
                        app6.draw(gems);//drawing animal image on the window as seperated tiles
                      }
                      for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                          // Without using flags, we might run into issues with
                          // repeated collisions.
                          Flag_xMatch = false;
                          Flag_yMatch = false;

                          if (matchx(k, l) == 1)
                            Flag_xMatch = true;

                          if (matchy(k, l) == 1)
                            Flag_yMatch = true;
                          if (Flag_xMatch) {
                            // animals will be replaced by new tiles after
                            // matching horizontally
                            Animal_Species[k][l] = rand() % 7;
                            Animal_Species[k][l + 1] = rand() % 7;
                            Animal_Species[k][l - 1] = rand() % 7;

                            // Function calling for animal count
                            bearmatch(k, l);
                            bunnymatch(k, l);
                            koalamatch(k, l);
                            catmatch(k, l);
                            raccoonmatch(k, l);
                            dogmatch(k, l);
                            foxmatch(k, l);
                          }
                          if (Flag_yMatch) {
                            // animals will be replaced by new tiles after
                            // matching horizontally
                            Animal_Species[k][l] = rand() % 7;
                            Animal_Species[k + 1][l] = rand() % 7;
                            Animal_Species[k - 1][l] = rand() % 7;

                            // Function calling for animal count
                            bearmatch(k, l);
                            bunnymatch(k, l);
                            koalamatch(k, l);
                            catmatch(k, l);
                            raccoonmatch(k, l);
                            dogmatch(k, l);
                            foxmatch(k, l);
                          }
                        }
                      }
                    }

                    // Printing scores, moves, and animal count on screen//
                    Font Calibri;
                    Calibri.loadFromFile("sprites/Calibri.ttf");//loading Calibri font for the level2 window
                    Text text, text1, text2, text3, text4, text5, text6, text7,
                        text8, text9, text10, text11, text12, text13, text14,
                        text15, text16, text17;
                    // Printing score
                    text.setFont(Calibri);//setting font as calibri
                    string scores = to_string(score);//score variable will be printed as a string
                    Text scores1(scores, Calibri);//score will be printed as in Calibri font
                    scores1.setCharacterSize(23);//setting character size 23
                    scores1.setFillColor(Color::Black);//setting font color black
                    scores1.setPosition(640, 200);//position on the right side of the window

                    text1.setFont(Calibri);//setting font as calibri
                    text1.setString("SCORE:");//Printing string 'SCORE:' on the window
                    text1.setCharacterSize(23);//setting character size 23
                    text1.setFillColor(Color::Magenta);//setting font color magenta
                    text1.setPosition(470, 200);//positioning on the right side of the window

		    //the same logic will be repeated to display other things
                    // Printing timer
                    text2.setFont(Calibri);
                    text2.setString("Timer:");
                    text2.setCharacterSize(23);
                    text2.setFillColor(Color::Magenta);
                    text2.setPosition(470, 230);

                    text3.setFont(Calibri);
                    string timer_A = to_string(timer);
                    Text timer1(timer_A, Calibri);
                    timer1.setCharacterSize(23);
                    timer1.setFillColor(Color::Black);
                    timer1.setPosition(640, 230);

                    // Printing count of bear
                    text4.setFont(Calibri);
                    text4.setString("Bear count:");
                    text4.setCharacterSize(23);
                    text4.setFillColor(Color::Magenta);
                    text4.setPosition(470, 260);

                    text5.setFont(Calibri);
                    string bear_A = to_string(bear);
                    Text bear1(bear_A, Calibri);
                    bear1.setCharacterSize(23);
                    bear1.setFillColor(Color::Black);
                    bear1.setPosition(640, 260);

                    // Printing count of bunny
                    text6.setFont(Calibri);
                    text6.setString("Bunny count:");
                    text6.setCharacterSize(23);
                    text6.setFillColor(Color::Magenta);
                    text6.setPosition(470, 290);

                    text7.setFont(Calibri);
                    string bunny_A = to_string(bunny);
                    Text bunny1(bunny_A, Calibri);
                    bunny1.setCharacterSize(23);
                    bunny1.setFillColor(Color::Black);
                    bunny1.setPosition(640, 290);

                    // Printing count of koala
                    text8.setFont(Calibri);
                    text8.setString("Koala count:");
                    text8.setCharacterSize(23);
                    text8.setFillColor(Color::Magenta);
                    text8.setPosition(470, 320);

                    text9.setFont(Calibri);
                    string koala_A = to_string(koala);
                    Text koala1(koala_A, Calibri);
                    koala1.setCharacterSize(23);
                    koala1.setFillColor(Color::Black);
                    koala1.setPosition(640, 320);

                    // Printing count of cat
                    text10.setFont(Calibri);
                    text10.setString("Cat count");
                    text10.setCharacterSize(23);
                    text10.setFillColor(Color::Magenta);
                    text10.setPosition(470, 350);

                    text11.setFont(Calibri);
                    string cat_A = to_string(cat);
                    Text cat1(cat_A, Calibri);
                    cat1.setCharacterSize(23);
                    cat1.setFillColor(Color::Black);
                    cat1.setPosition(640, 350);

                    // Printing count of raccoon
                    text12.setFont(Calibri);
                    text12.setString("Raccoon count:");
                    text12.setCharacterSize(23);
                    text12.setFillColor(Color::Magenta);
                    text12.setPosition(470, 380);

                    text13.setFont(Calibri);
                    string raccoon_A = to_string(raccoon);
                    Text raccoon1(raccoon_A, Calibri);
                    raccoon1.setCharacterSize(23);
                    raccoon1.setFillColor(Color::Black);
                    raccoon1.setPosition(640, 380);

                    // Printing count of dog
                    text14.setFont(Calibri);
                    text14.setString("Dog count:");
                    text14.setCharacterSize(23);
                    text14.setFillColor(Color::Magenta);
                    text14.setPosition(470, 410);

                    text15.setFont(Calibri);
                    string dog_A = to_string(dog);
                    Text dog1(dog_A, Calibri);
                    dog1.setCharacterSize(23);
                    dog1.setFillColor(Color::Black);
                    dog1.setPosition(640, 410);

                    // Printing count of fox
                    text16.setFont(Calibri);
                    text16.setString("Fox count:");
                    text16.setCharacterSize(23);
                    text16.setFillColor(Color::Magenta);
                    text16.setPosition(470, 440);

                    text17.setFont(Calibri);
                    string fox_A = to_string(fox);
                    Text fox1(fox_A, Calibri);
                    fox1.setCharacterSize(23);
                    fox1.setFillColor(Color::Black);
                    fox1.setPosition(640, 440);
                    // Printing scores, moves, and animal count on screen//

                    // Drawing everything on the window
                    app6.draw(scores1);
                    app6.draw(timer1);
                    app6.draw(bear1);
                    app6.draw(bunny1);
                    app6.draw(koala1);
                    app6.draw(cat1);
                    app6.draw(raccoon1);
                    app6.draw(dog1);
                    app6.draw(fox1);
                    app6.draw(text1);
                    app6.draw(text2);
                    app6.draw(text3);
                    app6.draw(text4);
                    app6.draw(text5);
                    app6.draw(text6);
                    app6.draw(text7);
                    app6.draw(text8);
                    app6.draw(text9);
                    app6.draw(text10);
                    app6.draw(text11);
                    app6.draw(text12);
                    app6.draw(text13);
                    app6.draw(text14);
                    app6.draw(text15);
                    app6.draw(text16);
                    app6.display();
					if(score < 0)
					{
						score = 0;
					}
                    
                  
                  }
                }
                
                
                
                
                
                if (i.key.code ==
                    Keyboard::Num1) // Menu Page will be redirected to Level 1
                                    // ingame window
                {
                  app4.close();
                  RenderWindow app(VideoMode(740, 480), "Level 1");
                  app.setFramerateLimit(60);
                  Texture t1, t2;
                  t1.loadFromFile("sprites/Background.png");
                  t2.loadFromFile("sprites/animals.png");
                  Sprite background(t1), gems(t2);
                  Event e;

                  for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                      // 0)Bear  1)Bunny  2)Koala  3)Cat  4)Raccoon  5)Dog 6)Fox
                      Animal_Species[i][j] =
                          rand() % 7; // Saving random numbers that represents
                                      // the number of animal species
                      x_axis[i][j] = j * ts; // Grid x-axis
                      y_axis[i][j] = i * ts; // Grid y-axis
                    }
                  }

                  while (app.isOpen()) // level 1 Ingame window
                  {

                    while (app.pollEvent(e)) {
                      if (e.type == Event::Closed) {
                        app.close();//window will be closed if the user presses 'x' button
                      }
                      if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) // Sprites will move with
                                                       // left mouse click
                        {
                          click++;
                          pos = Mouse::getPosition(app) -
                                offset; // offsetting the mouse position

                          // code of action to be performed on mouse click
                        }
                    }
                    if (moves <= 0) // You lose window
                    {
                      app.close();//level 1 window will be closed
                      RenderWindow app2(VideoMode(740, 480), "Menagerie");//window size
                      Texture YouLose;
                      YouLose.loadFromFile("sprites/YouLose.png");//loading background for You Lose window
                      Sprite You_Lose(YouLose);
                      Event g;
                      while (app2.isOpen()) {

                        while (app2.pollEvent(g)) {
                          if (g.type == Event::Closed)//window will be closed if the user presses 'x' button
                            app2.close();
                          if (g.type == Event::KeyPressed) {
                            if (g.key.code ==
                                Keyboard::Escape) // Window will close with
                                                  // Keyboard press "Escape"
                            {
                              app2.close();
                            }
                          }
                        }
                        app2.draw(You_Lose);//drawing background for you lose window
                        app2.display();
                      }
                    }
                    if (score >= 250) // You win window
                    {
                      app.close();//level 1 window will be closed
                      RenderWindow app3(VideoMode(740, 480), "Menagerie");//window size
                      Texture YouWin;
                      YouWin.loadFromFile("sprites/YouWin.png");//loading background for You Win window
                      Sprite You_Win(YouWin);
                      Event h;
                      while (app3.isOpen()) {

                        while (app3.pollEvent(h)) {
                          if (h.type == Event::Closed)//window will be closed if the user presses 'x' button
                            app3.close();
                          if (h.type == Event::KeyPressed) {
                            if (h.key.code ==
                                Keyboard::Escape) // Window will close with
                                                  // Keyboard press "Escape"
                            {
                              app3.close();
                            }
                          }
                        }
                        app3.draw(You_Win);//loading background for You Win window
                        app3.display();
                      }
                    }
                    if (click == 1) {
                      pos_copy.x = pos.x / ts; // Copying the x coordinate of
                                               // the first mouse click
                      pos_copy.y = pos.y / ts; // Copying the y coordinate of
                                               // the first mouse click
                    }
                    if (click == 2) {
                      pos_copy1.x = pos.x / ts; // Copying the x coordinate of
                                                // the second mouse click
                      pos_copy1.y = pos.y / ts; // Copying the y coordinate of
                                                // the second mouse click
                      click =
                          0; // Refreshing the mouseclick counter after 2 clicks
                    }
                    app.draw(background);//drawing background for level 1 window

                    for (int i = 0; i < 8; i++) {
                      for (int j = 0; j < 8; j++) {

                        if (pos_copy.x == x_axis[i][j] / ts &&
                            pos_copy.y == y_axis[i][j] / ts) {
                          a = i;
                          b = j; // Storing the positions of the array from the
                                 // first click to be used for swapping
                          Animal_Species_copy =
                              Animal_Species[i][j]; // Storing the tile of the
                                                    // first mouse click into a
                                                    // temp int
                        }
                        //condition to swap the tile with its adjacent tile
                        if ((pos_copy1.x - pos_copy.x == 1 &&
                             pos_copy1.y - pos_copy.y == 0) ||
                            (pos_copy.x - pos_copy1.x == 1 &&
                             pos_copy.y - pos_copy1.y == 0) ||
                            (pos_copy1.x - pos_copy.x == 0 &&
                             pos_copy1.y - pos_copy.y == 1) ||
                            (pos_copy.x - pos_copy1.x == 0 &&
                             pos_copy.y - pos_copy1.y == 1)) {

                          if (pos_copy1.x == x_axis[i][j] / ts &&
                              pos_copy1.y == y_axis[i][j] / ts) {
                            // Swapping the tiles from the first click with the
                            // tiles from the second click
                            Animal_Species[a][b] = Animal_Species[i][j];
                            Animal_Species[i][j] = Animal_Species_copy;
                            pos_copy.x = 8;  // to refresh the temp vector
                            pos_copy.y = 8;  // to refresh the temp vector
                            pos_copy1.x = 8; // to refresh the temp vector
                            pos_copy1.y = 8; // to refresh the temp vector
                            moves--;//decrementing the moves with each swap
                          }
                        }

                        gems.setTextureRect(
                            IntRect(Animal_Species[i][j] * 49, 0, 49,
                                    49)); // Breaking animals img into 7 pieces
                        gems.setPosition(
                            x_axis[i][j],
                            y_axis[i][j]); // Sets the position where we want to
                                           // print the animal specie
                        gems.move(offset.x, offset.y); // moves the object to
                                                       // the specified position
                        app.draw(gems);//drawing animal image on the window as seperated tiles
                      }
                      for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                          // Without using flags, we might run into issues with
                          // repeated collisions.
                          Flag_xMatch = false;
                          Flag_yMatch = false;

                          if (matchx(k, l) == 1)
                            Flag_xMatch = true;

                          if (matchy(k, l) == 1)
                            Flag_yMatch = true;
                          if (Flag_xMatch) {
                            // animals will be replaced by new tiles after
                            // matching horizontally
                            Animal_Species[k][l] = rand() % 7;
                            Animal_Species[k][l + 1] = rand() % 7;
                            Animal_Species[k][l - 1] = rand() % 7;

                            // Function calling for animal count
                            bearmatch(k, l);
                            bunnymatch(k, l);
                            koalamatch(k, l);
                            catmatch(k, l);
                            raccoonmatch(k, l);
                            dogmatch(k, l);
                            foxmatch(k, l);
                          }
                          if (Flag_yMatch) {
                            // animals will be replaced by new tiles after
                            // matching horizontally
                            Animal_Species[k][l] = rand() % 7;
                            Animal_Species[k + 1][l] = rand() % 7;
                            Animal_Species[k - 1][l] = rand() % 7;

                            // Function calling for animal count
                            bearmatch(k, l);
                            bunnymatch(k, l);
                            koalamatch(k, l);
                            catmatch(k, l);
                            raccoonmatch(k, l);
                            dogmatch(k, l);
                            foxmatch(k, l);
                          }
                        }
                      }
                    }

                    // Printing scores, moves, and animal count on screen//
                    Font Calibri;
                    Calibri.loadFromFile("sprites/Calibri.ttf");//loading Calibri font for the level1 window
                    Text text, text1, text2, text3, text4, text5, text6, text7,
                        text8, text9, text10, text11, text12, text13, text14,
                        text15, text16, text17;
                    // Printing score
                    text.setFont(Calibri);//setting font as calibri
                    string scores = to_string(score);//score variable will be printed as a string
                    Text scores1(scores, Calibri);//score will be printed as in Calibri font
                    scores1.setCharacterSize(23);//setting character size 23
                    scores1.setFillColor(Color::Black);//setting font color black
                    scores1.setPosition(640, 200);//position on the right side of the window

                    text1.setFont(Calibri);//setting font as calibri
                    text1.setString("SCORE:");//Printing string 'SCORE:' on the window
                    text1.setCharacterSize(23);//setting character size 23
                    text1.setFillColor(Color::Magenta);//setting font color magenta
                    text1.setPosition(470, 200);//positioning on the right side of the window
		     
		    //the same logic will be repeated to display other things
                    // Printing move
                    text2.setFont(Calibri);
                    text2.setString("Moves:");
                    text2.setCharacterSize(23);
                    text2.setFillColor(Color::Magenta);
                    text2.setPosition(470, 230);

                    text3.setFont(Calibri);
                    string moves_A = to_string(moves);
                    Text moves1(moves_A, Calibri);
                    moves1.setCharacterSize(23);
                    moves1.setFillColor(Color::Black);
                    moves1.setPosition(640, 230);

                    // Printing count of bear
                    text4.setFont(Calibri);
                    text4.setString("Bear count:");
                    text4.setCharacterSize(23);
                    text4.setFillColor(Color::Magenta);
                    text4.setPosition(470, 260);

                    text5.setFont(Calibri);
                    string bear_A = to_string(bear);
                    Text bear1(bear_A, Calibri);
                    bear1.setCharacterSize(23);
                    bear1.setFillColor(Color::Black);
                    bear1.setPosition(640, 260);

                    // Printing count of bunny
                    text6.setFont(Calibri);
                    text6.setString("Bunny count:");
                    text6.setCharacterSize(23);
                    text6.setFillColor(Color::Magenta);
                    text6.setPosition(470, 290);

                    text7.setFont(Calibri);
                    string bunny_A = to_string(bunny);
                    Text bunny1(bunny_A, Calibri);
                    bunny1.setCharacterSize(23);
                    bunny1.setFillColor(Color::Black);
                    bunny1.setPosition(640, 290);

                    // Printing count of koala
                    text8.setFont(Calibri);
                    text8.setString("Koala count:");
                    text8.setCharacterSize(23);
                    text8.setFillColor(Color::Magenta);
                    text8.setPosition(470, 320);

                    text9.setFont(Calibri);
                    string koala_A = to_string(koala);
                    Text koala1(koala_A, Calibri);
                    koala1.setCharacterSize(23);
                    koala1.setFillColor(Color::Black);
                    koala1.setPosition(640, 320);

                    // Printing count of cat
                    text10.setFont(Calibri);
                    text10.setString("Cat count");
                    text10.setCharacterSize(23);
                    text10.setFillColor(Color::Magenta);
                    text10.setPosition(470, 350);

                    text11.setFont(Calibri);
                    string cat_A = to_string(cat);
                    Text cat1(cat_A, Calibri);
                    cat1.setCharacterSize(23);
                    cat1.setFillColor(Color::Black);
                    cat1.setPosition(640, 350);

                    // Printing count of raccoon
                    text12.setFont(Calibri);
                    text12.setString("Raccoon count:");
                    text12.setCharacterSize(23);
                    text12.setFillColor(Color::Magenta);
                    text12.setPosition(470, 380);

                    text13.setFont(Calibri);
                    string raccoon_A = to_string(raccoon);
                    Text raccoon1(raccoon_A, Calibri);
                    raccoon1.setCharacterSize(23);
                    raccoon1.setFillColor(Color::Black);
                    raccoon1.setPosition(640, 380);

                    // Printing count of dog
                    text14.setFont(Calibri);
                    text14.setString("Dog count:");
                    text14.setCharacterSize(23);
                    text14.setFillColor(Color::Magenta);
                    text14.setPosition(470, 410);

                    text15.setFont(Calibri);
                    string dog_A = to_string(dog);
                    Text dog1(dog_A, Calibri);
                    dog1.setCharacterSize(23);
                    dog1.setFillColor(Color::Black);
                    dog1.setPosition(640, 410);

                    // Printing count of fox
                    text16.setFont(Calibri);
                    text16.setString("Fox count:");
                    text16.setCharacterSize(23);
                    text16.setFillColor(Color::Magenta);
                    text16.setPosition(470, 440);

                    text17.setFont(Calibri);
                    string fox_A = to_string(fox);
                    Text fox1(fox_A, Calibri);
                    fox1.setCharacterSize(23);
                    fox1.setFillColor(Color::Black);
                    fox1.setPosition(640, 440);
                    // Printing scores, moves, and animal count on screen//

                    // Drawing everything on the window
                    app.draw(scores1);
                    app.draw(moves1);
                    app.draw(bear1);
                    app.draw(bunny1);
                    app.draw(koala1);
                    app.draw(cat1);
                    app.draw(raccoon1);
                    app.draw(dog1);
                    app.draw(fox1);
                    app.draw(text1);
                    app.draw(text2);
                    app.draw(text3);
                    app.draw(text4);
                    app.draw(text5);
                    app.draw(text6);
                    app.draw(text7);
                    app.draw(text8);
                    app.draw(text9);
                    app.draw(text10);
                    app.draw(text11);
                    app.draw(text12);
                    app.draw(text13);
                    app.draw(text14);
                    app.draw(text15);
                    app.draw(text16);
                    app.display();
					if(score < 0)
					{
						score = 0;
					}
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

int matchx(int x, int y) {

  if ((Animal_Species[x][y] == Animal_Species[x][y + 1] &&
       Animal_Species[x][y] == Animal_Species[x][y - 1] &&
       Animal_Species[x][y] == Animal_Species[x][y + 2] &&
       Animal_Species[x][y] ==
           Animal_Species[x][y - 2])) // for chains of 4 equal species
  {
    score += 30;
  }
  if (Animal_Species[x][y] == Animal_Species[x][y + 1] &&
      Animal_Species[x][y] == Animal_Species[x][y + 2] &&
      Animal_Species[x][y] ==
          Animal_Species[x][y + 3]) // for chains of 4 equal species
  {
    score += 20;
  }

  if ((Animal_Species[x][y] == Animal_Species[x][y + 1] &&
       Animal_Species[x][y] == Animal_Species[x][y - 1])) {
    for (int k = 0; k < 8; k++) {
      for (int l = 0; l < 8; l++) {
        if (k != x && l != y) // checking for 2 chain in 1 move
        {
          if ((Animal_Species[k][l] == Animal_Species[k][l + 1] &&
               Animal_Species[k][l] == Animal_Species[k][l - 1])) {
            for (int m = 0; m < 8; m++) {
              for (int n = 0; n < 8; n++) {
                if (m != k && n != l) // checking for 3 chains in 1 move
                {
                  if ((Animal_Species[m][n] == Animal_Species[m][n + 1] &&
                       Animal_Species[m][n] == Animal_Species[m][n - 1])) {
                    for (int o = 0; o < 8; o++) {
                      for (int p = 0; p < 8; p++) {
                        if (o != m && p != n) // checking for 3 chains in 1 move
                        {
                          if ((Animal_Species[o][p] ==
                                   Animal_Species[o][p + 1] &&
                               Animal_Species[o][p] ==
                                   Animal_Species[o][p - 1])) {
                            for (int q = 0; q < 8; q++) {
                              for (int r = 0; r < 8; r++) {
                                if (q != o && r != p) {
                                  if ((Animal_Species[q][r] ==
                                           Animal_Species[q][r + 1] &&
                                       Animal_Species[q][r] ==
                                           Animal_Species[q][r - 1])) {
                                    score *= 5;
                                  }
                                }
                              }
                            }
                          } else
                            score *= 3;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    score += 10;

    return 1;
  }

  else
    return 0;
}
int matchy(int x, int y) {
  if ((Animal_Species[x][y] == Animal_Species[x + 1][y] &&
       Animal_Species[x][y] == Animal_Species[x - 1][y] &&
       Animal_Species[x][y] == Animal_Species[x + 2][y] &&
       Animal_Species[x][y] == Animal_Species[x - 2][y])) {
    score += 40;
  }
  if ((Animal_Species[x][y] == Animal_Species[x + 1][y] &&
       Animal_Species[x][y] == Animal_Species[x - 1][y] &&
       Animal_Species[x][y] == Animal_Species[x + 2][y] &&
       Animal_Species[x][y] == Animal_Species[x - 2][y] &&
       Animal_Species[x][y] == Animal_Species[x + 3][y] &&
       Animal_Species[x][y] == Animal_Species[x - 3][y])) {
    score += 50;
  }

  if ((Animal_Species[x][y] == Animal_Species[x + 1][y] &&
       Animal_Species[x][y] == Animal_Species[x - 1][y])) {
    for (int k = 0; k < 8; k++) {
      for (int l = 0; l < 8; l++) {
        if (k != x && l != y) {
          if ((Animal_Species[k][l] == Animal_Species[k + 1][l] &&
               Animal_Species[k][l] == Animal_Species[k - 1][l])) {
            for (int m = 0; m < 8; m++) {
              for (int n = 0; n < 8; n++) {
                if (m != k && n != l) {
                  if ((Animal_Species[m][n] == Animal_Species[m + 1][n] &&
                       Animal_Species[m][n] == Animal_Species[m - 1][n])) {
                    for (int o = 0; o < 8; o++) {
                      for (int p = 0; p < 8; p++) {
                        if (o != m && p != n) {
                          if ((Animal_Species[o][p] ==
                                   Animal_Species[o + 1][p] &&
                               Animal_Species[o][p] ==
                                   Animal_Species[o - 1][p])) {
                            for (int q = 0; q < 8; q++) {
                              for (int r = 0; r < 8; r++) {
                                if (q != o && r != p) {
                                  if ((Animal_Species[q][r] ==
                                           Animal_Species[q + 1][r] &&
                                       Animal_Species[q][r] ==
                                           Animal_Species[q - 1][r])) {
                                    score *= 5;
                                  }
                                }
                              }
                            }
                          } else
                            score *= 3;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    score += 10;

    return 1;
  }

  else
    return 0;
}

void bearmatch(int k, int l) // for bear count
{
  if (Animal_Species[k][l] == 0)
    bear += 3;
}
void bunnymatch(int k, int l) // for bunny count
{
  if (Animal_Species[k][l] == 1)
    bunny += 3;
}

void koalamatch(int k, int l) // for dog count
{
  if (Animal_Species[k][l] == 2)
    koala += 3;
}

void catmatch(int k, int l) // for cat count
{
  if (Animal_Species[k][l] == 3)
    cat += 3;
}

void raccoonmatch(int k, int l) // for raccoon count
{
  if (Animal_Species[k][l] == 4)
    raccoon += 3;
}

void dogmatch(int k, int l) // for dog count
{
  if (Animal_Species[k][l] == 5)
    dog += 3;
}
void foxmatch(int k, int l) // for fox count
{
  if (Animal_Species[k][l] == 6)
    fox += 3;
}

/*
int gravitycheck(int x, int y) //LOOP THIS 8 TO 0 INSTEAD OF 0 TO 8 
{
    bool Flag_Available = false;
    bool Flag_Spawnable = false; // Is this block at the top of stack? If not, something from above will fall in this block.
    int DropLocation = 69; // Which block is droppable?

    //Step 1: Is this cell available?
    if (Animal_Species[x][y] == 7)
    {
        Flag_Available = true;
    }

    //Step 2: Is this cell spawnable?
    for (int m = 0; m < 8; m++) 
    {
        if (y-m >= 0) 
        {
            if (Animal_Species[x][y - m] != 7){
                Flag_Spawnable == true;
                DropLocation = y - m;
                break;
            }
        }
    }
    
    if (Flag_yMatch){
    cout << "(" << x << " , " << y << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;
  //  cout << "(" << x << " , " << y+1 << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;
   // cout << "(" << x << " , " << y-1 << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;}
    
    if (Flag_xMatch){
    cout << "(" << x << " , " << y << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;
  //  cout << "(" << x+1 << " , " << y << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;
  //  cout << "(" << x-1 << " , " << y << ")" << "A" << Flag_Available << "S" << Flag_Spawnable;}
    
    
    //Step 3: Fill cell
    return 0;
}*/
