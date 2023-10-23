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


## Пример вывода

```
FFT:

(342.368,-41.5205)
(6704.09,1004.64)
(-1637.83,-194.773)
(1994.16,1181.75)
(777.787,-1043.22)
(2535.51,159.398)
(5893.11,-1162.04)
(1046.15,1978.63)
(-2179.76,-829.904)
(585.771,474.123)
----------
FFT reverse:

(-6361.72,-1046.16)
(-2556.52,-2322.97)
(145.867,-3503.89)
(8098.17,-1545.56)
(-1427.18,-790.638)
(7046.46,963.122)
(-719.132,1933.43)
(1409.71,1417.46)
(3688.04,-778.517)
(-2932.34,-869.17)
----------
----------
(1438.94,58.9387)
(1096.57,100.459)
(6298.6,-78.6979)
(308.722,-1114.78)
(-295.837,891.928)
(-618.816,1612.12)
(-92.7965,175.925)
(1601.51,-1674)
(681.779,-284.546)
(-368.263,-670.208)
----------
----------
Mistake for DFT:5674.74
----------
----------
Mistake for FFT:3091.07
----------
----------
Mistake for reverse FFT:4058.1
```