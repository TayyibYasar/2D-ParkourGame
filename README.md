# Parkour Game

This is a simple game with SFML library in C++. In the future, this project could evolve into a simple game engine as it continues to develop.


## Installation

Clone the project

```bash
git clone https://github.com/TayyibYasar/2D-ParkourGame.git
```

## Usage

1) SFML requires a 32-bit compiler, it won't work with a 64-bit compiler. For example, if u use DEV-C++ IDE make sure you select TDM-GCC 4.9.2 32-bit Release version as compiler.

2) From Tools menu, select Compiler Options. Make sure TDM-GCC 4.9.2 32-bit Release is also selected as the Compiler set to configure in the dropdown box in Compiler Options dialog. 

    In the dialog box, select the  checkbox next to “Add the following commands when calling the compiler”. Enter the following line to the 
text box below this option: 

       -I. -std=c++11 

      Similarly, into the bottom text box, enter the following line: 

       -static-libgcc -L. -lsfml-window -lsfml-graphics -lsfml-system


## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.


![alt text](https://github.com/TayyibYasar/2D-ParkourGame/blob/main/Game%20start.png)

![alt text](https://github.com/TayyibYasar/2D-ParkourGame/blob/main/Game-middle.png)

![alt text](https://github.com/TayyibYasar/2D-ParkourGame/blob/main/Game-end.png)
