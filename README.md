# Yadro_var2
## Установка компиллятора

Для запуска программы на Linux необходимо установить компиллятор g++:



```shell
sudo apt update
sudo apt upgrade
sudo apt install g++
```

## Запуск программы 
### Linux
```shell
g++ Yadro_var2.cpp FFT.cpp -o run
./run
```
### Windows
```shell
cl .\Yadro_var2\Yadro_var2.cpp .\Yadro_var2\FFT.cpp
.\Yadro_var2.exe
```