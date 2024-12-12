#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 165
#define HEIGHT 42

#define FPS_COUNT 25

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

void update(Buffer* buff) {
	static float angle = 0.f;

	static vec3f        l_v = { 0.f, 0.f, 1.f };
	static const char*  ll = ".,-~:;=!*#$@";
	static const size_t ll_cnt = 12;

	clear(buff);

	static float z_bk = -0.5f, z_fr = 0.5f;

	// back and front walls
	for (float y = -0.5f; y <= 0.5f; y += 0.005f) {
		for (float x = -0.5f; x <= 0.5f; x += 0.005f) {
			vec3f bk   = { x, y, z_bk };
			vec3f n_bk = { 0.f, 0.f, -1.f };

			rotateY(&bk, angle);
			rotateZ(&bk, angle);
			rotateX(&bk, angle);

			rotateY(&n_bk, angle);
			rotateZ(&n_bk, angle);
			rotateX(&n_bk, angle);

			int s = ll_cnt * fmax(dot(n_bk, l_v), 0.f);
			addVertex(buff, bk, ll[s]);

			vec3f fr = { x, y, z_fr };
			vec3f n_fr = { 0.f, 0.f,  1.f };

			rotateY(&fr, angle);
			rotateZ(&fr, angle);
			rotateX(&fr, angle);

			rotateY(&n_fr, angle);
			rotateZ(&n_fr, angle);
			rotateX(&n_fr, angle);

			s = ll_cnt * fmax(dot(n_fr, l_v), 0.f);
			addVertex(buff, fr, ll[s]);
		}
	}

	static float x_lf = -0.5f, x_rt = 0.5f;

	// right and left walls
	for (float y = -0.5f; y <= 0.5f; y += 0.005f) {
		for (float z = -0.5f; z <= 0.5f; z += 0.005f) {
			vec3f lf = { x_lf, y, z };
			vec3f n_lf = { -1.f, 0.f, 0.f };

			rotateY(&lf, angle);
			rotateZ(&lf, angle);
			rotateX(&lf, angle);

			rotateY(&n_lf, angle);
			rotateZ(&n_lf, angle);
			rotateX(&n_lf, angle);

			int s = ll_cnt * fmax(dot(n_lf, l_v), 0.f);
			addVertex(buff, lf, ll[s]);

			vec3f rt = { x_rt, y, z };
			vec3f n_rt = {  1.f, 0.f, 0.f };

			rotateY(&rt, angle);
			rotateZ(&rt, angle);
			rotateX(&rt, angle);

			rotateY(&n_rt, angle);
			rotateZ(&n_rt, angle);
			rotateX(&n_rt, angle);

			s = ll_cnt * fmax(dot(n_lf, l_v), 0.f);
			addVertex(buff, rt, ll[s]);
		}
	}


	static float y_up = 0.5f, y_dn = -0.5f;

	// up and down walls
	for (float x = -0.5f; x <= 0.5f; x += 0.005f) {
		for (float z = -0.5f; z <= 0.5f; z += 0.005f) {
			vec3f up = { x, y_up, z };
			vec3f n_up = { 0.f,  1.f, 0.f };

			rotateY(&up, angle);
			rotateZ(&up, angle);
			rotateX(&up, angle);

			rotateY(&n_up, angle);
			rotateZ(&n_up, angle);
			rotateX(&n_up, angle);
			
			int s = ll_cnt * fmax(dot(n_up, l_v), 0.f);
			addVertex(buff, up, ll[s]);

			vec3f dn = { x, y_dn, z };
			vec3f n_dn = { 0.f, -1.f, 0.f };

			rotateY(&dn, angle);
			rotateZ(&dn, angle);
			rotateX(&dn, angle);

			rotateY(&n_dn, angle);
			rotateZ(&n_dn, angle);
			rotateX(&n_dn, angle);

			s = ll_cnt * fmax(dot(n_dn, l_v), 0.f);
			addVertex(buff, dn, ll[s]);
		}
	}


	angle += 0.06f;
}	

int main() {
	Buffer buff;
	clear(&buff);

	while (true) {
		update(&buff);
		draw(&buff);
	}
}