import java.util.Scanner;
import java.util.Random;

/**
 * 幸运抽奖系统
 * 功能：注册、登录、抽奖
 * 文件名：LoginAndRegister.java
 */
public class LoginAndRegister {
    // 全局变量
    static String username = "";
    static String password = "";
    static int cardNumber = 0;
    static boolean isRegistered = false;
    static Scanner scanner = new Scanner(System.in);
    static Random random = new Random();

    public static void main(String[] args) {
        boolean continueRun = true;

        while (continueRun) {
            showMenu();
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    register();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    luckyDraw();
                    break;
                default:
                    System.out.println("您的输入有误！");
            }

            System.out.print("是否继续操作？(y/n): ");
            String choiceContinue = scanner.nextLine();
            if (!choiceContinue.equalsIgnoreCase("y")) {
                continueRun = false;
                System.out.println("程序已退出！");
            }
        }
        scanner.close();
    }

    /**
     * 显示菜单
     */
    public static void showMenu() {
        System.out.println("===== 幸运抽奖系统 =====");
        System.out.println("1. 用户注册");
        System.out.println("2. 用户登录");
        System.out.println("3. 幸运抽奖");
        System.out.println("========================");
        System.out.print("请输入菜单编号：");
    }

    /**
     * 注册功能
     */
    public static void register() {
        System.out.println("===== 用户注册 =====");
        System.out.print("请输入用户名：");
        username = scanner.nextLine();
        System.out.print("请输入密码：");
        password = scanner.nextLine();

        // 生成4位随机卡号
        cardNumber = 1000 + random.nextInt(9000);
        isRegistered = true;

        System.out.println("注册成功！");
        System.out.println("用户名：" + username);
        System.out.println("卡号：" + cardNumber);
        System.out.println("====================");
    }

    /**
     * 登录功能
     */
    public static void login() {
        if (!isRegistered) {
            System.out.println("请先注册再登录！");
            return;
        }

        System.out.println("===== 用户登录 =====");
        int loginCount = 0;
        boolean loginSuccess = false;

        while (loginCount < 3) {
            System.out.print("请输入用户名：");
            String inputUsername = scanner.nextLine();
            System.out.print("请输入密码：");
            String inputPassword = scanner.nextLine();

            if (inputUsername.equals(username) && inputPassword.equals(password)) {
                loginSuccess = true;
                break;
            } else {
                loginCount++;
                System.out.println("用户名或密码错误！剩余次数：" + (3 - loginCount));
            }
        }

        if (loginSuccess) {
            System.out.println("登录成功！欢迎您，" + username + "！");
        } else {
            System.out.println("登录失败，已超过最大尝试次数！");
        }
        System.out.println("====================");
    }

    /**
     * 幸运抽奖功能
     */
    public static void luckyDraw() {
        if (!isRegistered) {
            System.out.println("请先注册并登录！");
            return;
        }

        System.out.println("===== 幸运抽奖 =====");
        System.out.print("请输入您的会员卡号：");
        int inputCard = scanner.nextInt();

        // 生成5个4位随机幸运数字
        int[] luckyNumbers = new int[5];
        System.out.print("本期幸运数字：");
        for (int i = 0; i < luckyNumbers.length; i++) {
            luckyNumbers[i] = 1000 + random.nextInt(9000);
            System.out.print(luckyNumbers[i] + " ");
        }
        System.out.println();

        // 判断是否中奖
        boolean isLucky = false;
        for (int num : luckyNumbers) {
            if (num == inputCard) {
                isLucky = true;
                break;
            }
        }

        if (isLucky) {
            System.out.println("恭喜您成为本日幸运会员！");
        } else {
            System.out.println("很遗憾，您不是本日幸运会员！");
        }
        System.out.println("====================");
    }
}
