# lights

Qt application to design frames sets for lights project.

there is a lights matrix controlled by Atmega8 microcontroller.
this application is an editor of the scenarios for this system.

Intall Qt v.6:
```bash
sudo apt install qt6-base-dev qt6-base-dev-tools

qmake6 -v
```

Generate Makefile:
```bash
qmake6 light.pro
```

Build the application:
```bash
make -j$(nproc)
```

Run:
```bash
./lights
```

