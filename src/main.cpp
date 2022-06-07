#include "Tracer.h"
#include <stdio.h>

using namespace glm;

int main(int argc, char** argv)
{
  CTracer tracer;
  CScene scene;
  SCamera camera;
  uvec2 rs;
  vec3 eye, v;
  float a;
  int iter;
  float step, ra, Ra;
  if(argc == 2)
  {
    FILE* file = fopen(argv[1], "r");
    if(file)
    {
      if(fscanf(file, "%d%d", &rs.x, &rs.y) != 2)
      	printf("Invalid config format! Using default parameters.\r\n");
      else if(fscanf(file, "%f%f%f", &eye.x, &eye.y, &eye.z) != 3)
      	printf("Invalid config format! Using default parameters.\r\n");
      else if(fscanf(file, "%f%f%f", &v.x, &v.y, &eye.z) != 3)
      	printf("Invalid config format! Using default parameters.\r\n");
      	else if(fscanf(file, "%f%d%f%f%f", &a, &iter, &step, &ra, &Ra) != 5)
      	printf("Invalid config format! Using default parameters.\r\n");
      else {
        camera.cset(rs, eye, v, a);
        scene.scset(iter, step, ra, Ra);
        tracer.tset(camera, scene);
	}
      fclose(file);
    }

  }
  else printf("No config! Using default parameters.\r\n");
  tracer.RenderImage();
  tracer.SaveImageToFile("../img/Result.png");
  return 0;
}
