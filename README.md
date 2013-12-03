TopCoder598Div1
===============

TopCoder SRM 597 Div1

第1题解题报告

类型：其他  难度：2.5

题意：给出一组数，表示一组物品的重量，每个物品重量范围[100,300]，现在要将这组物品放到若干个桶中，每个桶最多放重量300的物品，问最少需要多少桶

分析：一开始把题目想简单了，经过几次修改才正确。

1、首先将物品按重量排序，从重量大的遍历，考虑大于200的物品，这些物品必定一个物品占一个桶（因为最轻的物品重量为100，大于200的不能和其他物品放在一个桶里）

2、再遍历剩余的物品，找到当前最重的物品，并找到能和它放在一个桶中的最重的物品

（1）若没有和它能放在一个桶中的，那么这个物品单独占一个桶

（2）若有，那么这两个物品放在一个桶中

3、若当前最重物品重量为100，那么还需要（剩余物品数+2）/ 3 个桶


第2题解题报告

类型：博弈  难度：2

题意：不知道为啥这道不算太难的博弈会是550分的题，考察细节吧。Ciel和Liss在一条直线的两点，相距距离为d，他们每次能走的最大距离为mov1,mov2，他们的武器能够到的范围为rng1,rng2，Ciel先走，每一步包括走一段并可以尝试用武器打对方，每个人都用最优策略走，问谁会赢，还是平局

分析：1、首先应该考虑第一回合会不会分出胜负，若mov1+rng1>=d，那么Ciel赢，若mov2+rng2>=d+mov1，Liss赢（Liss后手，要加mov1）

2、若第一回合分不出胜负，那么需要比较mov1，mov2（之前考虑比较mov1+rng1和mov2+rng2，发现并不正确，每次只能走mov步，所以要按mov来分情况）

（1）mov1==mov2，一定是平局

（2）mov1>mov2，Ciel走得快，那么Ciel如果想赢，必须在追着Liss走了x步时能打到Liss，但是又要防止Liss在x-1步时反向走倒打一耙，所以需要满足条件，

mov1-mov2+rng1>mov2+rng2。也可以理解为，当Ciel走到和Liss距离为mov1+rng1时，Liss又会走mov2，那么Ciel必须保证第x步走到和Liss距离为mov1-mov2+rng1，然后Liss走第x步走过mov2，然后这时轮到Ciel走第x+1步，此时距离为mov1+rng1，那么一走一打刚好打到Liss，其中，当Ciel走完第x步而Liss未走第x步时，二者距离最近，为mov1-mov2+rng1，必须保证这个距离大于mov2+rng2，否则Liss就会倒打一耙，就是平局。

（3）mov1<mov2，和(2)同理
