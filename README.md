# Break_it_all

I am learning a little bit about OpenGL and this is a repository to put in practice my knowledge.
I am trying to create a simple brick breaking game.

You can build a Android version using Android Studio or a desktop version building it using CMake on Linux.

[![CMake](https://github.com/simonppg/Break_it_all/actions/workflows/cmake.yml/badge.svg)](https://github.com/simonppg/Break_it_all/actions/workflows/cmake.yml)
[![Android CI](https://github.com/simonppg/Break_it_all/actions/workflows/android.yml/badge.svg)](https://github.com/simonppg/Break_it_all/actions/workflows/android.yml)
[![Lint Code Base](https://github.com/simonppg/Break_it_all/actions/workflows/linter.yml/badge.svg)](https://github.com/simonppg/Break_it_all/actions/workflows/linter.yml)

## Run it on Linux

### Linux Dependencies

- java # to run gradle wrapper
- g++
- cmake
- libglfw3-dev
- libgles2-mesa-dev
- xorg-dev
- adb
- Android sdk version 30
- androind studio # to download the SDK, still don't know how to make gradle download it before the build

### Build in Linux

1. First you need to have the Android sdk install somewhere.
2. Then clone the project.
3. Now manualy create a `local.properties` file in the root of the project with the Android sdk directory like this: `sdk.dir=/home/<User>/Android/Sdk`, **NOTE**: replace <User> with your username.
4. Finally you can run the build script `build-linux.sh` to build and run the app.


```shell
git clone https://github.com/simonppg/Break_it_all.git ~/Break_it_all
cd Break_it_all
touch local.properties
echo "sdk.dir=/home/<User>/Android/Sdk" >> local.properties
./build-linux.sh
```

### """Features available so far"""

If everything when well, the app should start running, and a new window will show a "sandbox scene".

- Handle window resize.
- Cursor position change detection.
- Key press detections only for ESC, W, A, S, D and L keys.
- Touch screen detection (Android only).

### Recompile app

After running the build script `build-linux.sh` you should have a `Break_it_all/linux-build` directory, there you can run `make` commands. So you can recompile again without waiting for `cmake` configurations.

```shell
cd Break_it_all/linux-build
make run
```

## Run it on Android

### From terminal

This commands would build and run the app on your Android phone and then show the logcat on the console.

```shell
./gradlew run
```

or if you want to change the filters, connect to you phone running a shell session using adb and then run logcat with different options.

```shell
./gradlew runApp
adb shell
logcat libNative:I *:S
```

Other useful gradle tasks:

```shell
./gradlew installDebug
./gradlew runApp
./gradlew clearLogcat
./gradlew run
```

### From Android Studio

If non of that works, you still can build with Android studio.

### Android studio dependencies

- Android studio of course.
- cmake
- Android sdk version 30
- Android ndk

You can install Android studio with this commands:

```shell
sudo add-apt-repository ppa:maarten-fonville/android-studio
sudo apt update
sudo apt install android-studio
```

Then just click on the run button I guess :see_no_evil:.

TODO: finish this part of the docs.
