# Function Drawer
This is an UI app for getting a function plot on the specified interval.

The app supports wide variety of functions (absolute value, powers and logarithms, trigonometric and inverse trigonometric functions).

## Installing
1. Install `qtcreator` and `qmake` if you don't have it:

```bash
$ sudo apt-get update
$ sudo apt-get install build-essential
$ sudo apt-get install qtcreator
$ sudo apt install qt5-default
```
2. Clone the repository:

```bash
$ git clone https://github.com/cutehater/FunctionDrawer.git
```

3. Create build directory and open it:

```bash
$ mkdir FunctionDrawer/build
$ cd FunctionDrawer/build
```
4. Create executable file `FunctionDrawer`:

```bash
$ qmake ../FunctionDrawer.pro
$ make
```

## Usage
Function Drawer has pretty intuitive user interface: you just need to enter your function and segment bounds in special boxes and press `Draw` button to get function plot. Pay attention that you should type the function in a special format — you can learn more about it by pressing `?` button.
