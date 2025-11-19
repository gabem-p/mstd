#pragma once

typedef struct {
    float x;
    float y;
} vec2;

typedef struct {
    float x;
    float y;
    float z;
} vec3;

typedef struct {
    float r;
    float g;
    float b;
    float a;
} color;

#define vec2(x, y) (vec2){x,y}
#define vec3(x, y, z) (vec3){x,y,z}
#define color(r, g, b, a) (color){r,g,b,a}

#define VEC2_ZERO (vec2){0,0}
#define VEC2_ONE (vec2){1,1}
#define VEC3_ZERO (vec3){0,0,0}
#define VEC3_ONE (vec3){1,1,1}

#define COLOR_RED (color){1,0,0,1}
#define COLOR_YELLOW (color){1,1,0,1}
#define COLOR_GREEN (color){0,1,0,1}
#define COLOR_CYAN (color){0,1,1,1}
#define COLOR_BLUE (color){0,0,1,1}
#define COLOR_MAGENTA (color){1,0,1,1}
#define COLOR_WHITE (color){1,1,1,1}
#define COLOR_BLACK (color){0,0,0,1}
#define COLOR_TRANSPARENT (color){0,0,0,0}