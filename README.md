# Break_it_all
I am learning a little bit about OpenGL and this is a repository to put in practice my knowledge.
I am trying to create a simple brick breaking game.

You can build a Android version using Android Studio or a desktop version building it using CMake on Linux.

## Dependencies
- g++
- cmake
- libglfw3-dev
- libgles2-mesa-dev
- androind studio
- xorg-dev

### Android Studio installation
```
$ sudo add-apt-repository ppa:maarten-fonville/android-studio
$ sudo apt update
$ sudo apt install android-studio
```

## Build in Linux
Clone the project in your home directory
```console
$ git clone https://github.com/simonppg/Break_it_all.git ~/Break_it_all
$ cd Break_it_all
$ mkdir linux-build
$ cd linux-build
$ cmake ..
$ make all
```
run the tests
```console
$ cd Break_it_all/linux-build
$ make check
```

to run the examples
```console
$ cd Break_it_all/linux-build
$ make run
```

or

```console
$ cd Break_it_all/linux-build/app/src/main/cpp/hal
$ make all
$ ./linuxLauncher <no_example>
```

### build dependencies
I am using the GLFW and mesa libs, so install it first.
```console
$ sudo apt-get install libglfw3-dev libgles2-mesa-dev
```
### test dependencies
```console
$ sudo apt-get install libgtest-dev
$ sudo apt-get install cmake
$ cd /usr/src/gtest
$ sudo cmake CMakeLists.txt
$ sudo make
$ sudo cp *.a /usr/lib
```

## Run tests
```console
$ make check
```

## Build for Windows
TODO
