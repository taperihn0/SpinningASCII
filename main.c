#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 165
#define HEIGHT 42

#define FPS_COUNT 60

typedef struct Vector3F_Type {
	float x, y, z;
} vec3f;

void rotateZ(vec3f* v, float offset) {
	vec3f cp = *v;
	v->x = cp.x * cos(offset) - cp.y * sin(offset);	
	v->y = cp.x * sin(offset) + cp.y * cos(offset);
}

void rotateY(vec3f* v, float offset) {
	vec3f cp = *v;
	v->x =  cp.x * cos(offset) + cp.z * sin(offset);	
	v->z = -cp.x * sin(offset) + cp.z * cos(offset);
}

void rotateX(vec3f* v, float offset) {
	vec3f cp = *v;
	v->y =  cp.y * cos(offset) - cp.z * sin(offset);	
	v->z =  cp.y * sin(offset) + cp.z * cos(offset);
}

// simplified projection operation.
// takes into consideration depth of the vertex
// which is shifted to be always negative (translation).
void project(vec3f* v) {
	v->x = v->x / (v->z - 1.5f);
	v->y = v->y / (v->z - 1.5f);
}

float dot(vec3f v1, vec3f v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

typedef struct BufferType {
	char  mem[HEIGHT][WIDTH];
	float   d[HEIGHT][WIDTH];
} Buffer;

void clear(Buffer* buff) {
	memset(buff->mem, ' ', sizeof(buff->mem));
	memset(buff->d, -10.f, sizeof(buff->d));
}

void draw(const Buffer* buff) {
	system("clear");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			putchar(buff->mem[i][j]);
		}

		putchar('\n');
	}

	usleep(1000 / FPS_COUNT * 1000);
}

void addVertex(Buffer* buff, vec3f v, char c) {
	const size_t y = ((v.y + 1.f) / 2.f * HEIGHT);
	const size_t x = (0.6f * (v.x + 1.f) / 2.f *  WIDTH);

	if (v.z > buff->d[y][x]) {
		buff->mem[y][x] = c;
		buff->d[y][x] = v.z;
	}
}	

// rotate vertex and normal by given angle offset
void rotateWall(vec3f* v, vec3f* n, float angle) {
	rotateY(v, angle);
	rotateZ(v, angle);
	rotateX(v, angle);

	rotateY(n, angle);
	rotateZ(n, angle);
	rotateX(n, angle);
}

void update(Buffer* buff) {
	static float 		angle = 0.f;

	static vec3f        l_v = { 0.f, 0.f, 1.f };
	static const char*  ll = ".,-~:;=!*#$@";
	static const size_t ll_cnt = 12;

	clear(buff);

	static float z_bk = -0.5f, 
				 z_fr = 0.5f;

	// back and front walls
	for (float y = -0.5f; y <= 0.5f; y += 0.005f) {
		for (float x = -0.5f; x <= 0.5f; x += 0.005f) {
			vec3f bk   = { x, y, z_bk };
			vec3f n_bk = { 0.f, 0.f, -1.f };

			rotateWall(&bk, &n_bk, angle);
			project(&bk);

			int s = ll_cnt * fmax(dot(n_bk, l_v), 0.f);
			addVertex(buff, bk, ll[s]);

			vec3f fr = { x, y, z_fr };
			vec3f n_fr = { 0.f, 0.f,  1.f };

			rotateWall(&fr, &n_fr, angle);
			project(&fr);

			s = ll_cnt * fmax(dot(n_fr, l_v), 0.f);
			addVertex(buff, fr, ll[s]);
		}
	}

	static float x_lf = -0.5f, 
				 x_rt = 0.5f;

	// right and left walls
	for (float y = -0.5f; y <= 0.5f; y += 0.005f) {
		for (float z = -0.5f; z <= 0.5f; z += 0.005f) {
			vec3f lf = { x_lf, y, z };
			vec3f n_lf = { -1.f, 0.f, 0.f };

			rotateWall(&lf, &n_lf, angle);
			project(&lf);

			int s = ll_cnt * fmax(dot(n_lf, l_v), 0.f);
			addVertex(buff, lf, ll[s]);

			vec3f rt = { x_rt, y, z };
			vec3f n_rt = {  1.f, 0.f, 0.f };

			rotateWall(&rt, &n_rt, angle);
			project(&rt);

			s = ll_cnt * fmax(dot(n_rt, l_v), 0.f);
			addVertex(buff, rt, ll[s]);
		}
	}


	static float y_up = 0.5f,
				 y_dn = -0.5f;

	// up and down walls
	for (float x = -0.5f; x <= 0.5f; x += 0.005f) {
		for (float z = -0.5f; z <= 0.5f; z += 0.005f) {
			vec3f up = { x, y_up, z };
			vec3f n_up = { 0.f,  1.f, 0.f };

			rotateWall(&up, &n_up, angle);
			project(&up);

			int s = ll_cnt * fmax(dot(n_up, l_v), 0.f);
			addVertex(buff, up, ll[s]);

			vec3f dn = { x, y_dn, z };
			vec3f n_dn = { 0.f, -1.f, 0.f };

			rotateWall(&dn, &n_dn, angle);
			project(&dn);

			s = ll_cnt * fmax(dot(n_dn, l_v), 0.f);
			addVertex(buff, dn, ll[s]);
		}
	}


	angle += 0.02f;
}	

int main() {
	Buffer buff;
	clear(&buff);

	while (true) {
		update(&buff);
		draw(&buff);
	}
}