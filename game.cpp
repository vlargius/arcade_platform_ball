#include "stdafx.h"
#include "svga/svga.h"
#include <memory>
#include <list>
#include <algorithm>

#include "game_field.h"
#include "racket.h"
#include "ball.h"
#include "drawer.h"

#include "colider.h"

extern int gButtons[6];

namespace {
	GameField field;
	std::unique_ptr<Drawer> drawer;

	std::unique_ptr<Racket> racket;

	std::unique_ptr<Ball> ball;

	std::list<Brick> bricks;

	const int BlocksCountX = 12; 
	const int BlocksCountY = 4;

	bool is_run = false;
}


//This function update full screen from scrptr. The array should be at least sv_height*scrpitch bytes size;
void w32_update_screen(void *scrptr,unsigned scrpitch);

extern bool game_quited;

//sv_width and sv_height variables are width and height of screen
extern unsigned int sv_width,sv_height;

//These functions called from another thread, when a button is pressed or released
void win32_key_down(unsigned k){
  if(k==VK_F1) game_quited=true;
}
void win32_key_up(unsigned){}

//This is default fullscreen shadow buffer. You can use it if you want to.
static unsigned *shadow_buf=NULL;

void init_game(){
  shadow_buf=new unsigned [sv_width*sv_height];
  drawer = std::make_unique<Drawer>(Drawer(shadow_buf, sv_width, sv_height));

  field = GameField{ sv_width, sv_height };
  racket = std::make_unique<Racket>(Racket(100, 20, { field.width / 2., field.height - field.height / 10. }, field));
  ball = std::make_unique<Ball>(Ball(10, 10, { field.width / 2., field.height - field.height / 5. }, field));

  int blockWidth = 50;
  int blockHeight = 10;
  for (int x = 0; x < BlocksCountX; ++x)
	  for (int y = 0; y < BlocksCountY; ++y)
		  bricks.emplace_back(Brick(blockWidth, blockHeight,
			  { (double)(x) * (blockWidth + 3) + 27, (double) (y + 5) * (blockHeight + 3) }));
}

void close_game(){
  if(shadow_buf) delete shadow_buf;
  shadow_buf=NULL;
}

//draw the game to screen
void draw_game(){
  if(!shadow_buf)return;
  memset(shadow_buf, 255,sv_width*sv_height*4);

  if (gButtons[3] == 1) {
	  is_run = true;
  }

  if (is_run) {

	  racket->update();
	  ball->update();

  }
  colider::colide(racket, ball);

  for (auto& b : bricks) colider::colide(&b, ball);
  bricks.erase(remove_if(begin(bricks), end(bricks),
	  [](const Brick& mBrick)
  {
	  return !mBrick.is_ok();
  }),
	  end(bricks));

  if (!ball->in_game()) close_game();

  drawer->draw(racket.get());
  drawer->draw(ball.get());

  for (auto b : bricks) { drawer->draw(&b); }

  //here you should draw anything you want in to shadow buffer. (0 0) is left top corner
  w32_update_screen(shadow_buf,sv_width*4);
}

//act the game. dt - is time passed from previous act
void act_game(float dt){
}
