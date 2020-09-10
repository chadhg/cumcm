# CUMCM

### B题  **穿越沙漠**

考虑如下的小游戏：玩家凭借一张地图，利用初始资金购买一定数量的水和食物（包括食品和其他日常用品），从起点出发，在沙漠中行走。途中会遇到不同的天气，也可在矿山、村庄补充资金或资源，目标是在规定时间内到达终点，并保留尽可能多的资金。

游戏的基本规则如下：

> （1）以天为基本时间单位，游戏的开始时间为第0天，玩家位于起点。玩家必须在截止日期或之前到达终点，到达终点后该玩家的游戏结束。

> （2）穿越沙漠需水和食物两种资源，它们的最小计量单位均为箱。每天玩家拥有的水和食物质量之和不能超过负重上限。若未到达终点而水或食物已耗尽，视为游戏失败。

> （3）每天的天气为“晴朗”、“高温”、“沙暴”三种状况之一，沙漠中所有区域的天气相同。

> （4）每天玩家可从地图中的某个区域到达与之相邻的另一个区域，也可在原地停留。沙暴日必须在原地停留。

> （5）玩家在原地停留一天消耗的资源数量称为基础消耗量，行走一天消耗的资源数量为基础消耗量的 **2 倍**。

> （6）玩家第 0 天可在起点处用初始资金以基准价格购买水和食物。玩家可在起点停留或回到起点，但**不能多次在起点购买资源**。玩家到达终点后可退回剩余的水和食物，每箱退回价格为基准价格的一半。

> （7）玩家在矿山停留时，可通过挖矿获得资金，挖矿一天获得的资金量称为基础收益。如果挖矿，消耗的资源数量为基础消耗量的 **3 倍**；如果不挖矿，消耗的资源数量为基础消耗量。到达矿山当天不能挖矿。沙暴日也可挖矿。

> （8）玩家经过或在村庄停留时可用剩余的初始资金或挖矿获得的资金随时购买水和食物，每箱价格为基准价格的2倍。

------



请根据游戏的不同设定，建立数学模型，解决以下问题。

1. 假设只有一名玩家，在整个游戏时段内<u>*每天天气状况事先全部已知*</u>，试给出一般情况下玩家的<u>最优策略</u>。求解附件中的“**第一关**”和“**第二关**”，并将相应结果分别填入`Result.xlsx`。
2. 假设只有一名玩家，玩家<u>仅知道**当天**的天气状况</u>，可据此决定**当天**的行动方案，试给出一般情况下玩家的<u>最佳策略</u>，并对附件中的“**第三关**”和“**第四关**”进行具体讨论。
3. 现有 **n** 名玩家，他们有相同的初始资金，且同时从起点出发。若某天其中的任意` k(2<=k<=n) `名玩家均从区域A行走到区域B，则他们中的任一位消耗的资源数量均为基础消耗量的 `2k` 倍；若某天其中的任意` k(2<=k<=n) `名玩家在同一矿山挖矿，则他们中的任一位消耗的资源数量均为基础消耗量的 **3** 倍，且每名玩家一天可通过挖矿获得的资金是基础收益的 ` 1 / k ` ；若某天其中的任意` k(2<=k<=n) `名玩家在同一村庄购买资源，每箱价格均为基准价格的 **4** 倍。其他情况下消耗资源数量与资源价格与单人游戏相同。
   1. 假设在整个游戏时段内每天天气状况事先全部已知，每名玩家的行动方案需在**第 0 天**确定且此后不能更改。试给出一般情况下玩家应采取的策略，并对附件中的“**第五关**”进行具体讨论。
   2. 假设所有玩家仅知道当天的天气状况，从**第 1 天**起，每名玩家在当天行动结束后均知道其余玩家当天的行动方案和剩余的资源数量，随后确定各自第二天的行动方案。试给出一般情况下玩家应采取的策略，并对附件中的“**第六关**”进行具体讨论。

 

注1：附件所给地图中，有公共边界的两个区域称为相邻，仅有公共顶点而没有公共边界的两个区域不视作相邻。

注2：Result.xlsx中剩余资金数（剩余水量、剩余食物量）指当日所需资源全部消耗完毕后的资金数（水量、食物量）。若当日还有购买行为，则指完成购买后的资金数（水量、食物量）。