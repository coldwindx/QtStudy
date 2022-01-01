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
- 结束绘制painter->end【没有结束容易崩溃】