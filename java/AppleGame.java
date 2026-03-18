import java.util.Random;
import java.util.Scanner;

public class AppleGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // 1. 鍒濆鍖栨父鎴忔暟鎹�
        int coins = 10; // 鍒濆閲戝竵
        String[] fruits = {"鑻规灉", "鏈ㄧ摐", "瑗跨摐", "棣欒晧", "姗欏瓙", "钁¤悇"};
        int[] multipliers = {2, 5, 10, 20, 50, 100}; // 瀵瑰簲濂栧姳绯绘暟

        System.out.println("馃幃 娆㈣繋鏉ュ埌骞歌繍鑻规灉鏈烘父鎴忥紒");
        System.out.println("鍒濆閲戝竵锛�" + coins);
        System.out.println("------------------------");

        // 2. 娓告垙涓诲惊鐜�
        while (coins > 0) {
            // 鏄剧ず褰撳墠閲戝竵
            System.out.println("\n褰撳墠閲戝竵锛�" + coins);

            // 鏄剧ず姘存灉閫夐」
            System.out.println("鍙€夋按鏋滃強濂栧姳绯绘暟锛�");
            for (int i = 0; i < fruits.length; i++) {
                System.out.println((i + 1) + ". " + fruits[i] + " 鈥斺€� 濂栧姳绯绘暟 脳" + multipliers[i]);
            }

            // 閫夋嫨姘存灉
            System.out.print("璇烽€夋嫨浣犺鎶兼敞鐨勬按鏋滐紙杈撳叆鏁板瓧1-6锛夛細");
            int fruitChoice = scanner.nextInt() - 1; // 杞垚鏁扮粍涓嬫爣
            if (fruitChoice < 0 || fruitChoice >= fruits.length) {
                System.out.println("鉂� 杈撳叆閿欒锛岃閲嶆柊閫夋嫨锛�");
                continue;
            }
            String selectedFruit = fruits[fruitChoice];

            // 杈撳叆鎶兼敞閲戦
            System.out.print("璇疯緭鍏ユ娂娉ㄩ噾甯侊紙1~" + coins + "锛夛細");
            int bet = scanner.nextInt();
            if (bet < 1 || bet > coins) {
                System.out.println("鉂� 鎶兼敞閲戦鏃犳晥锛岃閲嶆柊杈撳叆锛�");
                continue;
            }

            // 3. 妯℃嫙杩愯浆锛堥殢鏈虹粨鏋滐級
            System.out.println("\n馃幇 鑻规灉鏈烘鍦ㄨ繍杞�...");
            int resultIndex = random.nextInt(fruits.length);
            String resultFruit = fruits[resultIndex];
            System.out.println("缁撴灉锛�" + resultFruit);

            // 4. 缁撶畻
            if (resultFruit.equals(selectedFruit)) {
                // 鐚滀腑锛氳幏寰楀鍔�
                int reward = bet * multipliers[resultIndex];
                coins += reward;
                System.out.println("馃帀 鎭枩锛佺寽涓簡 " + selectedFruit + "锛岃幏寰� " + reward + " 閲戝竵锛�");
            } else {
                // 娌＄寽涓細鎵ｉ櫎鎶兼敞
                coins -= bet;
                System.out.println("馃槩 寰堥仐鎲撅紝娌＄寽涓紝澶卞幓 " + bet + " 閲戝竵銆�");
            }

            // 璇㈤棶鏄惁缁х画
            System.out.print("\n鏄惁缁х画娓告垙锛燂紙杈撳叆y缁х画锛屽叾浠栭敭閫€鍑猴級锛�");
            String choice = scanner.next();
            if (!choice.equalsIgnoreCase("y")) {
                break;
            }
        }

        // 5. 娓告垙缁撴潫
        System.out.println("\n------------------------");
        System.out.println("娓告垙缁撴潫锛佹渶缁堥噾甯侊細" + coins);
        scanner.close();
    }
}