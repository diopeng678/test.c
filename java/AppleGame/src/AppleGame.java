import java.util.Random;
import java.util.Scanner;

public class AppleGame{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // 1. 初始化游戏数据
        int coins = 10; // 初始金币
        String[] fruits = {"苹果", "木瓜", "西瓜", "香蕉", "橙子", "葡萄"};
        int[] multipliers = {2, 5, 10, 20, 50, 100}; // 对应奖励系数
        System.out.println("🎮 欢迎来到幸运苹果机游戏！");
        System.out.println("初始金币：" + coins);
        System.out.println("------------------------");

        // 2. 游戏主循环
        while (coins > 0) {
            // 显示当前金币
            System.out.println("\n当前金币：" + coins);
            // 显示水果选项
            System.out.println("可选水果及奖励系数：");
            for (int i = 0; i < fruits.length; i++) {
                System.out.println((i + 1) + ". " + fruits[i] + " —— 奖励系数 ×" + multipliers[i]);
            }

            // 选择水果
            System.out.print("请选择你要押注的水果（输入数字1-6）：");
            int fruitChoice = scanner.nextInt() - 1; // 转成数组下标
            if (fruitChoice < 0 || fruitChoice >= fruits.length) {
                System.out.println("输入错误，请重新选择！");
                continue;
            }
            String selectedFruit = fruits[fruitChoice];

            // 输入押注金额
            System.out.print("请输入押注金币（1~" + coins + "）：");
            int bet = scanner.nextInt();
            if (bet < 1 || bet > coins) {
                System.out.println(" 押注金额无效，请重新输入！");
                continue;
            }

            // 3. 模拟运转（随机结果）
            System.out.println("\n 苹果机正在运转...");
            int resultIndex = random.nextInt(fruits.length);
            String resultFruit = fruits[resultIndex];
            System.out.println("结果：" + resultFruit);

            // 4. 结算
            if (resultFruit.equals(selectedFruit)) {
                // 猜中：获得奖励
                int reward = bet * multipliers[resultIndex];
                coins += reward;
                System.out.println(" 恭喜！猜中了 " + selectedFruit + "，获得 " + reward + " 金币！");
            } else {
                // 没猜中：扣除押注
                coins -= bet;
                System.out.println(" 很遗憾，没猜中，失去 " + bet + " 金币。");
            }

            // 询问是否继续
            System.out.print("\n是否继续游戏？（输入y继续，其他键退出）：");
            String choice = scanner.next();
            if (!choice.equalsIgnoreCase("y")) {
                break;
            }
        }
        // 5. 游戏结束
        System.out.println("\n------------------------");
        System.out.println("游戏结束！最终金币：" + coins);
        scanner.close();
    }
}