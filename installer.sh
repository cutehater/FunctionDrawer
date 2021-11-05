sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt install qt5-default
sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
git clone https://github.com/cutehater/FunctionDrawer.git
mkdir FunctionDrawer/build
cd FunctionDrawer/build
qmake ../FunctionDrawer.pro
make
cd ../..
