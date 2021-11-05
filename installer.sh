sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt install qt5-default
git clone https://github.com/cutehater/FunctionDrawer.git
mkdir FunctionDrawer/build
cd FunctionDrawer/build
qmake ../FunctionDrawer.pro
make
