import java.util.Scanner;

/**
 * 简单的Java入门程序
 * 功能：向用户问好，并展示基本的Java语法结构
 */
public class HelloWorldEnhanced {
    // 程序入口方法（main方法）
    public static void main(String[] args) {
        // 1. 打印欢迎信息
        System.out.println("=== 欢迎使用Java入门程序 ===");

        // 2. 创建Scanner对象，用于接收用户输入
        Scanner scanner = new Scanner(System.in);

        // 3. 提示用户输入姓名
        System.out.print("请输入你的名字：");
        String userName = scanner.nextLine(); // 接收用户输入的字符串

        // 4. 提示用户输入年龄
        System.out.print("请输入你的年龄：");
        int userAge = scanner.nextInt(); // 接收用户输入的整数

        // 5. 输出个性化问候
        System.out.println("\n你好，" + userName + "！");
        System.out.println("你的年龄是：" + userAge + " 岁");

        // 6. 简单的条件判断
        if (userAge >= 18) {
            System.out.println("你已经是成年人了！");
        } else {
            System.out.println("你还未成年，要好好学习哦！");
        }

        // 7. 关闭Scanner，释放资源
        scanner.close();

        // 8. 程序结束提示
        System.out.println("\n程序执行完毕！");
    }
}