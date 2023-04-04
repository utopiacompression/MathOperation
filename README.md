# MathOperation
A ROS tutorial package includes a publisher and a subscriber.

## How to install
1. Download the code
2. Navigate to the workspace
```bash
cd math_ws
```
3. Cmake
```bash
catkin_make
```
If this leads to an error as python3 is not default version, use
```bash
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
```
4. Enable env
```bash
./devel/setup.bash
```

## How to run
```bash
roscore
```
In a new terminal,
```bash
roslaunch math_operation math_operation.launch
```

## About yaml file
The yaml files are placed under the package folder (i.e., math_operation/inputs.yaml) and the config folder (i.e., math_operation/config/inputs.yaml). They are identical.

When running the program, there is a known issue that the publisher node cannot find the path of yaml file by a relative path. One solution is to place the yaml file to the Desktop folder and use a absolute path to locate it). This is how this project solved the problem. Therefore, if encountering YAML::BadFile exception, copy and paste the yaml file to your Desktop.
