# Ray-Tracing-Cpp-PWJC
In this repo we implement basic ray tracing algorithm for university project

## Linux:
```bash
premake5 gmake
make
```
## Windows:
```bash
premake5 vs2022
```
Generates .sln and .vcxproj files
1. Open the generated MojProjektCPP.sln file in Visual Studio.
2. Select the desired configuration (Debug or Release).
3. Build the solution.

## Running the app
To generate the image file, you must run the compiled executable and redirect its standard output to a file with the *.ppm* extension.
```bash
./bin/x64/Debug/Ray_Tracing > image.ppm 
```
To see the output image on Linux use `eog` or `feh`, and on Windows the best way is to convert *.ppm* file to png by some online tool
![Generated Image](/home/mzabiero/Documents/studia/PWJC/Ray-Tracing-Cpp-PWJC/image.png)
