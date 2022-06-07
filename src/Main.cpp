#include "Tracer.h"
#include <stdio.h>
#include <string>

int main(int argc, char** argv) {
	glm::uvec2 rs;														// Image resolution: res_x, res_y
	glm::vec3 eye, v;													// Camera position and orientation up
	float a;															// Tan view angles
	int iter;
	float step, ra, Ra;

	SCamera camera;
	CScene scene;
	CTracer tracer;

	if(argc == 2) {														// There is input file in parameters
		FILE* file = fopen(argv[1], "r");

		if(file) {
			if (fscanf(file, "%d%d", &rs.x, &rs.y) != 2) {
				printf("Invalid config format! Using default parameters.\r\n");
			}
			else if (fscanf(file, "%f%f%f", &eye.x, &eye.y, &eye.z) != 3) {
				printf("Invalid config format! Using default parameters.\r\n");
			}
			else if (fscanf(file, "%f%f%f", &v.x, &v.y, &v.z) != 3) {
				printf("Invalid config format! Using default parameters.\r\n");
			}
			else if (fscanf(file, "%f%d%f%f%f", &a, &iter, &step, &ra, &Ra) != 5) {
				printf("Invalid config format! Using default parameters.\r\n");
			} else {
				camera.cset(rs, eye, v, a);
				scene.scset(iter, step, ra, Ra);
				tracer.tset(camera, scene);
			}

			fclose(file);
		}
		else {
			printf("Invalid config path! Using default parameters.\r\n");
		}
	} else {
		printf("No config! Using default parameters.\r\n");
	}

	tracer.RenderImage();
	tracer.SaveImageToFile("Result.png");
}
