7-2.c，7-2-debug.c
其实想实现的想法是7-2-debug.c中的，但是一开始 LMUL = NULL，LMUL = AddList(LMUL,LTMP)
总是得不到正确的结果。每次加之前Print()，发现LMUL除了一开始是NULL，之后和LTMP都是一样的，
我以为，是LMUL没有malloc出来，然后，就考虑先让LMUL存着L1中第一项乘以L2的结果，再AddList，
发现结果就对了。当然OJ还有个点没通过，发现是AddList()函数中，当两项指数相同时，忘了将指数赋给。。
当然，还是想不明白为什么初值是NULL，就不行。明明AddList()是malloc一个链表，然后返回的头结点指针。
所以自己写了个f()函数来测试，发现NULL是可以的。
然后就去娱乐了几把，再打开看，发现是自己的AddList()，写的有问题。if( L1 == NULL ) return L2; 一开始LMUL是NULL，那不就是将LMUL指到和LTMP指的链表？就算L1是空表，那也应该将L2拷贝一份，所以再写个while循环？不用的，后面的while(L1)，while(L2)其实已经将空表考虑进来了，有一点问题是，会多一个空的头结点，那就让头结点赋为0 0，这样就会被free掉了。

过几天根据老师的做法再改进一下。