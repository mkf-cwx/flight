#F450四旋翼与遥控器开发
------
遥控端只采用手动控制模式，带有悬停状态和飞行状态的开关
遥控端----发送数据(油门量，期望角度，状态位)

飞控框架
飞行状态：--目标角度(遥控端）-->+-------->角度环pid----+--->角速度环pid------->pwm--->电调

                              |                     |
                              |                     |
                              |<--------欧拉角       |<---------角速度



悬停模式：--目标位置(0)---->+------>位置环pid----+--->速度环pid------->角度环pid------->角速度环pid--->pwm---->电调

                          |                    |
                          |                    |
                          |<-------位移量       |<-------线速度
F4_Flight 文件夹存放四旋翼的程序代码

飞控端：使用主控芯片为STM32F411RET6，主要外围电路包括：mpu6050，优象光流计，nrf24l01射频模块

通过i2c协议获取mpu6050三轴加速度和三轴角速度，采用四元数互补滤波进行姿态解算，求解出欧拉角

光流计数据包为14个字节，20ms的发送间隔，故采用串口接收中断写入ringbuffer的方式接收，创建20ms的定时器中断读取并更新光流数据

通过spi协议获取nrf24l01的接收通道的数据，该数据为遥控端的控制信号

F4_Remote 文件夹存放遥控器的程序代码

遥控端：使用主控芯片为STM32F411RET6，主要外围电路包括：LCD触摸屏，nrf24l01射频模块，电位器及开关

LCD为ST7789V和FT6336芯片，分别采用的是SPI,I2C协议，用于显示遥控数据信息
