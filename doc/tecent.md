前半个小时，15道选择题，其中掌握不熟练的有C++的语法题，指针题（free，delete的用法），计算设备的使用效率（多个任务，单CPU，双设备，可抢占），二分查找效率，时间复杂度的计算，网络层协议种类（传输层：TCP和UDP，网络层：IP，ARP，RARP，ICMP，IGMP）等等。

后半个小时，3道编程题，这时间对我来讲有些紧张，第一道生成N阶格雷码（去年在leetcode似乎做过），第二道求数组中出现次数超过数组元素个数一半的数，第三道是大数乘法（大二程设做过，大三汇编也写过一次，可是这次还是思路不清，加上时间紧迫，最后没有写完）。

四道大题，第一题考sql写法，sql我只会简单的增删改查，每次还是查资料才写的出来，结果考个高级点的卡了我好久，最后也不一定写对；然后是编程题，问字符串删除任意字符后得到的保持顺序的最长回文字符串长度，回溯法写的蛋疼（后来看到讨论区做法很巧妙啊，先对字符串求逆，然后求最长公共子序列就好了），第二题纯模拟倒是写出来了，看来算法这块我还是欠缺的很，而且回溯之前一直用Python写，如果用C++可能又是另一种写法了，这个之后也要继续学习；最后问答题谈谈stack和heap的区别

C/C++部分主要考察了，宏展开，数组和指针，sizeof和strlen，类多态，STL等;UNIX/LINUX部分主要是考察了，shell脚本，线程同步机制和死锁，进程，基本的命令如ps，iostat等;数据库比较基础，主要是SQL语句的运用

5道程序输出写结果或者程序找错，5道编程题。这5道编程题大概为：

　　1、将一个4字节的整数的二进制表示中的001替换为011，输出替换后的整数。

　　2、将一个数组右移几位，比如数组为1 2 3 4，右移一位即为4 1 2 3。

　　3、输入一个表示十六进制的字符串，转换为十进制的整数输出。

　　4、单链表反转。

　　5、一个8*8的方格子，A点在左下角，B点在右上角，求A点到B点的最短路径有多少条。

一、单链表逆转。

 struct Node {

struct Node *next;

};

头指针为Node *pHeadNode; 请写出这个单链表的逆转程序。

二、有char a[n],char b[m]两个数组，n > m > 1000 ，b数组中的元素a中都有，现在需要生成数组c，将a中有b中没有的元素都放到c里面，要求高效，用c/c++语言实现。

三、找出数组中出现次数超过一半的数字

一个数量为N的整数数组，其中有很多重复，其中一个数字出现次数超过N/2，请将该数字找出来。要求高效，用c/c++语言实现。

四、旋转数组二分查找

已知有序数组a[N]， 从中间某个位置k（k未知，k=-1表示整个数组有序）分开，然后将前后两部分互换，得到新的数组，在该新数组里面查找元素x。如：a[]={1,2,5,7,9,10,15}，从k=4分开，得到新数组a={9,10,15, 1,2,5,7}。

                    函数原型

                   // n为数组长度, x为待查找的元素，如果存在则返回元素在a中的下标（a下标从0开始），如果不存在则返回-1

                   int binary_search_rotate_array(int* a, int n, int x);
