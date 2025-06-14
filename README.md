# Get Started

openocd -s openocd -f target.cfg -c "program prj/STM32CubeF3_Demo_STM32F3-DISCOVERY.hex verify reset exit"