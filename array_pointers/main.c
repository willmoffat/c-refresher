/*
 * Demonstrate how utility functions can work with runtime sized arrays in C.
 * You must pass a pointer of the element type and do pointer arithmetic to
 * index into the array.
 */

#include <stdio.h>

#define MAX_Y 3
#define MAX_X 4

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
      printf("%d", *tile);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {

  // Allocate memory for world.
  int map[MAX_Y][MAX_X] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  struct World world;
  world.width = MAX_X;
  world.height = MAX_Y;
  world.map = (int *)&map;
  print_map(&world);

  return 0;
}
