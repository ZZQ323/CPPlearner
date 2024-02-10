# vim move
w 跳到一个单词开头  
b 开头  
e 结尾  
ge 上一个末尾  
gg 跳到第一行  
G 跳到最后一行  
f{Char}  
F{char}  
t{char}  
T{char}  
; 重复执行上一次查找命令  
, 反向执行上一次查找命令  
$ 行尾  
^ 非空行首  
0 行首  
k  
j 下面  
h 上面  
l  

# vim operator  

d 删除  
c 修改  
y 复制  
p 粘贴  
v 选中  

# vim motion  

a(around)  
i(inner)  
后面可以加上各种成对的字符来表示选中的区域和符号。  
2cc、2dd、2yy倍数操作  
修改或删除数组里面的内容 a[123412]
修改或删除字符串里面的内容 ci" di"
修改或删除整个字符串 ca" da"  
删除到、修改到 s fsd fsc
删除到修改到开头、结尾  d^ d$ c^ c$  
修改删除整个文件 de ce  
删除修改整个标签  dt ct  
vib viB   
~ 切换大小写  
3~ 切换连续的三个字符的大小写
gd 跳转到定义  
gh 显示 hover 效果  
gt 切换 tab  
gT 切换到前一个 tab  
4gt 向后跳转 4 个tab  
ctrl + 0 跳转到侧边栏 Explore  
space 打开文件  
l 将光标跳转到文件  

# vim easy motion

leader leader s f F t T 
c s " ( 将字符串替换为单括号  
删除标签 dst  
变成数组 ysiw [ 
加上p标签 ysiw <p>  
  