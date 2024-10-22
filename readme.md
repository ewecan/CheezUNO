# CheezUNO

> CheezUNO是一块让 IO引脚都带有酷炫LED的Arduino开发板

<img src="./image/3D_PCB_CheeseUNO_01.png"  style="zoom:80%;" />

## 硬件说明：

1. 模拟IO部分：**CheezUNO**使用了一个电压跟随器和三极管作为电流源，从而根据io口电压控制流过LED灯珠的电流来控制灯珠的亮度。
2. 数字IO部分：**CheezUNO**使用了一个滞回比较器，根据io口输入的电压和比较器设置的阈值做对比，高过阈值就点亮LED灯，反之就熄灭LED灯。这里推荐一个 [在线仿真网站](http://scratch.trtos.com/circuitjs.html)用来测试模拟电压阈值。
3. 电源部分：**CheezUNO**使用了DC-DC降压，支持12V输入。同时板载了电源切换电路，当检测到 DC 端有电源输入时，则将 Type-C 电源切换到 DC 端输入，同时 VIN 灯将亮起（**注意！！！ VIN 电压：即为输入12V电压**）。
4. 串口驱动部分：**CheezUNO** 使用了CH343作为串口驱动，需要到沁恒官网下载驱动。
5. 接口：**CheezUNO** 使用了type-c作为烧录程序和串口通信的接口，同时预留了一个 I2C 的SH2.54接口和一个 User 按键（D2）方便朋友有做开发

## 软件说明：

1. 准备的Demo程序中需要使用到库 **SoftPWM**，可在Arduino里下载安装。
2. 烧录Bootloader：
   1. 板子焊好后需要烧录Bootloader，具体网上有很多资料啦~

## 其他说明：本项目为开源项目，不可商用！

<br/>

### 感谢以下项目：

> Uno Plus+： https://hackaday.io/project/189785-uno-plus
> 
> SoftPWM Library：https://github.com/bhagman/SoftPWM