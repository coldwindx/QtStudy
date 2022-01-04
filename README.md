# QtStudy
## 信号和槽
&nbsp;&nbsp;QT框架引以为豪，本质是观察者模式。<br>
&nbsp;&nbsp;Signal信号来自被观察者，只需要函数声明，不需要实现，系统内大多数类都内置了信号；<br>
&nbsp;&nbsp;Slot槽来自观察者，本质是函数，必须有实现,系统内大多数类都内置了槽。<br>
&nbsp;&nbsp;使用connect函数为信号和槽建立连接，当信号广播（触发）时，槽做出相应处理。使用disconnect函数断开连接<br>
### 自定义信号和槽
&nbsp;&nbsp;自定义槽<br>
&nbsp;&nbsp;&nbsp;&nbsp;- 有函数声明且实现
&nbsp;&nbsp;&nbsp;&nbsp;- 返回值类型为void
&nbsp;&nbsp;&nbsp;&nbsp;- 可以带参，可以重载
&nbsp;&nbsp;自定义信号<br>
&nbsp;&nbsp;&nbsp;&nbsp;- 只需函数声明
&nbsp;&nbsp;&nbsp;&nbsp;- 返回值类型为void
&nbsp;&nbsp;&nbsp;&nbsp;- 可以带参，可以重载
&nbsp;&nbsp;emit用于触发信号，信号和槽的函数参数表需要一一对应，信号的参数表可以多于槽函数;信号可以连接信号<br>
## 常用控件
### QPushButton
### QToolButton
- 设置透明：QToolButton{border-style: flat;background: transparent;}
### QLabel
### Qslider
### QProgressBar
### QTextEdit
## 窗口部件
### QMenur
&nbsp;&nbsp;菜单栏，在主窗口只有一个！
### QToolBar
&nbsp;&nbsp;工具栏，在主窗口可以多个！
### QStatusBar
&nbsp;&nbsp;状态栏，在主窗口可以多个！
### 中心部件
&nbsp;&nbsp;中心部件，在主窗口只有一个！
### QDockWidget
&nbsp;&nbsp;衔接部件(浮动窗口)，在主窗口可以多个！
## 对话框
### 模态对话框
&nbsp;&nbsp;阻塞式创建对话框，无法对其他对话框操作。
&nbsp;&nbsp;创建模态对话框注意不要使用new，防止内存泄露。不能使用show函数，会导致模态失效。
### 非模态对话框
&nbsp;&nbsp;非阻塞式创建对话框，可以对其他对话框操作。
&nbsp;&nbsp;使用setAttribute(Qt::WA_DeleteOnClose)设置关闭时释放，防止内存泄露。
## 图形绘制
- 设置画家Painter
- 设置画布painter->begin()【放在paintEvent轮询访问】
- 配置画笔QPen
- 开始绘制
- 结束绘制painter->end【没有结束容易崩溃】<br>
## 图形
元素--->场景--->视图--->窗口
- 一个场景可以包含多个元素，每个视图只能包含一个场景，每个窗口可以包含多个视图
- 元素加入场景的顺序影响显示顺序
- 视图需要绑定父亲窗口，否则出现额外窗口
## 对象池
&nbsp;&nbsp;对象被频繁创建或删除时，大量使用new和delete关键字处理堆内存，如果该对象比较大，则对计算机的消耗比较大，导致卡顿<br>
&nbsp;&nbsp;对象缓冲池，本质是个容器（工厂），预先缓存一定数量的对象，创建对象时直接从对象池取出。<br>
&nbsp;&nbsp;对象池可以暂时管理本应释放的对象，不销毁而回收，循环利用。<br>
&nbsp;&nbsp;窗口关闭时释放对象的两种方法1，把对象加入对象树2，在窗口closeEvent事件中处理<br>

## 音乐
&nbsp;&nbsp;需要添加QT += multimedia<br>
&nbsp;&nbsp;注意QUrl路径对象的字符串格式"qrc:/+前缀+路径"<br>