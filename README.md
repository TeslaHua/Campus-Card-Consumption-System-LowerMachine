<font face="Times New Roman">

## 这是刷卡消费系统的下位机部分：

#### 1. 功能简介： 

  下位机完成S50卡的初始化(将卡号等信息存入该卡内)，通过射频模块来读取卡号，并在12864液晶显示屏上显示,通过薄膜键盘进行扣费金额输入，出现盗刷时下位机的指示灯闪烁，蜂鸣器鸣响。

#### 2. 开发环境
   
  下位机软件部分基于IAR for MSP430的开发平台来开发，电路图和PCB 板的设计是基于Altium designer来设计。WIFI 模块是采用的庆科的EMW3162 Tools工具来进行配置。

#### 3. 所需的相关硬件资源

  整个下位机部分的视图：

![LowerMachine](https://thumbnail0.baidupcs.com/thumbnail/24a8d3d6f12a33379b8cb117a4da309d?fid=559684340-250528-1037660589395931&time=1507611600&rt=pr&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-eLV%2fgfMajckfpW8UMZNRFpHzERI%3d&expires=8h&chkbd=0&chkv=0&dp-logid=6552991414200832615&dp-callid=0&size=c10000_u10000&quality=90&vuk=559684340&ft=image)


   (1). 电路板上所需的电子元器件（请参考电路图）
   
   (2). 12864液晶显示屏(3.3v供电)

   (3). A6 GSM短信模块

   (4). MFRC522射频读写模块

   (5). USB转串口

   (6). S50卡和钥匙卡扣

   (7). 薄膜矩阵键盘

#### 4. 焊接完成的PCB电路板如下图


![PCB](https://thumbnail0.baidupcs.com/thumbnail/de414cd0f8703ef97c14c6906466157c?fid=559684340-250528-468551037266572&time=1507611600&rt=pr&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-QEoIc%2bOhE%2f46q3j%2bOPYc0cvF4MM%3d&expires=8h&chkbd=0&chkv=0&dp-logid=6552991414200832615&dp-callid=0&size=c10000_u10000&quality=90&vuk=559684340&ft=image)

</font>