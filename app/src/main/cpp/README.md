# Build it on linux

## Dependencies
install [GLFW](https://www.glfw.org/), [The Mesa 3D Graphics Library](https://www.mesa3d.org/)

```console
$ sudo apt-get install libglfw3-dev libgles2-mesa-dev
```

## Build
```console
$ cd Break_it_all/app/src/main/cpp/
$ mkdir build
$ cd build
$ cmake ..
$ make run
```
