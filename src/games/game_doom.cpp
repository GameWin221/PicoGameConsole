#include "games_list.hpp"

#include <cmath>

#include <lcd_fonts/lcd_fonts.hpp>
#include <console_draw.hpp>
#include <console_lcd.hpp>

#include <console_core.hpp>
#include <console_audio.hpp>
#include <console_timing.hpp>
#include <console_input.hpp>

#define MAP_WIDTH  24
#define MAP_HEIGTH 24

#define ROTATE_SPEED -1.3f
#define MOVE_SPEED 1.2f

constexpr static uint8_t world_map[MAP_WIDTH][MAP_HEIGTH] = {
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

static float pos_x = 6, pos_y = 3.2f;
static float dir_x = -1, dir_y = 0;
static float plane_x = 0, plane_y = 0.66;

static void game_demo_init() {
	pos_x = 6, pos_y = 3.2f;
	dir_x = -1, dir_y = 0;
	plane_x = 0, plane_y = 0.66;
}
static void game_demo_exit() {
	
}
static void game_demo_update(const ConsoleInput& input, const ConsoleTiming& timing) {
    console_draw_fill(RGB565(0, 0, 0));

    if(input.joystick_x != 0) {
		float rotation = ROTATE_SPEED * input.joystick_x * timing.delta_time;

		float old_dir_x = dir_x;
      	dir_x = dir_x * cosf(-rotation) - dir_y * sinf(-rotation);
      	dir_y = old_dir_x * sinf(-rotation) + dir_y * cosf(-rotation);

      	float old_plane_x = plane_x;
      	plane_x = plane_x * cosf(-rotation) - plane_y * sinf(-rotation);
      	plane_y = old_plane_x * sinf(-rotation) + plane_y * cosf(-rotation);
	}

	if(input.joystick_y != 0) {
		float speed = MOVE_SPEED * input.joystick_y * timing.delta_time;

    	if(world_map[(uint32_t)(pos_x + dir_x * speed)][(uint32_t)pos_y] == 0) {
			pos_x += dir_x * speed;
		}

    	if(world_map[(uint32_t)pos_x][(uint32_t)(pos_y + dir_y * speed)] == 0) {
			pos_y += dir_y * speed;
		}
	}

	float half_h_f = 0.5f * LCD_HEIGHT;
	int half_h_i = LCD_HEIGHT / 2;

	// rayDir for leftmost ray (x = 0) and rightmost ray (x = LCD_WIDTH)
	float ray_dir_x0 = dir_x - plane_x;
	float ray_dir_y0 = dir_y - plane_y;
	float ray_dir_x1 = dir_x + plane_x;
	float ray_dir_y1 = dir_y + plane_y;

	for(int x = 0; x < LCD_WIDTH; ++x) {
		float camera_x = 2.0 * x / LCD_WIDTH - 1;
		float ray_dir_x = dir_x + plane_x * camera_x;
		float ray_dir_y = dir_y + plane_y * camera_x;

		int map_x = (int)pos_x;
		int map_y = (int)pos_y;

		float side_dist_x = 0.0f;
		float side_dist_y = 0.0f;

		float delta_dist_x = (ray_dir_x == 0.0) ? 1e30 : fabsf(1.0 / ray_dir_x);
		float delta_dist_y = (ray_dir_y == 0.0) ? 1e30 : fabsf(1.0 / ray_dir_y);

		int step_x = 0;
		int step_y = 0;

		if (ray_dir_x < 0) {
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else {
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0) {
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else {
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}

		bool side = false; //was a NS or a EW wall hit?

		while (true) {
			if (side_dist_x < side_dist_y) {
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = false;
			}
			else {
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = true;
			}

			if (world_map[map_x][map_y] > 0) break;
		} 

		float perp_wall_dist = side ? side_dist_y - delta_dist_y : side_dist_x - delta_dist_x;
		
		int line_height = (int)(LCD_HEIGHT / perp_wall_dist);

		int draw_start = -line_height / 2 + LCD_HEIGHT / 2 - 1;
		if(draw_start < 0) {
			draw_start = 0;
		}

		int draw_end = line_height / 2 + LCD_HEIGHT / 2;
		if(draw_end > LCD_HEIGHT) {
			draw_end = LCD_HEIGHT - 1;
		}
	
		uint8_t tex_index = world_map[map_x][map_y] - 1;

		float wall_x{}; 
		if (!side) {
			wall_x = pos_y + perp_wall_dist * ray_dir_y;
		} else {
			wall_x = pos_x + perp_wall_dist * ray_dir_x;
		}      

		wall_x -= floorf((wall_x));

		for(uint16_t y = draw_start; y < draw_end; ++y) {
			// generate random values for now 
			uint16_t r = tex_index * 142127;
			uint16_t g = tex_index * 555125;
			uint16_t b = tex_index * 666313;
			
			// vary the color based on the side
			if(side == 1) {
				console_draw_pixel(x, y, RGB565(r, g, b));
			} else {
				console_draw_pixel(x, y, RGB565(r / 2, g / 2, b / 2));
			}
		}

		for(uint16_t y = 0; y < draw_start; ++y) {
			console_draw_pixel(x, y, RGB565(180, 180, 180));
		}
		
		for(uint16_t y = draw_end; y < LCD_HEIGHT; ++y) {
			console_draw_pixel(x, y, RGB565(80, 80, 80));  
		}
	}
}

GameInfo game_doom_info {
	.game_init_fn = game_demo_init,
	.game_exit_fn = game_demo_exit,
	.game_update_fn = game_demo_update
};