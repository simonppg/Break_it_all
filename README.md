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
- adb

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

## Android

This commands would build and run the app on your android phone and then show the logcat on the console.

```shell
./gradlew log
```

or if you want to change the filters, connect to you phone running a shell session using adb and then run logcat with different options.

```shell
./gradlew appStart
adb shell
logcat libNative:I *:S
```


## Build for Windows
TODO
