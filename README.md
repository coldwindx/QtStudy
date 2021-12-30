# QtStudy
## 信号和槽
&amp;&amp;QT框架引以为豪，本质是观察者模式。<br>
&amp;&amp;Signal信号来自被观察者，只需要函数声明，不需要实现，系统内大多数类都内置了信号；<br>
&map;&amp;Slot槽来自观察者，本质是函数，必须有实现,系统内大多数类都内置了槽。<br>
&amp;&amp;使用connect函数为信号和槽建立连接，当信号广播（触发）时，槽做出相应处理。<br>
### 自定义信号和槽
&amp;&amp;自定义槽<br>
&amp;&amp;&amp;&amp;- 有函数声明且实现
&amp;&amp;&amp;&amp;- 返回值类型为void
&amp;&amp;&amp;&amp;- 可以带参，可以重载
&amp;&amp;自定义信号<br>
&amp;&amp;&amp;&amp;- 只需函数声明
&amp;&amp;&amp;&amp;- 返回值类型为void
&amp;&amp;&amp;&amp;- 可以带参，可以重载
&amp;&amp;emit用于触发信号，信号和槽的函数参数表需要一一对应，信号的参数表可以多于槽函数<br>
## 常用控件
### QPushButton
### QLabel
### Qslider
### QProgressBar
### QTextEdit