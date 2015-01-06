/*
 * Demonstrate how utility functions can work with runtime sized arrays in C.
 * You must pass a pointer of the element type and do pointer arithmetic to
 * index into the array.
 *
 * Also demonstrates ArrayCount macro.
 */

#include <stdio.h>

#define ArrayCount(array) (sizeof(array)/sizeof((array)[0]))

// This struct can represent any world size.
struct World {
  int width;
  int height;
  int *map;
};

// Utility func that world on any size of world.
void print_map(struct World *world) {
  int x, y;
  int *tile;
  for (y = 0; y < world->height; y++) {
    for (x = 0; x < world->width; x++) {
      tile = world->map + y * world->height + x;
      putchar(*tile ? '%' : '.');
    }
    putchar('\n');
  }
}

int main(int argc, char **argv) {

  // Allocate memory for world.
  int map[][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  struct World world;

  world.width = ArrayCount(map[0]);
  world.height = ArrayCount(map);
  world.map = (int *)&map;
  print_map(&world);

  return 0;
}
